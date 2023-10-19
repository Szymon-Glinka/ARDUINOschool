unsigned long t, t1, t2, t3, v_time, lastBTNpress;
bool lightON_btn1 = false;
volatile unsigned long tBTN1;
volatile int btn_1 = HIGH;
volatile int btn_2 = HIGH;
int prevBTNstate = LOW, btn_state = LOW, buttonState = 0;
int run = 1, potRead = 0, pwmPot = 0, pwmLed = 9;

void setup(){
  Serial.begin(9600);

  for(int i=4; i<=11; i++)
    pinMode(i, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(A0, INPUT);

  t1 = millis();
  t2 = millis();
  t3 = millis();
  v_time = millis();
  
  //pin to listen to, function, FALLING/RISING - when to run the program or sth
  attachInterrupt(digitalPinToInterrupt(2), inter_btn1, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), inter_btn2, FALLING);
}

void inter_btn1(){
  btn_1 = LOW;
  tBTN1 = millis();
}

void inter_btn2(){
  if(millis() - lastBTNpress > 50)
    btn_2 = LOW;
  lastBTNpress = millis();
}

void loop(){
  //two lights on auto
  t = millis();
  if(t-t1 > 223)
    digitalWrite(5, HIGH);
  if(t-t1 > 557){
    digitalWrite(5, LOW);
    t1 = t;
  }
  if(t-t2 > 1000)
    digitalWrite(4, HIGH);
  if(t-t2 > 2000){
    digitalWrite(4, LOW);
    t2 = t;
  }
  
  //LED button, blink button
  if(!btn_1){
    lightON_btn1 = true;
    btn_1 = HIGH;
  }
  if(t-tBTN1 < 4000 && lightON_btn1 == true){
    if(t-t3 > 100*run/2)
      digitalWrite(6, HIGH);
    if(t-t3 > 100*run){
      digitalWrite(6, LOW);
      t3 = t;
      run++;      
    }
  }
  else if(t-tBTN1 > 4000){
    digitalWrite(6, LOW);
    lightON_btn1 = false;
    run = 1;
  }

  
  //LED button, toggle button
  buttonState = digitalRead(8);
  if(!buttonState && prevBTNstate){
    if(btn_state){
      digitalWrite(7, LOW);
      btn_state = LOW;

    }
    else{
      digitalWrite(7, HIGH);
      btn_state = HIGH;
    }
  }
  prevBTNstate = buttonState;
  

  //pwm LED's
  potRead = analogRead(A0);
  pwmPot = potRead/4;
  analogWrite(pwmLed, pwmPot);
  
  if(!btn_2){
    btn_2 = HIGH;
    Serial.println("Clicked");
    pwmLed++;
    if(pwmLed == 12)
      pwmLed = 9;    
  }  
}