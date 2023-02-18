//---------------------------------------------------------------------------| IMA von Dietmar SCHRAUSSER 2010              
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
	
	long double M_[20][20], V_[20][20] , E_[20][20]; //Dimensionierung max k=n= 200
	
	long double x_=0, cb=0;

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

	if(n_==2)//Inversion bei n=2
	{
		x_= M_[1][1]*M_[2][2] - M_[1][2]*M_[2][1];  // determinate

		E_[1][1] =  (1/x_)*  M_[2][2]; E_[1][2] =  (1/x_)* -M_[1][2];
		E_[2][1] =  (1/x_)* -M_[2][1]; E_[2][2] =  (1/x_)*  M_[1][1];
	
	}

	if(n_==3)//Inversion bei n=3 
	{
		x_=  M_[1][1]*(M_[2][2]*M_[3][3] - M_[3][2]*M_[2][3]);   // determinate
		x_-= M_[2][1]*(M_[1][2]*M_[3][3] - M_[3][2]*M_[1][3]);
		x_+= M_[3][1]*(M_[1][2]*M_[2][3] - M_[2][2]*M_[1][3]);

		// Adjunkte A(adj)

		V_[1][1]=  M_[2][2]*M_[3][3]-M_[3][2]*M_[2][3];  V_[1][2]=-(M_[2][1]*M_[3][3]-M_[3][1]*M_[2][3]); V_[1][3]=  M_[2][1]*M_[3][2]-M_[3][1]*M_[2][2];    
		V_[2][1]=-(M_[1][2]*M_[3][3]-M_[1][3]*M_[3][2]); V_[2][2]=  M_[1][1]*M_[3][3]-M_[3][1]*M_[1][3];  V_[2][3]=-(M_[1][1]*M_[3][2]-M_[3][1]*M_[1][2]);
		V_[3][1]=  M_[1][2]*M_[2][3]-M_[2][2]*M_[1][3];  V_[3][2]=-(M_[1][1]*M_[2][3]-M_[2][1]*M_[1][3]); V_[3][3]=  M_[1][1]*M_[2][2]-M_[2][1]*M_[1][2];
	
		E_[1][1]= (1/x_)* V_[1][1];  E_[1][2]= (1/x_)* V_[1][2];  E_[1][3]= (1/x_)* V_[1][3];
		E_[2][1]= (1/x_)* V_[2][1];  E_[2][2]= (1/x_)* V_[2][2];  E_[2][3]= (1/x_)* V_[2][3];
		E_[3][1]= (1/x_)* V_[3][1];  E_[3][2]= (1/x_)* V_[3][2];  E_[3][3]= (1/x_)* V_[3][3];
	}
	
	if(n_> 3)//Inversion bei n>3 via Verkettung nach Gauss
	{
	
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

		for(kLauf=1;kLauf<=k_;kLauf++) //Erzeugung der Einheitsmatrix E_
		{
			for(iLauf=1;iLauf<=n_;iLauf++)
			{
				E_[iLauf][kLauf]=0; if(iLauf==kLauf)E_[iLauf][kLauf]=1;
			}
		}

		for(kLauf=1;kLauf<=k_;kLauf++) M_[1][kLauf]= E_[1][kLauf];//Berechnung der der Matrix T_

		for(kLauf=1;kLauf<=k_;kLauf++)
		{
			for(iLauf=2;iLauf<=n_;iLauf++)
			{
						for(jLauf=1;jLauf<=iLauf-1;jLauf++)cb += E_[jLauf][kLauf]*V_[iLauf][jLauf];
					
					M_[iLauf][kLauf] = 	E_[iLauf][kLauf] + cb;
														   cb=0;
			}
		}

		for(iLauf=n_;iLauf>=1;iLauf--) //Berechnung der Matrix A_ (Transponierte inverse von M_)
		{
			for(kLauf=k_;kLauf>=1;kLauf--)
			{
				
				  for(jLauf=k_+1;jLauf>kLauf+1;jLauf--)cb += E_[iLauf][jLauf-1]*V_[kLauf][jLauf-1];
				E_[iLauf][kLauf]= (-M_[kLauf][iLauf] + cb) / -V_[kLauf][kLauf];
													   cb=0;
			}

		}
	}

	outStream = fopen( argv[2], "w" );//Transponierte Ausgeben von Matrix A_ in Datei
	for(iLauf=1;iLauf<=n_;iLauf++)
	{
		for(jLauf=1;jLauf<=k_;jLauf++)
		{
			 fprintf(outStream, "%.4f", E_[jLauf][iLauf]);
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
	printf("Usage: IMA [matrix] [output]\n");
	printf(" [matrix] ....... Matrix Datei\n");
	printf(" [output] ....... Matrix Ausgabe Datei\n");
	printf("--------------------------------------\n");
	printf("IMA by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nIMA by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing IMA:\n\n"); 
}
