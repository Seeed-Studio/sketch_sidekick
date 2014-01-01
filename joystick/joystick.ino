// demo of joystick and rgb led
// x+ r   x- g y+(y-) b
// button connect to D2
// joystick X connect to A1
// joystick Y connect to A2
// Rgb led - R connect to D3
// rgb led - G connect to D5
// rgb led - B connect to D6


#define STSET       0                                   // setting
#define STDONE      1                                   // work

const int pinX    =  A1;
const int pinY    =  A0;

const int pinR    = 3;
const int pinG    = 9;
const int pinB    = 10;


int originX = 0;
int originY = 0;

int color_r = 0;
int color_g = 0;
int color_b = 0;


// get value of analog
int getAnalog(int pin)
{

    int sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(pin);
    }
    
    return sum >> 5; 
}

void makeRGB()
{

    int x = getAnalog(pinX) - originX;
    int y = getAnalog(pinY) - originY;
    
    if(x < 0)
    {
        x = -x;
        color_r = map(x, 0, 280, 255, 0);
    }
    else if(x > 0)
    {
        color_g = map(x, 0, 280, 255, 0);
    }
    else
    {
        color_r = 255;
        color_g = 255;
    }
    
    y = abs(y);
    
    color_b = map(y, 0, 280, 255, 0);
    
    analogWrite(pinR, color_r);
    analogWrite(pinG, color_g);
    analogWrite(pinB, color_b);
}

void setup()
{   

    originX = getAnalog(pinX);
    originY = getAnalog(pinY);
    
    pinMode(pinR, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinB, OUTPUT);

}

void loop()
{
	makeRGB();
	delay(10);
}