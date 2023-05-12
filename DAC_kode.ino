
void setup() {
  //Serial.begin(115200);
  DDRD = B11110000;
  DDRB = B00001111;
}

void intToDAC(int value) {
  byte binVal = byte(value);
  PORTD = binVal << 4;
  PORTB = binVal >> 4;
}

int sig = 0;
bool rising = true;
void loop() {
  /*
  if(rising){
    sig++;
  }else{
    sig--;
  }*/
  if(sig > 314){
    sig = -314;
  }
  sig++;
  /*
  if(sig<-313 && !rising){
    rising = true;
  }
  if(sig>313 && rising){
    rising = false;
  }*/
  int output = map(sin(sig/100.0)*1000,-1000,1000,0,255);
  //Serial.println(output);
  intToDAC((sin(sig/100.0)+1)*127);
  //(sin(sig/100.0)+1)*127
  
  //delayMicroseconds(1);
}
