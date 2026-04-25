#include <SPI.h>
#include <RH_ASK.h>

RH_ASK rf315; // RF_out = 12

int forward = 3; //W 
int backward = 0; //S 
int right = 1; //D  
int left = 2; //A   
int mains = 4;
int clutch = 7;
int spid = 6;
int flow = 5;
int indi = 11;
int S0 = 15;
int S1 = 16;
int S2 = 17;
int S3 = 18;
int F0 = 8;
int F1 = 9;
int F2 = 13;
int F3 = 19;
int flowData = 0;
int speedData = 0;
int voltSens = A0;
float R1 = 26000;
float R2 = 6600 ;
float minVolt = 6.6;
float valu;
float valu1;
float vRead;

void setup()
{
    pinMode(forward,INPUT_PULLUP);
    pinMode(backward,INPUT_PULLUP);
    pinMode(right,INPUT_PULLUP);
    pinMode(left,INPUT_PULLUP);
    pinMode(spid,INPUT_PULLUP);
    pinMode(flow,INPUT_PULLUP);
    pinMode(clutch,INPUT_PULLUP);
    pinMode(voltSens,INPUT);
    pinMode(mains,OUTPUT);
	  pinMode(indi,OUTPUT);
    pinMode(S0,OUTPUT);
    pinMode(S1,OUTPUT);
    pinMode(S2,OUTPUT);
    pinMode(S3,OUTPUT);
    pinMode(F0,OUTPUT);
    pinMode(F1,OUTPUT);
    pinMode(F2,OUTPUT);
    pinMode(F3,OUTPUT);
    Serial.begin(9600);
    rf315.init();
}

void loop()
{   
	digitalWrite(mains,1);
	
	valu = analogRead(voltSens);
    valu1 = (valu * 5.0) / 1024.0;
    vRead = valu1 / (R2/(R1+R2));
     
    Serial.print("Voltage = ");
    Serial.println(vRead); 
    delay(500);
    
    if(vRead < minVolt)
     {
      digitalWrite(indi,HIGH);
      delay(500);
      digitalWrite(indi,LOW);
      delay(500);
     }
    else
     {
      digitalWrite(indi,LOW);
     }
 
	
    if (digitalRead(spid) == 0)
  {
      if (speedData == 4) 
       {
        speedData = 0;
       }
         else 
       {
        speedData++;
        delay(250);
       } 
       
    Serial.print("SpeedData = ");
    Serial.println(speedData);

  }
    if (digitalRead(flow) == 0)
  {
       if (flowData == 4) 
       {
        flowData = 0;
       }
         else 
       {
        flowData++;
        delay(250);
       }
     
      Serial.print("FlowData = ");
     Serial.println(flowData);
    
  }
     
  if (digitalRead(clutch) == 0)
  {
	  
   digitalWrite(S0,1);
   digitalWrite(S1,1);
   digitalWrite(S2,1);
   digitalWrite(S3,1);
   digitalWrite(F0,1);
   digitalWrite(F1,1);
   digitalWrite(F2,1);
   digitalWrite(F3,1);   
   delay(250);
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,0);
   digitalWrite(F0,0);
   digitalWrite(F1,0);
   digitalWrite(F2,0);
   digitalWrite(F3,0);
   delay(250);
   
  if(speedData == 0 && flowData == 0)
  {
   const char *msg = "a"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
   Serial.println(msg);
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
   const char *msg = "b"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
   Serial.println(msg);
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
   const char *msg = "c"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
   Serial.println(msg);
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
   const char *msg = "d"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
   Serial.println(msg);
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,1);
   digitalWrite(F0,1);
   digitalWrite(F1,0);
   digitalWrite(F2,0);
   digitalWrite(F3,0);
  }
  else if(speedData == 4 && flowData == 0)
  {
   speedData = 0;  
  }
  else if(speedData == 0 && flowData == 1)
  {
   const char *msg = "e"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
   Serial.println(msg);
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
   const char *msg = "f"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); Serial.print("Sent = "); Serial.println(msg);
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
   const char *msg = "g"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); Serial.print("Sent = "); Serial.println(msg);
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
   const char *msg = "h"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
    Serial.println(msg);
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,1);
   digitalWrite(F0,0);
   digitalWrite(F1,1);
   digitalWrite(F2,0);
   digitalWrite(F3,0);  
  }
  else if(speedData == 4 && flowData == 1)
  {
   speedData = 0;  
  }
  else if(speedData == 0 && flowData == 2)
  {
   const char *msg = "A"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
   Serial.println(msg);
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
   const char *msg = "B"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
   Serial.println(msg);
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
   const char *msg = "C"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); Serial.print("Sent = "); Serial.println(msg);
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
   const char *msg = "D"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
   Serial.println(msg);
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,1);
   digitalWrite(F0,0);
   digitalWrite(F1,0);
   digitalWrite(F2,1);
   digitalWrite(F3,0);   
  }
  else if(speedData == 4 && flowData == 2)
  {
   speedData = 0;  
  }
  else if(speedData == 0 && flowData == 3)
  {
   const char *msg = "E"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
   Serial.println(msg);
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
   const char *msg = "F"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
   Serial.println(msg);
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
   const char *msg = "G"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
   Serial.println(msg);
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
   const char *msg = "H"; 
   rf315.send((uint8_t *)msg, strlen(msg)); 
   rf315.waitPacketSent(); 
   Serial.print("Sent = "); 
   Serial.println(msg);
   digitalWrite(S0,0);
   digitalWrite(S1,0);
   digitalWrite(S2,0);
   digitalWrite(S3,1);
   digitalWrite(F0,0);
   digitalWrite(F1,0);
   digitalWrite(F2,0);
   digitalWrite(F3,1); 
  }
  else if(speedData == 4 && flowData == 3)
  {
   speedData = 0;  
  }
  else if(speedData == 0 && flowData == 4)
  {
   flowData = 0;
  }
  else if(speedData == 1 && flowData == 4)
  {
	  flowData = 0;
  }
  else if(speedData == 2 && flowData == 4)
  {
	  flowData = 0;
  }
  else if(speedData == 3 && flowData == 4)
  {
	  flowData = 0;
  }	  
  else if(speedData == 4 && flowData == 4)
  {
	  speedData = 0;
	  flowData = 0;
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
    const char *msg = "i"; 
    rf315.send((uint8_t *)msg, strlen(msg)); 
    rf315.waitPacketSent(); 
    Serial.print("Sent = "); 
    Serial.println(msg);
  }

  else if(digitalRead(backward) == 0 && digitalRead(forward) == 1 && digitalRead(left) == 1 && digitalRead(right) == 1)
  {
    const char *msg = "j"; 
    rf315.send((uint8_t *)msg, strlen(msg));
    rf315.waitPacketSent(); 
    Serial.print("Sent = "); 
    Serial.println(msg);
  }
  
  else if(digitalRead(right) == 0 && digitalRead(backward) == 1 && digitalRead(left) == 1 && digitalRead(forward) == 1)
  {
    const char *msg = "k"; 
    rf315.send((uint8_t *)msg, strlen(msg)); 
    rf315.waitPacketSent(); 
    Serial.print("Sent = "); 
    Serial.println(msg);
  }
 
  else if(digitalRead(left) == 0 && digitalRead(backward) == 1 && digitalRead(right) == 1 && digitalRead(forward) == 1)
  {
    const char *msg = "l"; 
    rf315.send((uint8_t *)msg, strlen(msg)); 
    rf315.waitPacketSent(); 
    Serial.print("Sent = "); 
    Serial.println(msg);
  }

  else if(digitalRead(right) == 0 && digitalRead(forward) == 0 && digitalRead(backward) == 1 && digitalRead(left) == 1)
  {
    const char *msg = "m"; 
    rf315.send((uint8_t *)msg, strlen(msg)); 
    rf315.waitPacketSent(); 
    Serial.print("Sent = "); 
    Serial.println(msg);
  }

  else if(digitalRead(left) == 0 && digitalRead(forward) == 0 && digitalRead(backward) == 1 && digitalRead(right) == 1)
  {
    const char *msg = "n"; 
    rf315.send((uint8_t *)msg, strlen(msg)); 
    rf315.waitPacketSent(); 
    Serial.print("Sent = "); 
    Serial.println(msg);
  }

  else if(digitalRead(right) == 0 && digitalRead(backward) == 0 && digitalRead(forward) == 1 && digitalRead(left) == 1)
  {
    const char *msg = "o"; 
    rf315.send((uint8_t *)msg, strlen(msg));
    rf315.waitPacketSent(); 
    Serial.print("Sent = "); 
    Serial.println(msg);
  }

  else if(digitalRead(left) == 0 && digitalRead(backward) == 0 && digitalRead(forward) == 1 && digitalRead(right) == 1)
  {
    const char *msg = "p";
    rf315.send((uint8_t *)msg, strlen(msg)); 
    rf315.waitPacketSent(); 
    Serial.print("Sent = "); 
    Serial.println(msg);
  }
  if(digitalRead(left) == 1 && digitalRead(backward) == 1 && digitalRead(forward) == 1 && digitalRead(right) == 1)
  {
    const char *msg = "T";
    rf315.send((uint8_t *)msg, strlen(msg)); 
    rf315.waitPacketSent(); 
    Serial.print("Sent = "); 
    Serial.println(msg); 
  }
}
