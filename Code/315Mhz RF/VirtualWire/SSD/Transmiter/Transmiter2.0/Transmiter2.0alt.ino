#include <VirtualWire.h>

int RFout = 1;
int forward = 6;  //2830 red
int backward = 8; //2224 black
int right = 9;    //1921 white
int left = 7;     //2527 mitti
int mains = 3;
int speedPot = A5;
int flowPot = A3;
int flow;
int flowData;
int spidd;
int speedData;
char *dat;

void setup() 
{
  vw_set_tx_pin(RF_out);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  pinMode(forward,INPUT);
  pinMode(backward,INPUT);
  pinMode(right,INPUT);
  pinMode(left,INPUT);
  pinMode(speedPot,INPUT);
  pinMode(flowPot,INPUT);
  pinMode(mains,OUTPUT);
  pinMode(RF_out,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  analogWrite(mains,125);
  
  spidd = analogRead(speedPot);
  speedData = map(spidd,0,1023,0,3);
  Serial.print("Speed = ");
  Serial.println(speedData);

  flow = analogRead(flowPot);
  flowData = map(flow,0,1023,0,3);
  Serial.print("Flow = ");
  Serial.println(flowData);

  if(speedData == 0)
  {
    char dat = "a";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }
  else if(speedData == 1)
  {
    char dat = "b";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }
  else if(speedData == 2)
  {
    char dat = "c";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }
  else if(speedData == 3)
  {
    char dat = "d";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }
  else if(flowData == 0)
  {
    char dat = "e";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }
  else if(flowData == 1)
  {
    char dat = "f";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }
  else if(flowData == 2)
  {
    char dat = "g";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }
  else if(flowData == 3)
  {
    char dat = "h";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }
  
  if(digitalRead(forward) == 1)
  {
    char dat = "i";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }

  else if(digitalRead(backward) == 1)
  {
    char dat = "j";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }
  
  else if(digitalRead(right) == 1)
  {
    char dat = "k";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }
 
  else if(digitalRead(left) == 1)
  {
    char dat = "l";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }

  else if(digitalRead(right) == 1 && digitalRead(forward) == 1)
  {
    char dat = "m";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }

  else if(digitalRead(left) == 1 && digitalRead(forward) == 1)
  {
    char dat = "n";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }

  else if(digitalRead(right) == 1 && digitalRead(backward) == 1)
  {
    char dat = "o";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }

  else if(digitalRead(left) == 1 && digitalRead(backward) == 1)
  {
    char dat = "p";
    vw_send((uint8_t *)dat, strlen(dat)+1);
    vw_wait_tx();
    delay(200);
  }
  delay(200);
}
