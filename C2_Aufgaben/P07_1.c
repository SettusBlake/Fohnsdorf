float summe(void);

int zahlen[4] = { 12, 34, 56, 78 };

void main(void)
{
	float laenge;
	float sum;
	float durch;
	sum = summe();
	printf("\nSumme: %d", sum);
	laenge = sizeof(zahlen) / sizeof(zahlen[0]);
	durch = sum / laenge;
	printf("\nDurchschnitt: %5.1f", sum / laenge);
	getch();
}

float summe(void)
{
	int i, summe, laenge;
	laenge = sizeof(zahlen)/sizeof(zahlen[0]);
	printf("\nLaenge des Arrays: %d", laenge);
	summe = 0;

	for (i = 0; i < laenge; i++)
	{
		printf("\nArray %d = %d", i, zahlen[i]);
		summe += zahlen[i];
	}
	return summe;
}
