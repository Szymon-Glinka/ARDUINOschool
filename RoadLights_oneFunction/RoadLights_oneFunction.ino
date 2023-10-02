const int button_1 =  2;
const int button_2 = 3;
const int road1_R = 4;
const int road1_Y = 5;
const int road1_G = 6;
const int ped1_R = 10;
const int ped1_G = 11;
const int road2_R = 7;
const int road2_Y = 8;
const int road2_G = 9;
const int ped2_R = 12;
const int ped2_G = 13;

void streetLights(int r1R, int r1Y, int r1G, int p1R, int p1G, int r2R, int r2Y, int r2G, int p2R, int p2G){
  digitalWrite(road1_R, r1R);
  digitalWrite(road1_Y, r1Y);
  digitalWrite(road1_G, r1G);
  digitalWrite(ped1_R, p1R);
  digitalWrite(ped1_G, p1G);
  digitalWrite(road2_R, r2R);
  digitalWrite(road2_Y, r2Y);
  digitalWrite(road2_G, r2G);
  digitalWrite(ped2_R, p2R);
  digitalWrite(ped2_G, p2G);
}


void setup() {
  Serial.begin(9600);

  for(int i=3; i<=13; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
  
}

void loop() {
    streetLights(1, 0, 0, 1, 0, 1, 0, 0, 1, 0);
    delay(1000);   

    streetLights(1, 1, 0, 1, 0, 1, 0, 0, 1, 0);
    delay(1000);

    streetLights(0, 0, 1, 1, 0, 1, 0, 0, 0, 1);
    delay(4000);

    streetLights(0, 1, 0, 1, 0, 1, 0, 0, 1, 0);
    delay(1000);

    streetLights(1, 0, 0, 1, 0, 1, 0, 0, 1, 0);
    delay(1000);

    streetLights(1, 0, 0, 1, 0, 1, 1, 0, 1, 0);
    delay(1000);

    streetLights(1, 0, 0, 0, 1, 0, 0, 1, 1, 0);
    delay(4000);

    streetLights(1, 0, 0, 1, 0, 0, 1, 0, 1, 0);
    delay(1000);
}

