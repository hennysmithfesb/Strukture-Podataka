#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef ERROR
#define ERROR -1
#endif


struct clan;
typedef struct clan* position;
typedef struct clan
{
	int koef;
	int eksp;
	position next;

}CLAN;
int ReadFromFile(position);
int InsertSorted(position,int,int);
int Print(position);
int Zbrajanje(position,position,position);
int Mnozenje (position,position,position);
int main()
{
	CLAN pol1,pol2,suma,umn;
	pol1.next=NULL;
	pol2.next=NULL;
	suma.next=NULL;
	umn.next=NULL;
	printf("ucitavanje prvog polinoma\n");
	if(ReadFromFile(&pol1)==ERROR)
	  {  return ERROR; }

	printf("ucitavanje drugog polinoma\n");
	if(ReadFromFile(&pol2)==ERROR)
	  {  return ERROR; }

	printf("ispisivanje prvog polinoma\n");
	Print(pol1.next);

	printf("ispisivanje drugog polinoma\n");
	Print(pol2.next);

	printf("zbroj polinoma\n");
	Zbrajanje(pol1.next,pol2.next,&suma);
	printf("ispis sume\n");
	Print(suma.next);

	printf("umnozak polinoma \n");
	Mnozenje(pol1.next,pol2.next,&umn);
	printf("ispis umnoska \n");
	Print(umn.next);




	return SUCCESS;


}
int ReadFromFile(position P)
{
 char *filename=NULL;
 FILE *fp=NULL;
 int koeficijent,eksponent;
 printf("Unesi ime datoteke iz koje citamo polinom\n");
 filename=(char *)malloc(sizeof(char)*20);
 if(filename==NULL) return ERROR;

 scanf("%s",filename);
 fp=fopen(filename,"r");
 if(fp==NULL) return ERROR;
 while(!feof(fp))
	{
		fscanf(fp,"%d %d",&koeficijent,&eksponent);
		if(InsertSorted(P,koeficijent,eksponent)==ERROR)
		{
			return ERROR;
		}

	}

	return SUCCESS;

}
int InsertSorted(position P,int koeficijent,int eksponent)
{
	position newNode=NULL;
	newNode=(position)malloc(sizeof(CLAN));
	if(newNode==NULL) return ERROR;

	newNode->next=NULL;
	newNode->eksp=eksponent;
	newNode->koef=koeficijent;

	while(P->next!=NULL && P->next->eksp>newNode->eksp)
	{
		P=P->next;

	}

	if(P->next!=NULL && P->next->eksp==newNode->eksp)
	{
		P->next->koef=P->next->koef+newNode->koef;
		return SUCCESS;
	
	}
	newNode->next=P->next;
	P->next=newNode;
	return SUCCESS;




}

int Print(position P)
{
	while(P!=NULL)
	{
		printf("%d\t x ^%d\n",P->koef,P->eksp);
		P=P->next;
	
	}
	return SUCCESS;


}

int Zbrajanje(position prvi,position drugi,position suma)
{
 
	position tmp=NULL;
	int koeficijent=0;
	int eksponent=0;
	while(prvi!=NULL)
 {
	 koeficijent=prvi->koef;
	 eksponent=prvi->eksp;
	 InsertSorted(suma,koeficijent,eksponent);
	 prvi=prvi->next;
	
	}
	while(drugi!=NULL)
	{
	koeficijent=drugi->koef;
	 eksponent=drugi->eksp;
	 InsertSorted(suma,koeficijent,eksponent);
	 drugi=drugi->next;
	}

	return SUCCESS;
 }

int Mnozenje(position prvi,position drugi,position umnozak)
{
	position tmp=NULL;
	int koeficijent=0;
	int eksponent=0;
	while(prvi!=NULL)
	{
		tmp=drugi;
		while(tmp!=NULL)
		{
			koeficijent=tmp->koef*prvi->koef;
			eksponent=tmp->eksp+prvi->eksp;
			InsertSorted(umnozak,koeficijent,eksponent);
			tmp=tmp->next;
		}
		prvi=prvi->next;
	}


	return SUCCESS;


}





