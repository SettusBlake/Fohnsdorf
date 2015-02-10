#include <stdio.h>
#include <ctype.h>

int main(void)
{
	static char cZeichenfolge[80];
	int i, flag;
	i = 0;
	flag = 0;

	printf("Leerzeichen werden bei der Auswertung ignoriert\n");
	printf("Bitte Zeichenfolge eingeben: ");
	fgets(cZeichenfolge, 80, stdin);

	while (cZeichenfolge[i] != 10) // 10 = New Line in Ascii
	{
		if (!isalpha(cZeichenfolge[i]))
		{
			if (cZeichenfolge[i] != 32)  // 32 = Space in Ascii
			{
				flag = 1;
			}
		}
		i++;
	} 

	if (flag)
	{
		printf("\nNicht nur Buchstaben!");
	}
	else
	{
		printf("\nNur Buchstaben!");
	}

	getch();
	return 0;
}