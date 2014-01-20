#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

#include "figio.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <size> " << endl;
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
      


  if (!save_tiff(argv[2], image, w, h)) {
    cerr << "Could not write output file " << argv[2] << endl;
    return 1;
  }



  return 0;
}
