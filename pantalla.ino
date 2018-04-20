/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {

  //  welcome screen
  clearAllScreen();
  firstScreenText(78.3, 67.8);
  delay(2000);
  
}

void clearLineScreen(int col, int row) {
  if (col > 20) {
    col = 20;
  }
  if (row > 4) {
    row = 4;
  }
  lcd.setCursor(col, row);
  for (int i=0; i<20; i++) {
    lcd.print(' ');
  }
  
}

void clearAllScreen(){
  clearLineScreen(0, 0);
  clearLineScreen(0, 1);
  clearLineScreen(0, 2);
  clearLineScreen(0, 3);
}

void firstScreenText(int setPointBowlPercent, int reserveFoodPercent) {
  lcd.setCursor(0, 0);
  lcd.print("[-----PET CARE-----]");
  lcd.setCursor(0, 1);
  lcd.print("--------------------");
  lcd.setCursor(0, 2);
  lcd.print("Setpoint bowl: " + String(setPointBowlPercent) + "%");
  lcd.setCursor(0, 3);
  lcd.print("Reserve: " + String(reserveFoodPercent) + "%");
}

void secondScreenText() {
  lcd.setCursor(0, 0);
  lcd.print("Dispensado inmediato");
  lcd.setCursor(0, 2);
  lcd.print("Aceptar: B1");
  lcd.setCursor(0, 3);
  lcd.print("Cancelar: B2");    
}