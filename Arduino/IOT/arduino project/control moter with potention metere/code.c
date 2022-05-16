/*******************************************************************************
    Project Title: Comando robot con telecomando a infrarossi
    Author: Ing. Antonio De Feo
    Version: 1.0
    Revision Date: 18/11/2018

    This file is free software; you can redistribute it and/or modify
    it under the terms of either the GNU General Public License version 2
    or the GNU Lesser General Public License version 2.1, both as
    published by the Free Software Foundation.

   Collegamenti

   Servo per movimenti verticali    PIN 6
   Servo per movimenti orizzontali  PIN 5
   Servo per le Rotazioni           PIN 4
   Servo per muovere la Pinza       PIN 3
   input potenziometro 1 movimenti verticali        PIN A0
   input potenziometro 2 movimenti orizzontali      PIN A1
   input potenziometro 3 Rotazioni           		PIN A2
   input potenziometro 4 Pinza           			PIN A3

 *******************************************************************************/
// Controllo di 4 servo con 4 potenziometri
#include <Servo.h>         	//carica la libreria per i servomotori

Servo Verticale;        //crea un oggetto servo per controllare il servo dei mov. verticali (Su e Giù)
Servo Orizzontale;      //crea un oggetto servo per controllare il servo dei mov. orizzontali (Avanti Indietro)
Servo Rotazione;      //crea un oggetto servo per controllare il servo delle rotazioni
Servo Pinza;            //crea un oggetto servo per controllare l'apertura/chiusura della pinza

int Angolo;                	//angolo di rotazione
  	int pot1 = 0;			//Potenziometro 1 - movimenti verticali -->PIN A0
    int pot2 = 1;			//Potenziometro 2 - movimenti orizzontali -->PIN A1
    int pot3 = 2;			//Potenziometro 3 - movimenti Rotazioni -->PIN A2
    int pot4 = 3;			//Potenziometro 4 - movimenti Pinza -->PIN A3
int Pos1 ;	// Inizializza una variabile di tipo intero "valore" il cui valore sarà la posizione da impartire al servo 1.
int Pos2 ;	// Inizializza una variabile di tipo intero "valore" il cui valore sarà la posizione da impartire al servo 2.
int Pos3 ;	// Inizializza una variabile di tipo intero "valore" il cui valore sarà la posizione da impartire al servo 3.
int Pos4 ;	// Inizializza una variabile di tipo intero "valore" il cui valore sarà la posizione da impartire al servo 4.
void setup()
{
  Verticale.attach(9);     //servo movimenti verticali 	 -->PIN 9
  Orizzontale.attach(6);   //servo movimenti orizzontali -->PIN 6
  Rotazione.attach(5);     //servo movimenti Rotazioni 	 -->PIN 5
  Pinza.attach(3);     	   //servo movimenti Pinza 	 	 -->PIN 3
  Serial.begin(9600);
 }

void loop()
{
Pos1 = analogRead(pot1);// Legge il valore analogico del potenziometro 1
 
Angolo = map(Pos1,0,1023,0,180);// "Mappa" i valori di una lettura analogica (che vanno quindi da 0 a 1023) a valori che vanno da 0 a 180.
  Serial.print("pos=");
  Serial.print(Pos1); 
  Verticale.write(Angolo);//comanda il servo dei movimenti Verticali la posizione che deve raggiungere.
 Serial.print("Angolo=");
  Serial.print(Angolo);  
Pos2 = analogRead(pot2);// Legge il valore analogico del potenziometro 2
Angolo = map(Pos2,0,1023,0,180);// "Mappa" i valori di una lettura analogica (che vanno quindi da 0 a 1023) a valori che vanno da 0 a 180.
Orizzontale.write(Angolo);//comanda il servo dei movimenti Orizzontale la posizione che deve raggiungere.
  
Pos3 = analogRead(pot3);// Legge il valore analogico del potenziometro 3
Angolo = map(Pos3,0,1023,0,180);// "Mappa" i valori di una lettura analogica (che vanno quindi da 0 a 1023) a valori che vanno da 0 a 180.
Rotazione.write(Angolo); //comanda il servo delle Rotazioni la posizione che deve raggiungere.
  
Pos4 = analogRead(pot4);// Legge il valore analogico del potenziometro 4
Angolo = map(Pos4,0,1023,0,180);// "Mappa" i valori di una lettura analogica (che vanno quindi da 0 a 1023) a valori che vanno da 0 a 180.
Pinza.write(Angolo);//comanda il servo della Pinza la posizione che deve raggiungere.
delay(1000);
}
