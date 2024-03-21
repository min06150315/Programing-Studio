// Enter your student ID and Fullname

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 50

char LNAME[5][30]={"Graphite","Opal","Bronze","Silver","Gold"}; // labels by level

struct st_channel{
	char name[100]; // Channel name
	int count;	  // # of subscriptions
	int level;	  // index of level (0~4)
};

int loadData(struct st_channel* c[]); 
int findLevel(int num); 
void printStatistics(struct st_channel* c[], int size);
void printChannels(struct st_channel* c[], int size);
void pickupRandomChannels(struct st_channel* c[], int size);
void searchChannel(struct st_channel* c[], int size);
int addChannel(struct st_channel* c[], int size);
void updateChannel(struct st_channel* c[], int size);
int deleteChannel(struct st_channel* c[], int size);
void makeReport(struct st_channel* c[], int size); 

int main(void) {
	int no;	// amount of channels
	struct st_channel* clist[SIZE]; // channel list
	int menu; // menu number 

	srand(time(0));
	no = loadData(clist);

	while(1)
	{
		// Print menu
		printf("\n[1]List [2]Statistics [3]Random pick [4]Search [5]Add [6]Modify [7]Delete [8]Report [0]Exit\n> Enter a menu >> ");
		scanf("%d",&menu);	

		if(menu==1){
			printChannels(clist, no); // Print all list of channels
		}
		else if(menu==2){
			printStatistics(clist, no);	// Print statistics of each level
		}
		else if(menu==3){
			pickupRandomChannels(clist, no); // Pick up random channels
		}
		else if(menu==4){
			searchChannel(clist, no);	// Search a channel
		}
		else if(menu==5){
			no = addChannel(clist, no); // Add a channel
		}
		else if(menu==6){
			updateChannel(clist, no); // Modify a channel
		}
		else if(menu==7){
			no = deleteChannel(clist, no); // Delete a channel
		}
		else if(menu==8){
			makeReport(clist, no);	// Make a Report
		}
		else {
			break;
		}
	}
	return 0;
}

int loadData(struct st_channel* c[]){
	int no=0;
	FILE* file;

	file=fopen("channels.txt", "r");
	while(!feof(file)){
		struct st_channel* t = (struct st_channel*)malloc(sizeof(struct st_channel));
		int r=fscanf(file, "%s %d", t->name, &(t->count));
		if(r<2) break;
		t->level = findLevel(t->count);
		c[no] = t;
		no++;
	}
	fclose(file);
	printf("> %d channels are loaded.\n", no);
	return no;
}

int findLevel(int num){
	int range[5]={1000,10000,100000,1000000,10000000}; // range for level
	for(int j=0;j<5;j++)
		if(num<range[j])
			return j;
	return 0;
}

void printChannels(struct st_channel* c[], int size){
	printf("> List of Channels\n");
	for(int i=0; i<size; i++){
		printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
	}
}

int addChannel(struct st_channel* c[], int size){
	struct st_channel* temp;
	printf("> Add a new Channel\n");
	temp = (struct st_channel*)malloc(sizeof(struct st_channel));
	printf("> Enter a name of channel > ");
	scanf("%s", temp->name);
	printf("> Enter an amount of peoples > ");
	scanf("%d", &(temp->count));
	temp->level = findLevel(temp->count);
	c[size] = temp;
	printf("> New channel is added.\n");
	printf("[%2d] %-20s %10d peoples [%s] \n",size+1, c[size]->name, c[size]->count,LNAME[c[size]->level]);
	return size+1;
}

void printStatistics(struct st_channel* c[], int size){
	printf("> Statistics of Channels\n");
    int count[5] = {0};
    int sub_sum[5] = {0};
    float sub_avg[5] = {0};
    char top[5][30];
    int top_people[5] = {0};
	
    // compute subscriptions count, sum and average
    //  check the top channel
    for (int i = 0; i < size; i++){
        if (c[i]->count < 1000){
            count[0]++;
            sub_sum[0] += c[i]->count;
            if(c[i]->count > top_people[0]){
                top_people[0] = c[i]->count;
                strcpy(top[0], c[i]->name);
            }
        }else if (c[i]->count < 10000){
            count[1]++;
            sub_sum[1] += c[i]->count;
            if(c[i]->count > top_people[1]){
                top_people[1] = c[i]->count;
                strcpy(top[1], c[i]->name);
            }
        }else if (c[i]->count < 100000){
            count[2]++;
            sub_sum[2] += c[i]->count;
            if(c[i]->count > top_people[2]){
                top_people[2] = c[i]->count;
                strcpy(top[2], c[i]->name);
            }
        }else if (c[i]->count < 1000000){
            count[3]++;
            sub_sum[3] += c[i]->count;
            if(c[i]->count > top_people[3]){
                top_people[3] = c[i]->count;
                strcpy(top[3], c[i]->name);
            }
        }else {
            count[4]++;
            sub_sum[4] += c[i]->count;
            if(c[i]->count > top_people[4]){
                top_people[4] = c[i]->count;
                strcpy(top[4], c[i]->name);
            }
        }
    }

    // print the average and top channel
    for (int i = 0; i < 5; i++){
        sub_avg[i] = (float)sub_sum[i] / count[i];
        printf("%s : %d channels, Average %.1f, Top channel : %s (%d peoples)\n", LNAME[i], count[i], sub_avg[i], top[i], top_people[i]);
    }
}

void pickupRandomChannels(struct st_channel* c[], int size){
	int count;
	int r;
	srand(time(NULL));
	printf("> Pick up Channels\n");

	// User input
	printf("> How much channels you want to pick up? > ");
	scanf("%d", &count);

	// Print random result
	printf("Random Channels\n");
	for (int i = 0; i < count; i++){
		r = rand() % size;
		printf("[%2d] %s (%s level, %d peoples)\n", r + 1, c[r]->name, LNAME[c[r]->level], c[r]->count);
	}
}
void searchChannel(struct st_channel* c[], int size){
	int menu;
	int from, to;
	char c_name[64];
	int count = 0;
	printf("> Search Channels\n");

	// User input
	printf("> Choose one (1:by peoples 2:by names) > ");
	scanf("%d", &menu);

	// Input system
	while(1){
		if (menu == 1){ // Searching by people
			// User input
			printf("> Enter the range of peoples (from ~ to) > ");
			scanf("%d %d", &from, &to);

			// Error check
			if (from > to){
				printf("Wrong range!!");
				exit(-1);
			}

			// Searching System
			printf("> Result:\n");
			for (int i = 0; i < size; i++){
				if(c[i]->count > from && c[i]->count < to){
					printf("[%2d] %-20s %10d peoples [%s] \n", i + 1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
					count++;
				}
			}
			break;
		}else if (menu == 2){ // Searcing by name
			// User input
			printf("> Enter a names > ");
			scanf("%s", c_name);
			count = 0;

			// Searcing system
			printf("> Result:\n");
			for (int i = 0; i < size; i++){
				if (strstr(c[i]->name, c_name) != NULL){
					printf("[%2d] %-20s %10d peoples [%s] \n", i + 1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
					count++;
				}
			}
			break;
		}else {
			printf("Error!! Retry to Choose!!\n");
		}
	}
	printf("> %d channels are found.\n", count);
}

void updateChannel(struct st_channel* c[], int size){
	int num;
	char new_name[64];
	int new_count;
	printf("> Modify a new Channel\n");

	// User input
	printf("> Enter a number of channel > ");
	scanf("%d", &num);

	if (num > size){
		printf("> Wrong number.\n");
	}else {
		printf("> Channel Info.\n");
		printf("[%2d] %-20s %10d peoples [%s] \n", num, c[num - 1]->name, c[num - 1]->count,LNAME[c[num - 1]->level]);

		// User input
		//	Modify the name of channel
		printf("> Enter a new name of channel > ");
		scanf("%s", new_name);
		strcpy(c[num - 1]->name, new_name);

		//	Modify the count of people
		printf("> Enter a new amount of peoples > ");
		scanf("%d", &new_count);
		c[num - 1]->count = new_count;
		
		//Modify the level of channel
		if (new_count < 1000){
			c[num - 1]->level = 0;
		}else if (new_count < 10000){
			c[num - 1]->level = 1;
		}else if (new_count < 100000){
			c[num - 1]->level = 2;
		}else if (new_count < 1000000){
			c[num - 1]->level = 3;
		}else {
			c[num - 1]->level = 4;
		}
		printf("> Channel info. is modified.\n");
	}
}

int deleteChannel(struct st_channel* c[], int size){
	int no, yesno;
	printf("> Delete a new Channel\n");

	// User input
	printf("> Enter a number of channel > ");
	scanf("%d", &no);
	if (no > size){
		printf("> Wrong number.\n");
	}else {
		printf("> Channel Info.\n");
		printf("[%2d] %-20s %10d peoples [%s] \n", no , c[no - 1]->name, c[no - 1]->count,LNAME[c[no - 1]->level]);
		
		// User input
		printf("> Do you want to delete the channel? (1:Yes 0:No) > ");
		scanf("%d", &yesno);
		if (yesno == 1){
			printf("> Channel is deleted.\n");

			// change the result
			strcpy(c[no - 1]->name, c[size - 1]->name);
			c[no - 1]->count = c[size - 1]->count;
			c[no - 1]->level = c[size - 1]->level;
			size = size - 1;
		}else if (yesno == 0){
			printf("> Canceled.\n");
		}
	}
	return size;
}


void makeReport(struct st_channel* c[], int size){
	FILE *fp = NULL;
	fp = fopen("report.txt", "w");
	printf("> All information of channels are saved into channels.txt\n");
	printf("> Channel Statistics are saved into report.txt\n");

	// Write at report.txt
	//	Write channel information
	fprintf(fp, "Channel List\n");
	for (int i = 0; i < size; i++){
		fprintf(fp, "[%2d] %-20s %10d peoples [%s] \n", i + 1, c[i]->name, c[i]->count, LNAME[c[i]->level]);
	}
	
	// Reuse the printStatistics() function
	fprintf(fp, "\nStatistics of Channels\n");
	int count[5] = {0};
    int sub_sum[5] = {0};
    float sub_avg[5] = {0};
    char top[5][30];
    int top_people[5] = {0};
    for (int i = 0; i < size; i++){
        if (c[i]->count < 1000){
            count[0]++;
            sub_sum[0] += c[i]->count;
            if(c[i]->count > top_people[0]){
                top_people[0] = c[i]->count;
                strcpy(top[0], c[i]->name);
            }
        }else if (c[i]->count < 10000){
            count[1]++;
            sub_sum[1] += c[i]->count;
            if(c[i]->count > top_people[1]){
                top_people[1] = c[i]->count;
                strcpy(top[1], c[i]->name);
            }
        }else if (c[i]->count < 100000){
            count[2]++;
            sub_sum[2] += c[i]->count;
            if(c[i]->count > top_people[2]){
                top_people[2] = c[i]->count;
                strcpy(top[2], c[i]->name);
            }
        }else if (c[i]->count < 1000000){
            count[3]++;
            sub_sum[3] += c[i]->count;
            if(c[i]->count > top_people[3]){
                top_people[3] = c[i]->count;
                strcpy(top[3], c[i]->name);
            }
        }else {
            count[4]++;
            sub_sum[4] += c[i]->count;
            if(c[i]->count > top_people[4]){
                top_people[4] = c[i]->count;
                strcpy(top[4], c[i]->name);
            }
        }
    }

	// Write channel statistics
	for (int i = 0; i < 5; i++){
			sub_avg[i] = (float)sub_sum[i] / count[i];
			fprintf(fp, "%s : %d channels, Average %.1f, Top channel : %s (%d peoples)\n", LNAME[i], count[i], sub_avg[i], top[i], top_people[i]);
		}
	fclose(fp);
}