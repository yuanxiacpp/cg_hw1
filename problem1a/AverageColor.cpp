#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

#include "figio.h"

using namespace std;

const unsigned int max_h = 2000;
const unsigned int max_w = 2000;

int main(int argc, char* argv[]) {
  
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <input-file> " << endl;
    return 1;
  }
  
  unsigned char* image = new unsigned char[max_w*max_h*3];
  int w = max_w;
  int h = max_h;

  if (!load_tiff(argv[1], image, w, h)) {
    cout << "Could not read input file " << argv[1] << endl;
    return 1;
    
  }

  int sumBlue = 0;
  int sumGreen = 0;
  int count = 0;

  for (int j = 0; j < h; j++)
    for (int i = 0; i < w; i++) {
      int idx = 3*(i*h+j);
      
      sumGreen += image[idx+1];
      sumBlue += image[idx+2];
      count++;
    }

  double avgBlue = (double)sumBlue / count;
  double avgGreen = (double)sumGreen / count;
  
  cout << fixed << setprecision(1) 
       << "Average Blue: " << avgBlue << endl
       << "Average Green: " << avgGreen << endl;
  return 0;
}
