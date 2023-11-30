## Programms
### * RoadLights:
```
Green LED's for car -> 2, 5
Yellow LED's for car -> 3, 6
Red LED's for car -> 4, 7
Green LED's for pedestrian -> 8, 10
Red LED's for pedestrian -> 9, 11
Button's -> 12, 13
```
### * RoadLights_button && RoadLights_oneFunction:
```
Green LED's for car -> 6, 9
Yellow LED's for car -> 5, 8
Red LED's for car -> 4, 7
Green LED's for pedestrian -> 11, 13
Red LED's for pedestrian -> 10, 12
button's -> 2, 3
```
### * all_LED's_rev1:
```
buttons -> 2, 3, 8
potentiometer -> A0
LED's -> 4-7
RGB LED -> 9-11
```
### * async_lightsANDbtn-newMillis:
Based on ```attachInterupt``` in arduino IDE. On UNO works only with pins 2 && 3. 
```
LED's -> 4-7
Button -> 2, 3
```
### * async_lightsANDbtn-oldMillis:
```
LED's -> 2-4
Button -> 5
```
### * pwm:
```
LED's -> 9-11
Potentiometer -> A0
```
### * servo_based_game:  
  ```TO BE FINISHED```
### * shift_register:  
  ```links```       
  [shift register datascheet - ...595A](https://www.alldatasheet.com/datasheet-pdf/pdf/12192/ONSEMI/MC74HC595A.html)
  [8x8 led matrix's datascheet](https://components101.com/sites/default/files/component_datasheet/LED%20Matrix%20Datasheet.pdf)
```
uses arduino's built-in shiftOut(); function
shiftOut(dataPin, clockPin, bitOrder, value);
bitOrder: MSBFIRST, LSBFIRST
```
### * stepper_motor:  
  ```links```    
  [H-bridge's datasheet - L293E](https://pdf1.alldatasheet.com/datasheet-pdf/view/227655/STMICROELECTRONICS/L293E.html)  
  [Stepper.h](https://www.arduino.cc/reference/en/libraries/stepper/) 

