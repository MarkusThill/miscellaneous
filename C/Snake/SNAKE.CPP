#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#define SPEED 0  //von 0 bis 50
#define SCHLANGENLAENGE 100 //von 10 bis 200



void grafikmodus(void);
void feldnullsetzen(void);
void spielfeldzeichner(void);
void feldlevel1(void);
void feldlevel2(void);
void feldlevel3(void);
void feldlevel4(void);
void feldlevel5(void);
int  schlangen(void);
void schlangenbewegung(int *ende);
void schlangeloeschen(void);
void schlangenzeichner(int *e);
void ziffern(int ziffer);
void gameover(void);
void spiel(void);
void punktausgabe(int);
int level(int);
void leertaste(int);
void lebenausgabe(int);
void levelausgabe(int);


int feld[62][46];
int schlange[SCHLANGENLAENGE][2];
int gesamtpunktzahl=0;


int main(void)
{
	spiel();
	getch();
}
void grafikmodus(void)
{
	/*Diese Funktion initialisiert den Grafikmodus. Der Pfad des Graphiktreibers
	muss ggf. angepasst werden.*/
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "C:\\PROGRA~1\\TC\\BGI\\");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}
}

void spiel(void)
{
	int gewinn, leben=5;
	grafikmodus();
	do
	{
		levelausgabe(1);
		gewinn=level(1);
		if(gewinn==0)
			leben--;
		if(leben==0)
		break;
		lebenausgabe(leben);
	}
	while(gewinn==0);
	leertaste(2);

	if(leben>0)
	{
		cleardevice();
		do
		{
			levelausgabe(2);
			gewinn=level(2);
			if(gewinn==0)
				leben--;
			if(leben==0)
				break;
			lebenausgabe(leben);
		}
		while(gewinn==0);
		leertaste(2);
	}

	if(leben>0)
	{
		cleardevice();
		do
		{
			levelausgabe(3);
			gewinn=level(3);
			if(gewinn==0)
				leben--;
			if(leben==0)
				break;
			lebenausgabe(leben);
		}
		while(gewinn==0);
		leertaste(2);
	}

	if(leben>0)
	{
		cleardevice();
		do
		{
			levelausgabe(4);
			gewinn=level(4);
			if(gewinn==0)
				leben--;
			if(leben==0)
				break;
			lebenausgabe(leben);
		}
		while(gewinn==0);
		leertaste(2);
	}
	if(leben>0)
	{
		cleardevice();
		do
		{
			levelausgabe(5);
			gewinn=level(5);
			if(gewinn==0)
				leben--;
			if(leben==0)
				break;
			lebenausgabe(leben);
		}
		while(gewinn==0);
		leertaste(2);
	}
	if(leben==0)
		gameover();
	else if(leben>0)
		punktausgabe(2);
}

void lebenausgabe(int leben)
{
	char temp[150];
	setcolor(WHITE);
	sprintf(temp, "Sie haben noch %d Leben!!!", leben);
	outtextxy(200, 80, temp);
}

void levelausgabe(int level)
{
	char temp[150];
	setcolor(YELLOW);
	sprintf(temp, "LEVEL %d !!!", level);
	outtextxy(250, 10, temp);
}

int level(int level)
{
	int gewinn;
	leertaste(1);
	feldnullsetzen();
	if(level==1)
		feldlevel1();
	else if(level==2)
		feldlevel2();
	else if(level==3)
		feldlevel3();
	else if(level==4)
		feldlevel4();
	else if(level==5)
		feldlevel5();
	spielfeldzeichner();
	delay(1000);
	gewinn=schlangen();
	if(gewinn==1)
		gesamtpunktzahl+=100;
	punktausgabe(gewinn);
	return gewinn;
}



void leertaste(int anlass)
{
	int x;
	setcolor(WHITE);
	if(anlass==1)
		outtextxy(160, 250, "Zum Starten Leertaste drcken...");
	else if(anlass==2)
		outtextxy(200, 250, "Leertaste drcken...");
	do
	{
		if(kbhit())
			x=getch();
	}

	while(x!=32);
}

void punktausgabe(int gewinn)
{
	char temp[100];
	setfillstyle(1, BLACK);
	bar(0,0,640, 480);
	setcolor(WHITE);
	if(gewinn==1)
	{
		sprintf(temp, "Herzlichen Glckwunsch, ihre Punktzahl betr„gt %d !!!", gesamtpunktzahl);
		outtextxy(100, 230, temp);
	}
	else if(gewinn==0)
	{
		sprintf(temp,"Hat leider nicht geklappt, ihre Punktzahl betr„gt %d !!!", gesamtpunktzahl);
		outtextxy(100, 230, temp);
	}
	else if(gewinn==2)
	{
		sprintf(temp,"Herzlichen Glckwunsch, Sie haben alle Level geschafft!!!");
		outtextxy(70, 230, temp);
	}
}

void feldnullsetzen(void)
{
	/*Diese Funktion erzeugt ein leeres Spielfeld. Es werden alle Feldelemente
	auf 0 gesetzt -> LEER.*/
	int i, j;
	for(i=0;i<63;i++)
		for(j=0;j<47;j++)
			feld[i][j]=0;
}

void feldlevel1(void)
{
}

void feldlevel2(void)
{
	/*Es wird ein Spielfeld erzeugt. Ein Balken(Hinderniss) wird in der Mitte
	des Feldes erzeugt->Elemente werden auf 12 gesetzt.*/
	int i, j=22;
	for(i=21;i<42;i++)
		feld[i][j]=12;
}

void feldlevel3(void)
{
	/*Es wird ein Spielfeld erzeugt. Ein Balken(Hinderniss) wird in der Mitte
	des Feldes erzeugt->Elemente werden auf 12 gesetzt.*/
	int i, j=15;
		for(i=11;i<36;i++)
	feld[j][i]=12;
	j=46;
	for(i=11;i<36;i++)
		feld[j][i]=12;
}

void feldlevel4(void)
{
	/*Es wird ein Spielfeld erzeugt. Ein Balken(Hinderniss) wird in der Mitte
	des Feldes erzeugt->Elemente werden auf 12 gesetzt.*/
	int i, j=10;
	for(i=0;i<25;i++)
		feld[i][j]=12;
	j=35;
	for(i=61;i>35;i--)
		feld[i][j]=12;
	j=15;
	for(i=45;i>20;i--)
		feld[j][i]=12;
	j=47;
	for(i=0;i<25;i++)
		feld[j][i]=12;
}

void feldlevel5(void)
{
	/*Es wird ein Spielfeld erzeugt. Ein Balken(Hinderniss) wird in der Mitte
	des Feldes erzeugt->Elemente werden auf 12 gesetzt.*/
	int i, j=10;
	for(i=20;i<40;i++)
		feld[i][j]=12;
	j=33;
	for(i=20;i<40;i++)
		feld[i][j]=12;
	j=19;
	for(i=12;i<32;i++)
		feld[j][i]=12;
	j=40;
	for(i=12;i<32;i++)
		feld[j][i]=12;

}

void spielfeldzeichner(void)
{
	/*Diese Funktion zeichnet das Spielfeld. Es wird ein Rahmen erzeugt und
	die Hindernisse werden gezeichnet*/
	int i, j;
	setfillstyle(1, BLACK);
	bar(0,0,640,480);
	setfillstyle(1,7);
	for(i=0;i<63;i++)
		for(j=0;j<47;j++)
			if(feld[i][j]==12)
				bar((i+1)*10,(j+1)*10,(i+1)*10+10,(j+1)*10+10);
	setcolor(WHITE);
	rectangle(9,9,631,471);
	rectangle(8,8,632,472);
	setfillstyle(1, BLACK);
	bar(0,473,640,480);
}

int schlangen(void)
{
	/*Hauptfunktion der Schlange. Hier werden die Tastendrcke abgefragt und
	damit die Richtung bestimmt und die Unterfunktionen werden aufgerufen.*/
	int richtung=3, x, x1, tod=0, wert=1, gewonnen=0, j=0;
	int ende[2], laenger[2], i=0;
	laenger[0]=-1;
	laenger[1]=-1;
	schlangeloeschen();
	schlange[0][0]=1;
	schlange[0][1]=0;
	schlange[1][0]=0;
	schlange[1][1]=0;
	ziffern(wert);
	do
	{   if(!kbhit())
		{
			/*Kollision berprfen...*/
			if(schlange[0][0]<0 || schlange[0][0]>61 || schlange[0][1]<0 || schlange[0][1]>45)
			{
				tod=1;
				break;
			}
			if(feld[schlange[0][0]][schlange[0][1]]==12)
			{
				tod=1;
				break;
			}
			for(i=2;i<SCHLANGENLAENGE-1;i++)
			{
				if(schlange[0][0]==schlange[i][0] && schlange[0][1]==schlange[i][1])
					tod=1;
			}
			if(tod==1)
				break;


			/*Bei gefressener Zahl die Schlange verl„ngern...*/
			if(laenger[0]>-1)
			{
				j=0;
				for(i=0;i<SCHLANGENLAENGE-1;i++)
					if(schlange[i][0]==-1)
					{
						schlange[i][0]=laenger[0];
						schlange[i][1]=laenger[1];
						j++;
						if(j==SCHLANGENLAENGE/10)
							break;
					}

				laenger[0]=-1;
				laenger[1]=-1;
			}
			/*Schlange "bewegen"...*/
			schlangenzeichner(ende);
			schlangenbewegung(ende);
			switch(richtung)
			{
				case 1:
					schlange[0][1]--;
					break;
				case 2:
					schlange[0][1]++;
					break;
				case 3:
					schlange[0][0]++;
					break;
				case 4:
					schlange[0][0]--;
					break;
			};
			delay(60-SPEED);   //35

			/*Auf gefressene Zahl prfen...*/

			if(feld[schlange[0][0]][schlange[0][1]]>=1 && feld[schlange[0][0]][schlange[0][1]]<=9)
			{
				feld[schlange[0][0]][schlange[0][1]]=0;
				gesamtpunktzahl+=wert;
				wert++;
				if(wert==10)
				{
					gewonnen=1;
					break;
				}
				ziffern(wert);
				laenger[0]=ende[0];
				laenger[1]=ende[1];
			}
		}
		/*Neue Richtung abfragen, falls eine Taste gedrckt wird...*/
		else
		{
			x=getch();
			if(x==0)
			{
				x1=getch();
				if(x1==77 && richtung!=4)
					richtung=3;
				if(x1==75 && richtung!=3)
					richtung=4;
				if(x1==72 && richtung!=2)
					richtung=1;
				if(x1==80 && richtung!=1)
					richtung=2;
			}
		}
	}
	while(1);
	if(tod==1)
	{
		delay(1000);
		return (0);
	}
	else
		return (1);
}


void schlangenbewegung(int *e)
{
	int i, j;
	/*Berechnet anhand der Richtung die neue Position der Schlange*/
	for(i=SCHLANGENLAENGE-1;schlange[i][0]==-1;i--);
	e[0]=schlange[i][0];
	e[1]=schlange[i][1];
	for(i=SCHLANGENLAENGE-1;i>0;i--)
		for(j=0;j<2;j++)
			if(schlange[i][j]!=-1)
				schlange[i][j]=schlange[i-1][j];
}

void schlangeloeschen(void)
{
	/*Loescht die Schlange, alle Feldelemente werden auf -1 gesetzt.*/
	int i, j;
	for(i=0;i<SCHLANGENLAENGE;i++)
		for(j=0;j<2;j++)
			schlange[i][j]=-1;
}

void schlangenzeichner(int *e)
{
	/*Zeichnet die Schlange auf*/
	int i;
	setfillstyle(1, BLUE);
	for(i=0;i<SCHLANGENLAENGE;i++)
	{
		if(schlange[i][0]>-1)
		{
			bar((schlange[i][0]+1)*10, (schlange[i][1]+1)*10, (schlange[i][0]+1)*10+10, (schlange[i][1]+1)*10+10);
		}
	}
	if(e[0]!=-1)
	{
		setfillstyle(1, BLACK);
			bar((e[0]+1)*10, (e[1]+1)*10, (e[0]+1)*10+10, (e[1]+1)*10+10);
	}
}

void gameover(void)
{
	/*Ausgabe von Game Over mit Sound*/
	delay(1000);
	setfillstyle(1,BLACK);
	bar(0,0,640,480);
	setcolor(RED);
	outtextxy(280,230,"Game Over");
	sound(2000);
	delay(500);
	sound(1500);
	delay(500);
	sound(2000);
	delay(500);
	sound(1000);
	delay(500);
	sound(500);
	delay(500);
	nosound();
}

void ziffern(int ziffer)
{
	int x, y, i=0, wiederhol=0;
	char buffer[1];
	sprintf(buffer, "%d", ziffer);
	randomize();
	do
	{
		x=rand() % 62;
		y=rand() % 46;
		for(i=0;i<SCHLANGENLAENGE;i++)
		{
			if(x==schlange[i][0] && y==schlange[i][1])
			{
				wiederhol=1;
				break;
			}
		}
		if(i==SCHLANGENLAENGE)
			wiederhol=0;

	}
	while(feld[x][y]>9 || wiederhol==1);
	feld[x][y]=ziffer;
	setcolor(WHITE);
	outtextxy(x*10+10, y*10+10, buffer);
}