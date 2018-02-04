//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#pragma hdrstop

#include <tchar.h>
//---------------------------------------------------------------------------

void prog(int i);
int ungleich(int p);

int b[8] = {0};
int *s=b, *e=b+1, *n=b+2, *d=b+3;
int *m=b+4, *o=b+5, *r=b+6, *y=b+7;


#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	prog(0);

	printf("\nfinished");
	getch();
	return 0;
}
//---------------------------------------------------------------------------

void prog(int i) {
	int j = 0;
	if(!ungleich(i))
		return;
	if(i==8) {
		/*int op1 = *s * 1000 + *e * 100 + *n * 10 + *d;
		int op2 = *m * 1000 + *o * 100 + *r * 10 + *e;
		int erg = *m * 10000 + *o * 1000 + *n *100 + *e * 10 + *y;*/
		if(op1 + op2 == erg && b[4] != 0)
			for(i=0;i<8;i++)
				printf("%d ", b[i]);
		return;
	}
	if(i==0 || i==4)
    	j++;
	for(;j<10;j++) {
		b[i] = j;
		prog(i+1);
	}
}

int ungleich(int p) {
	int i, j, k;
	for(i=0;i<p;i++) {
		k = b[i];
		for(j=i+1;j<p;j++)
			if(b[j] == k)
				return 0;
	}
	return 1;
}