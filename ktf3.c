//---------------------------------------------------------------------------| KTF3 von Dietmar SCHRAUSSER 2009              
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>

void _profil(); 
void _kopf(); 

void main(int argc, char *argv[])      
{	
	FILE *inStream, *outStream;

	int n_=0,  iLauf;
	double in_d1[550], ye, maxx, mini, maxi;
	
	char in_[550][30];

	if (argc != 6)             { printf("\n> check arguments\n"); _profil(argv[0]);}
	if(fopen(argv[1], "r")==0) { printf("\n> check inputfile\n"); _profil(argv[0]);}
	
	ye= atof(argv[3]);
	maxx= atof(argv[4]);
	
	_kopf();
	
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );	
	inStream = fopen( argv[1], "r" ); for (iLauf=1;iLauf<=n_;iLauf++) fscanf( inStream, "%s",  in_[iLauf]);	fclose( inStream  );
	
	for (iLauf=1;iLauf<=n_;iLauf++) in_d1[iLauf]= atof(in_[iLauf]);

	mini=in_d1[1];
	maxi=in_d1[n_];
	
	for (iLauf=1;iLauf<=n_;iLauf++)
	{
		                     in_d1[iLauf]= (ye+ (((ye- mini)- (ye- in_d1[iLauf]))* ((maxx- ye)/ ((ye- mini)-(ye-maxi)))));

		if(atoi(argv[5])==1) in_d1[iLauf]= (maxx+ ye) - in_d1[iLauf];
	}
	
    outStream = fopen( argv[2],"w" );
	for (iLauf=1;iLauf<=n_;iLauf++) fprintf( outStream, "%f\t%s\n",  in_d1[iLauf], in_[iLauf]);
	fclose( outStream ); 
	
	//getch();	
}

void _profil()
{
	printf("------------------------------------------------\n");
	printf("Usage: KTF3 [input] [output] [minx] [maxx] [inv]\n");
	printf(" [input] ......................... Eingabe Datei\n");
	printf(" [output] ........................ Ausgabe Datei\n");
	printf(" [minx] ..... y Koordinaten Minimalpositionswert\n");
	printf(" [maxx] ..... y Koordinaten Maximalpositionswert\n");
	printf(" [inv] ......... 1:invertiert 0:nicht invertiert\n");
	printf("------------------------------------------------\n");
	printf("KTF3 by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nKTF3 by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing KTF3:\n"); 
}
