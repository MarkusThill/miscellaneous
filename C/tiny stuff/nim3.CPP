
#include <conio.h>
#include <stdio.h>
#include <dos.h>
void main()
{	
	
	int laden=0, laden1=0, steine=29, weg=0, y1=0, y2=0;
	char name1[20], name2[20];
	char antwort='j';

	clrscr();
	
	
	/*

	do
	{

		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tLaden...");
		delay(99999999);
		clrscr();

		delay(99999999);
		laden++;
	}
	while(laden<=10);

	clrscr();
	printf("\tLade Grafik");

	do
	{
		printf(".");
		laden1++;
		delay(99999999);
	}
	while(laden1<=60);
	delay(999999999);
	*/
	clrscr();
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t29 Steine\n");
	printf(" Bei diesem Spiel, fuer 2 Personen, geht es darum, von 29 Steinen immer 1, \n");
	printf(" 2 oder 3 Steine wegzunehmen. \n");
	printf(" Jeder Spieler nimmt abwechselnd Steine weg, wer den letzten Stein wegnimmt, \n");
	printf(" der hat verloren. ");
	printf("\n\n\n\t\t\tBeliebige Taste druecken");
	getch();
	clrscr();




	printf("\tSpieler 1 bitte Namen eingeben (nur Vorname!!!): ");
	fflush(stdin);
	scanf("%s", name1);
	printf("\n\tSpieler 2 bitte Namen eingeben (nur Vorname!!!): ");
	fflush(stdin);
	scanf("%s", name2);
	clrscr();

	do
	{
	steine=29;
	weg=0; y1=0;
	y2=0;
	clrscr();
	printf("\n\n\n\n\n\n\n\n\n\t\t\t %s faengt an! ", name1);
	delay(99);
	clrscr();



	do
	{
		do
		{
			y1=0;
			printf(" Es sind %d Steine vorhanden. Wie viele nimmst du %s?: ", steine, name1);
			fflush(stdin);
			scanf("%d", &weg);
			if(weg<1 || weg>3)
			{
				printf(" Du must eine Zahl zwischen 1 und 3 eingeben. Bitte erneut versuchen\a");
				delay(999);
				y1=1;
				weg=0;
				clrscr();
			}

			steine=steine-weg;
		}
		while(y1==1);
		clrscr();
		if(steine<=0)
		{
			printf("\n\n\n\n\n\n\n\n\n\t\t\tDu hast leider verloren %s!\a\a\a\a", name1);
			delay(999);
			break;
		}


		do
		{
			y2=0;
			printf(" Es sind %d Steine vorhanden. Wie viele nimmst du %s?: ", steine, name2);
			fflush(stdin);
			scanf("%d", &weg);
			if(weg<1 || weg>3)
			{
				printf(" Du must eine Zahl zwischen 1 und 3 eingeben. Bitte erneut versuchen\a");
				delay(999);
				y2=1;
				weg=0;
				clrscr();
			}
			steine=steine-weg;
		}
		while(y2==1);
		clrscr();
		if(steine<=0)
		{
			printf("\n\n\n\n\n\n\n\n\n\t\t\tDu hast leider verloren %s!\a\a\a\a", name2);
			delay(999);
			break;
		}

	}
	while(steine>=1);


	printf("\n\tMoechtet ihr von Vorne beginnen, j fuer Ja, n fuer nein: ");
	fflush(stdin);
	antwort=getch();
	}
	while(antwort=='J' || antwort=='j');
	delay(999);




}