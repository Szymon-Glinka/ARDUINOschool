#define data 3
#define latch 4
#define shift 5

int test1 = 0b0101010101010101;

void setup() {

  for(int i=3; i<6; i++) pinMode(i, OUTPUT);

}

void loop() {
  digitalWrite(latch, LOW);
  shiftOut(data, shift, MSBFIRST, test1);
  digitalWrite(latch, HIGH);
}
