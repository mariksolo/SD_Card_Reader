#define CS 5
#define MOSI 3
#define MISO 2
#define SCLK 4

#include "timing.h"
int CLOCK_TIME = FAST;

int CMD0[8] = {0, 1, 0, 0, 0, 0, 0, 0};
int CRC[8] = {1, 0, 0, 1, 0, 1, 0, 1};

void setup() {
  pinMode(MISO, INPUT);
  pinMode(CS, OUTPUT);
  pinMode(SCLK, OUTPUT);
  pinMode(MOSI, OUTPUT);

  delay(1500);

  digitalWrite(CS, HIGH);
  digitalWrite(MOSI, HIGH);

  for (int i = 0; i < 75; i++) {
    digitalWrite(SCLK, HIGH);
    delay(CLOCK_TIME / 2.0);
    digitalWrite(SCLK, LOW);
    delay(CLOCK_TIME / 2.0);
  }

  digitalWrite(CS, LOW);
  
  for (int i = 0; i < 8; i++) {
    digitalWrite(MOSI, HIGH * CMD0[i]);
    digitalWrite(SCLK, HIGH);
    delay(CLOCK_TIME / 2.0);
    digitalWrite(SCLK, LOW);
    delay(CLOCK_TIME / 2.0);
  }

  digitalWrite(MOSI, LOW);
  
   for (int i = 0; i < 32; i++) {
    digitalWrite(SCLK, HIGH);
    delay(CLOCK_TIME / 2.0);
    digitalWrite(SCLK, LOW);
    delay(CLOCK_TIME / 2.0);
  }
  
  for (int i = 0; i < 8; i++) {
    digitalWrite(MOSI, HIGH * CRC[i]);
    digitalWrite(SCLK, HIGH);
    delay(CLOCK_TIME / 2.0);
    digitalWrite(SCLK, LOW);
    delay(CLOCK_TIME / 2.0);
  }
  
//  delay(10);
  digitalWrite(MOSI, HIGH);

  CLOCK_TIME = SLOW;
  for (int i = 0; i < 72; i++) {
    Serial.print(digitalRead(MISO));
    digitalWrite(SCLK, HIGH);
    delay(CLOCK_TIME / 2.0);
    digitalWrite(SCLK, LOW);
    delay(CLOCK_TIME / 2.0);
  }
  CLOCK_TIME = FAST;

  
}

void loop(void) {
//  Serial.print(digitalRead(MISO));
//  digitalWrite(SCLK, HIGH);
////  Serial.print(digitalRead(MISO));
//  delay(CLOCK_TIME / 2.0);
//  Serial.print(digitalRead(MISO));
//  digitalWrite(SCLK, LOW);
////  Serial.print(digitalRead(MISO));
//  delay(CLOCK_TIME / 2.0);

for (int i = 0; i < 8; i++) {
    digitalWrite(MOSI, HIGH * CMD0[i]);
    digitalWrite(SCLK, HIGH);
    delay(CLOCK_TIME / 2.0);
    digitalWrite(SCLK, LOW);
    delay(CLOCK_TIME / 2.0);
  }

  digitalWrite(MOSI, LOW);
  
   for (int i = 0; i < 32; i++) {
    digitalWrite(SCLK, HIGH);
    delay(CLOCK_TIME / 2.0);
    digitalWrite(SCLK, LOW);
    delay(CLOCK_TIME / 2.0);
  }
  
  for (int i = 0; i < 8; i++) {
    digitalWrite(MOSI, HIGH * CRC[i]);
    digitalWrite(SCLK, HIGH);
    delay(CLOCK_TIME / 2.0);
    digitalWrite(SCLK, LOW);
    delay(CLOCK_TIME / 2.0);
  }
  
//  delay(10);
  digitalWrite(MOSI, HIGH);

  
  CLOCK_TIME = SLOW;
  for (int i = 0; i < 72; i++) {
    Serial.print(digitalRead(MISO));
    digitalWrite(SCLK, HIGH);
    delay(CLOCK_TIME / 2.0);
    digitalWrite(SCLK, LOW);
    delay(CLOCK_TIME / 2.0);
  }
  CLOCK_TIME = FAST;

}
