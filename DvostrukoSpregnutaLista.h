#ifndef DVOSTRUKOSPREGNUTALISTA_H
#define DVOSTRUKOSPREGNUTALISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Cvor {
	int vrednost;
	struct Cvor* sledeci;
	struct Cvor* prethodni;
} Cvor;

typedef struct Lista {
	int velicina;
	Cvor* prvi;
	Cvor* poslednji;
} Lista;

int NapraviListu(Lista*);
void UnistiListu(Lista*);
int UbaciElement(Lista*, Cvor*, int);
void IspisListe(Lista*);
int Sortiranje(Lista*,int (*IspisElemeta)(Lista* lista,int index));
int IspisElementa(Lista* ,int );

#endif
