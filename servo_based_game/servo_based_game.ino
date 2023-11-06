#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Wire.h>

//servo & display init
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo1;

//variables
int pot_before_map, pot, progress_bar=0, pot_first, btn1_clicks;
long lastButtonPress, t_btn1_clicks, t;
bool update = false, btn3_pressed = true, btn4_pressed = true, btns_pressed = true, Lresistor_pressed = true, pot_pressed = true;
bool lr_bt1_bt2 = true, clicks1 = true, clicks2 = true;


void setup() {
  //lcd init
  lcd.begin(16, 2);  
  lcd.backlight();
  
  //serial init
  Serial.begin(9600);  
  
  //servo init
  Wire.begin();
  servo1.attach(9);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);

  //millis
  t_btn1_clicks = millis();

  //potentiometer init
  pot_before_map = analogRead(A0);
  pot = map(pot_before_map, 0, 1023, 0, 180);
  pot_first = pot;
}

void loop() {
  //------basic init------
  pot_before_map = analogRead(A0);
  pot = map(pot_before_map, 0, 1023, 0, 180);
  t = millis();

  //------servo conditions------
  //btn1 pressed
  if(digitalRead(3) == LOW && btn3_pressed){
    if (millis() - lastButtonPress > 50){
      update = true;
      btn3_pressed = false;
      if(progress_bar <= 16)
        progress_bar++;
	  }
    lastButtonPress = millis();
  }
  //btn2 pressed
  else if(digitalRead(4) == LOW && btn4_pressed){
    if (millis() - lastButtonPress > 50){
      update = true;
      btn4_pressed = false;
      if(progress_bar <= 16)
        progress_bar++;
	  }
    lastButtonPress = millis();
  }
  //btn1 && btn2 pressed
  else if(digitalRead(3) == LOW && digitalRead(4) == LOW && btns_pressed){
    if (millis() - lastButtonPress > 50){
      update = true;
      btns_pressed = false;
      if(progress_bar <= 16)
        progress_bar++;
	  }
    lastButtonPress = millis();
  }
  //photo resistor covered
  else if(analogRead(A1) > 700 && Lresistor_pressed){
    if (millis() - lastButtonPress > 50){
      update = true;
      Lresistor_pressed = false;
      if(progress_bar <= 16)
        progress_bar++;
	  }
    lastButtonPress = millis();
  }
  //potentiometer turned
  else if(pot > pot_first+10 && pot_pressed){
    if (millis() - lastButtonPress > 50){
      update = true;
      pot_pressed = false;
      if(progress_bar <= 16)
        progress_bar++;
	  }
    lastButtonPress = millis();
  }
  //btn1 && btn2 pressed, photo resistor covered
  else if(analogRead(A1) > 700 && digitalRead(3) == LOW && digitalRead(4) == LOW && lr_bt1_bt2){
    if (millis() - lastButtonPress > 50){
      update = true;
      lr_bt1_bt2 = false;
      if(progress_bar <= 16)
        progress_bar++;
	  }
    lastButtonPress = millis();
  }
  //more than 3 clicks on btn1 
  else if(btn1_clicks >= 4 && clicks1){
    update = true;
    clicks1 = false;
    if(progress_bar <= 16)
      progress_bar++;
  }
  //more than 17 clicks on btn1
  else if(btn1_clicks >= 18 && clicks2){
    update = true;
    clicks2 = false;
    if(progress_bar <= 16)
      progress_bar++;
  } 


  //------update servo && arduino-------
  if(update){
	  progress(progress_bar);
    update = false;
  }

  //------button clicked------
  if(digitalRead(3) == LOW){
    if (millis() - lastButtonPress > 50){
      btn1_clicks++;
	  }
    lastButtonPress = millis();
  }

  if(t-t_btn1_clicks > 3000){
    btn1_clicks = 0;
    t_btn1_clicks = millis();
  }

  Serial.println(btn1_clicks);
}

void progress(int bar){
  for(int i = 0; i <= bar; i++){
    lcd.setCursor(i,1);
    lcd.print("X");
  }    
  servo1.write(bar*12);
}