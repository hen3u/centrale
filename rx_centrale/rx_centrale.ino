#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";
int led_red = 6;

void setup() {
  Serial.begin(9600);
    
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
  pinMode(led_red, OUTPUT);
}

void loop() {

  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    if(strcmp(text,"Hello World")==0){
      digitalWrite(led_red, HIGH);
      delay(1000);
    }
  }
  digitalWrite(led_red, LOW);
  delay(1000);
}
