#include <DHT.h>


#define DHTPIN 25 
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
 Serial.begin(9600);
 dht.begin(); 
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembaban = dht.readHumidity();
  
  //POST DATA SERIAL
  Serial.print("SUHU        :"); Serial.print(suhu);        Serial.print(" C  | ");
  Serial.print("KELEMBABAN  :"); Serial.print(kelembaban);  Serial.print(" % ");
  Serial.println();
  delay(1000);
  
}
