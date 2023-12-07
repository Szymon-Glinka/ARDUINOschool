int HIGH_state, COL_pressed;
long lastBTNpress = 0, t1, t2;
int col,row, INTnumber2, whichNUM = 1;
float FLOATnumber1;
String STRnumber1, STRnumber2, STRoperator;
bool FIRTSfloat_str1 = false, FIRTSfloat_str2 = false; 

const char* matrix[][4]={ {"7", "8", "9", "+"},
                          {"4", "5", "6", "-"},
                          {"1", "2", "3", "/"},
                          {",", "0", "=", "*"}};


//ROW's from R1 to R4 -> 2-5
//COLUMN's from C1 to C4 -> 9-6

void setup(){
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop(){
  for(HIGH_state = 2; HIGH_state < 6; HIGH_state++){
    digitalWrite(HIGH_state, LOW);
    for(COL_pressed = 6; COL_pressed < 10; COL_pressed++){
      if(digitalRead(COL_pressed) == LOW){
        if(millis()-lastBTNpress > 50){
          row = COL_pressed-6;
          col = HIGH_state-2;

          //------Number1-------
          if(whichNUM == 1 && matrix[row][col] != "+" && matrix[row][col] != "-" && matrix[row][col] != "/" && matrix[row][col] != "*" && matrix[row][col] != "=" && matrix[row][col] != ","){
            STRnumber1 = STRnumber1 + matrix[row][col];
            FLOATnumber1 = STRnumber1.toFloat();
          }
          else if(whichNUM == 1 && matrix[row][col] == "," && !FIRTSfloat_str1){
            STRnumber1 = STRnumber1 + ".";
            FIRTSfloat_str1 = true;
            FLOATnumber1 = STRnumber1.toFloat();
          }


          //------Operator number 1------
          if(whichNUM == 1 && matrix[row][col] == "+" || whichNUM == 1 && matrix[row][col] == "-" || whichNUM == 1 && matrix[row][col] == "/" || whichNUM == 1 && matrix[row][col] == "*"){     
            STRoperator = matrix[row][col];
            whichNUM = 2;
          }

          //------Number 2------
          if(whichNUM == 2 && matrix[row][col] != "+" && matrix[row][col] != "-" && matrix[row][col] != "/" && matrix[row][col] != "*" && matrix[row][col] != "=" && matrix[row][col] != ","){
            STRnumber2 = STRnumber2 + matrix[row][col];
            INTnumber2 = STRnumber2.toFloat();
          }
            
          Serial.print(FLOATnumber1);
          Serial.print("\t");
          Serial.print(INTnumber2);
          Serial.print("\t");
          Serial.println(STRoperator);
        }
        lastBTNpress = millis();
      }
    }
    digitalWrite(HIGH_state, HIGH);
  }
}