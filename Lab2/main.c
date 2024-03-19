// Enter your student ID and Fullname

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_class{
	int code;		// class code
	char name[30]; 	// class name
	int unit;		// credites
	int grading;	// grading (1:A+~F, 2:P/F)
};

char kname[2][10] = {"A+~F", "P/F"}; // String for grading

// Functions provided
int loadData(struct st_class* c[]); // Load all class list from data file.
void printAllClasses(struct st_class* c[], int csize); // Print all class list

// Functions for modifying
int addNewClass(struct st_class* c[], int csize); // Add a class into the list
void editClass(struct st_class* c[], int csize); // Modify a class in the list
void findClasses(char* name, struct st_class* c[], int csize); // Search a class by name from the list

// Functions for making
int applyMyClasses(int my[], int msize, struct st_class* c[], int csize); // Apply a class
void printMyClasses(int my[], int msize, struct st_class* c[], int csize); // Print my classes
void saveMyClass(int my[], int msize, struct st_class* c[], int csize); // Save my classes
void saveAllClasses(struct st_class* c[], int csize); // Save all class list

int main(void) {
	int no;	// menu number 
	struct st_class* classes[50]; // Class list (max. 50 classes)

	int myclass[10]; // My classes (max. 10 classes of code)
	int mycount = 0; // Amount of my classes

	srand(time(0));
	int count = loadData(classes);
	printf("> Load %d classes.\n", count);

	while(1){
		printf("\n> Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n");
		printf(">> Menu? > ");
		scanf("%d", &no);

		if(no == 1){ 
			printf("> 1.Class list (%d classes)\n", count);
			printAllClasses(classes, count);
		}
		else if(no == 2){ 
			printf("> 2.Add a Class\n");
			count = addNewClass(classes, count);
		}
		else if(no == 3){ 
			printf("> 3.Modify a Class\n");
			editClass(classes, count);
		}
		else if(no == 4){
			printf("> 4.Search a Class\n");
			printf(">> Enter class name > ");
			char name[30];
			scanf("%s", name);
			findClasses(name, classes, count);
		}
		else if(no == 5){
			printf("> 5.Apply a class\n");
			mycount = applyMyClasses(myclass, mycount, classes, count);
			printf("%d classes has been applied.\n", mycount);
		}
		else if(no == 6){
			printf("> 6.My classes\n");
			printMyClasses(myclass, mycount, classes, count);
		}
		else if(no == 7){
			printf("> 7.Save\n");
			saveMyClass(myclass, mycount, classes, count);
			printf("\n> All my classes ware saved to my_classes.txt.\n");
			saveAllClasses(classes, count);
			printf("\n> All of class list ware saved to classes.txt.\n");
		}
		else break;
	}
	return 0;
}

int loadData(struct st_class* c[]){
	int count=0;
	FILE* file;

	file=fopen("classes.txt", "r");
	while(!feof(file)){
		c[count] = (struct st_class*)malloc(sizeof(struct st_class));
		int r = fscanf(file, "%d %s %d %d", &(c[count]->code),c[count]->name, &(c[count]->unit), &(c[count]->grading));
		if(r < 4) break;
		count++;
	}
	fclose(file);
	return count;
}

void printAllClasses(struct st_class* c[], int csize){
	for(int i=0; i<csize; i++){
		printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
	}
}

void saveAllClasses(struct st_class* c[], int csize){
	FILE* file;
	file = fopen("classes.txt", "w");
	for(int i=0; i<csize; i++){
		fprintf(file, "%d %s %d %d\n",c[i]->code, c[i]->name, c[i]->unit, c[i]->grading);
	}
	fclose(file);	
}

void findClasses(char* name, struct st_class* c[], int csize){
	int count = 0;

	printf("Searching (keyword : %s)\n", name);
	for(int i=0; i<csize; i++){
		if(strstr(c[i]->name, name)){
			printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
			count++;
		}
	}
	printf("%d classes found.\n", count);
}

// You must complete these functions.
int addNewClass(struct st_class* c[], int csize){
// Caution : Don't allow the duplicate class code.
// You must complete this function.
	struct st_class* p = (struct st_class*)malloc(sizeof(struct st_class));
	
	//	class code duplication check
	while (1){
		printf(">> code number > ");
		scanf("%d", &(p->code));

		int check = 0;
		for (int i = 0; i < csize; i++){
			if (p->code == c[i]->code){
				check = 1;
				printf(">> Code duplicated! Retry.\n");
				break;
			}
		}
		if (!check)
			break;
	}

	printf(">> class name > ");
	scanf("%s", p->name);
	printf(">> credits > ");
	scanf("%d", &(p->unit));
	printf(">> grading (1: A+~F, 2: P/F) > ");
	scanf("%d", &(p->grading));

	c[csize] = p;
	return csize+1;
}

void editClass(struct st_class* c[], int csize){
	struct st_class* p;
	int code;

	while (1){
		printf(">> Enter a code of class > ");
        scanf("%d", &code);

		//	check a code of class
		int check = 0;
		for (int i = 0; i < csize; i++){
			if (code == c[i]->code){
					check = 1;
					p = c[i];
					printf("> Current: [%d] %s [credits %d - %s]\n",p->code, p->name, p->unit, kname[p->grading-1]);
					printf("> Enter new class name > ");
					scanf("%s", p->name);
					printf("> Enter new credits > ");
					scanf("%d", &(p->unit));
					printf("> Enter new grading(1:Grade, 2: P/F) > ");
					scanf("%d", &(p->grading));

					printf("> Modified.\n");
					c[i] = p;
					break;
			}
		}
		if (check)
			break;
		else
			printf("> Please enter code again\n");
	}
}


// You must make all these functions.

int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){
	int code;
	while(1){
		printf(">> Enter a class code > ");
		scanf("%d", &code);
		int check = 0;
		for (int i = 0; i < csize; i++){
			if (code == c[i]->code){
				my[msize] = code;
				msize++;
				printf(">> [%d] %s [credits %d - %s]\n", c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
				check = 1;
				break;
			}
		}

		if (!check){
			printf(">> No such code of class.\n");
			continue;
		}
		printf(">> Add more?(1:Yes 2:No) > ");
		scanf("%d", &check);

		if(check == 1)
			continue;
		else if (check == 2)
			break;
	}
	return msize;
}

void printMyClasses(int my[], int msize, struct st_class* c[], int csize){
	int credit = 0;
	for (int i = 0; i < msize; i++){
		for (int j = 0; j < csize; j++){
			if (my[i] == c[j]->code){
				printf("%d. [%d] %s [credits %d - %s]\n",i + 1 ,c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading - 1]);
				credit += c[j]->unit;
			}
		}
	}
	printf("All : %d credits\n", credit);
}

void saveMyClass(int my[], int msize, struct st_class* c[], int csize){
	int credit = 0;
	int creditA = 0, creditP = 0;
	//	file open
	FILE *fp = NULL;
	fp = fopen("my_classes.txt", "w");
	//	error check
	if (fp == NULL)
    {
        printf("Failed to open the file my_classes.txt\n");
        exit(-1);
    }
	//	file write
	fprintf(fp, "My Classes\n");
	for (int i = 0; i < msize; i++){
		for (int j = 0; j < csize; j++){
			if (my[i] == c[j]->code){
				fprintf(fp, "%d. [%d] %s [credits %d - %s]\n", i + 1, c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading - 1]);
				//credit count
				credit += c[j]->unit;
				if (strcmp(kname[c[j]->grading - 1], "A+~F") == 0)
					creditA += c[j]->unit;
				else if (strcmp(kname[c[j]->grading - 1], "P/F") == 0)
					creditP += c[j]->unit;
				break;
			}
		}
	}
	fprintf(fp ,"All : %d classes, %d credits (A+~F %d credits, P/F %d credits)\n", msize, credit, creditA, creditP);
	fclose(fp);
}
