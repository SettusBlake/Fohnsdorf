/* Programm liest zwei Zeichenketten ein und vergleicht diese dann darauf, ob diese die gleichen Zeichen haben*/

#include <stdio.h>

#define MAX_CHARS	50

void sort_array(char string[]);
int compare_two_arrays(char string1[], char string2[]);

int main(void)
{
	static char string1[MAX_CHARS];
	static char string2[MAX_CHARS];

	printf("Bitte zwei gleichlange Zeichenketten eingeben. Auf Gross- u. Kleinschreibung wird geachtet!\n");
	printf("Bitte erste Zeichenkette eingeben: ");
	fgets(string1, MAX_CHARS, stdin);
	printf("Bitte zweite Zeichenkette eingeben: ");
	fgets(string2, MAX_CHARS, stdin);

	sort_array(string1);
	sort_array(string2);
	if (compare_two_arrays(string1, string2) == 1)
	{
		printf("\nZeichenketten enthalten nicht die gleichen Zeichen");
	}
	else
	{
		printf("\nZeichenketten enthalten die gleichen Zeichen!");
	}
	
	getch();
	return 0;
}

void sort_array(char string[])
{
	int i, h;
	char temp;
	i = 0;
	h = 0;

	//Sortierung des Arrays
	while (string[i] != 10)
	{
		while (string[h] != 10)
		{
			if (string[i] > string[h])
			{
				temp = string[i];
				string[i] = string[h];
				string[h] = temp;
			}
			h++;
		}
		h = 0; //Damit beim nächsten Schleifendurchlauf wieder mit 0 bei dem Index begonnen werden kann
		i++;
	}
}

//Hier wird überprüft ob die zwei Strings voneinander abweichen - zuvor wurde sortiert
int compare_two_arrays(char string1[], char string2[])
{
	int i;
	i = 0;
	
	while (string1[i] != 10)
	{
		if (string1[i] != string2[i])
		{
			return 1;
			break;
		}
		i++;
	}
	return 0;
}