#include <LiquidCrystal.h>
LiquidCrystal lcd(6, 8, 11, 10, 9, 8, 4);

int state = 0;

const int buttonPin1 = 2;
const int ledPin1 = 13;

const int buttonPin2 = 7;
const int ledPin2 = 12;

const int buttonPin3 = 3;


int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int minute = 10;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(buttonPin1, INPUT);

  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin2, INPUT);

  pinMode(buttonPin3, INPUT);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);

  lcd.begin(16, 2);
  lcd.print("Alarm clock");
  lcd.setCursor(0, 1);
  lcd.cursor();

  lcd.print(minute);
  Serial.println(minute);


}

void loop() {

  // state 0 will be setting the alarm clock setting
  while (state == 0){
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    buttonState3 = digitalRead(buttonPin3);
  // check if button is pushed.
  // if pushed, button is high 

    if (buttonState1 == HIGH){
      digitalWrite(ledPin1, HIGH);
      // increment by 10 seconds
      minute = minute + 10;
      delay(250);
      lcd.setCursor(0, 1);
      Serial.println(minute);
      lcd.print(minute);
      lcd.setCursor(0, 1);
    }
    else{
      // LED Off
      digitalWrite(ledPin1, LOW);
    }

    if (buttonState2 == HIGH){
      digitalWrite(ledPin2, HIGH);
      // decrement by 10 seconds
      minute = minute - 10;
      delay(250);
      lcd.setCursor(0, 1);
      lcd.print(minute);
      lcd.setCursor(0, 1);
    }
    else{
      // LED Off
      digitalWrite(ledPin2, LOW);
    }

    if (buttonState3 == HIGH){
      Serial.println("Button 3 pressed. Press button 1 and 2 at same time to start timer");
      state = 1;
    }
  }
  

  // it only starts when both buttons are pressed

  while(state == 1){
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
  if (buttonState1 == HIGH && buttonState2 == HIGH){

    while(minute > 0){
      if (minute > 1000 && minute < 10000){
        // remove the one's place between 1000-9999
        lcd.setCursor(0,1);
        lcd.print("     ");
        lcd.setCursor(0, 1);
        lcd.print(minute);
      }
      if (minute > 100 && minute < 1000){
        // remove the one's place between 100-999
        lcd.setCursor(0,1);
        lcd.print("    ");
        lcd.setCursor(0, 1);
        lcd.print(minute);
      }
      if (minute > 10 && minute < 100){
        // remove the one's place between 10-99
        lcd.setCursor(0,1);
        lcd.print("   ");
        lcd.setCursor(0, 1);
        lcd.print(minute);
      }
      if (minute < 10){
        // remove the one's place 
        lcd.setCursor(0,1);
        lcd.print("  ");
        lcd.setCursor(0, 1);
        lcd.print(minute);
      }
      minute--;
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print(minute); // for LCD screen
    Serial.println(minute); // for computer
    }
    // alarm clock goes off
      lcd.setCursor(0, 1);
      lcd.print("Wake up!");
      delay(30000);
      minute = 10;

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Alarm clock");

      lcd.setCursor(0, 1);
      lcd.print(minute);
      Serial.println(minute);
      // go back to 'settings' state
      state = 0;

   }
  }
}