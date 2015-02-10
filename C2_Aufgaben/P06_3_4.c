#include <math.h>
#define PI	3.14
#define VOLUMEN(radius)	((4 * PI * pow((radius), 3))/3)


void printvolume(float radius);

void main(void)
{
	float f;

	for (f = 0.2; f <= 4.0; f += 0.2)
	{
		printvolume(f);
	}

	getch();
}

void printvolume(float radius)
{
	float volume;

	volume = VOLUMEN(radius);
	printf("\n%8.3f", volume);
}