//---------------------------------------------------------------------------| AMA von Dietmar SCHRAUSSER 2010             
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
	FILE *inStream, *in1Stream, *outStream;

	int n_1=0, n_2=0, nk_1=-1, nk_2=-1, k_1, k_2, iLauf, jLauf;
	
	char dat1[20], dat2[20];
	
	double dat3;

	if (argc != 5 ){  printf("\n> check arguments\n"); _profil();}

	if(fopen(argv[1],"r")==0){  printf("\n> check file %s\n", argv[1]); _profil();}
	if(fopen(argv[2],"r")==0){  printf("\n> check file %s\n", argv[2]); _profil();}
	
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_1++;} while (feof (inStream) == 0);   fclose( inStream  );
	inStream = fopen( argv[1], "r" ); do { fscanf(inStream, "%s", dat1); nk_1++;} while (feof (inStream) == 0);   fclose( inStream  );
	inStream = fopen( argv[2], "r" ); do { if(fgetc(inStream)=='\n') n_2++;} while (feof (inStream) == 0);   fclose( inStream  );
	inStream = fopen( argv[2], "r" ); do { fscanf(inStream, "%s", dat1); nk_2++;} while (feof (inStream) == 0);   fclose( inStream  );

    k_1=nk_1/n_1;
	k_2=nk_2/n_2;

	if (k_1 != k_2) {  printf("\n> k1 <> k2\n"); _profil();}
	if (n_1 != n_2) {  printf("\n> n1 <> n2\n"); _profil();}

	_kopf();

	inStream = fopen( argv[1], "r" );
	in1Stream = fopen( argv[2], "r" );
	outStream = fopen( argv[3], "w" );

	
	for(iLauf=1; iLauf<= n_1; iLauf++)
	{
		for(jLauf=1; jLauf<= k_1; jLauf++)
		{
		                  fscanf(inStream,"%s",dat1); fscanf(in1Stream,"%s",dat2);		                                           
                if(atoi(argv[4])==0) dat3=atof(dat1) +                 atof(dat2);
				if(atoi(argv[4])==1) dat3=atof(dat1) -                 atof(dat2);
			
									 
			fprintf(outStream,"%.3f",dat3);
			
			if(jLauf < k_1)fprintf(outStream," ");
		}
		fprintf(outStream,"\n");
	}

	fclose( inStream );	
	fclose( in1Stream );	
	fclose( outStream );
}

void _profil()
{
	printf("----------------------------------------------\n");
	printf("Usage: AMA [matrix1] [matrix2] [output] [mode]\n");
	printf(" [matrix1] ...... Matrix Datei 1\n");
	printf(" [matrix2] ...... Matrix Datei 2\n");
	printf(" [output] ....... Matrix Ausgabe Datei\n");
	printf(" [mode] ......... (0):+ (1):-\n");
	printf("----------------------------------------------\n");
	printf("AMA by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nAMA by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing AMA:\n"); 
}
