#include <stdio.h>
#include <conio.h>

int feld[3][3];

void nullsetzer(void);
void eingabe(int);
int senkrecht(void);
int waagerecht(void);
int diagonal(void);
void haupt(void);
int gewinn(void);
void grafik(void);

void main(void)
{
	haupt();
}

void nullsetzer(void)
{
	int i=0;
	int j=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			feld[i][j]=0;
}

void eingabe(int spieler)
{
	int x, y;
	gotoxy(6,6);
	do
	{   gotoxy(6,6);
		printf("Spieler %d Spalte: ",spieler);
		scanf("%d",&x);
		gotoxy(6,7);
		printf("Spieler %d Reihe: ",spieler);
		scanf("%d",&y);
	}
	while(feld[x-1][y-1]>0 || x<0 || x>3 || y<0 || y>3);

	feld[x-1][y-1]=spieler;
}

int senkrecht(void)
{
	int i,j,wert1=0,wert2=0,ret=0;
	for(i=0;i<3;i++)
	{
		wert1=0;
		wert2=0;
		for(j=0;j<3;j++)
		{
			if(feld[i][j]==1)
				wert1++;
			else if(feld[i][j]==2)
				wert2++;
		}
		if(wert1==3 || wert2==3)
			break;
	}

	if(wert1==3)
		ret=1;
	if(wert2==3)
		ret=2;
	return ret;
}

int waagerecht(void)
{
	int i,j,wert1=0,wert2=0,ret=0;
	for(i=0;i<3;i++)
	{
		wert1=0;
		wert2=0;
		for(j=0;j<3;j++)
		{
			if(feld[j][i]==1)
				wert1++;
			else if(feld[j][i]==2)
				wert2++;
		}
		if(wert1==3 || wert2==3)
			break;
	}

	if(wert1==3)
		ret=1;
	if(wert2==3)
		ret=2;
	return ret;
}

int diagonal(void)
{
	int ret=0;

	if(feld[0][0]==1 && feld[1][1]==1 && feld[2][2]==1)
		ret=1;
	if(feld[2][0]==1 && feld[1][1]==1 && feld[0][2]==1)
		ret=1;
	if(feld[0][0]==2 && feld[1][1]==2 && feld[2][2]==2)
		ret=2;
	if(feld[2][0]==2 && feld[1][1]==2 && feld[0][2]==2)
		ret=2;
	return ret;
}

int gewinn(void)
{
	int ret=0,i;
	for(i=0;i<1;i++)
	{
		ret=senkrecht();
		if(ret>0)
			break;
		ret=waagerecht();
		if(ret>0)
			break;
		ret=diagonal();
		if(ret>0)
			break;
	}
	return ret;
}

void grafik(void)
{
	int i=0,j=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			gotoxy(i+1,j+1);
			printf("%d",feld[i][j]);
		}
	}

}


void haupt(void)
{
	int spieler=1,gewinner=0,durchlauf=0;
	clrscr();
	nullsetzer();

	do
	{
		grafik();
		eingabe(spieler);
		clrscr();
		grafik();
		gewinner=gewinn();
		if(spieler==1)
			spieler++;
		else if(spieler==2)
			spieler--;
		durchlauf++;
	}
	while(gewinner==0 && durchlauf<9);
	clrscr();
	grafik();
	gotoxy(5,5);
	textcolor(210);
	cprintf("Spieler %d hat gewonnen!!!",gewinner);
	getch();
}

