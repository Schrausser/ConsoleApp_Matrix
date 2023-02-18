//---------------------------------------------------------------------------| KTF von Dietmar SCHRAUSSER 2009              
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
	FILE *inStream, *outStream, *logStream;

	int n_=-1, iLauf, jLauf ;
	double in_d1[30010];
	
	char in_[30010][15];

	if (argc != 4){  printf("\n> check arguments\n"); _profil(argv[0]);}
	if (atoi(argv[3])> 30000){  printf("\n> n'max=30000\n"); _profil(argv[0]);}
	
	logStream = fopen( "KTF_log.txt", "a" ); fprintf(logStream, "%s @ %s\n", __DATE__, __TIME__); fclose( logStream  );
	
	_kopf();
	
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );	
	inStream = fopen( argv[1], "r" ); for (iLauf=0;iLauf<=n_;iLauf++) fscanf( inStream, "%s",  in_[iLauf]);	fclose( inStream  );
	
	for (iLauf=0;iLauf<=n_;iLauf++) in_d1[iLauf]= atof(in_[iLauf])-atof(in_[0]);

	outStream = fopen( argv[2],"w" );
	
	if(atoi(argv[3]) == n_+1)for(iLauf=0;iLauf<atoi(argv[3]);iLauf++) fprintf(outStream,"%s\n",in_[iLauf]);

	if(atoi(argv[3]) != n_+1)
	{
		if(atoi(argv[3]) < n_+1)
		{
			for (jLauf=0;jLauf<n_-atoi(argv[3])+1;jLauf++)
			{
				for(iLauf=1;iLauf< n_-jLauf; iLauf++) in_d1[iLauf]= in_d1[iLauf] * (n_-jLauf) / (n_-jLauf-1);
			 
				printf("Iteration[%i]\r", jLauf);
			}
		}

		if(atoi(argv[3]) > n_+1)
		{
			for (jLauf=0;jLauf<atoi(argv[3])-n_-1;jLauf++)
			{
				for(iLauf=1;iLauf<= n_+jLauf; iLauf++) in_d1[iLauf]= in_d1[iLauf] * (n_+jLauf) / (n_+jLauf+1);
				                                       in_d1[n_+jLauf+1]= atof(in_[n_])-atof(in_[0]);
				printf("Iteration[%i]\r", jLauf);
			}
		}

		for(iLauf=0;iLauf<atoi(argv[3])-1;iLauf++) 
		{
										  in_d1[iLauf]= in_d1[iLauf]+atof(in_[0]);
			if(in_d1[iLauf]>atof(in_[n_]))in_d1[iLauf]= atof(in_[n_]);
		}

		for(iLauf=0;iLauf<atoi(argv[3])-1;iLauf++) fprintf(outStream,"%f\n",in_d1[iLauf]); 
		
		fprintf(outStream,"%s\n",in_[n_]); 	
	}

	printf("\n");

	fclose( outStream ); 
	
	if(atoi(argv[3]) == 0) {outStream = fopen( argv[2],"w" ); fclose( outStream );}
	
	//getch();	
}

void _profil()
{
	printf("-------------------------------\n");
	printf("Usage: KTF [input] [output] [n]\n");
	printf(" [input] ........ Eingabe Datei\n");
	printf(" [output] ....... Ausgabe Datei\n");
	printf(" [n] .......... Vektorumfang n'\n");
	printf("-------------------------------\n");
	printf("KTF by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nKTF by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing KTF:\n\n"); 
}
