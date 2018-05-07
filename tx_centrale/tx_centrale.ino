#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";

const char sensor_red[] = "led_red";
const char sensor_green[] = "led_green";
const char sensor_orange[] = "led_orange";


void setup() {
  Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.setChannel(108);
  radio.stopListening();
}

void loop() {
  radio.write(&sensor_red, sizeof(sensor_red));
  delay(1000);
  radio.write(&sensor_green, sizeof(sensor_green));
  delay(1000);
  radio.write(&sensor_orange, sizeof(sensor_orange));
  delay(1000);
}
