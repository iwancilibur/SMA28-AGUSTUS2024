#include <WiFi.h>
#include <MQTT.h>

const char ssid[]       = "iotgateway"; //SSID WIFI
const char pass[]       = "iotgateway"; //PASSWORD WIFI
const char* mqtt_server = "broker.hivemq.com"; //MQTT Broker
const char* client_id   = "iwancilibur"; //Harus Unix

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("connecting...");
  while (!client.connect(client_id, "public", "public")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("connected!");
  client.subscribe("ping/iwancilibur");
  client.subscribe("iwancilibur/relay1");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("Topik: {" + topic + "} | Isi Pesan: [" + payload + "]") ;
  if(topic == "iwancilibur/relay1" && payload=="on"){
    Serial.println("RELAY MENYALA ABANGKUH");
  }
  if(topic == "iwancilibur/relay1" && payload=="off"){
    Serial.println("RELAY PADAM ABANGKUH");
  }
}

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);

  client.begin(mqtt_server, net);
  client.onMessage(messageReceived);
  connect();
}

void loop() {
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    client.publish("ping/iwancilibur", "Hello My Name Is Iwan Cilibur");
  }
}
