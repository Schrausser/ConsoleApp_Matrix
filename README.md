# ConsoleApp_Matrix
Console applications for matrix calculation and tools (German):

## AMA

Addiert oder subtrahiert 2 Matrizen

     k1=k2, n1=n2 

wird vorausgesetzt.

- Übernahme 2er ASCII Matrixdateien. 
- Ausgabe einer ASCII Matrixdatei.
  
## IMA

Berechnet die inverse 1/A von A über die verkettete Form 
des Gaussschen Algorithmus 

     k_max=n_max= 200,a11<>0.

Es resultieren 2 Dreiecksmatrizen B und C, sowie die Matrix T 
zur erzeugten Einheitsmatrix E, 1/A entsteht transponiert. 

    . . .  A  1 0 0 E
    . . .     0 1 0
    . . .     0 0 1
    
    . . .  B  . . . T
      . .     . . .
        .     . . .
    .      C
    ..

    . . . (1/A)'
    . . .
    . . .

- Übernahme einer quadratischen ASCII Matrixdatei. 
- Ausgabe einer quadratischen ASCII Matrixdatei.
  
## MMA

Multipliziert 2 Matrizen (k1=n2 wird vorausgesetzt).
Es resultiert eine Matrix mit 

     n=n1 und k=k2.    

           *          =
     o . .   o o         o o
     o . .   . .         o .
             . .
     
     
     o . .   o o         o o
     o . .   . .         o .
     o . .   . .         o .    
     o . .               o .
     o . .               o .
     
     
     o . .   o o o o o   o o o o o 
     o . .   . . . . .   o . . . . 
             . . . . .


- Übernahme 2er ASCII Matrixdateien. 
- Ausgabe einer ASCII Matrixdatei.

## QMA

Quadriert eine quadratische Matrix.

         *       =
     o .   o o      o o
     o .   . .      o .
 
- Übernahme einer quadratischen ASCII Matrixdateien. 
- Ausgabe einer quadratischen ASCII Matrixdatei.

## SMA

Selegiert eine Sub Matrix (oder einen Vektor) aus einer Matrix.

- Übernahme einer ASCII Matrixdatei. 
- Ausgabe einer ASCII (Matrix-)Datei.

## SPUR

Berechnet die Spur (sp) einer quadratischen Matrix A.

- Übernahme einer quadratischen ASCII Matrixdatei. 
- Ausgabe von sp A in die Datei 'SPUR.txt'.

## TRP

Transponiert eine Datenmatrix 

     n_max= k_max= 1299. 

Spaltentrennzeichen, Eingabedatei: Tabulator oder Leerzeichen.
Spaltentrennzeichen, Ausgabedatei: 1 Leerzeichen.

- Übernahme einer ASCII Datenmatrixdatei. 
- Ausgabe einer transponierten ASCII Datenmatrixdatei.

## VMA

Berechnet die verkettete Form des Gaussschen Algorithmus 
einer quadratischen Matrix A 

     k_max=n_max= 250,a11<>0.

Es resultieren 2 Dreiecksmatrizen B und C. Die Determinante von A (det A) ist das Produkt der Elemente in der Hauptdiagonale von B (TT bii).

- Übernahme einer quadratischen ASCII Matrixdatei. 
- Ausgabe einer quadratischen ASCII Matrixdatei.

## ZMA

Multipliziert eine Matrix mit einer reellen Zahl.

- Übernahme einer ASCII Matrixdatei. 
- Ausgabe einer ASCII Matrixdatei.
  
## ENT

Führt eine symmetrische entwobene Aufteilung einer Datenvektordatei x0 durch.

- Übernahme einer einspaltigen ASCII Datei. 
- Ausgabe von 2 einspaltigen ASCII Dateien.

## KTF

Verringert oder vergrössert den Umfang eines perfekt linearen Datenvektors. Die bis n' iterative Datenanpassung erfolgt über 
	
	xi[n]= xi[n+1](n/(n-1)) bei n'< n,
	xi[n]= xi[n-1]((n-2)/(n-1)) bei n' > n.

- Übernahme einer einspaltigen, aufsteigend geordneten ASCII Datenvektordatei im Umfang n. 
- Ausgabe einer einspaltigen, aufsteigend geordneten ASCII Datenvektordatei im Umfang n'. 

## KTF2

Verringert oder vergrössert den Umfang eines Datenvektors (n_max= n'_max= 33000). 

- Übernahme einer einspaltigen, aufsteigend geordneten ASCII Datenvektordatei im Umfang n. 
- Ausgabe einer einspaltigen, aufsteigend geordneten ASCII Datenvektordatei im Umfang n'.

## KTF3

Passt einen Datenvektor an ein Ziel-Koordinatensystem an. 
Die Datenanpassung erfolgt über
	
      x'[i] = minx+(((minx-x[min])-(minx-x[i]))*((maxx-minx)/((minx-x[min])-(minx-x[max])))),

bei einer Wertinvertierung errechnet man x''[i] über
	
      x''[i] = (minx+maxx) - x'[i],
mit

      minx  ... Wert des Minimalpunktes im Ziel-Koordinatensystem
      maxx .... Wert des Maximalpunktes im Ziel-Koordinatensystem
      x[min] .. Vektor Minimalwert
      x[max] .. Vektor Maximalwert   

- Übernahme einer einspaltigen, aufsteigend geordneten ASCII Datenvektordatei. 
- Ausgabe einer zweispaltigen, aufsteigend geordneten ASCII Datenmatrixdatei beinhaltend:

      Den an das Ziel-Koordinatensystem angepassten Datenvektor. 
      Den ursprünglichen Datenvektor. 

## NTF

Erzeugt einen aufsteigend geordneten linearen Datenvektor und passt diesen an ein Ziel-Koordinatensystem an. 
Die Datenanpassung erfolgt über
	
     x'[i] = minx+(((minx-x[min])-(minx-x[i]))*((maxx-minx)/((minx-x[min])-(minx-x[max])))),

bei einer Wertinvertierung errechnet man x''[i] über
	
     x''[i] = (minx+maxx) - x'[i],
mit

     minx .... Wert des Minimalpunktes im Ziel-Koordinatensystem
     maxx .... Wert des Maximalpunktes im Ziel-Koordinatensystem
     x[min] .. Vektor Minimalwert
     x[max] .. Vektor Maximalwert   

 - Ausgabe einer einspaltigen, aufsteigend geordneten linearen ASCII Datenvektordatei.

## SEL

Selegiert einen Datenvektor aus einer Datenmatrix 

     n_max= 33000. 

- Übernahme einer ASCII Datenmatrixdatei. 
- Ausgabe einer einspaltigen ASCII Datenvektordatei. 

## SRT

Sortiert einen Datenvektor

     n_max= 33000, 16 stellige Ausgabe. 

- Übernahme einer einspaltigen ASCII Datenvektordatei. 
- Ausgabe einer sortierten einspaltigen ASCII Datenvektordatei. 

## SRT2

Sortiert einen Datenvektor
    
     n_max= 33000.

Die Datensortierung erfolgt über iterativen Paarvergleich 
    
     (i vs. i+1) 

und Paartausch 

     (i > i+1).

(langsamer als SRT.EXE) 

- Übernahme einer einspaltigen ASCII Datenvektordatei. 
- Ausgabe einer sortierten einspaltigen ASCII Datenvektordatei. 

## SRT3

Sortiert einen Datenvektor

     n_max= 33000, max 8-Stellen. 

Sehr schnelle Berechnung durch Umsetzung der C-eigenen 'Qsort' Funktion.

- Übernahme einer einspaltigen ASCII Datenvektordatei. 
- Ausgabe einer sortierten einspaltigen ASCII Datenvektordatei. 

## V2V

Fügt 2 einspaltige ASCII Dateien aneinander (n1=n2 wird vorausgesetzt).

- Übernahme von 2 einspaltigen ASCII Dateien. 
- Ausgabe einer zweispaltigen ASCII Datei.

## Z2Z

Fügt zwei ASCII Dateien aneinander.

- Übernahme zweier ASCII Dateien. 
- Ausgabe einer ASCII Datei.
