// demo of rfid control arduino on board led
// rfid reader rx connect to D2, tx connect to D3

#include <SoftwareSerial.h>

const int pinLed = 13;

SoftwareSerial SoftSerial(2, 3);

unsigned char buffer[64];                               // buffer array for data recieve over serial port

int count=0;                                            // counter for buffer array
int status_led = 0;

void setup()
{
    SoftSerial.begin(9600);                             // the SoftSerial baud rate
    Serial.begin(9600);                                 // the Serial port of Arduino baud rate.
    pinMode(pinLed, OUTPUT);
}

void loop()
{
    if (SoftSerial.available())                         // if date is comming from softwareserial port ==> data is comming from SoftSerial shield
    {
        while(SoftSerial.available())                   // reading data into char array
        {
            buffer[count++]=SoftSerial.read();          // writing data into array

            if(buffer[count-1] == 0x03)                 // end
            {
                digitalWrite(pinLed, status_led);
                status_led = 1-status_led;
            }
            if(count == 64)break;
        }
        Serial.write(buffer,count);                     // if no data transmission ends, write buffer to hardware serial port
        clearBufferArray();                             // call clearBufferArray function to clear the storaged data from the array
        count = 0;                                      // set counter of while loop to zero
    }
}

void clearBufferArray()                                 // function to clear buffer array
{
    for (int i=0; i<count;i++)
    { buffer[i]=NULL;}                                  // clear all index of array with command NULL
}