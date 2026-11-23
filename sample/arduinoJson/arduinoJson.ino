#include <ArduinoJson.h>

const int led_pin = 2;
const int sensor_pin = 4;

const int threshold = 300;

StaticJsonDocument<200> doc;

void setup() {
  pinMode(led_pin, OUTPUT);
  Serial.begin(115200);
  doc["sensorValue"] = 0;
}

void loop() {
  int sensor_value = analogRead(sensor_pin);
  doc["sensorValue"] = sensor_value;

  serializeJsonPretty(doc, Serial);

  if (sensor_value >= threshold) {
    digitalWrite(led_pin, HIGH);
  }
  else {
    digitalWrite(led_pin, LOW);
  }

  delay(200);

}
