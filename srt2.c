//---------------------------------------------------------------------------| SRT2 von Dietmar SCHRAUSSER 2009              
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

	int n_=0, iLauf, sw1=0, sw=1, zlr=1;
	double in_d[33010], in_o;
	
	char in_[33010][45];

	
	if (argc > 4 || argc < 3){  printf("\n> check arguments\n"); _profil();}
	if (argc == 4 && atoi(argv[3]) != 1){  printf("\n> switch d <> 1\n"); _profil();}
	logStream = fopen( "SRT2_log.txt", "a" ); fprintf(logStream, "%s @ %s\n", __DATE__, __TIME__); fclose( logStream  );
	
	_kopf();
	
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );	
	inStream = fopen( argv[1], "r" ); for (iLauf=1;iLauf<=n_;iLauf++) fscanf( inStream, "%s",  in_[iLauf]);	fclose( inStream  );
	
	for (iLauf=1;iLauf<=n_;iLauf++) in_d[iLauf]= atof(in_[iLauf]);
 
	do
	{
		for (iLauf = 1; iLauf < n_; iLauf++)//-------------------> sortierung aufsteigend
		{

			if(in_d[iLauf+1] < in_d[iLauf])
			{ 
				            in_o = in_d[iLauf+1];
					               in_d[iLauf+1]= in_d[iLauf];
				in_d[iLauf]=in_o;
				sw1=1;
			}	 
		}

        if(sw1==0) sw=0;
		sw1=0;

		printf("i(%i)\r", zlr); zlr++;
	
	}while(sw==1);

	printf("\n");

	outStream = fopen( argv[2],"w" );
	
	if (argc == 3 ) for(iLauf=1;iLauf<=n_;iLauf++) fprintf( outStream, "%f\n",  in_d[iLauf]); //dateiausgabe aufsteigend
	if (argc == 4 ) for(iLauf=n_;iLauf>=1;iLauf--) fprintf( outStream, "%f\n",  in_d[iLauf]); //dateiausgabe absteigend
	
	fclose( outStream );


	//getch();	
}

void _profil()
{
	printf("--------------------------------------\n");
	printf("Usage: SRT2 [input] [output] [[d]]\n");
	printf(" [input] ............... Eingabe Datei\n");
	printf(" [output] .............. Ausgabe Datei\n");
	printf(" [d] .................... 1:absteigend\n");
	printf("--------------------------------------\n");
	printf("SRT2 by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nSRT2 by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing SRT2:\n\n"); 
}
