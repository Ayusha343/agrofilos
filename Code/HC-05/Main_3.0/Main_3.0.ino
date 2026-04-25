#include <SoftwareSerial.h>
#include <String.h>

#define TX 1
#define RX 0

int rForward = 8;  
int rBackward = 9; 
int lForward = 6;   
int lBackward = 7;  
int ENA = 5;    // Left   
int ENB = 10;     // Right  
int indi = 4;    
int onIndi = 2;    
int pump = 3;     
int spid = 0;
int flow = 0;
int turn = 0;
int voltSens = A0;
float R1 = 30000;
float R2 = 7500;
float minVolt = 10.7;
float valu;
float valu1;
float vRead;

SoftwareSerial bilu(RX,TX);

void setup()
{
	pinMode(rForward,OUTPUT);
    pinMode(rBackward,OUTPUT);
    pinMode(lForward,OUTPUT);
    pinMode(lBackward,OUTPUT);
    pinMode(onIndi,OUTPUT);
    pinMode(voltSens,INPUT);   
	pinMode(TX,OUTPUT);
	pinMode(RX,INPUT);
	Serial.begin(9600);
	bilu.begin(9600);
}

void loop()
{
	digitalWrite(onIndi,HIGH);
	
	valu = analogRead(voltSens);
    valu1 = (valu * 5.0) / 1024.0;
    vRead = valu1 / (R2/(R1+R2));
     
    Serial.print("Voltage = ");
    Serial.println(vRead);
    
    if(vRead < minVolt)
     {
      digitalWrite(indi,HIGH);
      delay(1000);
      digitalWrite(indi,LOW);
      delay(1000);
     }
    else
     {
      digitalWrite(indi,LOW);
     }
 
	if (bilu.available() > 0)
	{
	
	  Serial.print("Got : ");
	  Serial.println(bilu.read());
	
     if(strcmp(bilu.read(),"a") == 0)
      {
       spid = 0;
	   flow = 0;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);
      }

     else if(strcmp(bilu.read(),"b") == 0)
      {
       spid = 75;
       flow = 0;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);
      }

     else if(strcmp(bilu.read(),"c") == 0)
      {
       spid = 125;
       flow = 0;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);
      }

     else if(strcmp(bilu.read(),"d") == 0)
      {
       spid = 255;
       flow = 0;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);
      }

     else if(strcmp(bilu.read(),"e") == 0)
      {
       spid = 0;
       flow = 75;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);
      }

     else if(strcmp(bilu.read(),"f") == 0)
      {
       spid = 75;
       flow = 75;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);
      }

     else if(strcmp(bilu.read(),"g") == 0)
      {
       spid = 125;
       flow = 75;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);
      }

     else if(strcmp(bilu.read(),"h") == 0)
      {
       spid = 255;
       flow = 75;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);      
      }
     else if(strcmp(bilu.read(),"A") == 0)
      {
       spid = 0;
       flow = 125;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);      
      }
     else if(strcmp(bilu.read(),"B") == 0)
      {
       spid = 75;
       flow = 125;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);      
      }
     else if(strcmp(bilu.read(),"C") == 0)
      {
       spid = 125;
       flow = 125;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);      
      }
     else if(strcmp(bilu.read(),"D") == 0)
      {
       spid = 255;
       flow = 125;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);      
      }
     else if(strcmp(bilu.read(),"E") == 0)
      {
       spid = 0;
       flow = 255;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);      
      }
     else if(strcmp(bilu.read(),"F") == 0)
      {
       spid = 75;
       flow = 255;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);      
      }
     else if(strcmp(bilu.read(),"G") == 0)
      {
       spid = 125;
       flow = 255;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);      
      }
     else if(strcmp(bilu.read(),"H") == 0)
      {
       spid = 255;
       flow = 255;
       Serial.println("Speed = ");
       Serial.print(spid);
	   Serial.println("Flow = ");
       Serial.print(flow);
	   analogWrite(pump,flow);      
      }
     
     turn = spid - 125;
     
     if(strcmp(bilu.read(),"i") == 0)
      { 
      w();
      }
      
     else if(strcmp(bilu.read(),"j") == 0)
      {
      s();
      }
      
     else if(strcmp(bilu.read(),"k") == 0)
      {
      d();
      }

     else if(strcmp(bilu.read(),"l") == 0)
      {
      a();
      }

     else if(strcmp(bilu.read(),"m") == 0)
      {
      wd();
      }
  
     else if(strcmp(bilu.read(),"n") == 0)
      {
      wa();
      }

     else if(strcmp(bilu.read(),"o") == 0)
      {
      sd();
      }

     else if(strcmp(bilu.read(),"p") == 0)
      {
      sa();
      }
     else
      {
      gg();
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
   digitalWrite(lBackward,0);
}

void d()
{
   analogWrite(ENA,spid);
   analogWrite(ENB,spid);
   digitalWrite(rForward,0);
   digitalWrite(rBackward,0);
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
