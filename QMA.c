//---------------------------------------------------------------------------| QMA von Dietmar SCHRAUSSER 2010              
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
	FILE *inStream, *tmpStream, *outStream;

	int n_1=0, n_2=0, nk_1=-1, nk_2=-1, k_1, k_2, iLauf, jLauf, kLauf;
	
	char tmp[1000000], dat[20];

	double x_=0;

	if (argc != 3 ){  printf("\n> check arguments\n"); _profil();}

	if(fopen(argv[1],"r")==0){  printf("\n> check file %s\n", argv[1]); _profil();}
		
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_1++;} while (feof (inStream) == 0);   fclose( inStream  );
	inStream = fopen( argv[1], "r" ); do { fscanf(inStream, "%s", tmp); nk_1++;} while (feof (inStream) == 0);   fclose( inStream  );
	
    k_1=nk_1/n_1; nk_2=nk_1; n_2=n_1;
	k_2=nk_2/n_2;

	if (k_1 != n_1) {  printf("\n> n <> k\n"); _profil();}

	_kopf();

	//transponierung von matrix 2
	tmpStream = fopen( "~tmp1","w" );
	
	for (kLauf=1; kLauf<=k_2; kLauf++) 
	{
	    inStream = fopen( argv[1], "r" );  
		
		for (iLauf=1; iLauf<=n_2; iLauf++) 
		{
			for (jLauf=1; jLauf< kLauf ;jLauf++) fscanf( inStream,  "%s",    tmp);		
			
			fscanf ( inStream, "%s", tmp);
			fprintf( tmpStream, "%s", tmp); if(iLauf<n_2)fprintf( tmpStream, " ");
		
		  //for (jLauf=1; jLauf< k_2-kLauf ;jLauf++) fscanf( inStream,  "%s",    tmp);
			fgets( tmp,1000000,inStream);
		}
       
		fclose( inStream  );
	
		fprintf( tmpStream, "\n");
	}
	fclose( tmpStream );

	//matrizenmultiplikation
	outStream = fopen( "~tmp2","w" );

	for (kLauf=1; kLauf<=k_2; kLauf++) //über k_2
	{
		inStream = fopen( argv[1], "r" );  
		
		for (jLauf=1; jLauf<=n_1; jLauf++) // über n_1
		{
			tmpStream = fopen( "~tmp1","r" );
			for (iLauf=1; iLauf<kLauf; iLauf++)fgets( tmp,1000000,tmpStream);
			
			for (iLauf=1; iLauf<=k_1; iLauf++) //über k_1, n_2
			{

				fscanf ( inStream, "%s", dat);
				fscanf ( tmpStream, "%s", tmp);

				x_+=atof(tmp)*atof(dat);

			}
		    fprintf (outStream,"%.4f", x_); if(jLauf<n_1)fprintf( outStream, " ");

			x_=0;
		
		}

		fclose( inStream  );
		fclose( tmpStream  );
		fprintf (outStream,"\n");
	}
	fclose( outStream );

	//transponierung von tmp output
	outStream = fopen( argv[2],"w" );
	
	for (kLauf=1; kLauf<=n_1; kLauf++) 
	{
	    tmpStream = fopen( "~tmp2", "r" );  
		
		for (iLauf=1; iLauf<=k_2; iLauf++) 
		{
			for (jLauf=1; jLauf< kLauf ;jLauf++) fscanf( tmpStream,  "%s",    tmp);		
			
			fscanf ( tmpStream, "%s", tmp);
			fprintf( outStream, "%s", tmp); if(iLauf<k_2)fprintf( outStream, " ");
		
		  //for (jLauf=1; jLauf< n_1-kLauf ;jLauf++) fscanf( tmpStream,  "%s",    tmp);
			fgets( tmp,1000000,tmpStream);
		}
       
		fclose( tmpStream  );
	
		fprintf( outStream, "\n");
	}
	fclose( outStream );

	
	unlink("~tmp2");
	
	//getch();			
}

void _profil()
{
	printf("---------------------------------------\n");
	printf("Usage: QMA [matrix] [output]\n");
	printf(" [matrix] ........ Matrix Datei\n");
	printf(" [output] ........ Matrix Ausgabe Datei\n");
	printf("---------------------------------------\n");
	printf("QMA by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nQMA by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing QMA:\n"); 
}
