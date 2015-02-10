void block(char zeichen, int start, int laenge, int breite);

void main(void)
{
	int start, laenge, breite;
	char zeichen;

	printf("Es wird ein Block gezeichnet");
	printf("\nBitte Zeichen fuer den Block eingeben: ");
	scanf("%c", &zeichen);
	printf("Bitte Startposition als Zahlenwert eingeben: ");
	scanf("%i", &start);
	printf("Bitte Laenge eingeben: ");
	scanf("%i", &laenge);
	printf("Bitte Breite eingeben: ");
	scanf("%i", &breite);

	block(zeichen, start, laenge, breite);

	getch();
}

void block(char zeichen, int start, int laenge, int breite)
{
	int i, j, k;

	for (j = 1; j <= breite; j++)
	{
		for (i = 1; i <= start; i++)
		{
			printf(" ");
		}
		for (k = 1; k <= laenge; k++)
		{
			printf("%c", zeichen);
		}
		printf("\n");
	}
}