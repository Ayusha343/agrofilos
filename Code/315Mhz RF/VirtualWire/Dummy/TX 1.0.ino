#include <VirtualWire.h>
#include <string.h>

const int led_pin = 11;
const int transmit_pin = 1;

void setup()
{

  vw_set_tx_pin(transmit_pin);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  Serial.begin(9600;
}



char buff[0];

void loop()
{
    buff[0]='\0';
    char buff="a";   
    Serial.print("Mess= "); 
    Serial.println(buff);
    digitalWrite(led_pin, HIGH);
    vw_send((byte *)buff, strlen(buff));
    vw_wait_tx();
    digitalWrite(led_pin, LOW);
    delay(1000);
  
}
