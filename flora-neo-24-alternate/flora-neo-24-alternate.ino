// cwcoleman   
//  24 neo random lights
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      24

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int i,n;
int delayval = 1000; // delay for half a second
int red , green , blue, color;
int rgb = 25;
void setup() {
      Serial.begin(9600);
      randomSeed(analogRead(0));
      // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
      #if defined (__AVR_ATtiny85__)
      if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
      #endif
      // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
    i = random(24);
    color = random(25);
    Serial.println(i);
    red = blue = green = color;
    if (color % 19 == 0) {red = rgb; green = 0; blue = 0;}//red
    if (color % 20 == 0) {red = 0; green = rgb; blue = 0;}//green
    if (color % 21 == 0) {red = 0; green = 0; blue = rgb;}//blue
    if (color % 22 == 0) {red = rgb; green = rgb; blue = 0;}//yellow
    if (color % 23 == 0) {red = 0; green = rgb; blue = rgb;}//cyan
    if (color % 24 == 0) {red = rgb; green = 0; blue = rgb;} //magenta 
    if (i < 12){ 
         pixels.setPixelColor(i, pixels.Color(red,green ,blue)); 
         pixels.setPixelColor(i+12, pixels.Color(red,green ,blue)); 
    }else {
         pixels.setPixelColor(i, pixels.Color(red,green ,blue)); 
         pixels.setPixelColor(i-12, pixels.Color(red,green ,blue)); 
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
}
