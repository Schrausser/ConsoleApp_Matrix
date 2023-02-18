//---------------------------------------------------------------------------| ZMA von Dietmar SCHRAUSSER 2010             
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
	FILE *inStream, *outStream;

	int n_=0, nk_=-1, k_, iLauf, jLauf;
	
	char dat1[20];
	
	double dat2;

	if (argc != 4 ){  printf("\n> check arguments\n"); _profil();}

	if(fopen(argv[1],"r")==0){  printf("\n> check file %s\n", argv[1]); _profil();}
	
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );
	inStream = fopen( argv[1], "r" ); do { fscanf(inStream, "%s", dat1); nk_++;} while (feof (inStream) == 0);   fclose( inStream  );

	_kopf();

	k_=nk_/n_;

	inStream = fopen( argv[1], "r" );
	outStream = fopen( argv[2], "w" );

	
	for(iLauf=1; iLauf<= n_; iLauf++)
	{
		for(jLauf=1; jLauf<= k_; jLauf++)
		{
		                  fscanf(inStream,"%s",dat1); 		                                           
                                     dat2=atof(dat1) * atof(argv[3]);                 		 
			fprintf(outStream,"%.3f",dat2);
			
			if(jLauf < k_)fprintf(outStream," ");
		}
		fprintf(outStream,"\n");
	}

	fclose( inStream );	
	fclose( outStream );
}

void _profil()
{
	printf("----------------------------------------------\n");
	printf("Usage: ZMA [matrix] [output] [wert]\n");
	printf(" [matrix] .....Matrix Datei\n");
	printf(" [output] .....Matrix Ausgabe Datei\n");
	printf(" [wert] ...... zu multiplizierende reelle Zahl\n");
	printf("----------------------------------------------\n");
	printf("ZMA by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nZMA by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing ZMA:\n"); 
}
