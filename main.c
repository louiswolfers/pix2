// PINS
int pin_recepteur = A0; // pin du recepteur radio
int pin_distance = A1; // pin du capteur de distance
int pin_moteur = 2; // pin du moteur
int pin_trappe = 4; // pin du moteur
int pin_led = 7; // pin du moteur

int valeur_recepteur = 0;
int valeur_distance = 0;

void setup()
{
	pinMode(pin_recepteur, INPUT);
	pinMode(pin_distance, INPUT);
	pinMode(pin_moteur, OUTPUT);
	pinMode(pin_trappe, OUTPUT);
	pinMode(pin_led, OUTPUT);
	Serial.begin(2400);
}

void loop()
{
	valeur_distance = analogRead(pin_distance);
	if (valeur_distance < 3) // On verifie la presence des balles
	{
		Serial.println("balles presentes");
		valeur_recepteur = analogRead(pin_recepteur);
		if (valeur_recepteur)
		{
			Serial.println("signal recu");
			digitalWrite(pin_moteur, HIGH);
			// Ouverture de la trappe?
			digitalWrite(pin_trappe, HIGH);
			delay(100);
			digitalWrite(pin_trappe, LOW);
		}
	}
	else
	{
		digitalWrite(pin_led, HIGH);
	}
}
