// Librairies
#include <RH_ASK.h> // Librairie RadioHead pour le recepteur-emetteur radio
#include <SPI.h> // Librairie necessaire a RadioHead pour compiler

// PINS
int pin_bouton = 7;

int valeur_bouton = 0;

// Initialisation de l'objet rf_driver pour recevoir des donnees par radio
RH_ASK rf_driver;

void setup() {
  rf_driver.init();
  pinMode(pin_bouton, INPUT);
}

void loop() {
  valeur_bouton = digitalRead(pin_bouton);
  if (valeur_bouton != 0)
  {
    uint8_t msg = 1;
    rf_driver.send((uint8_t *) msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
  }
}
