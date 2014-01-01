// demo of temperature and humi... sensor
// temp and humisensor connect to A0

#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTTYPE 	DHT11					// define sensor type


const int DHTPIN = A0;

DHT dht(DHTPIN, DHTTYPE);					// object of temp&humi sensor

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);		// initialize the library with the numbers of the interface pins


void setup()
{
	dht.begin();
	lcd.begin(16, 2);
}

void loop()
{

	float h = dht.readHumidity();
	float t = dht.readTemperature();
	
	lcd.setCursor(0, 0);
	lcd.print(h);
	lcd.setCursor(0, 1);
	lcd.print(t);

}