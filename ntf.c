//---------------------------------------------------------------------------| NTF von Dietmar SCHRAUSSER 2009              
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
	FILE *outStream;

	int iLauf, mini, maxi;
	double n_, ye, maxx ;
	
	if (argc != 7)             { printf("\n> check arguments\n"); _profil(argv[0]);}
	
	mini= atoi(argv[2]);
	maxi= atoi(argv[3]);
	ye=  atof(argv[4]);
	maxx=  atof(argv[5]);
	
	_kopf();
	
	outStream = fopen( argv[1],"w" );

	for (iLauf=mini;iLauf<=maxi;iLauf++)
	{
		                     n_= (ye+ (((ye- mini)- (ye- iLauf))* ((maxx- ye)/ ((ye- mini)-(ye-maxi)))));

		if(atoi(argv[6])==1) n_= (maxx+ ye) - n_;
		
		fprintf( outStream, "%f\n",  n_);
	}
	
	fclose( outStream ); 
	
	//getch();	
}

void _profil()
{
	printf("---------------------------------------------------\n");
	printf("Usage: NTF [output] [minn] [maxn] [min] [max] [inv]\n");
	printf(" [output] ........................... Ausgabe Datei\n");
	printf(" [minn] ............................. n Minimalwert\n");
	printf(" [minn] ............................. n Maximalwert\n");
	printf(" [min] ........... Koordinaten Minimalpositionswert\n");
	printf(" [max] ........... Koordinaten Maximalpositionswert\n");
	printf(" [inv] ............ 1:invertiert 0:nicht invertiert\n");
	printf("---------------------------------------------------\n");
	printf("NTF by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nNTF by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing NTF:\n"); 
}
