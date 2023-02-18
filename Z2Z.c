//---------------------------------------------------------------------------| Z2Z by Dietmar SCHRAUSSER 2010               

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void _profil(); 
void _kopf();                      

int n1=0, n2=0,iLauf;
char dbuffer[9],tbuffer[9], in[200];  

main(int argc, char *argv[])   
{   
	FILE *in1Stream, *in2Stream, *outStream;                                 
      
	if (argc != 4) {printf("\n> check arguments\n");_profil();	}
   	          
	in1Stream = fopen( argv[1], "rb" );
	in2Stream = fopen( argv[2], "rb" );
	outStream = fopen( argv[3], "wb" ); 
	   
	if (in1Stream == 0) { 	printf("\n> check file %s\n", argv[1]); _profil(argv[0]);}          
	if (in2Stream == 0) { 	printf("\n> check file %s\n", argv[2]); _profil(argv[0]);} 

	do { if(fgetc(in1Stream)=='\n') n1++;} while (feof (in1Stream) == 0);  fclose( in1Stream  );
	do { if(fgetc(in2Stream)=='\n') n2++;} while (feof (in2Stream) == 0);  fclose( in2Stream  );

	_kopf();

	in1Stream = fopen( argv[1], "rb" );
	in2Stream = fopen( argv[2], "rb" );
	
	for(iLauf=1;iLauf <= n1; iLauf++) {fgets(in,200,in1Stream); fprintf(outStream,"%s",in);}
	for(iLauf=1;iLauf <= n2; iLauf++) {fgets(in,200,in2Stream); fprintf(outStream,"%s",in);}
	 
 
	fclose( in1Stream );
	fclose( in2Stream );
	fclose( outStream );

	return 0;
}
         
void _profil()
{
	printf("-------------------------------------\n");
	printf("Usage: Z2Z [input1] [input2] [output]\n");
	printf("[input1] ... Eingabe Datei 1 \n");
	printf("[input2] ... Eingabe Datei 2 \n");
	printf("[output] ... Ausgabe Datei \n");
	printf("-------------------------------------\n");
	printf("Z2Z by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(0);
}	

void _kopf() 
{
	printf("\nZ2Z by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing Z2Z:\n"); 
}                                           
