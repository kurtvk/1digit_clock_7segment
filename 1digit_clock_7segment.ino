#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 RTC;
int del=800; // delay between digits
int bdel=100; // blank delay

/*
DS1307 SDA pin 2
       SDL pin 3
       
*/

int sega =16;                 // segment a connected to pin 4
int segb =5;                 // segment b connected to pin 5
int segc =6;                 // segment c connected to pin 6
int segd =7;                 
int sege =8;                 
int segf =9;                 
int segg =10;       

void setup() {
    pinMode(sega, OUTPUT);      // sets the digital pin as output
    pinMode(segb, OUTPUT); 
    pinMode(segc, OUTPUT); 
    pinMode(segd, OUTPUT); 
    pinMode(sege, OUTPUT); 
    pinMode(segf, OUTPUT); 
    pinMode(segg, OUTPUT); 
    
  Serial.begin(57600);
    Wire.begin();
    RTC.begin();

    if (! RTC.isrunning()) {
        Serial.println("RTC not running, oh my!");
        // set the RTC to the date and time of sketch compilation
        RTC.adjust(DateTime(__DATE__, __TIME__));
    }
}

void loop() {
    DateTime now = RTC.now();
    int h1, h2, m1, m2;
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    

    h1=int(now.hour()/10);
    h2=(now.hour())%10;
    m1=int(now.minute()/10);
    m2=(now.minute())%10;
    Serial.print(h1);
    Serial.print(h2);
    Serial.print(m1);
    Serial.println(m2);

    
    
    displayTime1(h1); // displays the time on the display
     delay(del);
     digitalWrite(sega, LOW);   // sets the segments on
     digitalWrite(segb, LOW);
     digitalWrite(segc, LOW);
     digitalWrite(segd, LOW);
     digitalWrite(sege, LOW);
     digitalWrite(segf, LOW);
     digitalWrite(segg, LOW);
     //delay(100);

    displayTime1(h2); // displays the time on the display
     delay(del);
     digitalWrite(sega, LOW);   // sets the segments on
     digitalWrite(segb, LOW);
     digitalWrite(segc, LOW);
     digitalWrite(segd, LOW);
     digitalWrite(sege, LOW);
     digitalWrite(segf, LOW);
     digitalWrite(segg, LOW);
     delay(400);
     
    displayTime1(m1); // displays the time on the display
     delay(del);
     digitalWrite(sega, LOW);   // sets the segments on
     digitalWrite(segb, LOW);
     digitalWrite(segc, LOW);
     digitalWrite(segd, LOW);
     digitalWrite(sege, LOW);
     digitalWrite(segf, LOW);
     digitalWrite(segg, LOW);
     //delay(100);

    displayTime1(m2); // displays the time on the display
     delay(del);
     digitalWrite(sega, LOW);   // sets the segments on
     digitalWrite(segb, LOW);
     digitalWrite(segc, LOW);
     digitalWrite(segd, LOW);
     digitalWrite(sege, LOW);
     digitalWrite(segf, LOW);
     digitalWrite(segg, LOW);
     delay(100);

  delay(3000);
}

void displayTime1(int z)
{
 switch (z) {
   
    case 0:
     digitalWrite(sega, HIGH);   // sets the segments on
     digitalWrite(segb, HIGH);
     digitalWrite(segc, HIGH);
     digitalWrite(segd, HIGH);
     digitalWrite(sege, HIGH);
     digitalWrite(segf, HIGH);
      break;
      
    case 1:
     digitalWrite(segb, HIGH);
     digitalWrite(segc, HIGH);
      break;
      
    case 2:
     digitalWrite(sega, HIGH);   // sets the segments on
     digitalWrite(segb, HIGH);
     digitalWrite(segg, HIGH);
     digitalWrite(sege, HIGH);
     digitalWrite(segd, HIGH);
      break;
      
    case 3:
     digitalWrite(sega, HIGH);   // sets the segments on
     digitalWrite(segb, HIGH);
     digitalWrite(segg, HIGH);
     digitalWrite(segc, HIGH);
     digitalWrite(segd, HIGH);
      break;
      
      case 4:
     digitalWrite(segf, HIGH);   // sets the segments on
     digitalWrite(segg, HIGH);
     digitalWrite(segb, HIGH);
     digitalWrite(segc, HIGH);
      break;
      
    case 5:
     digitalWrite(sega, HIGH);   // sets the segments on
     digitalWrite(segf, HIGH);
     digitalWrite(segg, HIGH);
     digitalWrite(segc, HIGH);
     digitalWrite(segd, HIGH);
      break;
      
      case 6:
     digitalWrite(segf, HIGH);   // sets the segments on
     digitalWrite(sege, HIGH);
     digitalWrite(segd, HIGH);
     digitalWrite(segc, HIGH);
     digitalWrite(segg, HIGH);
      break;
      
    case 7:
     digitalWrite(sega, HIGH);   // sets the segments on
     digitalWrite(segb, HIGH);
     digitalWrite(segc, HIGH);
      break;
      
      case 8:
     digitalWrite(sega, HIGH);   // sets the segments on
     digitalWrite(segb, HIGH);
     digitalWrite(segc, HIGH);
     digitalWrite(segd, HIGH);
     digitalWrite(sege, HIGH);
     digitalWrite(segf, HIGH);
     digitalWrite(segg, HIGH);
      break;
      
    case 9:
     digitalWrite(sega, HIGH);   // sets the segments on
     digitalWrite(segb, HIGH);
     digitalWrite(segc, HIGH);
     digitalWrite(segf, HIGH);
     digitalWrite(segg, HIGH);
      break;
      
    //default: 
      // if nothing else matches, do the default
      // default is optional
  }

  
}
