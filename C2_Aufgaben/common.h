#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int ownstrlen(char string[])
{
	int i;
	for (i = 0; string[i] != '\0'; ++i);
	return i;
}

int random_number(int min_num, int max_num)
{
	int result = 0, low_num = 0, hi_num = 0;
	if (min_num<max_num)
	{
		low_num = min_num;
		hi_num = max_num + 1; // this is done to include max_num in output.
	}
	else{
		low_num = max_num + 1;// this is done to include max_num in output.
		hi_num = min_num;
	}
	srand(time(NULL));
	result = (rand() % (hi_num - low_num)) + low_num;
	return result;
}

void ownstrcpy(char *caZielstring, char *caQuellstring)
{
	int i = 0;
	while (*(caQuellstring + i) != 10)
	{
		*(caZielstring + i) = *(caQuellstring + i);
		i++;
	}
}