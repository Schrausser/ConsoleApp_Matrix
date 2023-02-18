//---------------------------------------------------------------------------| SRT3 von Dietmar SCHRAUSSER 2009              
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <iostream.h>

void _profil(); 
void _kopf();

int sort_function( const void *a, const void *b);

char in_[33010][20]; 

void main(int argc, char *argv[])      
{	
	FILE *inStream, *outStream, *logStream;

	int n_=0, x, iLauf, jLauf,  sw1=0, sw=1, zlr=1;

	double min;

	if (argc > 4 || argc < 3){  printf("\n> check arguments\n"); _profil();}
	if (argc == 4 && atoi(argv[3]) != 1){  printf("\n> switch d <> 1\n"); _profil();}
	logStream = fopen( "SRT3_log.txt", "a" ); fprintf(logStream, "%s @ %s\n", __DATE__, __TIME__); fclose( logStream  );
	
	_kopf();

	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );	
	inStream = fopen( argv[1], "r" ); for (iLauf=0;iLauf< n_;iLauf++) fscanf( inStream, "%s",  in_[iLauf]);fclose( inStream  );
	 
	min=atof(in_[0]); for (iLauf=1;iLauf< n_;iLauf++) if(atof(in_[iLauf]) < min) min = atof(in_[iLauf]); //minimalwertbestimmung
	
	if(min <0) //bei negativwerten subtraktion von min (nullsetzung), qsort funktion erkennt minuszeichen nicht (stringfunktion) 
	{
		outStream = fopen( "~tmp", "w" );for (iLauf=0;iLauf< n_;iLauf++) fprintf(outStream, "%f\n", atof(in_[iLauf])-min);fclose( outStream );
		inStream = fopen( "~tmp", "r" ); for (iLauf=0;iLauf< n_;iLauf++) fscanf( inStream, "%s",  in_[iLauf]);fclose( inStream  );
	}
	


	outStream = fopen( "~tmp", "w" );

	for(iLauf=0;iLauf<n_;iLauf++)//führende nullen setzen, sodass die zeichenlänge konstant ist (qsort stringfunktionsbedingte modifikation)
	{
		                     x=strlen(in_[iLauf]);
		for(jLauf=0;jLauf<15-x;jLauf++) fprintf(outStream, "0"); fprintf(outStream, "%s\n",in_[iLauf]); 
	}
	fclose( outStream );



	inStream = fopen( "~tmp", "r" );for (iLauf=0;iLauf< n_;iLauf++) fscanf( inStream, "%s",  in_[iLauf]); //modifizierte werte einlesen	
	fclose( inStream  );

	qsort((void *)in_, n_, sizeof(in_[0]), sort_function);//qsort Funktion
     


	outStream = fopen( argv[2],"w" );
	
	if (min>=0) min=0; // bei negativwerten addition von min
	
	if (argc == 3 ) for(iLauf=0;iLauf<=n_-1;iLauf++) fprintf( outStream, "%f\n",  atof(in_[iLauf])+min); //dateiausgabe aufsteigend
	if (argc == 4 ) for(iLauf=n_-1;iLauf>=0;iLauf--) fprintf( outStream, "%f\n",  atof(in_[iLauf])+min); //dateiausgabe absteigend


	fclose( outStream );

	unlink("~tmp");
	//getch();		
}

int sort_function( const void *a, const void *b){return( strcmp(a,b) );}

void _profil()
{
	printf("--------------------------------------\n");
	printf("Usage: SRT3 [input] [output] [[d]]\n");
	printf(" [input] ............... Eingabe Datei\n");
	printf(" [output] .............. Ausgabe Datei\n");
	printf(" [d] .................... 1:absteigend\n");
	printf("--------------------------------------\n");
	printf("SRT3 by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nSRT3 by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing SRT3:\n"); 
}







