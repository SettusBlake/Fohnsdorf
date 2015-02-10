#include <time.h>

#define ZEILEN	10
#define SPALTEN	6

void ermitteln(char *nLotto);
void sort_multi_int_array(int *nLotto, int nZD, int nSD);
void ausgabe_multi_array(int *nLotto, int nZD, int nSD);

int main(void)
{
	int nLotto[ZEILEN][SPALTEN];
	memset(nLotto, 0, sizeof(nLotto[0][0]) * ZEILEN * SPALTEN);

	//initialisierung des Zufallsgenerators
	srand((unsigned)time(NULL));

	ermitteln(&nLotto, ZEILEN, SPALTEN);
	sort_multi_int_array(&nLotto, ZEILEN, SPALTEN);
	ausgabe_multi_array(&nLotto, ZEILEN, SPALTEN);

	return 0;
}

//Das Array wird befüllt - pro Zeile dürfen keine doppelten Werte vorkommen
void ermitteln(int *nLotto, int nZD, int nSD)
{
	int temp;
	for (int nZeile = 0; nZeile < nZD; nZeile++)
	{
		for (int nSpalte = 0; nSpalte < nSD; nSpalte++)
		{
			*(nLotto + nZeile * 6 + nSpalte) = rand() % 45 + 1;

			for (int k = 0; k < nSpalte; k++)
			{
				if ((*(nLotto + nZeile * 6 + k)) == (*(nLotto + nZeile * 6 + nSpalte)))
				{
					*(nLotto + nZeile * 6 + k) = rand() % 45 + 1;
				}
			}
		}
	}
}

//Sortierung des Mehrdimensionalen Arrays - aufsteigend
void sort_multi_int_array(int *nLotto, int nZD, int nSD)
{
	int temp;

	for (int nZeile = 0; nZeile < nZD; nZeile++)
	{
		for (int nSpalte = 0; nSpalte < nSD; nSpalte++)
		{
			for (int k = 0; k < nSpalte; k++)
			{
				if (*(nLotto + nZeile * 6 + k) > *(nLotto + nZeile * 6 + nSpalte))
				{
					temp = *(nLotto + nZeile * 6 + k);
					*(nLotto + nZeile * 6 + k) = *(nLotto + nZeile * 6 + nSpalte);
					*(nLotto + nZeile * 6 + nSpalte) = temp;
				}
			}
		}
	}
}


//Einfache Ausgabe der Lotto-Zahlen
void ausgabe_multi_array(int *nLotto, int nZD, int nSD)
{
	int temp;

	printf("Hier deine Lotto Zahlen fuer die naechsten Wochen. Alle werden 100%%ig gewinnen\n\n\n");

	for (int nZeile = 0; nZeile < nZD; nZeile++)
	{
		printf("\nZahlenreihe Nr. %d: \t", nZeile+1);
		for (int nSpalte = 0; nSpalte < nSD; nSpalte++)
		{
			printf("%d ", *(nLotto + nZeile * 6 + nSpalte));
		}
	}

	printf("\n\n\nNach druecken einer Taste verschwinden deine Lotto-Zahlen fuer immer...");
	getch();
}