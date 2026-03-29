#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10);
const byte address[6] = "NODE1";

void setup() {
  Serial.begin(115200);

  Serial.println("Testing RF-NANO...");

  if (!radio.begin()) {
    Serial.println("Radio NOT detected!");
    while (1);
  }

  radio.setChannel(108);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);

  radio.openWritingPipe(address);
  radio.stopListening(); 

  Serial.println("Transmitter ready");
  delay(1000);
}

void loop() {
  const char text[] = "Bye World";

  bool ok = radio.write(text, strlen(text) + 1);

  if (ok) Serial.println("Sent OK");
  else Serial.println("Send FAIL");

  delay(1000);
}