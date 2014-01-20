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
const double blue_start = 220.0;
const double blue_end = 250.0;

const double s_start = 0.3;
const double l_start = 0.2;
const double l_end = 0.8;

void getHSL(int ri, int gi, int bi, double &h, double &s, double &l) {
  
  double r = (double)ri / 255.0;
  double g = (double)gi / 255.0;
  double b = (double)bi / 255.0;


  double mx = max(r, max(g, b));
  double mi = min(r, min(g, b));

  //cout << r << "," << g << "," << b << endl;
  //cout << mx << "," << mi << endl;
  
  h = 0.0;

  if (mx == mi)
    h = 0.0;  
  else if (mx == r && g >= b)
    h = 60 * (g-b)/(mx-mi);
  else if (mx == r && g < b)
    h = 60 * (g-b)/(mx-mi) + 360;
  else if (mx == g)
    h = 60 * (b-r)/(mx-mi) + 120;
  else if (mx == b)
    h = 60 * (r-g)/(mx-mi) + 240;

  l = 0.5 * (mx + mi);

  s = 0.0;
  if (l == 0)
    s = 0.0;
  else if (0 < l && l <= 0.5) 
    s = (mx-mi) / (2*l);
  else if (l > 0.5)
    s = (mx-mi) / (2-2*l);

  //cout << h << "," << s << "," << l << endl;
  return;
  
}
bool isYellow(double h, double s, double l) {
  
  
  if (yellow_start <= h && h <= yellow_end)
    if (s > s_start)
      if (l_start <= l && l <= l_end)
	return true;
  return false;
}
bool isYellow(int r, int g, int b) {
  double h = 0.0;
  double s = 0.0;
  double l = 0.0;
  getHSL(r, g, b, h, s, l);
  return isYellow(h, s, l);
}

bool isBlue(double h, double s, double l) {
  if (blue_start <= h && h <= blue_end)
    if (s > s_start)
      if (l_start <= l && l <= l_end)
	return true;
  return false;
}


double getLuminance(int r, int g, int b) {
  return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

void updateYellow(int &r, int &g, int &b) {
  //r = 0;
  //g = 0;
  //b = 255;
  
  double y = getLuminance(r, g, b);

  r *= 2;
  g *= 2;
  b *= 2;

  if (r < 256 && g < 256 && b < 256)
    return;

  int r_start = min(r, 255);
  int g_start = min(g, 255);
  int b_start = min(b, 255);
  
  for (int i = r_start; i < 256; ++i)
    for (int j = g_start; j < 256; j++)
      for (int k = b_start; k < 256; k++) {
	double tmp = getLuminance(i, j, k);
	if (tmp >= 2*y && isYellow(i, j, k)) {
	  r = i;
	  g = j;
	  b = k;
	}  
      }
       
  
  return;
}

void updateBlue(int &r, int &g, int &b) {
  //r = 255; 
  //g = 255;
  //b = 0;
  r /= 2;
  g /= 2;
  b /= 2;
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
      int idx = 3*(j*w+i);
      
      int r = image[idx];
      int g = image[idx+1];
      int b = image[idx+2];
      

      double h = 0.0;
      double s = 0.0;
      double l = 0.0;


      getHSL(r, g, b, h, s, l);


      //getchar();

      if (isYellow(h, s, l)) {
	updateYellow(r, g, b);
	image[idx] = r;
	image[idx+1] = g;
	image[idx+2] = b;
      }
      else if (isBlue(h, s, l)) {
	//cout << h << "," << s << "," << l << endl;
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
