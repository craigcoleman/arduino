#include <Adafruit_NeoPixel.h>
#define PIN            6
#define NUMPIXELS      16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int dval = 100; // delay for half a second

//http://www.youtube.com/user/greatscottlab
int tx=1;
int rx=0;
int inchar;


void setup(){
  Serial.begin(9600);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT); 
  pixels.begin(); // This initializes the NeoPixel library
}

void loop(){
                                        
    if (Serial.available() > 0) {             
       while (Serial.available() > 0) {
         inchar=Serial.read();    
       }
      Pixels(inchar);
     }} 
     
  
int i;
  int red =0, green=0, blue = 0;
  
void Pixels(int in){   

  Serial.println(in);
// r = 114 g = 103 b = 98
  // y = 121   c = 99  m = 109
  // w = 119  k = 107 black
  
  switch (in) {
         
        case 98://BLUE
            red = 0; green = 0; blue =50;
          break;
     
            case 99:// CYAN
          red = 0; green = 50; blue =50;
          break;
            
            case 103://GREEN
            red = 0; green = 50; blue = 0;
          break;
            
            case 109: //MAGENTA
          red = 50; green = 0; blue = 50;
          break;
          
           case 114://RED
            red = 50; green = 0; blue = 0;
          break;
          
          case 119:// WHITE
          red = 50; green = 50; blue = 50;
          break;

          case 121:// YELLOW
          red = 70; green = 50; blue =0;
          break;

          
          default://
          red = 50; green = 20; blue = 0;
          break;
  }
        in = 0;
    for(int i=0;i<NUMPIXELS;i++){
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(red,green,blue)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        delay(dval); // Delay for a period of time (in milliseconds).
    }
    
}
  
