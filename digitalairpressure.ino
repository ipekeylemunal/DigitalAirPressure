#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  if (!bmp.begin()) {
  Serial.println("Sensor Bulunamadi!!");
  while(1) {}
  }
}

void loop() {
  Serial.print("Sicaklik= ");
  Serial.print(bmp.readTemperature());
  Serial.println(" C ");
  
  Serial.print("Basinc= ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa ");

  Serial.print("Rakim= ");
  Serial.print(bmp.readAltitude());
  Serial.println(" metre ");

  Serial.print("Deniz seviyesindeki basinc (hesaplanan)= ");
  Serial.print(bmp.readSealevelPressure());
  Serial.println(" Pa ");

  Serial.print("Gercek Rakim= ");
  Serial.print(bmp.readAltitude(101500));
  Serial.println(" metre ");

  Serial.println();
  delay(2000);

}
