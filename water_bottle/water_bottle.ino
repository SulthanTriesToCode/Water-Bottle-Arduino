#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change the address (0x27) to match your LCD module
const int buttonPin1 = 8;
const int buttonPin2 = 7;
const int buzzerPin = 9;
unsigned long lastButtonPress = 0;
float totalWater = 0.0; // change this to your actual water consumption variable
int displayMode = 0; // 0 for time display, 1 for water consumption display, 2 for reminder timer
int prevDisplayMode = 0;
int remindTime = 0; // in minutes
bool buzzerOn = false;
unsigned long lastBuzzerToggle = 0;
const unsigned long buzzerInterval = 500; // 500 milliseconds

void setup() {
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin1) == LOW) {
    if (displayMode == 2) {
      remindTime += 5;
      if (remindTime > 60) remindTime = 0;
    } else {
      lastButtonPress = millis();
      if (buzzerOn) {
        buzzerOn = false;
        digitalWrite(buzzerPin, LOW);
      }
    }
    delay(200); // debounce delay
  }

  if (digitalRead(buttonPin2) == LOW) {
    displayMode = (displayMode + 1) % 3;
    delay(200); // debounce delay
  }

  if (prevDisplayMode != displayMode) {
    lcd.clear();
    prevDisplayMode = displayMode;
  }

  if (displayMode == 1) {
    lcd.setCursor(0,0);
    lcd.print("Water consumed:");
    lcd.setCursor(0,1);
    lcd.print(totalWater);
    lcd.print(" Liters");
  } else if (displayMode == 2) {
    lcd.setCursor(0,0);
    lcd.print("Remind time:");
    lcd.setCursor(0,1);
    lcd.print(remindTime);
    lcd.print(" Minutes");
  } else {
    lcd.setCursor(0,0);
    lcd.print("Time after drink: ");
  
    unsigned long duration = millis() - lastButtonPress;
  
    int seconds = (duration / 1000);
    int minutes = seconds / 60;
    seconds = seconds % 60;
  
    lcd.setCursor(0,1);
  
    if(minutes < 10)
      lcd.print("0");
    
    lcd.print(minutes);
  
    lcd.print(":");
  
    if(seconds < 10)
      lcd.print("0");
    
    lcd.print(seconds);

    if (minutes >= remindTime && remindTime > 0 && minutes > 0) {
      if (millis() - lastBuzzerToggle >= buzzerInterval) {
        buzzerOn = !buzzerOn;
        digitalWrite(buzzerPin, buzzerOn ? HIGH : LOW);
        lastBuzzerToggle = millis();
      }
    }
  }
}
