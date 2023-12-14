int HIGH_state, COL_pressed;
long lastBTNpress = 0;
int col,row;

void setup(){
  //ROW's from R1 to R4 -> 2-5 as outputs
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  
  //COLUMN's from C1 to C4 -> 9-6 as inputs
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop(){
  //loop for reading 8x8 button matrix
  for(HIGH_state = 2; HIGH_state < 6; HIGH_state++){
    digitalWrite(HIGH_state, LOW);
    for(COL_pressed = 6; COL_pressed < 10; COL_pressed++){
      if(digitalRead(COL_pressed) == LOW){
        if(millis()-lastBTNpress > 50){
          //Fix rows and cols to be from 0 to 3
          row = COL_pressed-6;
          col = HIGH_state-2;
          
          //DEBUG
          Serial.print("row: ");
          Serial.print(row);
          Serial.print("\t");
          Serial.print("column: ");
          Serial.println(col);

        }
        lastBTNpress = millis();
      }
    }
    digitalWrite(HIGH_state, HIGH);
  }
}
