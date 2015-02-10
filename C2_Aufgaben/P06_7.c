int ein(int anzahl);
void fehler(void);

void main()
{
	int i, summe, anzahl;
	summe = 0;
	printf("Bitte Anzahl der Additionen eingebe: ");
	scanf("%d", &anzahl);

	for (i = anzahl; i > 0; i--)
	{
		summe = summe + ein(i);
	}
	printf("\nSumme: %d", summe);
	getch();
}

int ein(int anzahl)
{
	int zahl;
	
	printf("\nBitte Zahl eingeben: ");
	scanf("%d", &zahl);
	
	if (zahl > 9)
	{
		fehler();
		ein(anzahl);
	}
	else
	{
		printf("\nEs muessen noch %d Zahlen eingegeben werden", anzahl - 1);
		return zahl;
	}
}

void fehler(void)
{
	printf("\nDie Zahl war leider nicht Einstellig!");
}