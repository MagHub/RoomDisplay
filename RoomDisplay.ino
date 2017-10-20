#include <dht.h>
#include <LiquidCrystal.h>
#define dht_apin A0 // Analog Pin sensor is connected to

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 8, 9, 10, 11); /// REGISTER SELECT PIN,ENABLE PIN,D4 PIN,D5 PIN, D6 PIN, D7 PIN

dht DHT;
 
void setup(){
   // set up the LCD’s number of columns and rows:
  lcd.begin(16, 2);
 
 //Set up remote terminal
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  
    //Get readings from pin A0
    DHT.read11(dht_apin);
    
   //Print data readings to remote terminal
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    //Print data readings to LCD display
    lcd.setCursor(0, 0);
    lcd.print("Fukt = ");
    lcd.print(DHT.humidity);
    lcd.print("%  ");
    lcd.setCursor(0, 1);
    lcd.print("Temp = ");
    lcd.print(DHT.temperature); 
    lcd.print("C  ");;
    
    delay(5000);//Wait 5 seconds before comtinuing loop. Never wait less than 2 sec!
 
}// end loop() 
