
void ClearScreen(int Zeilen);

void main(void)
{
	ClearScreen(25);
	getch();
}

void ClearScreen(int Zeilen)
{
	int i;
	for (i = 1; i <= Zeilen; i++)
	{
		printf("\n");
	}

}