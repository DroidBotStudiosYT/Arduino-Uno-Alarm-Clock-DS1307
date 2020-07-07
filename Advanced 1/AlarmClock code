#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <LiquidCrystal.h>
tmElements_t tm;
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
int switchPin1 = 4;
int switchPin2 = 3;
int switchPin3 = 2;

int switchState1 = 0;
int switchState2 = 0;
int switchState3 = 0;

int alarmTimeHour;
int alarmTimeMinutes;
int startAlarmTimeHour = 00;
int startAlarmTimeMinutes = 00;


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  while (!Serial) ; // wait for serial
  delay(200);
  lcd.setCursor(0, 0);
  lcd.clear();
  Serial.println("DS1307RTC Read Test");
  Serial.println("-------------------");
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
}

void loop() {
//  tmElements_t tm;
  switchState1 = digitalRead(switchPin1);
  switchState2 = digitalRead(switchPin2);
  switchState3 = digitalRead(switchPin3);

  if (RTC.read(tm)) {
    Serial.print("Ok, Time = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.println();
    lcd.setCursor(0, 0);
    lcd.print(tm.Hour);
    lcd.print(":");
    lcd.print(tm.Minute);
    lcd.print(":");
    lcd.print(tm.Second);
    
   } 
   else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } 
    else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
  delay(1000);
  if(switchState1 == HIGH){
    Serial.println("GOOD");
    lcd.clear();
//    lcd.print(startAlarmTimeHour);
//    lcd.print(":");
//    lcd.print(startAlarmTimeMinutes);
      lcd.print("00");
    
      if(switchState2 == HIGH){
        startAlarmTimeHour = alarmTimeHour;
        alarmTimeHour += 1;
        
        if(alarmTimeHour == 24){
          alarmTimeHour = 0;
        }
      }
      
      if(switchState3 == HIGH){
        startAlarmTimeMinutes = alarmTimeMinutes;
        startAlarmTimeMinutes += 1;
        
        if(alarmTimeHour == 60){
          alarmTimeHour = 0;
      }
    }
   
  }
}


void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
    lcd.clear();
    lcd.print(tm.Hour);
    lcd.print(":");
    lcd.print(tm.Minute);
    lcd.print(":");
    lcd.print(tm.Second);

  }
  Serial.print(number);
}
