#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <LiquidCrystal.h>

tmElements_t tm;

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int notes[] = {262};

int switchAlarmPin = 4;
int switchPin2 = 3;
int switchPin3 = 2;

int switchStateAlarm = 0;
int switchState1 = 0;
int switchState2 = 0;
int switchState3 = 0;

int alarmTimeHour;
int alarmTimeMinutes;

bool isOnAlarm = false;


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
  tmElements_t tm;
  switchState2 = digitalRead(switchPin2);
  switchState3 = digitalRead(switchPin3);
  switchStateAlarm = digitalRead(switchAlarmPin);

      if(switchStateAlarm == HIGH){
        if(isOnAlarm == false){
          isOnAlarm = true;
        }
        else if(isOnAlarm == true){
          isOnAlarm = false;
        }
      }
      if(alarmTimeMinutes == tm.Minute && alarmTimeHour == tm.Hour){
          if(tm.Second <= 5){
            if(isOnAlarm == true){
              tone(5, notes[0]);
            }
          }
          else{
            noTone(5);
          }
      }
      else{
        noTone(5);
      }


  
      if(switchState2 == HIGH){
        alarmTimeHour = alarmTimeHour + 1;
        lcd.clear();
        lcd.setCursor(7, 0);
        lcd.print(alarmTimeHour);
        lcd.print(":");
        lcd.print(alarmTimeMinutes);
        
        if(alarmTimeHour == 24){
          alarmTimeHour = 0;
        }
      }
      
      if(switchState3 == HIGH){
        alarmTimeMinutes = alarmTimeMinutes + 1;
        lcd.clear();
        lcd.setCursor(7, 0);
        lcd.print(alarmTimeHour);
        lcd.print(":");
        lcd.print(alarmTimeMinutes);
        
        if(alarmTimeMinutes == 60){
          alarmTimeMinutes = 0;
        }
      }
   

    lcd.clear();
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
    lcd.setCursor(0, 1);
    lcd.print("alarm");
    lcd.setCursor(7, 1);
    lcd.print(alarmTimeHour);
    lcd.print(":");
    lcd.print(alarmTimeMinutes);
    if(isOnAlarm == true){
          lcd.setCursor(13, 1);
          lcd.print("on");
    }
    if(isOnAlarm == false){
          lcd.setCursor(13, 1);
          lcd.print("off");
    }
    
    
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
  delay(300);
    
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
