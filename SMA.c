//---------------------------------------------------------------------------| SMA von Dietmar SCHRAUSSER 2010             
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
	
	char dat1[200];

	if (argc != 7 ){  printf("\n> check arguments\n"); _profil();}
	
	if (atoi(argv[3]) > atoi(argv[4])){  printf("\n> i0 > i1\n"); _profil();}
	if (atoi(argv[5]) > atoi(argv[6])){  printf("\n> j0 > j1\n"); _profil();}

	if(fopen(argv[1],"r")==0){  printf("\n> check file %s\n", argv[1]); _profil();}
	
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );
	inStream = fopen( argv[1], "r" ); do { fscanf(inStream, "%s", dat1); nk_++;} while (feof (inStream) == 0);   fclose( inStream  );

	k_=nk_/n_;

	if (atoi(argv[4]) > n_){  printf("\n> i1 > n\n"); _profil();}
	if (atoi(argv[6]) > k_){  printf("\n> j1 > k\n"); _profil();}

	_kopf();
	
	inStream = fopen( argv[1], "r" );
	outStream = fopen( argv[2], "w" );


	for(iLauf=1; iLauf< atoi(argv[3]); iLauf++) fgets(dat1 ,200, inStream);

	
	for(jLauf=1; jLauf<= atoi(argv[4]) - atoi(argv[3])+1; jLauf++)
	{
		for(iLauf=1; iLauf<  atoi(argv[5]); iLauf++) fscanf(inStream,"%s",dat1);

		for(iLauf=1; iLauf<= atoi(argv[6]) - atoi(argv[5])+1; iLauf++)
		{	
				  fscanf(inStream,"%s",dat1); 		                                                            		 
				fprintf(outStream,"%s",dat1);
				
				if(iLauf < atoi(argv[6]) - atoi(argv[5])+1)fprintf(outStream," ");
		}
		fprintf(outStream,"\n");

		for(iLauf=1; iLauf<=   k_-atoi(argv[6]); iLauf++) fscanf(inStream,"%s",dat1);
	}


	fclose( inStream );	
	fclose( outStream );
}

void _profil()
{
	printf("------------------------------------------------\n");
	printf("Usage: SMA [matrix] [output] [i0] [i1] [j0] [j1]\n");
	printf(" [matrix] ................. Matrix Datei\n");
	printf(" [output] ................. Matrix Ausgabe Datei\n");
	printf(" [i0] ..................... von Zeile\n");
	printf(" [i1] ..................... bis Zeile\n");
	printf(" [j0] ..................... von Spalte\n");
	printf(" [j1] ..................... bis Spalte\n");
	printf("------------------------------------------------\n");
	printf("SMA by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nSMA by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing SMA:\n"); 
}
