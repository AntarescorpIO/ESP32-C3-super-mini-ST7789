
/*
este programa esta diseñado para el procesador ESP32-C3 super mini
y el display ST7789  la secuenccia que se muestra es la cascasa de matrix

*/

#include <Arduino.h>
#include "DigitalRainAnimation.hpp"
#include <Adafruit_GFX.h> 
#include <Arduino_GFX_Library.h>
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789

  #define TFT_CS        10  
  #define TFT_RST        8 //  RESET pin
  #define TFT_DC         9
  #define SCL           4
  #define SDA           6
  #define BL  20 // Display backlight pin

Arduino_DataBus *bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS,SCL,SDA);//creamos el bus de salida
Arduino_GFX *gfx = new Arduino_ST7789(bus, TFT_RST  /* RST */);//creamos un gfx control con  el bus y el reset
// ST7789 TFT module connections
DigitalRainAnimation<Arduino_GFX> matrix_effect = DigitalRainAnimation<Arduino_GFX>();

  void setup() {

     Serial.begin(115200);

  Serial.print(F("Hello camara chavos ponganse chidooos"));
 pinMode(BL,OUTPUT);
 digitalWrite(BL,LOW);
   gfx->begin();
  matrix_effect.init(gfx);
 
 }

 void loop() {
 
      matrix_effect.loop();
  
  }