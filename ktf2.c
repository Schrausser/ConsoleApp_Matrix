//---------------------------------------------------------------------------| KTF2 von Dietmar SCHRAUSSER 2009              
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
	FILE *inStream, *outStream, *logStream;

	int n_=0, x_, s_=1, iLauf, jLauf, stp, ind=1, _in=0, c_, cc; 
	double in_d1[33010], in_d2[33010], o_, oo;
	
	char in_[33010][15];

	if (argc != 4)           {  printf("\n> check arguments\n"); _profil(argv[0]);}
	if (atoi(argv[3])> 33000){  printf("\n> n'max= 33000\n"); _profil(argv[0]);}
	
	logStream = fopen( "KTF2_log.txt", "a" ); fprintf(logStream, "%s @ %s\n", __DATE__, __TIME__); fclose( logStream  );
	
	_kopf();
	
	inStream = fopen( argv[1], "r" ); do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );	
	inStream = fopen( argv[1], "r" ); for (iLauf=1;iLauf<=n_;iLauf++) fscanf( inStream, "%s",  in_[iLauf]);	fclose( inStream  );
	
	for (iLauf=1;iLauf<=n_;iLauf++) in_d1[iLauf]= atof(in_[iLauf]); //string zu double konvertierung

	x_=n_;
	
	if(atoi(argv[3]) < n_ ) //Vektorpunkte - Verringerung
	{
		if( n_/atof(argv[3]) != floor(n_/atof(argv[3])) ) //bei unteilbarkeit von n/n', einzelpunktmittelung bis zur teilbarkeit
		{
									  oo= floor(n_/atoi(argv[3]));
								   o_=oo*atoi(argv[3]);
			for (iLauf=1;iLauf<=n_-o_;iLauf++)
			{
					 in_d2[x_ - s_]=(                     in_d1[x_ - s_ ] + in_d1[x_ - s_ +1]  )  /2; //mittelung beginnend bei max

					 for (jLauf=x_ - s_-1;jLauf>= 1; jLauf--) { in_d2[jLauf]= in_d1[jLauf];    } //wertübertragung unter dem mittelungswert
				
				for (jLauf=x_ - s_+1;jLauf<= x_;jLauf++) { in_d2[jLauf]= in_d1[jLauf+1];  }  //wertübertragung über dem mittelungswert
						
												  in_d1[1]=  atof(in_[1]);      //min
				for (jLauf=2;jLauf<=x_-1;jLauf++) in_d1[jLauf]=   in_d2[jLauf]; //vektorübertragung
												  in_d1[x_]= atof(in_[n_]);     //max

				x_-=1;
				s_+=n_/10;  //mittelungswerte-positions verschiebungs schritte

				if(s_>= x_-2) s_=1; //verschubpositionsrückstellung bei erreicehn der definierten vektorendposition
			}	
		}
		
		//teilpunktauswahl
		
		x_= atoi(argv[3]);
		stp= n_/atoi(argv[3]);
		
		for (iLauf=1;iLauf<=x_;iLauf++) {              in_d2[iLauf]= in_d1[ind]; ind+=stp;} //versetzte wertauswahl
		for (iLauf=1;iLauf<=x_;iLauf++ ){in_d1[iLauf]= in_d2[iLauf];  } //vektorübertragung
	}


	if(atoi(argv[3]) > n_ ) //Vektorpunkte - Vergrösserung
	{
		x_= atoi(argv[3]);
		stp= atoi(argv[3])/n_;
		
		for (iLauf=1;iLauf<=x_;iLauf+=stp) 
		{              
			                                 in_d2[iLauf]=       in_d1[ind];
			
			for (jLauf=1;jLauf< stp;jLauf++) in_d2[iLauf+jLauf]= in_d1[ind]; //wiederholte wertinsertion
			
			ind++;
		}

		for (iLauf=1;iLauf<=x_;iLauf++ ){ in_d1[iLauf]= in_d2[iLauf]; } //vektorübertragung

		if( atof(argv[3])/n_ != floor(atof(argv[3])/n_) )//bei unteilbarkeit von n'/n, einzelpunktdehnung bis n'
		{

			s_=1;
								         cc= atoi(argv[3])/n_;
								   c_=n_*cc;
			for (iLauf=1;iLauf<=x_-c_;iLauf++)
			{
				for (jLauf=c_+_in - s_-1;jLauf>= 1;     jLauf--) { in_d2[jLauf]=        in_d1[jLauf];  } //wertübertragung unter dem dehnungswert
				
				                                                   in_d2[c_+_in - s_]= (in_d1[c_+_in - s_ -1]+in_d1[c_+_in - s_ ] )/2; //dehnung beginnend bei max
				
				for (jLauf=c_+_in - s_+1;jLauf<= c_+_in;jLauf++) { in_d2[jLauf]=        in_d1[jLauf-1];  } //wertübertragung über dem dehnungswert
						
												      in_d1[1]=      atof(in_[1]);      //min
				for (jLauf=2;jLauf<=c_+_in-1;jLauf++) in_d1[jLauf]=       in_d2[jLauf]; //vektorübertragung
												      in_d1[c_+_in]= atof(in_[n_]);     //max
				_in++;
				s_+=10;  //dehnungswerte-positions verschiebungs  schritte

				if(s_>= c_+_in-2) s_=1; //verschubpositionsrückstellung bei erreicehn der definierten vektorendposition
			}
		}
	}


	outStream = fopen( argv[2],"w" );
	if(atoi(argv[3])>1)fprintf( outStream, "%f\n",  atof(in_[1]));				  //min
	for (iLauf=2;iLauf<=x_-1;iLauf++) fprintf( outStream, "%f\n",  in_d1[iLauf]); //dateiausgabe
	if(atoi(argv[3])>0)fprintf( outStream, "%f\n",  atof(in_[n_]));               //max
	fclose( outStream ); 
	
	//getch();	
}

void _profil()
{
	printf("--------------------------------\n");
	printf("Usage: KTF2 [input] [output] [n]\n");
	printf(" [input] ......... Eingabe Datei\n");
	printf(" [output] ........ Ausgabe Datei\n");
	printf(" [n] ........... Vektorumfang n'\n");
	printf("--------------------------------\n");
	printf("KTF2 by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	//getch(); 
	
	exit(0);
}	
                 
void _kopf() 
{
	printf("\nKTF2 by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing KTF2:\n"); 
}
