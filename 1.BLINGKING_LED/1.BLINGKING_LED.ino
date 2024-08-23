byte LED = LED_BUILTIN;

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  Serial.println("MENYALA ABANGKUH");
  digitalWrite(LED,HIGH);
  delay(1000);
  Serial.println("PADAM ABANGKUH");
  digitalWrite(LED,LOW);
  delay(1000);
}
