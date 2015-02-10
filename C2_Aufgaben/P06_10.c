void ziffernsumme(int zahl);
void sieben(int zahl);

int main(void)
{
	int zahl;

	printf("Bitte eine Zweitstellige Zahl eingeben: ");
	do
	{
		scanf("%d", &zahl);

		if (zahl > 9)
		{
			ziffernsumme(zahl);
			sieben(zahl);
			break;
		}
		else
		{
			printf("\nBitte wiederholen. Die Zahl muss Zweistellig sein!");
		}

	} while (1);

	getch();
	return 0;
}

void ziffernsumme(int zahl)
{
	int erste, zweite;
	erste = zahl / 10;
	zweite = zahl % 10;

	if ((zahl % (erste + zweite)) == 0)
	{
		printf("%d ist durch %d teilbar!", zahl, erste + zweite);
	}
	else
	{
		printf("%d ist durch %d nicht teilbar!", zahl, erste + zweite);
	}
}

void sieben(int zahl)
{
	if ((zahl % 10 == 7) || (zahl / 10 == 7))
	{
		printf("\nEine Ziffer der Zahl ist Sieben!");
	}
	else
	{
		printf("\nKeine der Ziffern der Zahl ist Sieben!");
	}
}