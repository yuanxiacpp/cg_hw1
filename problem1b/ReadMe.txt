1. How Yellow and Blue was detected
	I didn't use RGB value to determine blue and yellow because it seems to that the change of RGB value doesn't correspond intuitively with the actual color. Hence I decide to use HSL coordinates to check color instead.
	I used the online tool here(http://hslpicker.com/) to decide a range of coordinates that I think, by viewing colors with my eyes), are appropriate to use as ranges to determine blue and yellow.
	For yellow, the hue should fall in [50, 65], for blue the hue should fall in [220, 250].
	But only checking hue produces one problem, some of the shadows in the image will be treated as blue. 
	Hence, saturation and lightness was introduced to rule out those dark and bright areas. 
	The color_detection.tiff was the result of color detection, all the blue pixels in the original image are converted into (255, 255, 0), and all the yellow pixels are converted into (0, 0, 255). 

2. Change of Luminance
	Half the luminance of blue pixels is easy, my algorithm just divided current pixel's r, g, b value by 2, and it is guaranteed that the r, g, b values are still valid.
	Double the luminance of yellow needs one more step to validate the r, g, b values. If r, g, b values are all valid after double themselves, then nothing needs to be done. Otherwise, my algorithm will perform a brute force search in valid r, g, b space that will double the luminance. If no valid result was found, the r, g, b will become (255, 255, 255) eventually
	As result shows, almost all yellow pixels turned to white
	The reason I choose this method to double the luminance is that this guarantees r, g, b values to be valid and meanwhile also guarantees the luminance could be doubled if there exists one.
