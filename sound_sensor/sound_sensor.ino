// demo of sound sensor and led bar
// sound sensor connect to A0
// led bar connect to D2~D11


const int pinSoundSensor = A0;

// get val of analog(A0)
int getAnalog()
{
	int sum = 0;
	
	for(int i=0; i<32; i++)
	{
		sum += analogRead(pinSoundSensor);
	}
	
	return sum>>5;
}

int getSoundLevel()
{
	int val_light = getAnalog();					// get analog value
	int level = map(val_light, 0, 1023, 0, 10);		// make level
	return level;
}

// set led bar, 0-10 level. 
// 0 led for level-0 and 10 leds for level-10
void setLedBar(int lev)
{
	for(int i=2; i<=11; i++)
	{
		digitalWrite(i, LOW);
	}
	
	if(lev>0)
	{
		for(int i=0; i<lev; i++)
		{
			digitalWrite(i+2, HIGH);
		}
	}
}


void setup()
{
	for(int i=2; i<=11; i++)
	{
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
}

void loop()
{

	int level = getSoundLevel();					// get light level
	
	setLedBar(level);								// set led bar

}