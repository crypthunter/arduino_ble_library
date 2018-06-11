#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Ble.h"

Ble::Ble(SoftwareSerial *ss)
{
	_btSerial = ss;
}

//inizializza la seriale bluetooth
//baud: velocità di trasmissione
void Ble::bStart(int baud){
   delay (1000);
  _btSerial -> begin(baud);
}

//scrive una stringa sulla seriale bluetooth
void Ble::bWrite(const String data)
{
	_btSerial -> print(data);
}

//legge dalla seriale bluetooth finchè ci sono dati disponibili
//restituisce un unica stringa contenente tutti i dati letti
String Ble::bRead()
{
	String s;
	while (_btSerial -> available() > 0)
	{
		char received = _btSerial -> read();
		s = s + received;
	}

	return s;
}