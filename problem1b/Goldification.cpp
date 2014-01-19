#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

#include "figio.h"

using namespace std;

const unsigned int max_h = 2000;
const unsigned int max_w = 2000;

const double yellow_start = 45.0;
const double yellow_end = 65.0;
const double blue_start = 200.0;
const double blue_end = 255.0;

double getHue(int r, int g, int b) {
  int mx = max(r, max(g, b));
  int mi = min(r, min(g, b));
  
  double h = 0.0;
  
  if (mx == r && g >= b)
    h = 60 * (double)(g-b)/(mx-mi);
  else if (mx == r && g < b)
    h = 60 * (double)(g-b)/(mx-mi) + 360;
  else if (mx == g)
    h = 60 * (double)(b-r)/(mx-mi) + 120;
  else if (mx == b)
    h = 60 * (double)(r-g)/(mx-mi) + 240;

  return h;
}
bool isYellow(double h) {
  if (yellow_start <= h && h <= yellow_end)
    return true;
  return false;
}
bool isBlue(double h) {
  if (blue_start <= h && h <= blue_end)
    return true;
  return false;
}



void updateYellow(int &r, int &g, int &b) {
  return;
}

void updateBlue(int &r, int &g, int &b) {
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
      
      double h = getHue(r, g, b);
      
      if (isYellow(h)) {
	updateYellow(r, g, b);
	image[idx] = r;
	image[idx+1] = g;
	image[idx+2] = b;
      }
      else if (isBlue(h)) {
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
