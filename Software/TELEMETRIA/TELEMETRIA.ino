//#include <SPI.h>
#include <time.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_MPU6050.h>

void Inicializacion();
void LecturaBMP1();
void LecturaBMP2();
void LecturaBMP3();
void LecturaMPU();

Adafruit_BMP280 bmp1,bmp2,bmp3;
Adafruit_MPU6050 mpu;
int s0=19,s1=18,s2=5,s3=4;
unsigned long tiempo = 0;
unsigned long ant_tiempo = 0;
sensors_event_t a, g, temp;
long atraso = 150;

void setup() {
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);

  Serial.begin(57600);
  Serial.println("Iniciando: ");
  Inicializacion();
}

void loop() {
  tiempo = millis();
  if ((tiempo - ant_tiempo) >= atraso) {
    LecturaBMP1();
    LecturaBMP2();
    LecturaBMP3();
    LecturaMPU();
    ant_tiempo = tiempo; 
  }
}

void Inicializacion(){
  digitalWrite(s0,LOW);
  digitalWrite(s1,LOW);
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);

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
  
  digitalWrite(s0,HIGH); // 0010 -> 0011

  if (mpu.begin(0x68)) {
    Serial.println("Dispositivo MPU encontrado en 0x68");
    mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  }else if(mpu.begin(0x69)){
    Serial.println("Dispositivo MPU encontrado en 0x69");
    mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  }else{
    Serial.println("Dispositivo MPU no encontrado");
  }

  digitalWrite(s0,LOW); // 0011 -> 0010
  digitalWrite(s1,LOW); // 0010 -> 0000

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

void LecturaMPU(){
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);

  mpu.getEvent(&a, &g, &temp);

  Serial.print("\nAcceleracion X: ");
  Serial.print(a.acceleration.x - 10);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.print("Rotacion X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  //Serial.print("Temperature: ");
  //Serial.print(temp.temperature);
  //Serial.println(" °C");  
}
