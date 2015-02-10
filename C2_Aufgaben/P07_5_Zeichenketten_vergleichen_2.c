/* Programm liest zwei Zeichenketten ein und vergleicht diese dann darauf, ob diese die gleichen Zeichen haben*/

#include <stdio.h>

#define MAX_CHARS	50

int compare_two_arrays(char string1[], char string2[], int laenge1, int laenge2);
int length_of_array(char arr[]);

int main(void)
{
	static char string1[MAX_CHARS];
	static char string2[MAX_CHARS];

	printf("Bitte zwei gleichlange Zeichenketten eingeben. Auf Gross- u. Kleinschreibung wird geachtet!\n");
	printf("Bitte erste Zeichenkette eingeben: ");
	fgets(string1, MAX_CHARS, stdin);
	printf("Bitte zweite Zeichenkette eingeben: ");
	fgets(string2, MAX_CHARS, stdin);

	// Die Laengen des Arrays/der Eingabe vergleichen
	if (length_of_array(string1) != length_of_array(string2))
	{
		printf("\n\nDie Zeichenfolgen sind nicht gleich lang! \n\n\nProgramm wird nach druecken einer Taste beendet...");
		getch();
		return 0;
	}

	//Bei Rueckgabe von 1 sind die beiden uebergebenen Arrays Zeichen-Gleich
	if (compare_two_arrays(string1, string2, length_of_array(string1), length_of_array(string2)) == 1)
	{
		printf("\nDie Zeichenketten beinhalten die selben Zeichen!");
	}
	else
	{
		printf("\nDie Zeichenketten beinhalten NICHT die selben Zeichen!");
	}
	
	getch();
	return 0;
}

// Vergleicht von zwei Arrays, auf Gleichheit der Zeichen
int compare_two_arrays(char string1[], char string2[], int laenge1, int laenge2)
{
	int zaehler = 0;

	// Gleiche Zeichen werden in einem Array mit einem Zeichen ersetzt das nicht benutzt wird
	for (int i = 0; i < laenge1; i++)
	{
		for (int h = 0; h < laenge2; h++)
		{
			if (string1[i] == string2[h])
			{
				string1[i] = "*";
				zaehler++;
			}
		}
	}

	if (zaehler == laenge1)
	{
		return 1; // Zeichen sind gleich
	}
	else {
		return 0; // Zeichen sind ungleich
	}

}

// Zahler um Länge des Arrays zu ermitteln - Vorrausetzung ist New Line Steuerzeichen \n am Ende des Arrays
int length_of_array(char arr[])
{
	int i = 0;
	while (arr[i] != 10)
	{
		i++;
	} 
	return i;
}