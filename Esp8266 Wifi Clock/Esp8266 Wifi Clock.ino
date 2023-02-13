#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "Timer.h" 
const char *ssid     = "YOUR_WIFI_SSID_HERE";
const char *password = "WIFI_PASSWORD_HERE";

Timer timer; 

long number = 0; 
int num1 = 0;
int num2 = 0;
int num3 = 0;
int num4 = 0;
int timer_event = 0;

int cathode1 = 5;
int cathode2 = 4;
int cathode3 = 0;
int cathode4 = 2;

int latchPin = 15;
int clockPin = 14;
int dataPin = 13;

int flag = 0;
int count = 0;
int numbers[4] ;
int cathodePins[] = {5, 4, 0, 2};
int currentHour;
int currentMinute;

//If you are using common cathode change all 0 to 1 and all 1 to 0

byte table[10] {B00000011, B10011111, B00100101, B00001101, B10011001, B01001001, B01000001, B00011111, B00000001, B00001001};
byte table2[10] {B00000010, B10011110, B00100100, B00001100, B10011000, B01001000, B01000000, B00011110, B00000000, B00001000};

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");


void setup() {

  Serial.begin(115200);

  pinMode(cathode4, OUTPUT);
  pinMode(cathode3, OUTPUT);
  pinMode(cathode2, OUTPUT);
  pinMode(cathode1, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(cathode4, LOW);
  digitalWrite(cathode3, LOW);
  digitalWrite(cathode2, LOW);
  digitalWrite(cathode1, LOW);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  timeClient.begin();
  //Change offset according to your country. For Turkey it is +3 which means add 3 hours. for every hour add 3600 for example 2 hours is 7200
  timeClient.setTimeOffset(10800);
  

}

void loop() {
  
  timer.update();
  
  
  timeClient.update();
  currentHour = timeClient.getHours();
  currentMinute = timeClient.getMinutes();
  int currentTime = currentHour*100 + currentMinute;
  Serial.print("Time: ");
  Serial.println(currentTime); 
  timer.stop(timer_event); 
  separate(currentTime);
  timer_event = timer.every(1, Display); 
  delay(1);
  
}


void separate(long num) { 
  num1 = num / 1000;
  numbers[0] = num1;
  int num1_remove = num - (num1 * 1000);
  num2 = num1_remove / 100;
  numbers[1] = num2;
  int num2_remove = num1_remove - (num2 * 100);
  num3 = num2_remove / 10;
  numbers[2] = num3;
  num4 = num2_remove - (num3 * 10);
  numbers[3] = num4;
}



void Display() {
  screenOff(); 
  digitalWrite(latchPin, HIGH); 
  if(count == 1)
    shiftOut(dataPin, clockPin,LSBFIRST, table2[numbers[count]]); 
  else
    shiftOut(dataPin, clockPin,LSBFIRST, table[numbers[count]]);
  digitalWrite(cathodePins[count], HIGH); 
  digitalWrite(latchPin, LOW); 
  count++; 
  if (count == 4) { 
    count = 0;
  }
}

void screenOff() { 
  digitalWrite(cathode4, LOW);
  digitalWrite(cathode3, LOW);
  digitalWrite(cathode2, LOW);
  digitalWrite(cathode1, LOW);
}
