#include <dht.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 8, 9, 10, 11); /// REGISTER SELECT PIN,ENABLE PIN,D4 PIN,D5 PIN, D6 PIN, D7 PIN
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
 
void setup(){
  
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(7, OUTPUT);
  
  digitalWrite(7, LOW);
  
  // set up the LCD’s number of columns and rows:
  lcd.begin(16, 2);
  
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  
  //Wait before loop starts
  delay(1000);
 
}//end "setup()"
 
void loop(){
  //Start of Program 
     lcd.setCursor(0, 0);
    lcd.print("Kommando?           ");
    lcd.setCursor(0, 1);
    lcd.print("                 ");
            
    Serial.println(digitalRead(A4));
    delay(50);
    
    if(digitalRead(A4) < 1) { 
      
     lcd.setCursor(0, 1);
     lcd.print("Rumsdata.                 ");
     delay(1000);
     
      Serial.print(digitalRead(A4));
      Serial.println(digitalRead(A4));
      DHT.read11(dht_apin);
      /*
      Serial.print("Current humidity = ");
      Serial.print(DHT.humidity);
      Serial.print("%  ");
      Serial.print("temperature = ");
      Serial.print(DHT.temperature); 
      Serial.println("C  ");
    */
    
 
      //Fastest should be once every two seconds.
      lcd.setCursor(0, 0);
      lcd.print("Fukt = ");
      lcd.print(DHT.humidity);
      lcd.print("%  ");
      lcd.setCursor(0, 1);
      lcd.print("Temp = ");
      lcd.print(DHT.temperature); 
      lcd.print("C  ");;

      delay(10000);//Wait 10 seconds before accessing sensor again.
    }
 
 if(digitalRead(A5) < 1) { 
      
     lcd.setCursor(0, 1);
     lcd.print("Disco-knappen!                 ");
          
     digitalWrite(7, HIGH);
     delay(9000);
     digitalWrite(7, LOW);
    
 }
     
 
}// end loop() 
