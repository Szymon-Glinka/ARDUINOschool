int HIGH_state, COL_pressed;
long lastBTNpress = 0, t1, t2;
int col,row, INTnumber2, whichNUM = 1;
float FLOATnumber1, FLOATnumber2, calculatedNum, displayedNum, ph1, ph2;
String STRnumber1, STRnumber2, STRoperator1, STRoperator2;
bool FIRSTfloat_str1 = false, FIRSTfloat_str2 = false; 
const char* matrix[][4]={ {"7", "8", "9", "+"},
                          {"4", "5", "6", "-"},
                          {"1", "2", "3", "/"},
                          {",", "0", "=", "*"}};

/*

calculator layout:
7  8  9  +
4  5  6  -
1  2  3  /
,  0  =  *

TO DO:
squer and clear
*/



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

          //------Number1-------
          //inserting numbers to number1
          if(whichNUM == 1 && matrix[row][col] != "+" && matrix[row][col] != "-" && matrix[row][col] != "/" && matrix[row][col] != "*" && matrix[row][col] != "=" && matrix[row][col] != ","){
            STRnumber1 = STRnumber1 + matrix[row][col]; //put new number to a string1
            FLOATnumber1 = STRnumber1.toFloat(); //convert string1 to float (number1)
            displayedNum = FLOATnumber1; //set displayed number as number1
          }
          //inserting "." to number1
          else if(whichNUM == 1 && matrix[row][col] == "," && !FIRSTfloat_str1){
            STRnumber1 = STRnumber1 + "."; //put period to number1
            FIRSTfloat_str1 = true; //set true so not able to put period again
            FLOATnumber1 = STRnumber1.toFloat(); //convert string1 to float
          }

          //------Operator number 1------
          if(whichNUM == 1 && matrix[row][col] == "+" || whichNUM == 1 && matrix[row][col] == "-" || whichNUM == 1 && matrix[row][col] == "/" || whichNUM == 1 && matrix[row][col] == "*"){
            STRoperator1 = matrix[row][col]; //set operator number 1
            whichNUM = 2; //go to set number 2

            //IDK just some fix so it works and does not return an error
            if(matrix[row][col] == "*" || matrix[row][col] == "/") FLOATnumber2 = 1;
          }

          //------Number 2------
          //inserting numbers to number2
          if(whichNUM == 2 && matrix[row][col] != "+" && matrix[row][col] != "-" && matrix[row][col] != "/" && matrix[row][col] != "*" && matrix[row][col] != "R" && matrix[row][col] != ","){
            STRnumber2 = STRnumber2 + matrix[row][col]; //put new number to string2
            FLOATnumber2 = STRnumber2.toFloat(); //convert string2 to float (number2)
            displayedNum = FLOATnumber2; //set displayed number as number1
          }
          //inserting "." to number2
          else if(whichNUM == 2 && matrix[row][col] == "," && !FIRSTfloat_str2){
            STRnumber2 = STRnumber2 + "."; //put period to string2
            FIRSTfloat_str2 = true; //set true so not able to put period again
            FLOATnumber2 = STRnumber2.toFloat(); //convert string2 to float
          }

          //------Operator number 2------
          if(whichNUM == 2 && matrix[row][col] == "+" || whichNUM == 2 && matrix[row][col] == "-" || whichNUM == 2 && matrix[row][col] == "/" || whichNUM == 2 && matrix[row][col] == "*"  || whichNUM == 2 && matrix[row][col] == "="){     
            STRoperator2 = matrix[row][col]; //set oprator number 2
            
            //make calculations when operator "="
            if(STRoperator2 == "="){
              if(STRoperator1 == "+") calculatedNum = FLOATnumber1 + FLOATnumber2; //addition
              else if(STRoperator1 == "-") calculatedNum = FLOATnumber1 - FLOATnumber2; //subtraction
              else if(STRoperator1 == "/") calculatedNum = FLOATnumber1 / FLOATnumber2; //division
              else if(STRoperator1 == "*") calculatedNum = FLOATnumber1 * FLOATnumber2; //multiplication
              
              //set all variables to default
              whichNUM = 1;
              FIRSTfloat_str1 = false;
              FIRSTfloat_str2 = false;
              displayedNum = calculatedNum;
              calculatedNum = 0; 
              STRnumber1 = "";
              STRnumber2 = "";
              FLOATnumber1 = 0;
              FLOATnumber2 = 0;
            }

            //make calculations when other operators and set calculated number as number1
            else{
              if(STRoperator2 == "+") calculatedNum = FLOATnumber1 + FLOATnumber2; //addition
              else if(STRoperator2 == "-") calculatedNum = FLOATnumber1 - FLOATnumber2; //subtraction
              else if(STRoperator2 == "/") calculatedNum = FLOATnumber1 / FLOATnumber2; //division
              else if(STRoperator2 == "*") calculatedNum = FLOATnumber1 * FLOATnumber2; //multiplication 
            
              //clear for new calculations
              STRoperator1 = STRoperator2;
              FLOATnumber1 = calculatedNum;
              STRnumber2 = "";
              FLOATnumber2 = 0;
              displayedNum = calculatedNum;
            }

            //IDK just some fix so it works and does not return an error
            if(matrix[row][col] == "*" || matrix[row][col] == "/") FLOATnumber2 = 1;
          }

          //DEBUG
          if(false){  
            Serial.print(FLOATnumber1, 6);
            Serial.print(" | ");
            Serial.print(FLOATnumber2, 6);
            Serial.print("\t");
            Serial.print(STRoperator1);
            Serial.print(" | ");
            Serial.print(STRoperator2);
            Serial.print("\t");
            Serial.print(calculatedNum, 6);
            Serial.print(" | ");
            Serial.print(displayedNum, 6);
            Serial.print("\t");
            Serial.println(whichNUM);                      
          }
          else Serial.println(displayedNum, 6);          
        }
        lastBTNpress = millis();
      }
    }
    digitalWrite(HIGH_state, HIGH);
  }
}
