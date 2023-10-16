unsigned long t, t1, t2, t3;
bool lightON_btn1 = false;
volatile unsigned long tBTN1;
volatile int btn_1 = HIGH;
volatile int btn_2 = HIGH;
volatile int btn_state = 0;

void setup(){
  Serial.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  t1 = millis();
  t2 = millis();
  t3 = millis();
  
  //pin to listen to, function, FALLING/RISING - when to run the program or sth
  attachInterrupt(digitalPinToInterrupt(2), inter_btn1, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), inter_btn2, FALLING);
}

void inter_btn1(){
  btn_1 = LOW;
  tBTN1 = millis();
}

void inter_btn2(){
  btn_2 = LOW;
  
}

void loop(){
  //two lights on auto
  t = millis();
  if(t-t1 > 223){
    digitalWrite(5, HIGH);
  }
  if(t-t1 > 557){
    digitalWrite(5, LOW);
    t1 = t;
  }
  if(t-t2 > 1000){
    digitalWrite(4, HIGH);
  }
  if(t-t2 > 2000){
    digitalWrite(4, LOW);
    t2 = t;
  }
  
  //LED button, blink button
  if(!btn_1){
    Serial.println("btn worked");
    lightON_btn1 = true;
    btn_1 = HIGH;
  }
  if(t-tBTN1 < 2000 && lightON_btn1 == true){
    if(t-t3 > 100)
      digitalWrite(6, HIGH);
    if(t-t3 > 300){
      digitalWrite(6, LOW);
      t3 = t;
    }
  }
  else if(t-tBTN1 > 2000){
    digitalWrite(6, LOW);
    lightON_btn1 = false;
  }

  //LED button, toggle button
  if(!btn_2 && btn_state == 0){
    digitalWrite(7, HIGH);
    btn_state = 1;
    btn_2 = HIGH;
  }
  if(!btn_2 && btn_state == 1){
    digitalWrite(7, LOW);
    btn_state = 0;
    btn_2 = HIGH;
  }
}
