//ImageFilter.cpp - code to filter an image, turn all dark pixals light


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * You should have a good understanding of how this code works before
 *			 you start the assignment
 *!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

//figio.h includes our input/output tiff files
#include "figio.h"

// Maximum image dimensions of an image
const unsigned int max_h = 2000;
const unsigned int max_w = 2000;


int main(int argc, char* argv[]) {

	if(argc != 3) {
	  cerr << "Usage: " << argv[0] 
	       << " <input file>  <output file>  " << endl;
	  return 1;
	}

	//Allocate space to store the image in working memory.
	//Each color takes a single byte, each pixel has three colors
	unsigned char* image = new unsigned char[max_w*max_h*3];
	int w = max_w;
	int h = max_h;

	//Load the tiff file, and get the width and height. 
	if(!load_tiff(argv[1], image, w,h)) {
		cout << "Could not read input file " << argv[1] << endl;
		return 1;
	}

	//loop through all the pixels 
	for (int j=0;j<h;j++)
		for(int i=0;i<w;i++)
		{
			 //Find the index of the local pixel in the array. 
			 //Look up "Column-major order" if you need more info.
			 int index = 3*(j*w +i);
			 
			//If a pixel is dark...
			if (image[index]+image[index+1]+image[index+2] <30) {
				 //...Make it "white"
				 for (int k=0;k<3;k++)
				 {
					 image[index+k]= 255;
				 }
			 } 
		}

	//Save the new tiff.
	if(!save_tiff(argv[2], image, w,h) ){
		cerr << "Could not write output file " << argv[3] << endl;
		return 1;
	}
}
