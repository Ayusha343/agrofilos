#include <VirtualWire.h>

int RF_out = 12;
int RF_in = 11;
int aage = 9;
int peeche = 8;
int daen = 7;
int baen = 6;
int mains = 3;
int spid = A5;
int flow = A3;
int floww;
int flo;
int spidd;
int spi;
char *dat;

void setup() 
{
  vw_set_tx_pin(RF_out);
  vw_set_rx_pin(RF_in);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  pinMode(aage,INPUT);
  pinMode(peeche,INPUT);
  pinMode(daen,INPUT);
  pinMode(baen,INPUT);
  pinMode(spid,INPUT);
  pinMode(mains,OUTPUT);
  pinMode(RF_out,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  analogWrite(mains,125);
  
  spidd = analogRead(spid);
  spi = map(spidd,0,1023,0,255);
  Serial.print("Speed = ");
  Serial.println(spi);

  floww = analogRead(flow);
  flo = map(floww,0,1023,0,255);
  Serial.print("Flow = ");
  Serial.println(flo);

  if(spi >= 0 && spi <= 50)
  {
    char dat = "a";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }
  else if(spi >= 50 && spi <= 100)
  {
    char dat = "b";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }
  else if(spi >= 100 && spi <= 175)
  {
    char dat = "c";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }
  else if(spi >= 175 && spi <= 255)
  {
    char dat = "d";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }
  else if(flo >= 0 && flo <= 50)
  {
    char dat = "e";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }
  else if(flo >= 50 && flo <= 100)
  {
    char dat = "f";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }
  else if(flo >= 100 && flo <= 175)
  {
    char dat = "g";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }
  else if(flo >= 175 && flo <= 255)
  {
    char dat = "h";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }
  else if(digitalRead(aage) == 1)
  {
    char dat = "i";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }

  else if(digitalRead(peeche) == 1)
  {
    char dat = "j";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }
  
  else if(digitalRead(daen) == 1)
  {
    char dat = "k";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }
 
  else if(digitalRead(baen) == 1)
  {
    char dat = "l";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }

  else if(digitalRead(daen) == 1 && digitalRead(aage) == 1)
  {
    char dat = "m";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }

  else if(digitalRead(baen) == 1 && digitalRead(aage) == 1)
  {
    char dat = "n";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }

  else if(digitalRead(daen) == 1 && digitalRead(peeche) == 1)
  {
    char dat = "o";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }

  else if(digitalRead(baen) == 1 && digitalRead(peeche) == 1)
  {
    char dat = "p";
    vw_send((uint8_t *)dat, strlen(dat));
    vw_wait_tx();
    delay(200);
  }
  delay(200);
}
