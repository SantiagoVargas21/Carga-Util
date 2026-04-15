#include <SPI.h>
#include <time.h>
#include <LoRa.h>

//void Inicializacion();

#define Ra02_SCK 32
#define Ra02_MISO 33
#define Ra02_MOSI 25
#define Ra02_NSS 26

unsigned long tiempo = 0;
unsigned long ant_tiempo = 0;
long atraso = 1500;

void setup() {
  SPI.begin(Ra02_SCK, Ra02_MISO, Ra02_MOSI, Ra02_NSS);
  Serial.begin(57600);
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS);  
}

void loop() {
  tiempo = millis();
  if ((tiempo - ant_tiempo) >= atraso) {
    ant_tiempo = tiempo;
    Serial.println("hola");
  }
}

void Inicializacion(){

}
