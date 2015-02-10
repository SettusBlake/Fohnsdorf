int addieren(int z1, int z2);

void main(void)
{
	int zahl1, zahl2;
	int summe;

	zahl1 = 5;
	zahl2 = 7;

	summe = addieren(5, 7);

	printf("%d", summe);
	getch();
}


int addieren(int z1, int z2)
{
	return z1+z2;
}