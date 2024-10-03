/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-ws2812b-led-strip
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket

#endif

#define PIN_WS2812B 4  // Arduino pin that connects to WS2812B
#define NUM_PIXELS 64  // The number of LEDs (pixels) on WS2812B

#define Columns 8 // the number of columns


Adafruit_NeoPixel WS2812B(NUM_PIXELS, PIN_WS2812B, NEO_GRB + NEO_KHZ800);



int matrix[8][8][3] = {{{255,0,0},{0,255,229},{255,0,0},{0,255,229},{255,0,0},{0,255,229},{255,0,0},{0,255,229}}, {{0,255,229},{0,0,0},{0,255,229},{0,0,0},{0,255,229},{0,0,0},{0,255,229},{0,0,0}}, {{0,24,255},{111,0,255},{0,24,255},{111,0,255},{0,24,255},{111,0,255},{0,24,255},{111,0,255}}, {{111,0,255},{0,0,0},{111,0,255},{0,0,0},{111,0,255},{0,0,0},{111,0,255},{0,0,0}}, {{40,255,0},{255,0,52},{40,255,0},{255,0,52},{40,255,0},{255,0,52},{40,255,0},{255,0,52}}, {{255,0,52},{0,0,0},{255,0,52},{0,0,0},{255,0,52},{0,0,0},{255,0,52},{0,0,0}}, {{255,0,0},{255,112,0},{255,0,0},{255,112,0},{255,0,0},{255,112,0},{255,0,0},{255,112,0}}, {{255,112,0},{0,0,0},{255,112,0},{0,0,0},{255,112,0},{0,0,0},{255,112,0},{0,0,0}}};




void setup() {
  WS2812B.begin();  // INITIALIZE WS2812B strip object (REQUIRED)
  Serial.begin(9600);
}

void loop() {
  WS2812B.clear();  // sets all pixel colors to be off (0,0,0), only happens when pixels.show is called.

  // turn pixels to the pattern set out above.
  
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel

    /*
    Serial.print("The pixel is: "); 
    Serial.print(pixel);
    Serial.print("The matrix code is: [");
    Serial.print((pixel/8));
    Serial.print("][");
    Serial.print(pixel%8);
    Serial.print("] The matrix value here is:");
    Serial.print(matrix[(pixel/8)][pixel%8][0]);
    Serial.print(" + ");
    Serial.print(matrix[(pixel/8)][pixel%8][1]);
    Serial.print(" + ");
    Serial.println(matrix[(pixel/8)][pixel%8][2]);
*/
    
   
    WS2812B.setPixelColor(pixel, WS2812B.Color(matrix[(pixel/Columns)][pixel%Columns][0], matrix[(pixel/Columns)][pixel%Columns][1], matrix[(pixel/Columns)][pixel%Columns][2]));  //This tells each pixel what colour it should be
    WS2812B.show();  // This sends the new pixel colours to the pixel, this can be included only after all pixels are set to increase speed and reduce "rolling shutter" effect.
    
    //  delay(500); // This would be used to have the pixels filled in visibly one at a time.                                  

  }


  delay(500);   // wait 500 milliseconds 
  WS2812B.clear(); // this clears all the pixels 
  WS2812B.show();  // send the updated pixel colors to the WS2812B hardware (no color as cleared).
  delay(500);     // leave al pixels off for 2 seconds

  // make all pixels red for two seconds
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
    WS2812B.setPixelColor(pixel, WS2812B.Color(255, 255, 255));  // it only takes effect if pixels.show() is called
  }
  WS2812B.show();  // send the updated pixel colors to the WS2812B hardware.
  delay(2000);     // on time

  // turn off all pixels for one seconds
  WS2812B.clear();
  WS2812B.show();  // send the updated pixel colors to the WS2812B hardware.
  delay(1000);     // off time

}
