#ifndef _colortheorie_h_
#define _colortheorie_h_

#include <math.h>

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


int getcolor(color* couleur);
void HSLtoRGB(colorhsl* couleur1, color* couleurtransformer);
colorhsl* RGBtoHSL(color* couleur1);


color Rouge = {255, 0, 0, 0};
color Vert = {0, 255, 0, 0};
color Bleu = {0, 0, 255, 0};
color Blanc = {0, 0, 0, 255};


#endif // _colortheorie_h_