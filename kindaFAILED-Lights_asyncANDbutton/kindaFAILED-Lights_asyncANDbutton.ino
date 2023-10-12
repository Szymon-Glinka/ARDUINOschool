unsigned long t1,t2,t3,t4,t5,t6,t7,t8;
unsigned long button_cycle = 1;
int button = 0;
uint8_t button_prev;

void setup() {
  Serial.begin(9600);  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT_PULLUP);
  t1 = 0;
  t2 = 1000;
  t7 = 330;
  t8 = 1020;
  button_prev = digitalRead(button);    
}

void loop() {
  //button
  if(digitalRead(5) == LOW && button_prev == HIGH){
    Serial.println("button clicked");
    button = button + 10;
    t3 = millis() + 1000;
    t4 = millis() + 5770;
    t5 = (millis() + 1000) + (223*button_cycle);
    t6 = (millis() + 1000) + (574/2*(button_cycle));       
  }

  button_prev = digitalRead(5);
  
  //green LED
  if(millis() >= t1){
    digitalWrite(2, HIGH);
    t1 = millis() + 2000;
  }
  else if(millis() >= t2){
    digitalWrite(2, LOW);
    t2 = millis() + 2000;
  }
  
  //red LED
  if(millis() >= t7){
    digitalWrite(3, HIGH);
    t7 = millis() + 1020;
  }
  else if(millis() >= t8){
    digitalWrite(3, LOW);
    t8 = millis() + 1020;
  }
  
  //yellow LED with button
  if(button >=1 && millis() >= t3 && millis() < t4){
    if(millis() >= t5){
      digitalWrite(4, HIGH);
      t5 = millis() + (574*button_cycle);
    }
    else if(millis() >= t6){
      digitalWrite(4, LOW);
      t6 = millis() + (574*button_cycle);
    }
  }
  else if(millis() >= t4 && button >= 1){
    button = 0;
    button_cycle++;
    digitalWrite(4, LOW);
  }
}