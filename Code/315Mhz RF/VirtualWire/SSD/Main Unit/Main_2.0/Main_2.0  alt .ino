#include <VirtualWire.h>

int RF_in = 0;     //
int rForward = 9;  //IN1 blue  IN1 and IN2 belong to Motor A
int rBackward = 8;  //IN2 purple
int lForward = 7;   //IN3 gay IN3 and IN4 belong to Motor B
int lBackward = 6;  //IN4 white
int ENA = 10;       //left green wheel
int ENB = 5;       //right black wheel
int indi = 4;    //red battery indi13
int onIndi = 3;      //mitti 5
int pump = 2;      //19
int voltSens = A0;
float valu;
int spid;
int flow;
float R1 = 30000;
float R2 = 7500;
int turn;
int i;
float valu1;
float vRead;
float minVolt = 10.7;

void setup()
{
    pinMode(rForward,OUTPUT);
    pinMode(rBackward,OUTPUT);
    pinMode(lForward,OUTPUT);
    pinMode(lBackward,OUTPUT);
    pinMode(onIndi,OUTPUT);
    pinMode(voltSens,INPUT);   
    Serial.begin(9600);
    vw_set_rx_pin(RF_in);
    vw_set_ptt_inverted(true);
    vw_setup(2000);
    vw_rx_start();
    analogWrite(onIndi,125);
}

void loop()
{
  
      
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
      
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    
  if (vw_get_message(buf, &buflen))
  {
	
      buf[buflen]='/0';

      for (i = 0; i < buflen; i++)
    {
      Serial.print("Got : ");
      Serial.println((char*)buf);
    
     if(buf[i]=='a')
      {
       spid = 0;
       Serial.print("Speed =");
       Serial.print(spid);
       Serial.println("");
      }

     else if(buf[i]=='b')
      {
       spid = 75;
       Serial.print("Speed = ");
       Serial.print(spid);
       Serial.println("");
      }

     else if(buf[i]=='c')
      {
       spid = 125;
       Serial.print("Speed = ");
       Serial.print(spid);
       Serial.println("");
      }

     else if(buf[i]=='d')
      {
       spid = 255;
       Serial.print("Speed = ");
       Serial.print(spid);
       Serial.println("");
      }

     if(buf[i]=='e')
      {
       flow = 0;
       analogWrite(pump,flow);
       Serial.print("Flow = ");
       Serial.print(flow);
       Serial.println("");
      }

     else if(buf[i]=='f')
      {
       flow = 75;
       analogWrite(pump,flow);
       Serial.print("Flow = ");
       Serial.print(flow);
       Serial.println("");
      }

     else if(buf[i]=='g')
      {
       flow = 125;
       analogWrite(pump,flow);
       Serial.print("Flow = ");
       Serial.print(flow);
       Serial.println("");
      }

     else if(buf[i]=='h')
      {
       flow = 255;
       analogWrite(pump,flow);
       Serial.print("Flow = ");
       Serial.print(flow);
       Serial.println("");       
      }
     turn = spid - 50;
     if (buf[i]=='i')
      { 
      w();
      }
      
     else if (buf[i]=='j')
      {
      s();
      }
      
     else if (buf[i]=='k')
      {
      d();
      }

     else if (buf[i]=='l')
      {
      a();
      }

     else if (buf[i]=='m')
      {
      wd();
      }
  
     else if (buf[i]=='n')
      {
      wa();
      }

    else if (buf[i]=='o')
      {
      sd();
      }

    else if (buf[i]=='p')
      {
      sa();
      }
    else
      {
        digitalWrite(rForward,0);
        digitalWrite(rBackward,0);
        digitalWrite(lForward,0);
        digitalWrite(lBackward,0);
      }
    }
  }
}

void w(){
   analogWrite(ENA,spid);
   analogWrite(ENB,spid);
   digitalWrite(rForward,1);
   digitalWrite(rBackward,0);
   digitalWrite(lForward,1);
   digitalWrite(lBackward,0);
}

void s(){
   analogWrite(ENA,spid);
   analogWrite(ENB,spid);
   digitalWrite(rForward,0);
   digitalWrite(rBackward,1);
   digitalWrite(lForward,0);
   digitalWrite(lBackward,1);
}

void a(){
   analogWrite(ENA,spid);
   analogWrite(ENB,spid);
   digitalWrite(rForward,0);
   digitalWrite(rBackward,1);
   digitalWrite(lForward,1);
   digitalWrite(lBackward,0);
}

void d(){
   analogWrite(ENA,spid);
   analogWrite(ENB,spid);
   digitalWrite(rForward,1);
   digitalWrite(rBackward,0);
   digitalWrite(lForward,0);
   digitalWrite(lBackward,1);
}

void wa(){
   analogWrite(ENA,spid);
   analogWrite(ENB,turn);
   digitalWrite(rForward,1);
   digitalWrite(rBackward,0);
   digitalWrite(lForward,1);
   digitalWrite(lBackward,0);
}

void wd(){
   analogWrite(ENA,turn);
   analogWrite(ENB,spid);
   digitalWrite(rForward,1);
   digitalWrite(rBackward,0);
   digitalWrite(lForward,1);
   digitalWrite(lBackward,0);
}

void sa(){
   analogWrite(ENA,spid);
   analogWrite(ENB,turn);
   digitalWrite(rForward,1);
   digitalWrite(rBackward,0);
   digitalWrite(lForward,1);
   digitalWrite(lBackward,0);
}

void sd(){
   analogWrite(ENA,turn);
   analogWrite(ENB,spid);
   digitalWrite(rForward,1);
   digitalWrite(rBackward,0);
   digitalWrite(lForward,1);
   digitalWrite(lBackward,0);
}
