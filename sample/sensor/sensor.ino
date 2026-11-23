const int led_pin = 2;
const int sensor_pin = 4;

const int threshold = 300;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(sensor_pin, INPUT);
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(sensor_pin);

  Serial.print("sensor = ");
  Serial.println(sensorValue);

  if (sensorValue >= threshold) {
    digitalWrite(led_pin, HIGH);
  }
  else {
    digitalWrite(led_pin, LOW);
  }

  delay(200);

}
