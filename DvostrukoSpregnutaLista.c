#include "DvostrukoSpregnutaLista.h"

int NapraviListu(Lista* lista){

	lista->prvi = lista->poslednji = NULL;
	lista->velicina = 0;

	return 1;
}

void UnistiListu(Lista* lista)
{

	if(lista->velicina == 0)
		return;

	Cvor* trenutni;
	trenutni = lista->prvi;
	while(trenutni != lista->poslednji)
	{
		trenutni = trenutni->sledeci;
		free(trenutni->prethodni);
	}
	free(trenutni);
	lista->prvi = lista->poslednji = NULL;
	lista->velicina = 0;
}

int UbaciElement(Lista* lista, Cvor* element, int index)
{

	Cvor* pomocni;
	int i;


	if((index > lista->velicina) || (index < 0) )
		return 0;

	if(index == 0){
		element->prethodni = NULL;
		element->sledeci = lista->prvi;

		if( (lista->velicina) != 0){
			element->sledeci->prethodni = element;
		}else{
			//ako je lista prazna
			element->sledeci = NULL;
			lista->poslednji = element;
			lista->prvi = element;
		}

		lista->velicina++;

		return 1;
	}

	if(index == (lista->velicina))
	{

		element->sledeci = NULL;
		element->prethodni = lista->poslednji;
		element->prethodni->sledeci = element;
		lista->poslednji = element;
		lista->velicina++;

		return 1;
	}

	pomocni = lista->prvi->sledeci;
	for(i = 1; i < index; pomocni = pomocni->sledeci, i++);
	element->prethodni = pomocni;
	element->sledeci = pomocni->sledeci->sledeci;
	element->sledeci->prethodni = element;
	element->prethodni->sledeci = element;

	lista->velicina++;



	return 1;
}

void IspisListe(Lista* lista)
{

	Cvor* pomocni;
	int index = 0;

	if(lista->velicina == 0)
		return;

	pomocni = lista->prvi;
	do{
		printf("Cvor sa indexom %d, vrednost: %d \n", index, pomocni->vrednost);
		index++;
		pomocni = pomocni->sledeci;
	}while(pomocni != NULL);

	return;
}

int IspisElementa(Lista* lista,int index)
{

	Cvor* pomocni;

	int i;

	if((index > lista->velicina) || (index < 0))
		return 0;

		if(index == 0)
		{
			return lista->prvi;

		}

		if(index == (lista->velicina-1))
		{
			return lista->poslednji;
		}


		pomocni = lista->prvi->sledeci;
		for(i = 1 ; i < index ; pomocni = pomocni->sledeci , i++);
		return pomocni;

}

int Sortiranje(Lista* lista,int (*IspisElementa)(Lista* lista,int index) )
{

	Cvor* pomocni;
	Cvor* pom;
	Cvor* pom1;
	int moja, i, j;
	int* prvo;
	int* drugo;
	int* ie;

if((lista->velicina)%2==0)
{
	moja=(lista->velicina)/2;
	pomocni = lista->prvi;
	for(i = 0; i < moja-1 ; pomocni = pomocni->sledeci , i++);
	printf("\n %d",*pomocni);
	printf(" %d",*pomocni->sledeci);
	for(j = 1; j < moja; j++)
	{
		pom = pomocni;
		pom1 = pomocni->sledeci;
		prvo = pom - i;
		printf(" %d", *prvo);
		drugo = pom1 + i;
		printf(" %d",*drugo);

	}
}else{
	moja=(lista->velicina)/2+1;
	pomocni = lista->prvi;
	for(i = 0; i < moja-1 ; pomocni = pomocni->sledeci , i++);
	printf("\n %d",*pomocni);
	for(j = 1; j < moja; j++)
	{
		pom = pomocni;
		prvo = pomocni + i;
		printf(" %d",*prvo);
		drugo = pom - i;
		printf(" %d",*drugo);

	}

}
	ie = IspisElementa(lista,moja);
	printf("\n Ispis Elementa %d",*ie);

	return 1;
}
