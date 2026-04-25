#include <VirtualWire.h>

int RF_out = 12;
int RF_in = 11;
int aage = 10;
int peeche = 9;
int aageL = 6;
int peecheL = 5;
int mains = 7;
int batt = 8;
int pump = 3;
int voltSens = A0;
float R1 = 30000;
float R2 = 7500;
int valu;
int spid;
int flow;
int turn;
int i;
float vOUT;
float vIN;
float minVolt = 10.7;

void setup()
{
    pinMode(aage,OUTPUT);
    pinMode(peeche,OUTPUT);
    pinMode(aageL,OUTPUT);
    pinMode(peecheL,OUTPUT);
    pinMode(mains,OUTPUT);
    pinMode(RF_in,INPUT);
    pinMode(voltSens,INPUT);   
    Serial.begin(9600);
    vw_set_tx_pin(RF_out);
    vw_set_rx_pin(RF_in);
    vw_set_ptt_inverted(true);
    vw_setup(2000);
    vw_rx_start();
}

void loop()
{
    digitalWrite(mains,HIGH);
      
    valu = analogRead(voltSens);
    
    vOUT = (valu * 5.0) / 1024.0;
    vIN = vOUT / (R2/(R1+R2));
      
    Serial.print("Voltage = ");
    Serial.println(vIN);
    
    if(vIN < minVolt)
     {
      digitalWrite(batt,HIGH);
      delay(1000);
      digitalWrite(batt,LOW);
      delay(1000);
     }
    else
     {
      digitalWrite(batt,LOW);
     }
      
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    turn = spid - 50;
 
  if (vw_get_message(buf, &buflen))
   {
      
   for (i = 0; i < buflen; i++)
    {
      Serial.print("Got : ");
      Serial.println(buf[i]);
    
     if(buf[i]=='a')
      {
       spid = 0;
       Serial.print("Speed =");
       Serial.println(spid);
      }

     else if(buf[i]=='b')
      {
       spid = 75;
       Serial.print("Speed =");
       Serial.println(spid);
      }

     else if(buf[i]=='c')
      {
       spid = 125;
       Serial.print("Speed =");
       Serial.println(spid);
      }

     else if(buf[i]=='d')
      {
       spid = 255;
       Serial.print("Speed =");
       Serial.println(spid);
      }

     else if(buf[i]=='e')
      {
       flow = 0;
       analogWrite(pump,flow);
       Serial.print("Flow =");
       Serial.println(flow);
      }

     else if(buf[i]=='f')
      {
       flow = 75;
       analogWrite(pump,flow);
       Serial.print("Flow =");
       Serial.println(flow);
      }

     else if(buf[i]=='g')
      {
       flow = 125;
       analogWrite(pump,flow);
       Serial.print("Flow =");
       Serial.println(flow);
      }

     else if(buf[i]=='h')
      {
       flow = 255;
       analogWrite(pump,flow);
       Serial.print("Flow =");
       Serial.println(flow);
      }

     else if (buf[i]=='i')
      { 
       analogWrite(aage,spid);
       analogWrite(aageL,spid);
      }
      
     else if (buf[i]=='j')
      {
       analogWrite(peeche,spid);
       analogWrite(peecheL,spid);
      }
      
     else if (buf[i]=='k')
      {
       analogWrite(aageL,spid);  
       analogWrite(aage,0);
      }

     else if (buf[i]=='l')
      {
       analogWrite(aage,spid);
       analogWrite(aageL,0);
      }

     else if (buf[i]=='m')
      {
       analogWrite(aage,turn);
       analogWrite(aageL,spid);
      }
  
     else if (buf[i]=='n')
      {
       analogWrite(aageL,turn);
       analogWrite(aage,spid);
      }

    else if (buf[i]=='o')
      {
       analogWrite(peeche,turn);
       analogWrite(peecheL,spid);
      }

    else if (buf[i]=='p')
      {
       analogWrite(peecheL,turn);
       analogWrite(peeche,spid);
      }
    else
      {
        digitalWrite(aage,0);
        digitalWrite(aageL,0);
        digitalWrite(peeche,0);
        digitalWrite(peecheL,0);
      }
    }
  }
}
