void setup() {
 for(int i=1; i<=11; i++){
   pinMode(i, OUTPUT);
 }
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
}

void loop() {
  STREATgreen_red(6, 4, 2, 7, 5, 3);
  delay(4000);  
  STREATgreen_red(7, 5, 3, 6, 4, 2);
  delay(4000);

}

void STREATgreen_red(int R1, int Y1, int G1, int R2, int Y2, int G2){
  digitalWrite(G2, HIGH);
  delay(1000);
  digitalWrite(Y2, HIGH);
  digitalWrite(G2, LOW);
  delay(1000);
  digitalWrite(R2, HIGH);
  digitalWrite(Y2, LOW);
  
  delay(250);
        
  digitalWrite(R1, HIGH);
  delay(1000);
  digitalWrite(Y1, HIGH);
  delay(1000);  
  digitalWrite(R1, LOW);
  digitalWrite(Y1, LOW);
  digitalWrite(G1, HIGH);
}

void STREATred(int R, int Y, int G){
  digitalWrite(G, HIGH);
  delay(1000);
  digitalWrite(Y, HIGH);
  digitalWrite(G, LOW);
  delay(1000);
  digitalWrite(R, HIGH);
  digitalWrite(Y, LOW);
}

void STREATgreen(int R, int Y, int G){
  digitalWrite(R, HIGH);
  delay(1000);
  digitalWrite(Y, HIGH);
  delay(1000);  
  digitalWrite(R, LOW);
  digitalWrite(Y, LOW);
  digitalWrite(G, HIGH);
}