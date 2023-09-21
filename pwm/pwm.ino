int ADCread = 0;
float ADCconverted = 0;
int fill = 0;
int change = 1;
int ret = 0;
int LEDpot(int speed);


void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ADCread = analogRead(A0);
  ADCconverted = ADCread / 4;

  //LEDpot(ADCconverted);
  LEDauto();

  //Serial.println(ADCconverted);
  //Serial.println(ADCread);

}

int LEDpot(int speed){
  int a;
  if(a < 255){
    for(int i=9; i<=11; i++){
      analogWrite(i, speed);
    }
  }
}

int LEDauto(){
  for(int i=9; i<=11; i++){
    analogWrite(i, fill); 

    if(ret == 0){
      fill = fill + change;

      if(fill == 255){
        ret++;
      }
    }

    if(ret == 1){
      fill = fill - change;
      if(fill == 0){
        ret--;
      }
    }
    
    delay(10);
  }  
}