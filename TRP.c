//---------------------------------------------------------------------------| TRP von Dietmar SCHRAUSSER 2010              
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

	int n_=0, nk_=-1, k_, iLauf, jLauf, kLauf;
	
	char tmp[1000000];

	if (argc != 3 ){  printf("\n> check arguments\n"); _profil();}

	if(fopen(argv[1],"r")==0){  printf("\n> check file %s\n", argv[1]); _profil();}
	
	_kopf();
	
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );
	inStream = fopen( argv[1], "r" ); do { fscanf(inStream, "%s", tmp); nk_++;} while (feof (inStream) == 0);   fclose( inStream  );

    k_=nk_/n_;

	outStream = fopen( argv[2],"w" );
	
	for (kLauf=1; kLauf<=k_; kLauf++) 
	{
	    inStream = fopen( argv[1], "r" );  
		
		for (iLauf=1; iLauf<=n_; iLauf++) 
		{
			for (jLauf=1; jLauf< kLauf ;jLauf++) fscanf( inStream,  "%s",    tmp);		
			
			fscanf ( inStream, "%s", tmp);
			fprintf( outStream, "%s", tmp); if(iLauf<n_)fprintf( outStream, " ");
		
		  //for (jLauf=1; jLauf< k_-kLauf ;jLauf++) fscanf( inStream,  "%s",    tmp);
			fgets( tmp,1000000,inStream);
		}
       
		fclose( inStream  );
	
		fprintf( outStream, "\n");
	}
	
	
	fclose( outStream );

	//getch();	
}

void _profil()
{
	printf("---------------------------\n");
	printf("Usage: TRP [input] [output]\n");
	printf(" [input] .... Eingabe Datei\n");
	printf(" [output] ... Ausgabe Datei\n");
	printf("---------------------------\n");
	printf("TRP by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nTRP by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing TRP:\n"); 
}
