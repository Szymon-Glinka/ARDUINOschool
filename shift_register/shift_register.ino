#define data 4
#define latch 3
#define shift 2

byte tab1[] = {
            0b11111111,
            0b10101011,
            0b10101011,
            0b11111111,
            0b01111101,
            0b10111011,
            0b11000111,
            0b11111111,
            };

byte tab2[] = {
            0b10000000,
            0b01000000,
            0b00100000,
            0b00010000,
            0b00001000,
            0b00000100,
            0b00000010,
            0b00000001,
            };
int index = 0;

void setup(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop(){
  for(int i=0; i<8; i++){
    digitalWrite(latch, LOW);
    shiftOut(data, shift, MSBFIRST, tab1[i]);
    shiftOut(data, shift, MSBFIRST, tab2[i]);
    digitalWrite(latch, HIGH);
    delay(1);
  }
}


