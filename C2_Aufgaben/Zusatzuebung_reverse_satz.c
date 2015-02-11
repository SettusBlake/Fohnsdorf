#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

//#include "common.h"

#define MAX_ARRAY	200

void reverse_sentence(char caString[], int laenge);
void reverse_string(char caString[], int laenge);
int ownstrlen(char string[]);
void ownstrcpy(char *caZielstring, char *caQuellstring);

int main(void)
{
	char caEingabe[MAX_ARRAY];
	memset(caEingabe, 0, MAX_ARRAY);

	printf("Bitte einen Satz eingeben: ");
	fgets(caEingabe, MAX_ARRAY, stdin);

	int laenge = ownstrlen(caEingabe);

	reverse_sentence(caEingabe, laenge);

	getch();
	return 0;
}

void reverse_sentence(char caString[], int laenge)
{
	int wortlaenge = 0;
	int satzlaenge = laenge;

	char caReverse[MAX_ARRAY];
	memset(caReverse, 0, MAX_ARRAY);

	char temp;
	int i, c, d;
	int zaehler = 0;

	if (caString[laenge - 1] == 10)
	{
		laenge = laenge - 2; //um New Line weg zu schneiden und damit es mit dem Index zusammenpasst
	}

	for (i = 0; i <= laenge; i++)
	{
		caReverse[i] = caString[laenge - i];
	}

	// Wörter umdrehen
	for (int i = 0; i < laenge; ++i) {
		int wordstart = -1;
		int wordend = -1;

		if (caReverse[i] != ' ') {
			wordstart = i;
			for (int j = wordstart; j < laenge; ++j) {
				if (caReverse[j] == ' ') {
					wordend = j - 1;
					break;
				}
			}

			if (wordend == -1)
				wordend = laenge;

			int j = 0;

			//aktuell wird nur das erste wort umgedreht
			for (int i = wordstart; i <= (wordend) / 2; i++)
			{
				char temp = caReverse[wordend - i];
				caReverse[wordend - i] = caReverse[i];
				caReverse[i] = temp;
			}

			i = wordend;
		}
	}
	
	printf("\n\n%s", caReverse);
}

int ownstrlen(char string[])
{
	int i;
	for (i = 0; string[i] != 0; ++i);
	return i;
}