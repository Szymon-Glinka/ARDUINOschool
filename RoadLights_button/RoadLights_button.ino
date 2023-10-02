const int button_1 = 2;
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
unsigned long t0, t1, t2, t3, t4, t5, t6, t7;
int button1 = 0;
int button2 = 0;
uint8_t button_prev1;
uint8_t button_prev2;

void setup() {
  Serial.begin(9600);

  for(int i=3; i<=13; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  button_prev1 = digitalRead(button_1);
  button_prev2 = digitalRead(button_2);

  t1 = 1000;
  t2 = 2000;
  t3 = 3000;
  t4 = 7000;
  t5 = 8000;
  t6 = 9000;
  t7 = 10000;
  t0 = 14000;
}  

void loop() {
  if(millis() == t1){
    streetLights(1, 0, 0, 1, 0, 1, 0, 0, 1, 0); //all red, delay t1
    t1 = millis()+14000;   
  } 
  else if(millis() == t2){
    streetLights(1, 1, 0, 1, 0, 1, 0, 0, 1, 0); //road1 R+Y
    t2 = millis()+14000;
  }
  else if(millis() == t3){
    streetLights(0, 0, 1, 1, 0, 1, 0, 0, 1, 0); //road1 G
    t3 = millis()+14000;
    if(button1 >= 1){
      streetLights(0, 0, 1, 1, 0, 1, 0, 0, 0, 1);
      button1 = 0;
    }   
  }
  else if(millis() == t4){
    streetLights(0, 1, 0, 1, 0, 1, 0, 0, 1, 0); //road1 Y
    t4 = millis()+14000;   
  }
  else if(millis() == t5){
    streetLights(1, 0, 0, 1, 0, 1, 0, 0, 1, 0); //all red
    t5 = millis()+14000;    
  }
  else if(millis() == t6){
    streetLights(1, 0, 0, 1, 0, 1, 1, 0, 1, 0); //road2 R+Y
    t6 = millis()+14000;    
  }
  else if(millis() == t7){
    streetLights(1, 0, 0, 1, 0, 0, 0, 1, 1, 0); //road2 G
    t7 = millis()+14000;
    if(button2 >= 1){
      streetLights(1, 0, 0, 0, 1, 0, 0, 1, 1, 0);
      button2 = 0;
    }   
  }    
  else if(millis() == t0){
    streetLights(1, 0, 0, 1, 0, 0, 1, 0, 1, 0); //road2 Y
    t0 = millis()+14000;
  }
  
  if(digitalRead(button_1) == HIGH && button_prev1 == LOW){
    button1++;
    Serial.println("bt1 clicked");    
  }
  button_prev1 = digitalRead(button_1);

  if(digitalRead(button_2) == HIGH && button_prev2 == LOW){
    button2++;
    Serial.println("bt2 clicked");
  }  
  button_prev2 = digitalRead(button_2);

}

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
