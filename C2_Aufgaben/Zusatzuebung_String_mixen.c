/* Eine Funktion um zwei Strings miteinander zu vermixen. Der User gibt nacheinander zwei Strings ein.
zb. Hallo und Welt wird zu HWaelllto*/

#include <stdio.h>

#define MAXQUELLE	100
#define MAXZIEL	200

void mixstring(char *ziel[], char quelle1[], char quelle2[]);
int ownstrlen(char string[]);

int main(void)
{
	char quelle1[MAXQUELLE];
	char quelle2[MAXQUELLE];
	char ziel[MAXZIEL];

	memset(quelle1, 0, MAXQUELLE);
	memset(quelle2, 0, MAXQUELLE);
	memset(ziel, 0, MAXZIEL);

	printf("Bitte ersten String eingeben: ");
	fgets(quelle1, MAXQUELLE, stdin);
	printf("Bitte ersten String eingeben: ");
	fgets(quelle2, MAXQUELLE, stdin);
	
	mixstring(&ziel, quelle1, quelle2);

	printf("\nMixed String: %s", ziel);

	getch();

	return 0;
}

void mixstring(char *ziel, char quelle1[], char quelle2[])
{
	int laenge1, laenge2;
	int durchlauf;
	int diff;
	int flag = 0;
	int h = 0;

	laenge1 = ownstrlen(quelle1);
	laenge2 = ownstrlen(quelle2);

	//ermittlung des längeren Wortes, damit der durchlauf passt
	if (laenge1 > laenge2)
	{
		durchlauf = laenge1;
		diff = laenge1 - laenge2;
		flag = 1;
	}
	else
	{
		durchlauf = laenge2;
		diff = laenge2 - laenge1;
	}

	for (int i = 0; i < durchlauf; i++)
	{
		//Wenn durchlauf minus der differnz (also die übrigen zeichen) größer sind als i, dann werden die Buchstaben von beiden Wörtern ins Array geschrieben
		if ((durchlauf - diff) > i)
		{
			*(ziel + i * 2)  = quelle1[i];
			*(ziel + i * 2 + 1) = quelle2[i];
			h = i * 2 + 1; // h Variable um den Wert bzw. den Zustand von i zu speichern - für die Verwendung im ELSE
		}
		else
		{
			//Wenn das erste Wort bereits ins neue Array gespeichert wurde, wird nur noch das zweite Wort komplett rein geschrieben
			h++;
			if (flag == 1) 
			{
				*(ziel + h) = quelle1[i];
			}
			else
			{
				*(ziel + h) = quelle2[i];
			}
		}
	}
}

//ermittlung der Array Länge ohne den abschließenden Zeilenumbruch
int ownstrlen(char string[])
{
	int i = 0;
	while (string[i] != 10)
	{
		i++;
	}

	return i;
}