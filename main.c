// Librairies
#include "Ultrasonic.h"

// PINS
int pin_recepteur = A0; // pin du recepteur radio
int pin_distance_sig = 7; // pin echo du capteur de distance
int pin_moteur = 2; // pin du moteur
int pin_trappe = 4; // pin du moteur
int pin_led = 10; // pin du moteur

int valeur_recepteur = 0;

Ultrasonic ultrasonic(pin_distance_sig);

void setup()
{
  pinMode(pin_recepteur, INPUT);
  pinMode(pin_distance_echo, INPUT);
  pinMode(pin_distance_trigger, OUTPUT);
  pinMode(pin_moteur, OUTPUT);
  pinMode(pin_trappe, OUTPUT);
  pinMode(pin_led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  long RangeInCentimeters;
  RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print(RangeInCentimeters);//0~400cm
  Serial.println(" cm");
  delay(250);
}
