int latchPin=11;
int clockPin=9;
int dataPin=12;
int dt=250;

byte LED1s=0b00000000;

void setup() {
  pinMode(clockPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,LED1s);
  digitalWrite(latchPin,HIGH);
  delay(dt);
  Serial.println(LED1s,BIN);
  LED1s=LED1s+1;

  if(LED1s>255){
    LED1s=0;
  }

}
