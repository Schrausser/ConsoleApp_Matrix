//---------------------------------------------------------------------------| V2V by Dietmar SCHRAUSSER 2010               

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void _profil(); 
void _kopf();                      

int n1=0, n2=0,iLauf;
char dbuffer[9],tbuffer[9], in[200], out_string[200], c_;  

main(int argc, char *argv[])   
{   
	FILE *in1Stream, *in2Stream, *outStream;                                 
      
	if (argc != 5) {printf("\n> check arguments\n");_profil();	}
   	          
	in1Stream = fopen( argv[1], "rb" );
	in2Stream = fopen( argv[2], "rb" );
	outStream = fopen( argv[3], "wb" ); 
	   
	if (in1Stream == 0) { 	printf("\n> check file %s\n", argv[1]); _profil(argv[0]);}          
	if (in2Stream == 0) { 	printf("\n> check file %s\n", argv[2]); _profil(argv[0]);} 

	do { if(fgetc(in1Stream)=='\n') n1++;} while (feof (in1Stream) == 0);  fclose( in1Stream  );
	do { if(fgetc(in2Stream)=='\n') n2++;} while (feof (in2Stream) == 0);  fclose( in2Stream  );

	if (n1 != n2) {printf("\n> n of rows not equal\n");_profil();	}

	_kopf();

	in1Stream = fopen( argv[1], "rb" );
	in2Stream = fopen( argv[2], "rb" );
	
	
	for(iLauf=1;iLauf <= n2; iLauf++) 
	{ 
		do
		{ 
			      c_=fgetc(in1Stream);  
			   if(c_!='\n')
			fputc(c_, outStream); 
		}
		while(    c_ != '\n');
	                 	                      fgets(in, 200, in2Stream);
		if(argv[4][0]=='1')fprintf(outStream, " %s", in);
		if(argv[4][0]=='0')fprintf(outStream, "\t%s",in);
		if(argv[4][0]!='1' &&
		   argv[4][0]!='0')fprintf(outStream, "%s%s",argv[4],in);

	}
 
	fclose( in1Stream );
	fclose( in2Stream );
	fclose( outStream );

	return 0;
}
         
void _profil()
{
	printf("------------------------------------------------\n");
	printf("Usage: V2V [input1] [input2] [output] [tab]\n");
	printf("[input1] ... Eingabe Datei 1 \n");
	printf("[input2] ... Eingabe Datei 2 \n");
	printf("[output] ... Ausgabe Datei \n");
    printf("[tab] ...... (0):TAB (1):Leerzeichen (*):String \n");
	printf("------------------------------------------------\n");
	printf("V2V by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(0);
}	

void _kopf() 
{
	printf("\nV2V by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing V2V:\n"); 
}                                           
