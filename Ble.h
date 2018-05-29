#ifndef Ble_h
#define Ble_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class Ble
{
private:
  SoftwareSerial *_btSerial;

public:
  //costruttore primario, prende come parametro un puntatore ad un oggetto software serial (da inizializzare nel fil *ino)
  Ble(SoftwareSerial *ss);
  //fa partire la seriale ble, prende come input il rate di scrittura / lettura
  void bStart(int baud);
  //legge fino a quando sono disponibili byte sul bluetooth e li mette in un' unica stringa
  String bRead();
  //scrive un dato sul bluetooth
  void bWrite(const String data);
};

#endif

