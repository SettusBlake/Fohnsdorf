#pragma warning(disable:4996)

#include "common.h"

#define MAX_ARRAY	200

void reversestring(char *caString[], int laenge);

int main(void)
{
	char caEingabe[MAX_ARRAY];
	int laenge;

	memset(caEingabe, 0, MAX_ARRAY);

	printf("Bitte Zeichenkette eingeben: ");
	fgets(caEingabe, MAX_ARRAY, stdin);

	laenge = ownstrlen(caEingabe);
	reversestring(&caEingabe, laenge);

	printf("\nUmgedrehte Zeichenkette: %s", caEingabe);

	getch();
	return 0;
}

void reversestring(char *caString, int laenge)
{
	char caReverse[MAX_ARRAY];
	memset(caReverse, 0, MAX_ARRAY);

	for (int i = 0; i < laenge; i++)
	{
		int temp = (laenge - 1) - i;
		caReverse[i] = *(caString + temp);
	}

	for (int i = 0; i < laenge; i++)
	{
		*(caString + i) = caReverse[i];
	}
}