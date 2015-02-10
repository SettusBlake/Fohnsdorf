#include <stdio.h>

int ownstrlen(char string[]);

int main(void)
{
	char caEingabe[100];

	printf("Bitte eine Zeichenkette eingeben und mit Enter bestaetigen: ");
	fgets(caEingabe, 100, stdin);

	printf("Die Laenge des Strings ist %d", ownstrlen(caEingabe));

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