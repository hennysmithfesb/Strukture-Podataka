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
	char *prezime;
	int godina;
	position next;
}stud;

int FindSurname(position);
int InsertEnd(position);
int Insert(position,char*, char*,int);
int InsertBeginning(position);
int ReadFromFile(position);
int Print(position);
int Delete(position);
int main(){

	stud head;
	char choice=0;
	head.next=NULL;
	
	
	
	
	if(ReadFromFile(&head)==ERROR)
		return ERROR;
	printf("ovo je lista\n");
	Print(head.next);
	printf("\t\tMENU\t\t\n");
	printf("Dodavanje na kraj (1)\nDodavanje na pocetak (2)\nBrisanje sa liste (3)\nOdabir odredjene osobe (4)\n");
	scanf(" %c",&choice);
	switch(choice)
	{
	case '1':
	InsertEnd(&head);
	printf("nova lista\n");
	Print(head.next);
	break;
	case '2':
	InsertBeginning(&head);
	printf("nova lista\n");
	Print(head.next);
	break;
	case '3' :
		Delete(&head);
		printf("nova lista\n");
		Print(head.next);
		break;
	case '4' :
		FindSurname(&head);
		break;
	default:
		break;
	}



	



	return SUCCESS;
}

int ReadFromFile(position P){

	FILE *fp=NULL;
	char *buffime=NULL;
	char *buffprez=NULL;
	int buffgod=0;
	char *filename=NULL;
	filename=(char *)malloc(sizeof(char)*20);
	if(filename==NULL) return ERROR;
	printf("unesi ime datoteke \n");
	scanf("%s", filename);
	buffime=(char *)malloc(sizeof(char)*20);
	if(buffime == NULL) return ERROR;
	buffprez=(char *)malloc(sizeof(char)*20);
	if(buffprez == NULL) return ERROR;
	fp=fopen(filename,"r");
	if(fp==NULL)
		return ERROR;

	while(!feof(fp)){
		
		fscanf(fp,"%s %s %d", buffime,buffprez,&buffgod);
		
			if(Insert(P,buffime,buffprez,buffgod)==ERROR)
				return ERROR;
			

	
	}

	return SUCCESS;
	
}

int Insert(position p,char *name, char *surname, int year){

	position newNode=NULL;

	newNode=(position)malloc(sizeof(stud));
	if(newNode==NULL) return ERROR;
	newNode->ime=(char *)malloc(sizeof(char)*20);
	if(newNode->ime == NULL) return ERROR;
	newNode->prezime=(char *)malloc(sizeof(char)*20);
	if(newNode->prezime == NULL) return ERROR;

	newNode->next = NULL;

	strcpy(newNode->ime,name);
	strcpy(newNode->prezime,surname);
	newNode->godina=year;

	newNode->next=p->next;
	p->next=newNode;

	return SUCCESS;
}

int InsertEnd(position p){

	position newNode=NULL;
	char *name=NULL;
	char *surname=NULL;
	int year=0;
	newNode=(position)malloc(sizeof(stud));
	if(newNode==NULL) return ERROR;
	newNode->ime=(char *)malloc(sizeof(char)*20);
	if(newNode->ime == NULL) return ERROR;
	newNode->prezime=(char *)malloc(sizeof(char)*20);
	if(newNode->prezime == NULL) return ERROR;

	newNode ->next = NULL;
	printf("dodavanje na kraj\n");
	name=(char *)malloc(sizeof(char)*20);
	if(name==NULL) return ERROR;
	surname=(char *)malloc(sizeof(char)*20);
	if(surname==NULL) return ERROR;
	printf("unesi ime novoga elementa\n");
	scanf("%s",name);
	printf("unesi prezime novoga elementa\n");
	scanf("%s",surname);
	printf("unesi godinu novoga elementa\n");
	scanf("%d",&year);
	strcpy(newNode->ime,name);
	strcpy(newNode->prezime,surname);
	newNode->godina=year;
	while(p->next != NULL){
		p=p->next;
	}
	
	newNode->next=p->next;
	p->next=newNode;

	return SUCCESS;
}

int Print(position p){

	while(p!=NULL){
	
		printf("%s %s %d \n", p->ime, p->prezime, p->godina);

		p=p->next;
	
	}
	return SUCCESS;
}

int InsertBeginning(position P)
{
	position newNode=NULL;
	char *name=NULL;
	char *surname=NULL;
	int year=0;
	newNode=(position)malloc(sizeof(stud));
	if(newNode==NULL) return ERROR;
	newNode->ime=(char *)malloc(sizeof(char)*20);
	if(newNode->ime == NULL) return ERROR;
	newNode->prezime=(char *)malloc(sizeof(char)*20);
	if(newNode->prezime == NULL) return ERROR;

	newNode ->next = NULL;
	printf("dodavanje na kraj\n");
	name=(char *)malloc(sizeof(char)*20);
	if(name==NULL) return ERROR;
	surname=(char *)malloc(sizeof(char)*20);
	if(surname==NULL) return ERROR;
	printf("unesi ime novoga elementa\n");
	scanf("%s",name);
	printf("unesi prezime novoga elementa\n");
	scanf("%s",surname);
	printf("unesi godinu novoga elementa\n");
	scanf("%d",&year);
	strcpy(newNode->ime,name);
	strcpy(newNode->prezime,surname);
	newNode->godina=year;

	newNode->next=P->next;
	P->next=newNode;
	return SUCCESS;



}
int Delete(position P)
{
	char *surname=NULL;
	surname=(char *)malloc(sizeof(char)*20);
	if(surname==NULL) return ERROR;
	printf("unesi prezime lika kojeg zelis maknit iz liste\n");
	scanf("%s",surname);
	while(P->next!=NULL && strcmp(P->next->prezime,surname)!=0)
	{
		P=P->next;	
	}

	if(P->next!=NULL)
	{
		P->next=P->next->next;
	
	
	}
	else
	{
		printf("nepostojece prezime\n");
	}




	return SUCCESS;

}


int FindSurname(position p){

	char *surname;
	surname=(char *)malloc(sizeof(char)*20);
	if(surname == NULL) return ERROR;
	printf("unesite prezime osobe koju zelite pronac \n");
	scanf("%s", surname);

	while(p->next!=NULL && strcmp(p->next->prezime,surname)!=0){	
		
		p=p->next;
	}
		
			printf("%s %s %d \n",p->next->ime,p->next->prezime,p->next->godina);
		
	
	


	return SUCCESS;
}