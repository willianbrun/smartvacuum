#include <IRremote.h>
const int irReceiverPin = 7;
IRrecv irrecv(irReceiverPin);
decode_results results;
IRsend irsend;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.print("irCode HEX: ");
    Serial.print(results.value, HEX);
    Serial.print(" irCode DEC: ");
    Serial.print(results.value, DEC);
    Serial.print(", bits: ");
    Serial.println(results.bits);
    irrecv.resume();
  }  
  delay(250);
  
  int result = Serial.parseInt();
  if (result == 1) {
    irsend.sendNEC(0xF740BF, 32);
  }
}
