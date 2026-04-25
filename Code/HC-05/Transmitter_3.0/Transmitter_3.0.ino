#include <SoftwareSerial.h>

#define TX 1
#define RX 0

int forward = 3; //W 
int backward = 13; //S 
int right = 1; //D  
int left = 2; //A   
int mains = 4;
int clutch = 7;
int spid = 6;
int flow = 5;
int S0 = 15;
int S1 = 16;
int S2 = 17;
int S3 = 18;
int F0 = 8;
int F1 = 9;
int F2 = 10;
int F3 = 11;
int flowData = 0;
int speedData = 0;

SoftwareSerial bilu(RX,TX);

void setup()
{
    pinMode(forward,INPUT_PULLUP);
    pinMode(backward,INPUT_PULLUP);
    pinMode(right,INPUT_PULLUP);
    pinMode(left,INPUT_PULLUP);
    pinMode(spid,INPUT_PULLUP);
    pinMode(flow,INPUT_PULLUP);
    pinMode(clutch,INPUT_PULLUP);
    pinMode(mains,OUTPUT);
    pinMode(S0,OUTPUT);
    pinMode(S1,OUTPUT);
    pinMode(S2,OUTPUT);
    pinMode(S3,OUTPUT);
    pinMode(F0,OUTPUT);
    pinMode(F1,OUTPUT);
    pinMode(F2,OUTPUT);
    pinMode(F3,OUTPUT);
	pinMode(TX,OUTPUT);
	pinMode(RX,INPUT);
	Serial.begin(9600);
	bilu.begin(9600);
}

void loop()
{
	digitalWrite(mains,1);
	
 if (digitalRead(spid) == 0)
  {
    
    Serial.print("SpeedData = ");
    Serial.println(speedData);

         if (speedData == 4) 
       {
        speedData = 0;
       }
         else 
       {
        speedData++;
        delay(250);
       }
  }
    if (digitalRead(flow) == 0)
  {
    
     Serial.print("FlowData = ");
     Serial.println(flowData);
    
         if (flowData == 4) 
       {
        flowData = 0;
       }
         else 
       {
        flowData++;
        delay(250);
       }
  }
   if (digitalRead(clutch) == 0)
  {
  if(speedData == 0 && flowData == 0)
  {
   bilu.write("a"); 
   digitalWrite(S0,1);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,0);
   digitalWrite(F0,1);
   digitalWrite(F1,0);
   digitalWrite(F2,0);
   digitalWrite(F3,0);
  }
  else if(speedData == 1 && flowData == 0)
  {
   bilu.write("b"); 
   digitalWrite(S0,0);
   digitalWrite(S1,1);
   digitalWrite(S2,0);
   digitalWrite(S3,0);
   digitalWrite(F0,1);
   digitalWrite(F1,0);
   digitalWrite(F2,0);
   digitalWrite(F3,0);
  }
  else if(speedData == 2 && flowData == 0)
  {
   bilu.write("c"); 
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,1);
   digitalWrite(S3,0);
   digitalWrite(F0,1);
   digitalWrite(F1,0);
   digitalWrite(F2,0);
   digitalWrite(F3,0);
  }
  else if(speedData == 3 && flowData == 0)
  {
   bilu.write("d"); 
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,1);
   digitalWrite(F0,1);
   digitalWrite(F1,0);
   digitalWrite(F2,0);
   digitalWrite(F3,0);
  }
  else if(speedData == 0 && flowData == 1)
  {
   bilu.write("e"); 
   digitalWrite(S0,1);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,0);
   digitalWrite(F0,0);
   digitalWrite(F1,1);
   digitalWrite(F2,0);
   digitalWrite(F3,0);   
  }
  else if(speedData == 1 && flowData == 1)
  {
   bilu.write("f"); 
   digitalWrite(S0,0);
   digitalWrite(S1,1);
   digitalWrite(S2,0);
   digitalWrite(S3,0);
   digitalWrite(F0,0);
   digitalWrite(F1,1);
   digitalWrite(F2,0);
   digitalWrite(F3,0);
  }
  else if(speedData == 2 && flowData == 1)
  {
   bilu.write("g"); 
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,1);
   digitalWrite(S3,0);
   digitalWrite(F0,0);
   digitalWrite(F1,1);
   digitalWrite(F2,0);
   digitalWrite(F3,0);
   
  }
  else if(speedData == 3 && flowData == 1)
  {
   bilu.write("h"); 
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,1);
   digitalWrite(F0,0);
   digitalWrite(F1,1);
   digitalWrite(F2,0);
   digitalWrite(F3,0);  
  }
  else if(speedData == 0 && flowData == 2)
  {
   bilu.write("A"); 
   digitalWrite(S0,1);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,0);
   digitalWrite(F0,0);
   digitalWrite(F1,0);
   digitalWrite(F2,1);
   digitalWrite(F3,0);
  }
  else if(speedData == 1 && flowData == 2)
  {
   bilu.write("B"); 
   digitalWrite(S0,0);
   digitalWrite(S1,1);
   digitalWrite(S2,0);
   digitalWrite(S3,0);
   digitalWrite(F0,0);
   digitalWrite(F1,0);
   digitalWrite(F2,1);
   digitalWrite(F3,0);
  }
  else if(speedData == 2 && flowData == 2)
  {
   bilu.write("C"); 
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,1);
   digitalWrite(S3,0);
   digitalWrite(F0,0);
   digitalWrite(F1,0);
   digitalWrite(F2,1);
   digitalWrite(F3,0);   
  }
  else if(speedData == 3 && flowData == 2)
  {
   bilu.write("D"); 
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,1);
   digitalWrite(F0,0);
   digitalWrite(F1,0);
   digitalWrite(F2,1);
   digitalWrite(F3,0);   
  }
  else if(speedData == 0 && flowData == 3)
  {
   bilu.write("E"); 
   digitalWrite(S0,1);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,0);
   digitalWrite(F0,0);
   digitalWrite(F1,0);
   digitalWrite(F2,0);
   digitalWrite(F3,1);
  }
  else if(speedData == 1 && flowData == 3)
  {
   bilu.write("F"); 
   digitalWrite(S0,0);
   digitalWrite(S1,1);
   digitalWrite(S2,0);
   digitalWrite(S3,0);
   digitalWrite(F0,0);
   digitalWrite(F1,0);
   digitalWrite(F2,0);
   digitalWrite(F3,1);
  }
  else if(speedData == 2 && flowData == 3)
  {
   bilu.write("G"); 
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,1);
   digitalWrite(S3,0);
   digitalWrite(F0,0);
   digitalWrite(F1,0);
   digitalWrite(F2,0);
   digitalWrite(F3,1);  
  }
  else if(speedData == 3 && flowData == 3)
  {
   bilu.write("H"); 
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,1);
   digitalWrite(F0,0);
   digitalWrite(F1,0);
   digitalWrite(F2,0);
   digitalWrite(F3,1); 
  }
  else
  {
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,0);
   digitalWrite(F0,0);
   digitalWrite(F1,0);
   digitalWrite(F2,0);
   digitalWrite(F3,0);
  }

 }
  if(digitalRead(forward) == 0 && digitalRead(backward) == 1 && digitalRead(left) == 1 && digitalRead(right) == 1)
  {
    bilu.write("i");
  }

  else if(digitalRead(backward) == 0 && digitalRead(forward) == 1 && digitalRead(left) == 1 && digitalRead(right) == 1)
  {
    bilu.write("j");
  }
  
  else if(digitalRead(right) == 0 && digitalRead(backward) == 1 && digitalRead(left) == 1 && digitalRead(forward) == 1)
  {
    bilu.write("k");
  }
 
  else if(digitalRead(left) == 0 && digitalRead(backward) == 1 && digitalRead(right) == 1 && digitalRead(forward) == 1)
  {
    bilu.write("l");
  }

  else if(digitalRead(right) == 0 && digitalRead(forward) == 0 && digitalRead(backward) == 1 && digitalRead(left) == 1)
  {
    bilu.write("m");
  }

  else if(digitalRead(left) == 0 && digitalRead(forward) == 0 && digitalRead(backward) == 1 && digitalRead(right) == 1)
  {
    bilu.write("n");
  }

  else if(digitalRead(right) == 0 && digitalRead(backward) == 0 && digitalRead(forward) == 1 && digitalRead(left) == 1)
  {
    bilu.write("o");
  }

  else if(digitalRead(left) == 0 && digitalRead(backward) == 0 && digitalRead(forward) == 1 && digitalRead(right) == 1)
  {
    bilu.write("p");
  }
}
