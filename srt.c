//---------------------------------------------------------------------------| SRT von Dietmar SCHRAUSSER 2009, 2010             
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

	int n_=0, hub, iLauf, lLauf, kLauf;
	double in_d[33010], in_sort[33010], in_max;
	
	char in_[33010][15];

	
	if (argc > 4 || argc < 3){  printf("\n> check arguments\n"); _profil();}
	if (argc == 4 && atoi(argv[3]) != 1){  printf("\n> switch d <> 1\n"); _profil();}
	logStream = fopen( "SRT_log.txt", "a" ); fprintf(logStream, "%s @ %s\n", __DATE__, __TIME__); fclose( logStream  );
	
	_kopf();
	
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );	
	inStream = fopen( argv[1], "r" ); for (iLauf=1;iLauf<=n_;iLauf++) fscanf( inStream, "%s",  in_[iLauf]);	fclose( inStream  );
	
	for (iLauf=1;iLauf<=n_;iLauf++) {in_d[iLauf]= atof(in_[iLauf]);if(in_max < atof(in_[iLauf]) )in_max= atof(in_[iLauf]);}
 

	in_sort[1]= in_max; hub = 0;
	
	
	for (kLauf = 1; kLauf <= n_; kLauf++)//-------------------> sortierung aufsteigend
	{
	    for (lLauf = 0; lLauf < kLauf; lLauf++)
		{
			if (in_d[kLauf] < in_sort[kLauf-lLauf])
			{
				in_sort[(kLauf-lLauf)+1] = in_sort[kLauf-lLauf]; hub++;	
			}	
		}	
		in_sort[(kLauf+1)-hub] = in_d[kLauf]; hub=0;
		
		printf("i(%i)\r", kLauf); 
	}

	printf("\n");

	outStream = fopen( argv[2],"w" );
	
	if (argc == 3 ) for(iLauf=1;iLauf<=n_;iLauf++) fprintf( outStream, "%.16f\n",  in_sort[iLauf]); //dateiausgabe aufsteigend
	if (argc == 4 ) for(iLauf=n_;iLauf>=1;iLauf--) fprintf( outStream, "%.16f\n",  in_sort[iLauf]); //dateiausgabe absteigend
	
	fclose( outStream );


	//getch();	
}

void _profil()
{
	printf("--------------------------------------\n");
	printf("Usage: SRT [input] [output] [[d]]\n");
	printf(" [input] ............... Eingabe Datei\n");
	printf(" [output] . Ausgabe Datei (16 stellig)\n");
	printf(" [d] .................... 1:absteigend\n");
	printf("--------------------------------------\n");
	printf("SRT by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nSRT by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing SRT:\n\n"); 
}
