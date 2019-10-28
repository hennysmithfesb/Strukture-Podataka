#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#ifndef SUCCESS
#define SUCCESS 0
#endif
#ifndef ERROR 
#define ERROR 1
#endif

struct student;
typedef struct student *position;
typedef struct student{

	char *ime;
	char *prez;
	int god;
	position next;
}stud;


int ReadFromFile(position);
int PrintToFile(position);
int Insert(position,char *,char *, int);
int InsertInfront(position);
int InsertEnd(position);
int SortList(position);
int Print(position);
position FindPrevSurname(position);
position FindSurname(position);

int main(){

	stud head;
	head.next = NULL;
	char choice;

	if(ReadFromFile(&head)==ERROR)
		return ERROR;

	printf("ovo je vasa lista \n");
	Print(head.next);

	printf("~~~~~~~MENU~~~~~~~\n");
	printf("1: UNOS ISPRED \n 2: UNOS IZA \n 3: SORTIRANJE PO PREZIMENIMA \n 4: UNOS SA LISTE U DATOTEKU \n");
	scanf(" %c", &choice);

	switch(choice){
	
	case '1':
		{
		InsertInfront(&head);
		printf("nova lista \n");
		Print(head.next);
	break;
		}
	case '2':
		{
		InsertBehind(&head);
		printf("nova lista \n");
		Print(head.next);
	break;
		}
	case '3' :
		{
		SortList(&head);
		printf("nova lista \n");
		Print(head.next);
	break;
		}
	case '4' :
		{
		PrintToFile(&head);
	break;
		}
	default :
		break;
	}
	
	return SUCCESS;
}

int ReadFromFile(position p){

	FILE *fp;
	char *name = NULL;
	char *surname = NULL;
	int year =0;
	char *filename = NULL;

	filename=(char *)malloc(20*sizeof(char));
	if (filename == NULL) return ERROR;

	name=(char *)malloc(20*sizeof(char));
	if (name == NULL) return ERROR;

	surname=(char *)malloc(20*sizeof(char));
	if (surname == NULL) return ERROR;

	printf("upisite ime filea(mora ukljucivati i nastavak npr .txt) \n");
	scanf("%s", filename);

	fp=fopen(filename,"r");
		if(fp == NULL){
			printf("Neuspjesno otvorena datoteka kolega \n");
				return ERROR;
		}

		while(!feof(fp)){
		
			fscanf(fp,"%s %s %d", name,surname,&year);
		
		if(Insert(p,name,surname,year)==ERROR)
			return ERROR;
		
		} 
		fclose(fp);
		free(filename);

		return SUCCESS;
}

int Insert(position p,char *buffime,char *buffprez, int godina){


	position newNode = NULL;
	
	newNode=(position)malloc(sizeof(stud));
	if(newNode == NULL) return ERROR;

	newNode->ime=(char *)malloc(sizeof(char)*20);
	if(newNode->ime == NULL) return ERROR;

	newNode->prez=(char *)malloc(sizeof(char)*20);
	if(newNode->prez == NULL) return ERROR;

	
	newNode->next = NULL;

	strcpy(newNode->ime,buffime);
	strcpy(newNode->prez,buffprez);
	newNode->god = godina;

	newNode->next=p->next;
	p->next=newNode;

		return SUCCESS;
	}

int Print(position p){

	while(p!=NULL){

	printf("%s %s %d \n",p->ime,p->prez,p->god);

	p=p->next;
	}

	return SUCCESS;
}

position FindPrevSurname(position p){

	char *surname = NULL;

	surname=(char *)malloc(sizeof(char)*20);
	if(surname==NULL) return NULL;

	printf("Upisite prezime ispred kojeg zelite unijeti clan \n");
	scanf("%s", surname);


	while(p->next != NULL && strcmp(p->next->prez,surname)!=0){
		p=p->next;
	}

	if(p->next == NULL)
		return NULL;

	return p;
}

position FindSurname(position p){

	char *surname = NULL;

	surname=(char *)malloc(sizeof(char)*20);
	if(surname==NULL) return NULL;

	printf("Upisite prezime ispred kojeg zelite unijeti clan \n");
	scanf("%s", surname);


	while(p != NULL && strcmp(p->prez,surname)!=0){
		p=p->next;
	}

	if(p == NULL)
		return NULL;

	free (surname);

	return p;
}

int PrintToFile(position p){

	char *filename = NULL;
	FILE *fp;

	filename=(char *)malloc(sizeof(char)*20);
	if (filename == NULL) return ERROR;

	printf("Napisite ime dateteke u koju zelite upisati ovu listu \n");
	scanf(" %s", filename);

	fp=fopen(filename,"w+");
	if(fp == NULL)
		return ERROR;

	while(p->next != NULL){
		fprintf(fp,"%s %s %d \n",p->next->ime,p->next->prez,p->next->god);

		p=p->next;
	}

	fclose(fp);
	free(filename);

	return SUCCESS;
}

int InsertInfront(position p){

	char *surname;
	position q=NULL;
	position newNode = NULL;
	char *ime;
	char *prezime;
	int godina;

	newNode = (position)malloc(sizeof(stud));
	if (newNode == NULL ) return ERROR;

	ime=(char *)malloc(sizeof(char)*20);
	if(ime==NULL) return NULL;

	prezime=(char *)malloc(sizeof(char)*20);
	if(prezime==NULL) return NULL;

	newNode->ime=(char *)malloc(sizeof(char)*20);
	if(newNode->ime==NULL) return NULL;

	newNode->prez=(char *)malloc(sizeof(char)*20);
	if(newNode->prez==NULL) return NULL;

	surname=(char *)malloc(sizeof(char)*20);
	if(surname==NULL) return NULL;
	
	

	printf("Unesite ime prezime i godinu clana kojeg zelite umetnuti \n");
	scanf("%s %s %d", ime,prezime, &godina);

	q=FindPrevSurname(p);

	strcpy(newNode->ime,ime);
	strcpy(newNode->prez,prezime);
	newNode->god=godina;

	newNode->next=q->next;
	q->next=newNode;
	
	
	return SUCCESS;
}
int InsertBehind(position p){

	char *surname;
	position q=NULL;
	position newNode = NULL;
	char *ime;
	char *prezime;
	int godina;

	newNode = (position)malloc(sizeof(stud));
	if (newNode == NULL ) return ERROR;

	ime=(char *)malloc(sizeof(char)*20);
	if(ime==NULL) return NULL;

	prezime=(char *)malloc(sizeof(char)*20);
	if(prezime==NULL) return NULL;

	newNode->ime=(char *)malloc(sizeof(char)*20);
	if(newNode->ime==NULL) return NULL;

	newNode->prez=(char *)malloc(sizeof(char)*20);
	if(newNode->prez==NULL) return NULL;

	surname=(char *)malloc(sizeof(char)*20);
	if(surname==NULL) return NULL;
	
	

	printf("Unesite ime prezime i godinu clana kojeg zelite umetnuti \n");
	scanf("%s %s %d", ime,prezime, &godina);

	q=FindSurname(p->next);

	strcpy(newNode->ime,ime);
	strcpy(newNode->prez,prezime);
	newNode->god=godina;

	newNode->next=q->next;
	q->next=newNode;
	
	
	return SUCCESS;
}

int SortList(position p){

	position temp = p;
	position j = NULL;
	position prevj = NULL;
	position end = NULL;

	while(temp->next != end)
	{
	prevj = temp;
	j = prevj->next;
	while(j->next != end){
	
		if(strcmp(j->prez,j->next->prez)>0){
			prevj->next = j->next;
			j->next = j->next->next;
			prevj->next->next=j;
			j=prevj->next;
		}
		
		prevj = j;
		j = j->next;
	}
	end = j;
	}

	return SUCCESS;
}