void linie(char zeichen, int start, int laenge);

void main(void)
{
	int start, laenge;
	char zeichen;

	printf("Es wird eine Linie gezeichnet");
	printf("\nBitte Zeichen fuer die Linie eingeben: ");
	scanf("%c", &zeichen);
	printf("Bitte Startposition als Zahlenwert eingeben: ");
	scanf("%i", &start);
	printf("Bitte Laenge eingeben: ");
	scanf("%i", &laenge);

	linie(zeichen, start, laenge);

	getch();
}

void linie(char zeichen, int start, int laenge)
{
	int i;
	for (i = 1; i <= start; i++)
	{
		printf("\n");
	}
	for (i = 1; i <= laenge; i++)
	{
		printf("%c", zeichen);
	}
}