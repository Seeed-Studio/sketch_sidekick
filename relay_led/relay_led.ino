// demo of relay control led
// relay connect to D2

const int pinRelay = 2;

void setup()
{
	pinMode(pinRelay, OUTPUT);
	digitalWrite(pinRelay, LOW);
}

void loop()
{
	digitalWrite(pinRelay, HIGH);				// led on
	delay(1000);								// delay 1s
	digitalWrite(pinRelay, LOW);				// led off
	delay(1000);								// delay 1s
}