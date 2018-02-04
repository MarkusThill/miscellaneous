#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


//Es ist eine bestimmte Anzahl von MÑnnern in der Hîhle
//Jeder nte wird umgebracht. Die Frage ist, wer als letztes Åbrig bleibt
//Wenn 41 Mann eingegeben werden und jeder 3te umgebracht wird, dann muss der 31te Åberleben
struct Person{
	int nummer;
	Person *vorherige;
	Person *naechste;
};

int main(void)
{
	int anzahlpersonen, intervall,i;
	//clrscr();
	printf("Wie viele Personen sind in der Hîhle???");
	fflush(stdin);
	scanf("%d", &anzahlpersonen);
	printf("Wie gro· soll das Intervall sein???");
	fflush(stdin);
	scanf("%d", &intervall);


	Person *array;
	array= (Person *) malloc(sizeof(Person)*anzahlpersonen);
	for(i=1;i<anzahlpersonen-1;i++)
	{
		array[i].nummer=i+1;
		array[i].vorherige=&array[i-1];
		array[i].naechste=&array[i+1];
	}
	array[0].nummer=1;
	array[0].vorherige=&array[anzahlpersonen-1];
	array[0].naechste=&array[1];

	array[anzahlpersonen-1].nummer=anzahlpersonen;
	array[anzahlpersonen-1].vorherige=&array[anzahlpersonen-2];
	array[anzahlpersonen-1].naechste=&array[0];

	Person *aktueller=&array[0];
	i=0;
	while(aktueller!=aktueller->vorherige)
	{
		if(i==intervall-1)
		{
			aktueller->vorherige->naechste=aktueller->naechste;
			aktueller->naechste->vorherige=aktueller->vorherige;
			i=0;
			aktueller=aktueller->naechste;
			continue;
		}
		aktueller=aktueller->naechste;
		i++;
	}
	printf("\n\nDer%dte Åberlebt das Massaker!!!",aktueller->nummer);
	getch();
}
