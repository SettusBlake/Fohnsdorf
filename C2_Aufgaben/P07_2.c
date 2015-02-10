
void deztobin(int dezimal);


int main(void)
{
	int dezimal;

	printf("Bitte einen Dezimalwert eingeben der in Binaer umgewandelt werden soll: ");
	scanf("%d", &dezimal);
	deztobin(dezimal);

	getch();
	return 0;
}

void deztobin(int dezimal)
{
	static int bin_rev[100];
	static int bin[100];
	int i, h;
	int rest;
	char flag;
	flag = 0;

	for (i = 0; i < 100; i++)
	{
		bin_rev[i] = dezimal % 2;
		dezimal = dezimal / 2;
	}

	printf("\nDeine Dezimalzahl ist binaer: \n");
	for (i = 99, h = 0; i >= 0; i--, h++)
	{
		bin[h] = bin_rev[i];
		if ((bin[h] == 1) || (flag == 1))
		{
			printf("%d", bin[h]);
			flag = 1;
		}
	}
}
