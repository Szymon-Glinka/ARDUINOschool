unsigned long t, t1, t2, t4;
volatile unsigned long t3;
volatile int btn = HIGH;
bool lightON = false;

void setup(){
  Serial.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, INPUT_PULLUP);

  t1 = millis();
  t2 = millis();
  t4 = millis();
  
  //pin to listen to, function, FALLING/RISING - when to run the program or sth
  attachInterrupt(digitalPinToInterrupt(3), inter, FALLING);
}

void inter(){
  btn = LOW;
  t3 = millis();
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
    digitalWrite(6, HIGH);
  }
  if(t-t2 > 2000){
    digitalWrite(6, LOW);
    t2 = t;
  }
  
  //LED "on" button
  if(!btn){
    lightON = true;
    btn = HIGH;
  }
  if(t-t3 < 2000 && lightON == true){
    if(t-t4 > 200)
      digitalWrite(4, HIGH);
    if(t-t4 > 400){
      digitalWrite(4, LOW);
      t4 = t;
    }
  }
  else if(t-t3 > 2000){
    digitalWrite(4, LOW);
    lightON = false;
  }
}
