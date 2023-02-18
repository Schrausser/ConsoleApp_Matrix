//---------------------------------------------------------------------------| SEL von Dietmar SCHRAUSSER 2009              
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void _profil(); 
void _kopf(); 

void main(int argc, char *argv[])      
{	
	FILE *inStream, *outStream, *logStream;

	int n_=0, iLauf, jLauf;
	
	char data[20];

	if (argc != 5 ){  printf("\n> check arguments\n"); _profil();}
	
	logStream = fopen( "SEL_log.txt", "a" ); fprintf(logStream, "%s @ %s\n", __DATE__, __TIME__); fclose( logStream  );
	
	_kopf();
	
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );	
	
	inStream = fopen( argv[1], "r" ); 
	outStream = fopen( argv[2],"w" );
	
	for (iLauf=1; iLauf<=n_; iLauf++) 
	{
		for (jLauf=1;            jLauf<= atoi(argv[3]);jLauf++) fscanf( inStream,  "%s",    data);		
		                                                       fprintf( outStream, "%s\n",  data);	
		for (jLauf=atoi(argv[3]);jLauf<  atoi(argv[4]);jLauf++) fscanf( inStream,  "%s",    data);
	}
	
	fclose( inStream  );
	fclose( outStream );

	//getch();	
}

void _profil()
{
	printf("--------------------------------------\n");
	printf("Usage: SEL [input] [output] [a] [k]\n");
	printf(" [input] ............... Eingabe Datei\n");
	printf(" [output] .............. Ausgabe Datei\n");
	printf(" [a] .................... Vektornummer\n");
	printf(" [k] .................... Vektoranzahl\n");
	printf("--------------------------------------\n");
	printf("SEL by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nSEL by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing SEL:\n"); 
}
