#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Ble.h"

Ble::Ble(SoftwareSerial *ss)
{
	_btSerial = ss;
}

void Ble::bStart(int baud){
   delay (1000);
  _btSerial -> begin(baud);
}

void Ble::bWrite(const String data)
{
	_btSerial -> print(data);
}

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