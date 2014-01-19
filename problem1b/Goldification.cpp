#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

#include "figio.h"

using namespace std;

const unsigned int max_h = 2000;
const unsigned int max_w = 2000;

const double yellow_start = 50.0;
const double yellow_end = 65.0;
const double blue_start = 215.0;
const double blue_end = 250.0;

const double l_start = 0.5;
const double s_start = 0.2;
const double s_end = 60;

double getHSL(int ri, int gi, int bi, double &h, double &s, double &l) {
  
  double r = ri / 255.0;
  double g = gi / 255.0;
  double b = bi / 255.0;

  int mx = max(r, max(g, b));
  int mi = min(r, min(g, b));
  
  h = 0.0;
  
  if (mx == r && g >= b)
    h = 60 * (double)(g-b)/(mx-mi);
  else if (mx == r && g < b)
    h = 60 * (double)(g-b)/(mx-mi) + 360;
  else if (mx == g)
    h = 60 * (double)(b-r)/(mx-mi) + 120;
  else if (mx == b)
    h = 60 * (double)(r-g)/(mx-mi) + 240;

  l = 1/2 * (mx + mi);

  s = 0.0;
  if (0 < l && l <= 0.5) 
    s = (mx - mi) / 2 * l;
  else if (l > 0.5)
    s = (mx - mi) / (2 - 2*l);

  
  
}
bool isYellow(double h, double l, double s) {
  if (yellow_start <= h && h <= yellow_end)
    if (l > l_start)
      if (s_start <= s && s <= s_end)
	return true;
  return false;
}
bool isYellow(int r, int g, int b) {
  if (r > b && g > b)
    return true;
  return false;
}
bool isBlue(double h, double s, double l) {
  if (blue_start <= h && h <= blue_end)
    if (l > l_start)
      if (s_start <= s && s<= s_end)
	return true;
  return false;
}
bool isBlue(int r, int g, int b) {
  if (b > r && b > g)
    return true;
  return false;
}



void updateYellow(int &r, int &g, int &b) {
  r = 0;
  g = 0;
  b = 255;
  return;
}

void updateBlue(int &r, int &g, int &b) {
  r = 255; 
  g = 255;
  b = 0;
  return;
}

int main(int argc, char* argv[]) {
  
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " <input-file> <output-file> " << endl;
    return 1;
  }
  
  unsigned char* image = new unsigned char[max_w*max_h*3];
  int w = max_w;
  int h = max_h;

  if (!load_tiff(argv[1], image, w, h)) {
    cout << "Could not read input file " << argv[1] << endl;
    return 1;
    
  }

  for (int j = 0; j < h; j++)
    for (int i = 0; i < w; i++) {
      int idx = 3*(i*h+j);
      
      int r = image[idx];
      int g = image[idx+1];
      int b = image[idx+2];
      

      double h = 0.0;
      double s = 0.0;
      double l = 0.0;


      getHSL(r, g, b, h, s, l);
      
      if (isYellow(h, s, l)) {
	updateYellow(r, g, b);
	image[idx] = r;
	image[idx+1] = g;
	image[idx+2] = b;
      }
      else if (isBlue(h, s, l)) {
	updateBlue(r, g, b);
	image[idx] = r;
	image[idx+1] = g;
	image[idx+2] = b;
      }

    }

  if (!save_tiff(argv[2], image, w, h)) {
    cerr << "Could not write output file " << argv[2] << endl;
    return 1;
  }



  return 0;
}
