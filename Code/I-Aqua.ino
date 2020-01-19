#include <Arduino.h>
#include <EEPROM.h>
#define USE_SERIAL Serial
int l=0;
int limit =0;
  // Variable init
  const int  buttonPin = D8; 
  int contagem = 0;  
  int litros = 0;
  char thingspeak_string[200]; 
  char litros_string[10]="0";
  int addr = 0;
  String Reset="reset";
  int Liters = 0;
  void pin_ISR()
  {   
      contagem++;
  }

void setup() {
   // Serial Comunication init
   Serial.begin(115200);
   delay(10);

   // EEPROM access init
   EEPROM.begin(1);
   litros=EEPROM.read(addr);


   // Initialization of the variable “buttonPin” as INPUT (D2 pin)
   pinMode(buttonPin, INPUT);
   pinMode(23, OUTPUT);
   pinMode(22, OUTPUT);
   //digitalWrite(19,HIGH);
    
  // Attach an interrupt to the ISR vector
  attachInterrupt(digitalPinToInterrupt(buttonPin), pin_ISR, RISING);
}


void loop() {
  if(contagem > 440 )
  {
     //litros++;
      
      Liters++;
     Serial.println(Liters);
      contagem = 0;

  }

  delay(500);
}
