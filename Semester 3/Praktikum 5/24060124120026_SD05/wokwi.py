# mqtt_dht_rpi.py
# Versi Python dari sketch ESP: baca DHT22, publish ke MQTT, subscribe untuk kontrol LED.
# Instal: pip install paho-mqtt Adafruit_DHT RPi.GPIO
# Jalankan di Raspberry Pi (atau Linux) dengan DHT22 terpasang.

import time
import uuid
import socket
import Adafruit_DHT
import paho.mqtt.client as mqtt
import RPi.GPIO as GPIO

# ---------- Konfigurasi ----------
DHT_SENSOR = Adafruit_DHT.DHT22
DHT_PIN = 4                 # BCM pin untuk data DHT22 (ganti jika perlu)
LED_PIN = 18                # BCM pin untuk LED (ganti jika perlu)
MQTT_BROKER = "broker.hivemq.com"
MQTT_PORT = 1883
PUBLISH_INTERVAL = 2       # detik, sesuai kode Arduino (2000 ms)
TOPIC_TEMP = "iotfrontier/temperature"
TOPIC_HUM = "iotfrontier/humidity"
TOPIC_COMMAND = "iotfrontier/mqtt"   # topik yang disubscribe (callback)
TOPIC_ANNOUNCE = "iotfrontier/mqtt" # digunakan sketch Arduino untuk publish awal
# ---------------------------------

# Setup GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN, GPIO.OUT)
# LED active low pada sketch ESP (LOW = on). Di RPi asumsi active HIGH (True = on).
# Jika LED Anda aktif low, invert_led = True
INVERT_LED = False

def led_set(on: bool):
    if INVERT_LED:
        GPIO.output(LED_PIN, GPIO.LOW if on else GPIO.HIGH)
    else:
        GPIO.output(LED_PIN, GPIO.HIGH if on else GPIO.LOW)

def make_client_id():
    return "python-mqtt-" + uuid.uuid4().hex[:8]

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT broker.")
        client.subscribe(TOPIC_COMMAND)
        # Publish announcement similar to Arduino
        client.publish(TOPIC_ANNOUNCE, "iotfrontier", qos=1, retain=False)
    else:
        print("Failed to connect, rc=", rc)

def on_message(client, userdata, msg):
    payload = msg.payload.decode(errors="ignore")
    print(f"Message arrived [{msg.topic}] {payload}")
    if len(payload) > 0:
        # sesuai sketch ESP: jika char pertama '1' => nyalakan LED
        if payload[0] == '1':
            print("Turning LED ON (from MQTT message).")
            led_set(True)
        else:
            print("Turning LED OFF (from MQTT message).")
            led_set(False)

def read_dht():
    humidity, temperature = Adafruit_DHT.read_retry(DHT_SENSOR, DHT_PIN)
    if humidity is None or temperature is None:
        return None, None
    # Sesuaikan pembulatan seperti pada sketch
    return round(temperature, 2), round(humidity, 1)

def safe_publish(client, topic, payload, qos=0, retain=False):
    try:
        client.publish(topic, payload, qos=qos, retain=retain)
    except Exception as e:
        print("Publish error:", e)

def main():
    client_id = make_client_id()
    client = mqtt.Client(client_id=client_id)
    client.on_connect = on_connect
    client.on_message = on_message

    # Jika broker punya auth, aktifkan baris berikut:
    # client.username_pw_set("username", "password")

    try:
        client.connect(MQTT_BROKER, MQTT_PORT, keepalive=60)
    except (socket.error, OSError) as e:
        print("Could not connect to MQTT broker:", e)
        return

    client.loop_start()

    last_publish = 0
    try:
        while True:
            now = time.time()
            if now - last_publish >= PUBLISH_INTERVAL:
                last_publish = now
                temp, hum = read_dht()
                if temp is not None and hum is not None:
                    print(f"Temperature: {temp} °C, Humidity: {hum} %")
                    safe_publish(client, TOPIC_TEMP, str(temp), qos=1)
                    safe_publish(client, TOPIC_HUM, str(hum), qos=1)
                else:
                    print("Failed to read DHT sensor — skipping publish.")
                    safe_publish(client, "iotfrontier/status", "sensor_read_error", qos=1)
            time.sleep(0.1)

    except KeyboardInterrupt:
        print("Stopping by user.")
    finally:
        safe_publish(client, "iotfrontier/status", "offline", qos=1, retain=True)
        client.loop_stop()
        client.disconnect()
        GPIO.cleanup()

if __name__ == "__main__":
    main()
