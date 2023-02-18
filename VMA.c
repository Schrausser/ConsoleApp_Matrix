//---------------------------------------------------------------------------| VMA von Dietmar SCHRAUSSER 2010              
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

	int n_=0,  nk_=-1, k_, iLauf,  jLauf, kLauf;
	
	long double M_[251][251], V_[251][251]; //Dimensionierung max k=n= 250
	
	long double x_=0, cb=0, sp=1;

	char tmp[50];

	if (argc != 3 ){  printf("\n> check arguments\n"); _profil();}

	if(fopen(argv[1],"r")==0){  printf("\n> check file %s\n", argv[1]); _profil();}
	
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );
	inStream = fopen( argv[1], "r" ); do { fscanf(inStream, "%s", tmp); nk_++;} while (feof (inStream) == 0);   fclose( inStream  );
	
    k_=nk_/n_;

	if (k_ != n_) {  printf("\n> k <> n\n"); _profil();}
	if (n_ > 250) {  printf("\n> n_max =k_max = 250\n"); _profil();}

	_kopf();

    inStream = fopen( argv[1], "r" ); //Einlesen von Matrix A in Feld M_	
	for(iLauf=1;iLauf<=n_;iLauf++)
	{
		for(jLauf=1;jLauf<=k_;jLauf++)
		{
			 fscanf(inStream, "%s", tmp);
			 M_[iLauf][jLauf]= atof(tmp);
		}
	}
	fclose( inStream );
	
	for(jLauf=1;jLauf<=k_;jLauf++) V_[1][jLauf]= M_[1][jLauf];           //Übergabe der ersten Zeile von M_ an V_
	for(iLauf=2;iLauf<=n_;iLauf++) V_[iLauf][1]= M_[iLauf][1]/-V_[1][1]; //Berechnung der ersten Spalte von  V_

	for(kLauf=2;kLauf<=k_;kLauf++)
	{
		for(iLauf=2;iLauf<=n_;iLauf++)
		{
			if(iLauf <= kLauf) // bis zum diagonalelement berechnung der oberen dreiecksmatrizenelemente b
			{
				    for(jLauf=1;jLauf<=iLauf-1;jLauf++)cb += V_[jLauf][kLauf]*V_[iLauf][jLauf];
				
				V_[iLauf][kLauf] = 	M_[iLauf][kLauf] + cb;
				                                       cb=0;
			}
			
			if(iLauf > kLauf) // unter dem diagonalelement berechnung der unteren dreiecksmatrizenelemente c
			{
				
				     for(jLauf=1;jLauf<=kLauf-1;jLauf++)cb += V_[jLauf][kLauf]*V_[iLauf][jLauf];
	
				V_[iLauf][kLauf] = 	(M_[iLauf][kLauf] + cb) / -V_[kLauf][kLauf];
				                                        cb=0;
			}
		}
	}

	//Berechnung der Determinante von A

	for(iLauf=1;iLauf<=n_;iLauf++) sp*=V_[iLauf][iLauf]; //HauptdiagonalenPRODUKT von B (zur Unterscheidung Spur sp = HauptdiagonalenSUMME)
	
	 printf("det A = %.3f\n", sp);


	outStream = fopen( argv[2], "w" );//Ausgeben von Matrix V_ in Datei
	for(iLauf=1;iLauf<=n_;iLauf++)
	{
		for(jLauf=1;jLauf<=k_;jLauf++)
		{
			 fprintf(outStream, "%.3f", V_[iLauf][jLauf]);
			 if(jLauf<k_)fprintf(outStream, " ");
		}
		fprintf(outStream, "\n");
	}
	fclose( outStream );



	//getch();			
}

void _profil()
{
	printf("--------------------------------------\n");
	printf("Usage: VMA [matrix] [output]\n");
	printf(" [matrix] ....... Matrix Datei\n");
	printf(" [output] ....... Matrix Ausgabe Datei\n");
	printf("--------------------------------------\n");
	printf("VMA by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nVMA by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing VMA:\n\n"); 
}
