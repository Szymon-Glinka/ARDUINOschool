#define data 2
#define latch 3
#define shift 4

long t, t1;

byte tab1[][8] = {
            {
            0b00000000,
            0b01010100,
            0b01010100,
            0b00000000,
            0b10000010,
            0b01000100,
            0b00111000,
            0b00000000,
            },
            {
            0b00000000,
            0b00000000,
            0b01010100,
            0b00000000,
            0b10000010,
            0b01000100,
            0b00111000,
            0b00000000,
            },
            {
            0b00000000,
            0b00000000,
            0b00000000,
            0b00000000,
            0b10000010,
            0b01000100,
            0b00111000,
            0b00000000,
            }
            };

byte tab_row[] = {
            0b10000000,
            0b01000000,
            0b00100000,
            0b00010000,
            0b00001000,
            0b00000100,
            0b00000010,
            0b00000001,
            };

int anim = 0;

void setup(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop(){
  t = millis();
  for(int i=0; i<8; i++){
    digitalWrite(latch, LOW);
    shiftOut(data, shift, MSBFIRST, ~tab1[anim][i]);
    shiftOut(data, shift, MSBFIRST, tab_row[i]);        
    digitalWrite(latch, HIGH);
  }
  if(t-t1>2000 && t-t1<2050) anim = 1;
  else if(t-t1>2050 && t-t1<2100) anim = 2;
  else if(t-t1>2100 && t-t1<2150) anim = 1;  
  else if(t-t1>2200){
    anim = 0;
    t1 = t;
  }

}
