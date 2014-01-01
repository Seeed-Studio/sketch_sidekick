// ir send test
// Infrared Emitter connect to D3

#include <IRSendRev.h>

const int Button = 7;
const int irFreq = 38;                      

unsigned char dtaSend[] = {9, 90, 91, 11, 31, 4, 1, 2, 3, 4};

void setup()
{
    pinMode(Button, INPUT);
}

void loop()
{
    if(digitalRead(Button))                 // button press
    {
        IR.Send(dtaSend, irFreq);           // send data
        delay(20);
        while(digitalRead(Button));         // while button release
    }
}