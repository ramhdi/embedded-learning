#include <Arduino.h>

unsigned int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, 1);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Hello, world! ");
  Serial.println(i);
  digitalWrite(LED_BUILTIN, i%2);
  i++;
  delay(1000);
}