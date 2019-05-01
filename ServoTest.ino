#include <Adafruit_NeoPixel.h>
#include <Servo.h>

Servo myServo;
int musclePin = A0;
int servoPin = 9;
int neoPin = 6;

const int NUMPIXELS = 500;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, neoPin, NEO_GRB + NEO_KHZ800);

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop() {
  uint32_t on = strip.Color(255, 17, 17);
  uint32_t off = strip.Color(0, 0, 10);
  int sensorValue = analogRead(musclePin);
  int mapTorque = map(sensorValue, 0, 985, 180, 10);

  strip.clear();

  if (mapTorque > 115) {
    strip.fill(off, 0, NUMPIXELS);
    myServo.write(180);
  } else {
    strip.fill(on, 0, NUMPIXELS);
    myServo.write(0);
  }

  strip.show();

  delay(100);
}
