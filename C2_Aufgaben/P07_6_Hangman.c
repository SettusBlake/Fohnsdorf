#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define CLR	system("cls")

#define MAX_ARRAY	16
#define MAX_VERSUCHE	15

void aufbau(char caWort[], int versuche); //Ausgabe Aufbaun
int check_pos(char caWort[], char c, int lastpos); //Gibt die Position eines Eingegebenen Zeichens - liefert -1 wenn keine Position gefunden wurde
void zeichne_linie(void); //Simples Linie Zeichnen für die Ausgabe
int check_win(char caWort[], int laenge); // Überprüft ob der Spieler gewonnen hat
char to_upper(char c);

int main(void)
{
	static char caRatewort[MAX_ARRAY];
	char caControll[MAX_ARRAY];
	char cEingabe;

	int h = 0;
	int k = 0;
	int flag = 0;
	int pos = 0;
	int lastpos = 0;

	memset(caControll, 42, MAX_ARRAY);

	printf("Multiplayer Erlebnis - 2 Spieler. Der erste gibt das Wort ein\nGross und Kleinschreibung wird ignoriert\n");
	printf("Leerzeichen und Sonderzeichen koennen eingegeben werden, sollten aber gemieden werden!");
	printf("\n\nSpieler Eins\n\nWort mit max. 15 Zeichen eingeben: ");

	if (fgets(caRatewort, 15, stdin) == NULL)
	{
		printf("Eingabe ist zu lang");
	}
	else
	{
		while (caRatewort[k] != 0)
		{
			caRatewort[k] = to_upper(caRatewort[k]);
			k++;
		}
		caControll[k-1] = 10; //letztes Array soll New Line Zeichen sein

		for (int i = 0; i <= 15; i++)
		{
			h = 0;
			//Optische Darstellung
			aufbau(caControll, i);

			char cEingabe = getche();
			cEingabe = to_upper(cEingabe);
			
			while (caControll[h] != 10)
			{
				pos = check_pos(caRatewort, cEingabe, lastpos);

				if (pos != -1)
				{
					caControll[pos] = caRatewort[pos];
					lastpos = pos + 1;
				}
				else
				{
					lastpos = 0;
				}
				h++;
			}

			getch();  // damit die Überprüfung nicht sorfort nach Buchstaben-Eingabe weiterläuft - Ansonsten wär es merkwürdig für den User

			if (check_win(caControll, k) == 1) 
			{
				CLR;
				printf("\n\n\n\t\t\tDu hast das Spiel gewonnen!");
				printf("\n\n\t\t\tDas Wort war %s", caRatewort);
				break;
			}
		}
	}
	printf("\n\n\n\nProgramm wird nach einem Tastendruck beendet...");
	getch();
	return 0;
}

void aufbau(char caWort[], int versuche)
{
	int i;
	i = 0;

	CLR;
	
	zeichne_linie();
	printf("\n\n\t\t\t\tHangman\n\n\n");
	zeichne_linie();
	printf("\n\n\n\n\n\n\t\t\t");

	while (caWort[i] != 10)
	{
		if (caWort[i] == 42) //42 ist * in der ASCII Tabelle
		{
			printf("_ ");
		}
		else
		{
			printf("%c ", caWort[i]);
		}
		i++;
	}
	printf("\n\n\n\nBereits %d von 15 Versuchen", versuche);
	printf("\nRatewort hat %d Buchstaben\n\n\n\nEingabe: ", i);
}

int check_pos(char caWort[], char c, int lastpos)
{
	while (caWort[lastpos] != 0)
	{
		if (caWort[lastpos] == c)
		{
			return lastpos;
		}
		lastpos++;
	}
	return -1;
}

void zeichne_linie(void)
{
	printf("\t");
	for (int i = 1; i <= 60; i++)
	{
		printf("#");
	}
}

//überprüft ob man bereits gewonnen hat
int check_win(char caWort[], int laenge)
{
	for (int l = 0; l < laenge; l++)
	{
		if (caWort[l] == 42)
		{
			return 0;
		}
	}
	return 1;
}

char to_upper(char c)
{
	if ((c >= 97) && (c <= 122))
		c = c - 32;
	return c;
}
