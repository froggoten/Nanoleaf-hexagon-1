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
typedef struct colorhsl {
  unsigned int H;
  unsigned int S;
  unsigned int L;
} colorhsl;

int getcolor(color* couleur){return (couleur->R, couleur->G, couleur->B, couleur->W);}

color Rouge = {255, 0, 0, 0};
color Vert = {0, 255, 0, 0};
color Bleu = {0, 0, 255, 0};
color Blanc = {0, 0, 0, 255};


void HSLtoRGB(colorhsl* couleur1){


}

colorhsl* RGBtoHSL(color* couleur1){
  colorhsl* couleurconverti = malloc(sizeof(color));
  int R = couleur1->R;
  int G = couleur1->G;
  int B = couleur1->B;
  float r=R/255;
  float g=G/255;
  float b=B/255;
  float m=min(min(r, g), b);
  float M=max(max(r, g),b);
  float H, S;

 //luminescence
  float L=(m+M)/2;// arrondir?
  
 // Saturation
  if (m==M) {
    S = 0;
  }
  else if (L<=0.5) {
      S =(M-m)/(M+m);}
  else {
    S =(M-m)/(2-M-m);
  }

 //Hue
  if (M==r) {
    H=(g-b)/(M-m);
  }
  else if (M==g) {
    H=2+(b-r)/(M-m);
  }
  else {
    H=4+(r-g)/(M-m);
  }
couleurconverti->S = S;
couleurconverti->L = L;
couleurconverti->H=H*60; //arrondir?

return couleurconverti;
}


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
