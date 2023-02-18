//---------------------------------------------------------------------------| SPUR von Dietmar SCHRAUSSER 2010              
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

	int n_=0,  nk_=-1, k_, iLauf,  jLauf;

	double sp=0;

	char tmp[50];

	if (argc != 3 ){  printf("\n> check arguments\n"); _profil();}

	if(fopen(argv[1],"r")==0){  printf("\n> check file %s\n", argv[1]); _profil();}
	
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );
	inStream = fopen( argv[1], "r" ); do { fscanf(inStream, "%s", tmp); nk_++;} while (feof (inStream) == 0);   fclose( inStream  );
	
    k_=nk_/n_;

	if (k_ != n_) {  printf("\n> k <> n\n"); _profil();}

	_kopf();

    if(atoi(argv[2]) == 1) sp=1;
	
	inStream = fopen( argv[1], "r" );
	
	for(iLauf=1;iLauf<=n_;iLauf++)
	{
		for(jLauf=1;jLauf<iLauf;jLauf++) fscanf(inStream,"%s", tmp);
		 
		          fscanf(inStream,"%s", tmp); 
		
		if(atoi(argv[2]) == 0) sp+=atof(tmp);
		if(atoi(argv[2]) == 1) sp*=atof(tmp);
		if(atoi(argv[2]) == 2) 
		{
			if(iLauf==1) sp=atof(tmp);
			if(iLauf>1)  sp-=atof(tmp);
		
		}

		if(atoi(argv[2]) == 3) 
		{
			if(iLauf==1) sp=atof(tmp);
			if(iLauf>1)  sp/=atof(tmp);
		
		}

	    for(jLauf=iLauf+1;jLauf<=k_;jLauf++) fscanf(inStream,"%s", tmp);
	}


    fclose( inStream );
    
	outStream = fopen( "spur.txt", "a" );fprintf(outStream,"%.3f\n",sp);fclose( outStream );

	printf("sp A = %.3f\n\n",sp);


	//getch();			
}

void _profil()
{
	printf("-------------------------------------\n");
	printf("Usage: SPUR [matrix] [mode]\n");
	printf(" [matrix] .............. Matrix Datei\n");
	printf(" [mode] ..... (0):+ (1):* (2):- (3):/\n");
	printf("-------------------------------------\n");
	printf("SPUR by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nSPUR by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing SPUR:\n\n"); 
}
