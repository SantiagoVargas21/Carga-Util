#include <time.h>
#include <Adafruit_UBX.h>

void LecturaGPS();

long tiempo = 0;
long ant_tiempo = 0;
long atraso = 150;

void setup() {
  Serial.begin(38400);
  Serial.println("Iniciando: ");
}

void loop() {
  tiempo = millis();
  if ((tiempo - ant_tiempo) >= atraso) {
    ant_tiempo = tiempo;
    LecturaGPS();
  }
}

void LecturaGPS(){
  return;
}

