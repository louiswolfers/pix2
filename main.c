// Librairies
#include "Ultrasonic.h"

// PINS
int pin_recepteur = 6; // pin du recepteur radio
int pin_distance_sig = 7; // pin sig du capteur de distance
int pin_relay = 4; // pin du module de relais
int pin_interrupteur = 8;
int pin_led = 2; // pin de la led

int valeur_recepteur = 0;
int valeur_interrupteur = 0;

Ultrasonic ultrasonic(pin_distance_sig);

void setup() {
	pinMode(pin_recepteur, INPUT);
	pinMode(pin_relay, OUTPUT);
	pinMode(pin_led, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	long RangeInCentimeters;
	RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
	RangeInCentimeters = 4;
	Serial.print(RangeInCentimeters);//0~400cm
	Serial.println(" cm");
	valeur_interrupteur = digitalRead(pin_interrupteur);
	Serial.println(valeur_interrupteur);
	if (valeur_interrupteur == 1) {
		if (RangeInCentimeters < 3) {
			digitalWrite(pin_led, HIGH);
		}
		else {
			digitalWrite(pin_led, LOW);
			valeur_recepteur = digitalRead(pin_recepteur);
			//Serial.println(valeur_recepteur);
			if (valeur_recepteur == 0) {
				digitalWrite(pin_relay, 1);
				delay(200);
			}
			else {
				digitalWrite(pin_relay, 0);
				delay(200);
			}
		}
	}
	else {
		tone(pin_interrupteur, 1000, 500);
	}
}
