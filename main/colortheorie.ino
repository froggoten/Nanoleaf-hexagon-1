#include "colortheorie.h"

int getcolor(color* couleur) {
  return (couleur->R, couleur->G, couleur->B, couleur->W);
}


void HSLtoRGB(colorhsl* couleur1, color* couleurtransformer) {


}

colorhsl* RGBtoHSL(color* couleur1) {
  colorhsl* couleurconverti = malloc(sizeof(colorhsl));
  int R = couleur1->R;
  int G = couleur1->G;
  int B = couleur1->B;
  float r = R / 255;
  float g = G / 255;
  float b = B / 255;
  float m = min(min(r, g), b);
  float M = max(max(r, g), b);
  float H, S;

  //luminescence
  float L = (m + M) / 2; // arrondir?

  // Saturation
  if (m == M) {
    S = 0;
  }
  else if (L <= 0.5) {
    S = (M - m) / (M + m);
  }
  else {
    S = (M - m) / (2 - M - m);
  }

  //Hue
  if (M == r) {
    H = (g - b) / (M - m);
  }
  else if (M == g) {
    H = 2 + (b - r) / (M - m);
  }
  else {
    H = 4 + (r - g) / (M - m);
  }
  couleurconverti->S = S;
  couleurconverti->L = L;
  couleurconverti->H = H * 60; //arrondir?

  return couleurconverti;
}