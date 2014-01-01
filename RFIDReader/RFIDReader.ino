// demo of rfid control arduino on board led
// rfid reader rx connect to D2, tx connect to D3


#include <SoftwareSerial.h>

SoftwareSerial SoftSerial(2, 3);

const int LED = 13;

unsigned char buffer[64];                       // buffer array for data recieve over serial port
int count=0;                                    // counter for buffer array

int state_led = 0;
void setup()
{
    SoftSerial.begin(9600);                     // the SoftSerial baud rate
    Serial.begin(9600);                         // the Serial port of Arduino baud rate.
    pinMode(LED, OUTPUT);
    
}


void loop()
{

    if (SoftSerial.available())                 // if date is comming from softwareserial port ==> data is comming from SoftSerial shield
    {
        while(SoftSerial.available())           // reading data into char array
        {
            buffer[count++]=SoftSerial.read();  // writing data into array
            if(count == 64)break;
        }
        
        Serial.write(buffer,count);             // if no data transmission ends, write buffer to hardware serial port
        clearBufferArray();                     // call clearBufferArray function to clear the storaged data from the array
        count = 0;                              // set counter of while loop to zero

        state = 1-state;
        
        digitalWrite(LED, state);               // led on or off
    }
    
    if (Serial.available())                     // if data is available on hardwareserial port ==> data is comming from PC or notebook
    {
        SoftSerial.write(Serial.read());        // write it to the SoftSerial shield
    }
}


void clearBufferArray()                         // function to clear buffer array
{
    for (int i=0; i<count;i++)
    { buffer[i]=NULL;}                          // clear all index of array with command NULL
}