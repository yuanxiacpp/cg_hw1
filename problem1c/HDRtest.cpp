#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

#include "figio.h"

using namespace std;

const double PI = 3.1415926;

void printVector(vector<vector<double> > &v, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++)
      printf("%7.1f ", v[i][j]);
    cout << endl;
  }
  return;
      
}
int outputToTiff(vector<vector<double> > &v, string &str, int size);

int main(int argc, char* argv[]) {
  
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <size> " << endl;
    return 1;
  }

  int size = atoi(argv[1]);
  vector<vector<double> > hdr(size, vector<double>(size, 0.0));

  for (int i = 0; i < size; i++) 
    for (int j = 0; j < size; j++) 
      hdr[i][j] = 1000.0 * sin(2*PI*j/size);

  int start = 7*size/16;
  int end = 9*size/16;

  for (int i = start; i <= end; i++)
    for (int j = start; j <= end; j++)
      hdr[i][j] = 10000.0;

  

  vector<vector<double> > linear(size, vector<double>(size, 0.0));

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      linear[i][j] = 255.0/11000.0 * hdr[i][j] + 255.0/11.0;

  

  vector<vector<double> > log_result(size, vector<double>(size, 0.0));
  
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      log_result[i][j] = 255.0 * log(1001+hdr[i][j]) / log(11001);
      
  

  //printVector(linear, size);

  //cout << "=========================================" << endl;
  //printVector(log_result, size);


  string str1 = "linear-";
  string str2 = "log-";
  outputToTiff(linear, str1, size);
  outputToTiff(log_result, str2, size);
  
  

  


  return 0;
}

int outputToTiff(vector<vector<double> > &v, string &str, int size) {
  stringstream s;
  s << size;
  string filename = str + s.str() + ".tiff";
  
  unsigned char *image = new unsigned char[size*size*3];
  

  for (int j=0; j < size; j++)
    for (int i = 0; i < size; i++) {
      int idx = 3 * (j*size + i);
      char val = (char)v[j][i];
      
      image[idx] = val;
      image[idx+1] = val;
      image[idx+2] = val;
    }

  if (!save_tiff(filename.c_str(), image, size, size)) {
    cerr << "Could not write output file " << filename << endl;

    return 1;
  }
  return 0;
  
}








