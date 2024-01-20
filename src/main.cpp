#include <Arduino.h>
#include<LiquidCrystal_I2C.h>

#define GPIO_Signal 35;
#define GPIO_Power 5;
#define led 2;
#define GPIO_SDA 21 ;
#define GPIO_SCL 22 ;
LiquidCrystal_I2C lcd(0x27,16,2);

int value ;

void tache_water(void* pvparam){
    pinMode(5, OUTPUT);
    pinMode(2, OUTPUT);
while(1){
   digitalWrite(5,HIGH);//turn on the power 
  vTaskDelay(1000);
  value=analogRead(35);
  digitalWrite(5,LOW);//turn off the power after cap
  //value=random(1024);
  if(value>1){
    digitalWrite(2,HIGH);
  }
vTaskDelay(1000);
}
}
void tache_display(void* pvparams){
  while(1){
    lcd.setCursor(2,0);
    lcd.println("Water level is");
    lcd.setCursor(1,1);
    lcd.println(value);


  }
}
void setup() {

  Serial.begin(115200);
  //randomSeed(analogRead(0));
  lcd.init();
  lcd.backlight();
 xTaskCreate(tache_water,"tache",2048,NULL,1,NULL);
 xTaskCreate(tache_display,"tachze",2048,NULL,2,NULL);


}

void loop() {
 
}

