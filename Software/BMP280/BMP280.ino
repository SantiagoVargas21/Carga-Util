#include <time.h>
#include <Adafruit_BMP280.h>

void LecturaBMP1();
void LecturaBMP2();
void LecturaBMP3();

Adafruit_BMP280 bmp1, bmp2, bmp3;
uint8_t add;
int s0=19,s1=18,s2=5,s3=4;
//bool state=LOW;
long tiempo = 0;
long ant_tiempo = 0, ant_tiempo2 = 0, ant_tiempo3 = 0, ant_tiempo4=0;
long atraso = 150;

void setup() {
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);

  digitalWrite(s0,LOW);
  digitalWrite(s1,LOW);
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW); 

  Serial.begin(38400);
  Serial.println("Iniciando: ");
 
  // El multiplexor empieza con 0000
  if (bmp1.begin(0x76)) { // 0x76 o 0x77
    Serial.println("Dispositivo BMP 1 encontrado en 0x76");
  }else if(bmp1.begin(0x77)){
    Serial.println("Dispositivo BMP 1 encontrado en 0x77");
  }else{
    Serial.println("Dispositivo BMP 1 no encontrado");
  }

  digitalWrite(s0,HIGH); // 0000 -> 0001
  if (bmp2.begin(0x76)) { // 0x76 o 0x77
    Serial.println("Dispositivo BMP 2 encontrado en 0x76");
  }else if(bmp2.begin(0x77)){
    Serial.println("Dispositivo BMP 2 encontrado en 0x77");
  }else{
    Serial.println("Dispositivo BMP 2 no encontrado");
  }

  digitalWrite(s1,HIGH); // 0001 -> 0011
  digitalWrite(s0,LOW); // 0011 -> 0010
  if (bmp3.begin(0x76)) { // 0x76 o 0x77
    Serial.println("Dispositivo BMP 3 encontrado en 0x76");
  }else if(bmp3.begin(0x77)){
    Serial.println("Dispositivo BMP 3 encontrado en 0x77");
  }else{
    Serial.println("Dispositivo BMP 3 no encontrado");
  }
  digitalWrite(s1,LOW); // 0010 -> 0000
}

void loop() {
  tiempo = millis();
  
  if ((tiempo - ant_tiempo) >= atraso) {
    ant_tiempo = tiempo;
    LecturaBMP1();
    LecturaBMP2();
    LecturaBMP3();
  }

  /*
  LecturaBMP1();
  digitalWrite(s0,HIGH);
  delay(500);
  LecturaBMP2();
  digitalWrite(s1,HIGH);
  digitalWrite(s0,LOW); 
  delay(500);
  LecturaBMP3();
  digitalWrite(s1,LOW); 
  delay(500);
  */
}

void LecturaBMP1(){
  digitalWrite(s0,LOW);
  digitalWrite(s1,LOW); 

  Serial.print("\nAltura: ");
  Serial.print(bmp1.readAltitude());
  Serial.println(" metros");

  Serial.print("Presion: ");
  Serial.print(bmp1.readPressure());
  Serial.println(" hPa");

  //Serial.print("Temperatura: ");
  //Serial.print(bmp1.readTemperature());
  //Serial.println(" °C");
}

void LecturaBMP2(){
  digitalWrite(s0,HIGH); // 0000 -> 0001
  digitalWrite(s1,LOW);

  Serial.print("\nAltura: ");
  Serial.print(bmp2.readAltitude());
  Serial.println(" metros");

  Serial.print("Presion: ");
  Serial.print(bmp2.readPressure());
  Serial.println(" hPa");

  //Serial.print("Temperatura: ");
  //Serial.print(bmp2.readTemperature());
  //Serial.println(" °C");
}

void LecturaBMP3(){
  digitalWrite(s0,LOW);
  digitalWrite(s1,HIGH);

  Serial.print("\nAltura: ");
  Serial.print(bmp3.readAltitude());
  Serial.println(" metros");

  Serial.print("Presion: ");
  Serial.print(bmp3.readPressure());
  Serial.println(" hPa");

  //Serial.print("Temperatura: ");
  //Serial.print(bmp3.readTemperature());
  //Serial.println(" °C");
}