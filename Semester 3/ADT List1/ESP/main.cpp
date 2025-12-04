/* WOKWI 1 — SENSOR ROOM (ESP32)
   Broker: test.mosquitto.org (Mosquitto Test Broker)
   Port  : 1883 (MQTT TCP)
*/
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 15
#define PIRPIN 4
#define DHTTYPE DHT22

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "192.168.1.154";   // 🟢 UDAH DIUBAH KE MOSQUITTO

DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastPublish = 0;
bool currentAutoState = false; // last automatic decision (true=ON)

void callback(char* topic, byte* payload, unsigned int length) {
  String msg;
  for (unsigned int i=0;i<length;i++) msg += (char)payload[i];

  Serial.print("[MQTT] ");
  Serial.print(topic);
  Serial.print(" => ");
  Serial.println(msg);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting MQTT...");
    if (client.connect("WOKWI1_SENSOR_ROOM")) { 
      Serial.println("connected");

      client.subscribe("ac/mode");
      client.subscribe("ac/manual_control");
    } 
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 1s");
      delay(1000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(PIRPIN, INPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  client.setServer(mqtt_server, 1883);  // 🟢 MOSQUITTO PORT 1883
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  unsigned long now = millis();
  if (now - lastPublish >= 1500) {
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    int pir = digitalRead(PIRPIN);

    if (!isnan(t) && !isnan(h)) {
      client.publish("room/suhu", String(t,1).c_str());
      client.publish("room/kelembapan", String(h,1).c_str());
      Serial.printf("Publik suhu=%.1fC hum=%.1f%%\n", t, h);
    } 
    else {
      Serial.println("Gagal membaca DHT");
    }

    client.publish("room/pir", String(pir).c_str());
    Serial.print("PIR="); Serial.println(pir);

    // LOGIKA OTOMATIS
    bool shouldOn = false;
    if (pir == HIGH) shouldOn = true;
    if (!isnan(t) && t > 28.0) shouldOn = true;

    if (shouldOn != currentAutoState) {
      currentAutoState = shouldOn;
      client.publish("ac/auto_control", shouldOn ? "ON" : "OFF");
      Serial.print("ac/auto_control => ");
      Serial.println(shouldOn ? "ON" : "OFF");
    }

    lastPublish = now;
  }
}
