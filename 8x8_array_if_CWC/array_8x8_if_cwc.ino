// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

int clearPix ();
int cwc ();
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      64

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//  8x8 array

int i = 0, j = 0;


//
int delayval = 50; // delay for half a second

void setup() {
  Serial.begin(9600);      //ser up Serial.*
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
clearPix(); delay(2000);
cwc();  delay(2000);
 
  
}
int clearPix (){
  for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
    }
    pixels.show();
  }

int cwc(){
//ser base color
int r,c;//row and column
int red = 0, green = 0, blue = 0;
int m[8][8] = {  
    {1,1,1,1,1,1,1,1} ,
   {1, 1,0,0,0,0,0,1} ,
   {1, 0,1,0,0,0,0,1} ,
   {1, 0,0,1,1,0,0,1} ,
   {1, 0,0,1,1,0,0,1} ,
   {1, 0,0,0,0,1,0,1} ,
   {1, 0,0,0,0,0,1,1} ,
   {1, 1,1,1,1,1,1,1}     
};
int color = 100;
for(i = 31; i < 64; i++){
  red = 0;
  green = color / 2;
  blue = color;
 pixels.setPixelColor(i, pixels.Color(red,green,blue));
 pixels.show(); 
 delay(20);
 pixels.setPixelColor(63-i, pixels.Color(red,green,blue));
      pixels.show(); 
     delay(20);
   color = color - 3;
}  
  i = 0;
  delay(2000);
//  loop that increments x,y and i
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue
      if (m[r][c] == 1)
        { red = 30; green = 30; blue = 0;}
      else {red = 0; green = 30; blue = 1;}
      // end of set the color
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
 
      pixels.show(); 
      i++;
      delay(70);
     //Serial.print(c[x][y]);
    }//end y
}//end y and end of loop that increments x,y and i
}


