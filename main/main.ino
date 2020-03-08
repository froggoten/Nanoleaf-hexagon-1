#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN         6
#define NUMPIXELS 150

typedef struct color {
  unsigned int R;
  unsigned int G;
  unsigned int B;
  unsigned int W;
} color;
int getcolor(color* couleur){return (couleur->R, couleur->G, couleur->B, couleur->W);}

color Rouge = {255, 0, 0, 0};
color Vert = {0, 255, 0, 0};
color Bleu = {0, 0, 255, 0};
color Blanc = {0, 0, 0, 255};




Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);
#define DELAYVAL 100

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
    for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0, 0, 0, 0xFF));
    pixels.show();
    //delay(DELAYVAL);
  }
}

void loop() {
//  pixels.clear();


  for(int i=256; i>0; --i) {

    //pixels.setBrightness(i);
   // delay(DELAYVAL);
  }
}
