#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

main()
{
	int a,b,c,zufallswert;
	long double i, treffer=0,j=0;
	clrscr();
	randomize();
	for(i=0;i<999999999;i++)
	{
		if(i==j)
		{
			gotoxy(1,1);
			printf("%.0Lf Durchlauf",i);
			j+=1000000;
		}
		a=0;
		b=0;
		c=0;
		do
		{
			zufallswert = rand() % 4;
		}
		while(zufallswert==0);
		switch(zufallswert)
		{
			case 1:
				a=1;
				break;
			case 2:
				b=1;
				break;
			case 3:
				c=1;
				break;
		}
		do
		{
			zufallswert = rand() % 4;
		}
		while(zufallswert==0);
		if(zufallswert==1)
		{
			if(b==0)
			{
				if(c==1)
					treffer++;
			}
			else if(c==0)
			{
				if(b==1)
					treffer++;
			}
		}
		else if(zufallswert==2)
		{
			if(a==0)
			{
				if(c==1)
					treffer++;
			}
			else if(c==0)
			{
				if(a==1)
					treffer++;
			}
		}
		else if(zufallswert==3)
		{
			if(a==0)
			{
				if(b==1)
					treffer++;
			}
			else if(b==0)
			{
				if(a==1)
					treffer++;
			}
		}
	}
	printf("%.0Lf Durchg„nge\n",i);
	printf("%.0Lf Treffer\n",treffer);
	printf("%.20Lf%%Treffer",treffer/i*100);
	getch();
}

