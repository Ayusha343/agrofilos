#include <SPI.h>
#include <RH_ASK.h>
#include <String.h>

RH_ASK rf315; //RF_in = 11

int rForward = 8;  
int rBackward = 9; 
int lForward = 13;   
int lBackward = 7;   
int ENA = 5;    // Left 
int ENB = 6;     // Right  
int indi = 4;    
int onIndi = 2;    
int pump = 3;     
int spid = 0;
int flow = 0;
int turn = 0;
int pair = 15;
int led1 = 17;
int led2 = 18;
int led3 = 10;
int led4 = 12;
int i = 3;
int H2O = A5;
int voltSens = A0;
float pani;
float R1 = 30000;
float R2 = 7500;
float minVolt = 10.2;
float valu;
float valu1;
float vRead;
float minvalue = 500;
float midvalue = 450;
float maxvalue = 410;

void setup()
{
    pinMode(rForward,OUTPUT);
    pinMode(rBackward,OUTPUT);
    pinMode(lForward,OUTPUT);
    pinMode(lBackward,OUTPUT);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
    pinMode(led4,OUTPUT);
    pinMode(H2O,INPUT);
    pinMode(onIndi,OUTPUT);
    pinMode(voltSens,INPUT);  
	  pinMode(pair,OUTPUT);
    Serial.begin(9600);
    rf315.init();
}

void loop()
{  
	  digitalWrite(onIndi,HIGH);
  
   if(i == 3)
    {
      digitalWrite(pair,1);
      delay(1000);
      digitalWrite(pair,0);
      delay(1000);
    }
 
    pani = analogRead(H2O);
    Serial.print("Pani = ");
    Serial.println(pani);

    if(pani >= minvalue)
      {
        digitalWrite(led1,1);
        digitalWrite(led2,1);
        digitalWrite(led3,1);
        digitalWrite(led4,1);
        delay(100);
        digitalWrite(led1,0);
        digitalWrite(led2,0);
        digitalWrite(led3,0);
        digitalWrite(led4,0);
        delay(100);
      }
     else if(pani <= minvalue && pani > midvalue)
      {
        digitalWrite(led1,1);
        digitalWrite(led2,1);
        digitalWrite(led3,1);
        digitalWrite(led4,1);
        delay(500);
        digitalWrite(led1,0);
        digitalWrite(led2,0);
        digitalWrite(led3,0);
        digitalWrite(led4,0);
        delay(500);
      }
    else if(pani <= midvalue && pani >= maxvalue)
      {
        digitalWrite(led1,1);
        digitalWrite(led2,1);
        digitalWrite(led3,1);
        digitalWrite(led4,1);
        delay(1000);
        digitalWrite(led1,0);
        digitalWrite(led2,0);
        digitalWrite(led3,0);
        digitalWrite(led4,0);
        delay(1000);
      }
      else if(pani < maxvalue)
      {
        digitalWrite(led1,1);
        digitalWrite(led2,1);
        digitalWrite(led3,1);
        digitalWrite(led4,1);
      }
      else 
      {
        digitalWrite(led1,1);
        digitalWrite(led2,1);
        digitalWrite(led3,1);
        digitalWrite(led4,1);
      }

    valu = analogRead(voltSens);
    valu1 = (valu * 5.0) / 1024.0;
    vRead = valu1 / (R2/(R1+R2));
     
    Serial.print("Voltage = ");
    Serial.println(vRead); 
    delay(1000);
    
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
 
    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);
    
	if (rf315.recv(buf, &buflen))
	{
      
      String gott = (char*)buf;
      
	  Serial.print("Got : ");
	  Serial.println(gott);
	   
	  if(strcmp((char*)buf,"a") == 0)
      {
       spid = 0;
	   flow = 0;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);
      }
     else if(strcmp((char*)buf,"b") == 0)
      {
       spid = 153;
       flow = 0;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);
      }
     else if(strcmp((char*)buf,"c") == 0)
      {
       spid = 205;
       flow = 0;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);
      }
     else if(strcmp((char*)buf,"d") == 0)
      {
       spid = 255;
       flow = 0;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);
      }
     else if(strcmp((char*)buf,"e") == 0)
      {
       spid = 0;
       flow = 75;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);
      }
     else if(strcmp((char*)buf,"f") == 0)
      {
       spid = 153;
       flow = 75;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);
      }
     else if(strcmp((char*)buf,"g") == 0)
      {
       spid = 205;
       flow = 75;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);
      }
     else if(strcmp((char*)buf,"h") == 0)
      {
       spid = 255;
       flow = 75;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow); 
      }
     else if(strcmp((char*)buf,"A") == 0)
      {
       spid = 0;
       flow = 125;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);
      }
     else if(strcmp((char*)buf,"B") == 0)
      {
       spid = 153;
       flow = 125;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);
      }
     else if(strcmp((char*)buf,"C") == 0)
      {
       spid = 205;
       flow = 125;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow); 
      }
     else if(strcmp((char*)buf,"D") == 0)
      {
       spid = 255;
       flow = 125;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);  
      }
     else if(strcmp((char*)buf,"E") == 0)
      {
       spid = 0;
       flow = 255;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);  
      }
     else if(strcmp((char*)buf,"F") == 0)
      {
       spid = 153;
       flow = 255;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);  
      }
     else if(strcmp((char*)buf,"G") == 0)
      {
       spid = 205;
       flow = 255;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);      
      }
     else if(strcmp((char*)buf,"H") == 0)
      {
       spid = 255;
       flow = 255;
       Serial.print("Speed = ");
       Serial.println(spid);
	   Serial.print("Flow = ");
       Serial.println(flow);  
      }
     
	  turn = spid - 100;
    Serial.print("Turn = ");
    Serial.println(turn);
      analogWrite(pump,flow);
     
     if (strcmp((char*)buf,"i") == 0)
      { 
      w();
      }
     else if (strcmp((char*)buf,"j") == 0)
      {
      s();
      }
     else if (strcmp((char*)buf,"k") == 0)
      {
      d();
      }
     else if (strcmp((char*)buf,"l") == 0)
      {
      a();
      }
     else if (strcmp((char*)buf,"m") == 0)
      {
      wd();
      }
     else if (strcmp((char*)buf,"n") == 0)
      {
      wa();
      }
    else if (strcmp((char*)buf,"o") == 0)
      {
      sd();
      }
    else if (strcmp((char*)buf,"p") == 0)
      {
      sa();
      }
    else 
      { 
      gg();
	  }
    if (strcmp((char*)buf,"T") == 0)
      {
      gg();
	    digitalWrite(pair,0);
	    i = 4;
      }
   }
}

void w()
{
   analogWrite(ENA,spid);
   analogWrite(ENB,spid);
   digitalWrite(rForward,1);
   digitalWrite(rBackward,0);
   digitalWrite(lForward,1);
   digitalWrite(lBackward,0);
}

void s()
{
   analogWrite(ENA,spid);
   analogWrite(ENB,spid);
   digitalWrite(rForward,0);
   digitalWrite(rBackward,1);
   digitalWrite(lForward,0);
   digitalWrite(lBackward,1);
}

void a()
{
   analogWrite(ENA,turn);
   analogWrite(ENB,spid);
   digitalWrite(rForward,1);
   digitalWrite(rBackward,0);
   digitalWrite(lForward,0);
   digitalWrite(lBackward,1);
}

void d()
{
   analogWrite(ENA,spid);
   analogWrite(ENB,turn);
   digitalWrite(rForward,0);
   digitalWrite(rBackward,1);
   digitalWrite(lForward,1);
   digitalWrite(lBackward,0);
}

void wa()
{
   analogWrite(ENA,turn);
   analogWrite(ENB,spid);
   digitalWrite(rForward,1);
   digitalWrite(rBackward,0);
   digitalWrite(lForward,1);
   digitalWrite(lBackward,0);
}

void wd()
{
   analogWrite(ENA,spid);
   analogWrite(ENB,turn);
   digitalWrite(rForward,1);
   digitalWrite(rBackward,0);
   digitalWrite(lForward,1);
   digitalWrite(lBackward,0);
}

void sa()
{
   analogWrite(ENA,turn);
   analogWrite(ENB,spid);
   digitalWrite(rForward,0);
   digitalWrite(rBackward,1);
   digitalWrite(lForward,0);
   digitalWrite(lBackward,1);
}

void sd()
{
   analogWrite(ENA,spid);
   analogWrite(ENB,turn);
   digitalWrite(rForward,0);
   digitalWrite(rBackward,1);
   digitalWrite(lForward,0);
   digitalWrite(lBackward,1);
}

void gg()
{
	digitalWrite(rForward,0);
    digitalWrite(rBackward,0);
    digitalWrite(lForward,0);
    digitalWrite(lBackward,0);
}
