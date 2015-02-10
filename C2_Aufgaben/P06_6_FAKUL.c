void fakultaet(int anzahl);

void main(void)
{
	int anzahl;
	anzahl = 6;

	fakultaet(anzahl);

	getch();
}

void fakultaet(int anzahl)
{
	int mult = 1;
	int i;

	for (i = 1; i <= anzahl; i++)
	{
		mult = mult * i;
	}
	printf("\n%d", mult);
}