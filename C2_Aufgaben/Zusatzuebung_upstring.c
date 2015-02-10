#pragma warning(disable:4996)

#include <stdio.h>

#define MAX_ARRAY	200

int ownstrlen(char string[]);
int upstring(char *string, int laenge);

int main(void)
{
	char caEingabe[MAX_ARRAY];
	int count = 0;
	int laenge = 0;

	memset(caEingabe, 0, MAX_ARRAY);

	printf("Bitte geben Sie ein Wort ein: ");
	fgets(caEingabe, MAX_ARRAY, stdin);
	
	laenge = ownstrlen(caEingabe);
	count = upstring(&caEingabe, laenge);

	printf("\n\nCount: %d", count);
	printf("\nUmwandlung: %s", caEingabe);

	getch();

	return 0;
}

int ownstrlen(char string[])
{
	int i = 0;
	while (string[i] != 10)
	{
		i++;
	}

	return i;
}

//umwandlung und z‰hlung der Kleinbuchstaben in Groﬂbuchstaben - ich verwende die Variable a zur leichteren lesbarkeit
int upstring(char *string, int laenge)
{
	int count = 0;
	char a;

	for (int i = 0; i < laenge; i++)
	{
		a = *(string + i); //a bekommt den Wert der Adresse
		if ((a >= 97) && (a <= 122))
		{
			count++;
			a = a - 32;
			*(string + i) = a;
		}
	}

	return count;
}