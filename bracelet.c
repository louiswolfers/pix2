#include <RH_ASK.h> // Librairie RadioHead pour le recepteur-emetteur radio
#include <SPI.h> // Librairie necessaire a RadioHead pour compiler

RH_ASK rf_driver; // Initialisation de l'objet rf_driver pour recevoir des donnees par radio

void setup() {
  // put your setup code here, to run once:
  rf_driver.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t msg = 1;
  rf_driver.send((uint8_t *) msg, strlen(msg));
  rf_driver.waitPacketSent();
  delay(1000);
}