# ConsoleApp_Matrix
Console applications for matrix *calculation* and *tools* (German).

## AMA

Addiert oder subtrahiert 2 Matrizen

$$k_1=k_2\text { und } n_1=n_2$$

wird vorausgesetzt.

- Übernahme 2er ASCII Matrixdateien. 
- Ausgabe einer ASCII Matrixdatei.

Handhabung
~~~
AMA [matrix1] [matrix2] [output] [mode] 
[matrix1] ... Eingabe Datei 1
[matrix2] ... Eingabe Datei 2
[output]  ... Ausgabe Datei
[mode] ...... (0):Addition (1):Subtraktion
~~~

## IMA

Berechnet die inverse $\mathbfit A ^{-1}$ von $\mathbfit A$ über die verkettete Form 
des Gaussschen Algorithmus 

$$k_{max}=n_{max}= 200,a_{11}\ne0.$$

Es resultieren 2 Dreiecksmatrizen $\mathbfit B$ und $\mathbfit C$, sowie die Matrix $\mathbfit T$ 
zur erzeugten Einheitsmatrix $\mathbfit E$, $\mathbfit A^{-1}$ entsteht transponiert:

    . . .  A  1 0 0 E
    . . .     0 1 0
    . . .     0 0 1
    
    . . .  B  . . . T
      . .     . . .
        .     . . .
    .      C
    . .

    . . . (1/A)'
    . . .
    . . .

- Übernahme einer quadratischen ASCII Matrixdatei. 
- Ausgabe einer quadratischen ASCII Matrixdatei.

Handhabung
~~~
IMA [matrix] [output] 
[matrix] ... Eingabe Datei
[output] ... Ausgabe Datei
~~~
## MMA

Multipliziert 2 Matrizen ($k_1=n_2$ wird vorausgesetzt).
Es resultiert eine Matrix mit 

$$n=n_1,\text{ }k=k_2:$$

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

Handhabung
~~~
MMA [matrix1] [matrix2] [output] 
[matrix1] ... Eingabe Datei 1
[matrix2] ... Eingabe Datei 2
[output]  ... Ausgabe Datei
~~~

## QMA

Quadriert eine quadratische Matrix:

         *       =
     o .   o o      o o
     o .   . .      o .
 
- Übernahme einer quadratischen ASCII Matrixdateien. 
- Ausgabe einer quadratischen ASCII Matrixdatei.

Handhabung
~~~
QMA [matrix] [matrix] [output] 
[matrix] ... Eingabe Datei 
[output] ... Ausgabe Datei
~~~

## SMA

Selegiert eine Sub Matrix (oder einen Vektor) aus einer Matrix.

- Übernahme einer ASCII Matrixdatei. 
- Ausgabe einer ASCII (Matrix-)Datei.

Handhabung
~~~
SMA [matrix] [output] [i0] [i1] [j0] [j1]
[matrix] ................. Matrix Datei
[output] ................. Matrix Ausgabe Datei
[i0] ..................... von Zeile
[i1] ..................... bis Zeile
[j0] ..................... von Spalte
[j1] ..................... bis Spalte
~~~

## SPUR

Berechnet die Spur (*sp*) einer quadratischen Matrix $\mathbfit A$:

     o . .  A
     . o .  
     . . o
          sp A

- Übernahme einer quadratischen ASCII Matrixdatei. 
- Ausgabe von *sp* $\mathbfit A$ in die Datei `SPUR.txt`.

Handhabung
~~~
SPUR [matrix] [mode] 
[matrix] ... Eingabe Datei
[mode] ..... Art der Spurberechnung:
(0): Addition der Diagonalelemente (Standard)
(1): Multiplikation der Diagonalelemente (siehe Determinante, `VMA.exe`)
(2): Subtraktion der Diagonalelemente
(3): Division der Diagonalelemente
~~~

## TRP

Transponiert eine Datenmatrix 

$$n_{max}= k_{max}= 1299.$$

Spaltentrennzeichen, Eingabedatei: Tabulator oder Leerzeichen.
Spaltentrennzeichen, Ausgabedatei: 1 Leerzeichen.

- Übernahme einer ASCII Datenmatrixdatei. 
- Ausgabe einer transponierten ASCII Datenmatrixdatei.

Handhabung
~~~
TRP [input] [output] 
[inpup] .... Eingabe Datei
[output] ... Ausgabe Datei
~~~

## VMA

Berechnet die verkettete Form des Gaussschen Algorithmus 
einer quadratischen Matrix $\mathbfit A$, mit 

$$k_{max}=n_{max}= 250,a_{11}\ne0.$$

Es resultieren 2 Dreiecksmatrizen $\mathbfit B$ und $\mathbfit C$:

     . . .  A
     . . .  
     . . .
    
     . . .  B
       . .
         .
     .      C
     . .

Die Determinante von $\mathbfit A$ (det $\mathbfit A)$ ist das Produkt der Elemente in der Hauptdiagonale von $\mathbfit B$ ($\mathbfit{TT} b_{ii}$).

- Übernahme einer quadratischen ASCII Matrixdatei. 
- Ausgabe einer quadratischen ASCII Matrixdatei.

Handhabung
~~~
VMA [matrix] [output] 
[matrix] ... Eingabe Datei
[output] ... Ausgabe Datei
~~~

## ZMA

Multipliziert eine Matrix mit einer reellen Zahl.

- Übernahme einer ASCII Matrixdatei. 
- Ausgabe einer ASCII Matrixdatei.

Handhabung
~~~
ZMA [matrix] [output] [wert} 
[matrix] ... Eingabe Datei
[output] ... Ausgabe Datei
[wert] ..... Reelle Zahl
~~~

## ENT

Führt eine symmetrische entwobene Aufteilung einer Datenvektordatei $\mathbfit x_0$ durch:

     x0
     --
     1
     2	
     3
     4

     x1 x2
     -- -- 
     1
        2
     3 
        4 

- Übernahme einer einspaltigen ASCII Datei. 
- Ausgabe von 2 einspaltigen ASCII Dateien.

Handhabung
~~~
ENT [input] [output1] [output2]
[input] ..... Eingabe Datei
[output1] ... Ausgabe Datei 1
[output2] ... Ausgabe Datei 2 
~~~

## KTF

Verringert oder vergrössert den Umfang eines perfekt linearen Datenvektors. Die bis $n'$ iterative Datenanpassung erfolgt über 
	
$$x_i[n]= x_i[n+1]⋅\frac{n}{n-1}; n'\lt n,$$
$$x_i[n]= x_i[n-1]⋅\frac{n-2}{n-1} ; n'\gt n.$$

- Übernahme einer einspaltigen, aufsteigend geordneten ASCII Datenvektordatei im Umfang $n$. 
- Ausgabe einer einspaltigen, aufsteigend geordneten ASCII Datenvektordatei im Umfang $n'$.

Handhabung
~~~
KTF [input] [output] [n] 
[input] ... Eingabe Datei 
[output] .. Ausgabe Datei 
[n] ....... Vektorumfang n'
~~~

## KTF2

Verringert oder vergrössert den Umfang eines Datenvektors ($n_{max}= n'_{max}= 33000$). 

- Übernahme einer einspaltigen, aufsteigend geordneten ASCII Datenvektordatei im Umfang $n$. 
- Ausgabe einer einspaltigen, aufsteigend geordneten ASCII Datenvektordatei im Umfang $n'$.

Handhabung
~~~
KTF2 [input] [output] [n] 
[input] ... Eingabe Datei 
[output] .. Ausgabe Datei 
[n] ....... Vektorumfang n' 
~~~

## KTF3

Passt einen Datenvektor an ein Ziel-Koordinatensystem an. 
Die Datenanpassung erfolgt über
	
$$x_i'=min_x+《[(min_x-x_{min})-(min_x-x_i)]⋅\frac{max_x-min_x}{(min_x-x_{min})-(min_x-x_{max})}》$$

bei einer Wertinvertierung errechnet man $x''_i$ über
	
$$x''_i = (min_x+max_x) - x'_i,$$
mit

$min_x$  ... Wert des Minimalpunktes im Ziel-Koordinatensystem  
$max_x$ .... Wert des Maximalpunktes im Ziel-Koordinatensystem  
$x_{min}$ .. Vektor Minimalwert  
$x_{max}$ .. Vektor Maximalwert  

- Übernahme einer einspaltigen, aufsteigend geordneten ASCII Datenvektordatei. 
- Ausgabe einer zweispaltigen, aufsteigend geordneten ASCII Datenmatrixdatei beinhaltend: 
~~~
Den an das Ziel-Koordinatensystem angepassten Datenvektor. 
Den ursprünglichen Datenvektor. 
~~~
Handhabung
~~~
KTF3 [input] [output] [minx] [maxx] [inv]
[input] ... Eingabe Datei 
[output] .. Ausgabe Datei 
[minx] .... Wert des Minimalpunktes im Ziel-Koordinatensystem
{maxx] .... Wert des Maximalpunktes im Ziel-Koordinatensystem
[inv] ..... 1: Wertinvertierung 0: Keine Wertinvertierung
~~~

## NTF

Erzeugt einen aufsteigend geordneten linearen Datenvektor und passt diesen an ein Ziel-Koordinatensystem an. 
Die Datenanpassung erfolgt über

$$x_i'=min_x+《[(min_x-x_{min})-(min_x-x_i)]⋅\frac{max_x-min_x}{(min_x-x_{min})-(min_x-x_{max})}》$$

bei einer Wertinvertierung errechnet man $x_i''$ über
	
$$x''_i = (min_x+max_x) - x'_i,$$
mit

$min_x$ .... Wert des Minimalpunktes im Ziel-Koordinatensystem  
$max_x$ .... Wert des Maximalpunktes im Ziel-Koordinatensystem  
$x_{min}$ .. Vektor Minimalwert  
$x_{max}$ .. Vektor Maximalwert  

 - Ausgabe einer einspaltigen, aufsteigend geordneten linearen ASCII Datenvektordatei.

Handhabung
~~~
NTF [output] [minn] [maxn] [min] [max] [inv]
[output] ........................... Ausgabe Datei
[minn] ............................. n Minimalwert
[minn] ............................. n Maximalwert
[min] ........... Koordinaten Minimalpositionswert
[max] ........... Koordinaten Maximalpositionswert
[inv] ............ 1:invertiert 0:nicht invertiert
~~~

## SEL

Selegiert einen Datenvektor aus einer Datenmatrix 

$$n_{max}= 33000.$$

- Übernahme einer ASCII Datenmatrixdatei. 
- Ausgabe einer einspaltigen ASCII Datenvektordatei.

Handhabung
~~~
SEL [input] [output] [a] [k] 
[input] ... Eingabe Datei 
[output] .. Ausgabe Datei 
[a] ....... Vektornummer 
[k] ....... Vektoranzahl 
~~~

## SRT

Sortiert einen Datenvektor

$$n_{max}= 33000,$$

16 stellige Ausgabe. 

- Übernahme einer einspaltigen ASCII Datenvektordatei. 
- Ausgabe einer sortierten einspaltigen ASCII Datenvektordatei. 

Handhabung
~~~
SRT [input] [output] [[d]] 
[input] ... Eingabe Datei 
[output] .. Ausgabe Datei 
[d] ....... optional 1: absteigende Sortierung 
~~~

## SRT1

Verkettet 2 sortierte Datenvektoren mit
Filestream Verarbeitung, $n_{max} \rightarrow \infty$.

- Übernahme von zwei aufsteigend sortierten einspaltigen ASCII Datenvektordateien. 
- Ausgabe einer sortierten einspaltigen ASCII Datenvektordatei. 

Handhabung
~~~
SRT1 [input1] [input2] [output] 
[input1] ... Eingabe Datei 1
[input2] ... Eingabe Datei 2
[output] ... Ausgabe Datei 
~~~

## SRT2

Sortiert einen Datenvektor
    
$$n_{max}= 33000.$$

Die Datensortierung erfolgt über iterativen Paarvergleich 
    
$$i \text{ vs. } i+1$$

und Paartausch 

$$i > i+1.$$

(langsamer als `SRT.EXE`) 

- Übernahme einer einspaltigen ASCII Datenvektordatei. 
- Ausgabe einer sortierten einspaltigen ASCII Datenvektordatei. 

Handhabung
~~~
SRT2 [input] [output] [[d]] 
[input] ... Eingabe Datei 
[output] .. Ausgabe Datei 
[d] ....... optional 1: absteigende Sortierung 
~~~
## SRT3

Sortiert einen Datenvektor

$$n_{max}= 33000,$$

max. 8-Stellen. 

Sehr schnelle Berechnung durch Umsetzung der C-eigenen `Qsort` Funktion.

- Übernahme einer einspaltigen ASCII Datenvektordatei. 
- Ausgabe einer sortierten einspaltigen ASCII Datenvektordatei. 

Handhabung
~~~
SRT3 [input] [output] [[d]] 
[input] ... Eingabe Datei 
[output] .. Ausgabe Datei 
[d] ....... optional 1: absteigende Sortierung
~~~

## V2V

Fügt 2 einspaltige ASCII Dateien aneinander ($n_1=n_2$ wird vorausgesetzt).

- Übernahme von 2 einspaltigen ASCII Dateien. 
- Ausgabe einer zweispaltigen ASCII Datei.

Handhabung
~~~
V2V [input1] [input2] [output] [tab] 
[input1] ... Eingabe Datei 1
[input2] ... Eingabe Datei 2
[output] ... Ausgabe Datei 
[tab] ...... Spalten Trennzeichen (0):Tabulator (1):Leerzeichen (*):ein beliebiger String
~~~

## Z2Z

Fügt zwei ASCII Dateien aneinander.

- Übernahme zweier ASCII Dateien. 
- Ausgabe einer ASCII Datei.

Handhabung
~~~
Z2Z [input1] [input2] [output] 
[input1] ... Eingabe Datei 1
[input2] ... Eingabe Datei 2
[output] ... Ausgabe Datei
~~~
