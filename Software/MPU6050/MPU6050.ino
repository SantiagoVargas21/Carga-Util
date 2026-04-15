#include <time.h>
#include <Adafruit_MPU6050.h>

void LecturaMPU();

Adafruit_MPU6050 mpu;
int s0=19,s1=18,s2=5,s3=4;
long tiempo = 0;
long ant_tiempo = 0;
sensors_event_t a, g, temp;
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

  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  // El multiplexor empieza con 0011
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
}

void loop() {
  tiempo = millis();
  if ((tiempo - ant_tiempo) >= atraso) {
    ant_tiempo = tiempo;
    LecturaMPU();
  }
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

