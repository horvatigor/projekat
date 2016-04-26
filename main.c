#include "DvostrukoSpregnutaLista.h"

int main()
{
	int i, j, n;


	Lista L1;

	printf("Unesite zeljeni broj elemeneta:");
	scanf("%d",&n);
	Cvor nizElemenata[n];
	for(i = 0; i < n; i++)
	{
		nizElemenata[i].vrednost = i+2;
	}

	if( NapraviListu(&L1) == 1)
	{
		printf("Lista uspesno napravljena!\n");
	}

	for(j = 0; j < n; j++)
	{
		UbaciElement(&L1, &nizElemenata[j], j);
	}

	printf("Velicina liste: %d\n", L1.velicina);

	IspisListe(&L1);

	Sortiranje(&L1,IspisElementa);

	return 0;
}
