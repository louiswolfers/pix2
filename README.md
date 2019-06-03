% Notice de montage et d'utilisation du BallBot
% 3 juin 2019
% Equipe 46

# Notice de montage
## Assemblage de la boite

## Circuit electrique

## Code informatique
Pour l'Arduino située dans le BallBot:
```c
// Librairies
#include "Ultrasonic.h" // Librairie fournie pour controler le moteur
#include <RH_ASK.h> // Librairie RadioHead pour le recepteur-emetteur radio
#include <SPI.h> // Librairie necessaire a RadioHead pour compiler

// PINS
int pin_recepteur = 6; // pin du recepteur radio
int pin_distance_sig = 7; // pin sig du capteur de distance
int pin_relay = 4; // pin du module de relais
int pin_interrupteur = 8;
int pin_led = 2; // pin de la led

int valeur_recepteur = 0;
int valeur_interrupteur = 0;

Ultrasonic ultrasonic(pin_distance_sig); // Initialisation de l'objet ultrasonic pour pouvoir controler le moteur
RH_ASK rf_driver; // Initialisation de l'objet rf_driver pour recevoir des donnees par radio

void setup() {
  pinMode(pin_recepteur, INPUT);
  pinMode(pin_relay, OUTPUT);
  pinMode(pin_led, OUTPUT);
  rf_driver.init();
  Serial.begin(9600);
}

void loop() {
  long distance;
  distance = ultrasonic.MeasureInCentimeters();
  distance = 6;
  if (distance < 5) {
    digitalWrite(pin_led, HIGH);
  }
  else {
    digitalWrite(pin_led, LOW);
    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);
    if (rf_driver.recv(buf, &buflen))
    {
      Serial.println("Activation du mecanisme de jet de balle");
    }
    if (*buf == 1) {
      digitalWrite(pin_relay, 1);
      delay(200);
    }
    else {
      digitalWrite(pin_relay, 0);
      delay(200);
    }
  }
}
```

Pour l'Arduino "bracelet"
```c
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
```
