byte RELAY1 = 18;
byte RELAY2 = 19;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY1,OUTPUT);
  pinMode(RELAY2,OUTPUT);
}

void loop() {
  //RELAY 1
  Serial.println("RELAY 1 ON");
  digitalWrite(RELAY1,HIGH);
  delay(1000);
  Serial.println("RELAY 1 OFF");
  digitalWrite(RELAY1,LOW);
  delay(1000);

   //RELAY 2
  Serial.println("RELAY 2 ON");
  digitalWrite(RELAY2,HIGH);
  delay(1000);
  Serial.println("RELAY 2 OFF");
  digitalWrite(RELAY2,LOW);
  delay(1000);
}
