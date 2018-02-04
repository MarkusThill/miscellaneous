#include <stdio.h>
#include <conio.h>

main()
{
	long double x=0.0, y=0.0, z=1000000000000;
	double i=0;
	printf("Geben Sie eine Zahl ein:");
	scanf("%Lf",&x);
	clrscr();
	y=x;
	do
	{
		i++;
		gotoxy(3,3);
		printf("%20.39Lf",y);
		y=y-z;
		if((y*y)<x || y<0)
		{
			y=y+z;
			z=z/10;
		}
	}
	while(z>0.00000000000000000000001 && i<200000);
	clrscr();
	printf("\n%20.39Lf",y);
	getch();
}