void setup() {
  for(int i=1; i<=11; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
}

void loop() {
  WALKred(8, 9);
  STREETred(5, 6, 7);
  delay(250);
  STREETgreen(2, 3, 4);
  WALKgreen(10, 11);
  delay(2000);

  WALKred(10, 11);
  STREETred(2, 3, 4);
  delay(250);
  STREETgreen(5, 6, 7);
  WALKgreen(8, 9);
  delay(2000);
}

void STREETred(int R, int Y, int G){
  //digitalWrite(G, HIGH);
  //delay(1000);
  digitalWrite(Y, HIGH);
  digitalWrite(G, LOW);
  delay(1000);
  digitalWrite(R, HIGH);
  digitalWrite(Y, LOW);
}

void STREETgreen(int R, int Y, int G){
  digitalWrite(R, HIGH);
  delay(1000);
  digitalWrite(Y, HIGH);
  delay(1000);  
  digitalWrite(R, LOW);
  digitalWrite(Y, LOW);
  digitalWrite(G, HIGH);
}

void WALKgreen(int R, int G){
  digitalWrite(R, LOW);
  delay(250);
  digitalWrite(G, HIGH);
}

void WALKred(int R, int G){
  for(int i=1; i<=5; i++){
    digitalWrite(G, LOW);
    delay(250);
    digitalWrite(G, HIGH);
    delay(250);
  }
  digitalWrite(G, LOW);
  delay(250);
  digitalWrite(R, HIGH);
}

void STREETgreen_red(int R1, int Y1, int G1, int R2, int Y2, int G2){
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
