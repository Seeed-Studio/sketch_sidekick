#include <IRSendRev.h>

void setup()
{
    Serial.begin(38400);
    IR.Init(A0);
    Serial.println("init over");
}

unsigned char dta[20];

void loop()
{
    if(IR.IsDta())
    {
        IR.Recv(dta);
    }
    
}
