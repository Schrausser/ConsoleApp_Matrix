//---------------------------------------------------------------------------| ENT by Dietmar SCHRAUSSER 2010               

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void _profil(); 
void _kopf();                      

main(int argc, char *argv[])   
{   
	FILE *in, *out1, *out2; 
	
	char x_[50];
      
	if (argc != 4) {printf("\n> check arguments\n");_profil();	}

	in=fopen( argv[1], "r" );
	out1=fopen( argv[2], "w" );
	out2=fopen( argv[3], "w" );

	_kopf();

	while(1)
	{
	        fscanf(in,"%s",&x_ );if (feof (in) != 0) break;
		fprintf(out1,"%s\n",x_);
            fscanf(in,"%s",&x_ );
		fprintf(out2,"%s\n",x_);
	}

	fclose(in);
	fclose(out1);
	fclose(out2);
	return 0;
}
         
void _profil()
{
	printf("--------------------------------------\n");
	printf("Usage: ENT [input] [output1] [output2]\n");
	printf("[input] ..... Eingabe Datei \n");
	printf("[output1] ... Ausgabe Datei 1 \n");
	printf("[output2] ... Ausgabe Datei 2 \n");
	printf("--------------------------------------\n");
	printf("ENT by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(0);
}	

void _kopf() 
{
	printf("\nENT by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing ENT:\n"); 
}                                           
