//---------------------------------------------------------------------------| SRT1 von Dietmar SCHRAUSSER 2011              
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
	FILE *in1Stream, *in2Stream, *outStream, *logStream;

	int n_1=0, n_2=0, sw1=0, zlr=1, i_=0, i_1=0,i_2=0,sw=0;

	double cf1, cf2;
	
	char c1[20], c2[20];

	char *t_="~tmp";

	if (argc > 4 || argc < 4){  printf("\n> check arguments\n"); _profil();}
	logStream = fopen( "SRT1_log.txt", "a" ); fprintf(logStream, "%s @ %s\n", __DATE__, __TIME__); fclose( logStream  );
	
	_kopf();
	
	in1Stream = fopen( argv[1], "r" ); do { if(fgetc(in1Stream)=='\n') n_1++;} while (feof (in1Stream) == 0);   fclose( in1Stream  );
	in2Stream = fopen( argv[2], "r" ); do { if(fgetc(in2Stream)=='\n') n_2++;} while (feof (in2Stream) == 0);   fclose( in2Stream  );	
	
	in1Stream = fopen( argv[1], "r" );
	in2Stream = fopen( argv[2], "r" );
	outStream=  fopen( t_,      "w" ); 

	do 
	{
		if(sw==0||sw==1)if(i_1<=n_1){i_1++;fscanf(in1Stream,"%s",c1);cf1=atof(c1);}//printf("i1=%i\n", i_1);
		if(sw==0||sw==2)if(i_2<=n_2){i_2++;fscanf(in2Stream,"%s",c2);cf2=atof(c2);}//printf("i2=%i\n", i_2);

		if(cf1==cf2)if(i_1<=n_1&&i_2<=n_2) {fprintf(outStream,"%s\n%s\n", c1, c2); sw=0;}//printf("sw0\n");
		if(cf1< cf2)if(i_1<=n_1)           {fprintf(outStream,"%s\n",     c1);     sw=1;}//printf("sw1\n");
		if(cf1> cf2)if(i_2<=n_2)           {fprintf(outStream,"%s\n",         c2); sw=2;}//printf("sw2\n");

		if(i_1>n_1)                        {fprintf(outStream,"%s\n",         c2); sw=2;}//printf("end1\n");
		if(i_2>n_2)                        {fprintf(outStream,"%s\n",         c1); sw=1;}//printf("end2\n");

		printf("i1(%i),i2(%i)\r", i_1,i_2);

	}while(i_1<=n_1||i_2<=n_2);

	printf("i1(%i),i2(%i)\n", n_1,n_2);

	fclose(in1Stream);
	fclose(in2Stream);
	fclose(outStream);

	in1Stream = fopen( t_, "r" );
	outStream=  fopen( argv[3], "w" );

	i_1=0;
	do 
	{
		fscanf(in1Stream,"%s",       c1);
		fprintf(outStream,"%s\n",    c1);

		i_1++;

	}while(i_1<n_1+n_2);
	
	fclose(in1Stream);
	fclose(outStream);

	unlink(t_);
}

void _profil()
{
	printf("--------------------------------------\n");
	printf("Usage: SRT1 [input1] [input2] [output]\n");
	printf(" [input1] ..............  Input File 1\n");
	printf(" [input2] ..............  Input File 2\n");
	printf(" [output] ...............  Output File\n");
	printf("--------------------------------------\n");
	printf("SRT1 by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nSRT1 by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing SRT1:\n\n"); 
}
