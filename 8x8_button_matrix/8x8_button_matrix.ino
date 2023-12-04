int HIGH_state, COL_pressed;
long lastBTNpress = 0;

//ROW's from R1 to R4 -> 2-5
//COLUMN's from C1 to C4 -> 9-6

void setup() {
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);

  Serial.begin(9600);
}

void loop() {
  for(HIGH_state = 2; HIGH_state < 6; HIGH_state++){
    digitalWrite(HIGH_state, HIGH);
    for(COL_pressed = 6; COL_pressed < 10; COL_pressed++){
      if(digitalRead(COL_pressed) == HIGH){
        Serial.print("C: ");
        Serial.print(HIGH_state);
        Serial.print("\t");
        Serial.print("R: ");
        Serial.println(COL_pressed);
      }
    }
    digitalWrite(HIGH_state, LOW);
  }
}