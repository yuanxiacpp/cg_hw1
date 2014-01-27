1. choose 3 pixels from the original picture that I want to align together.
	The 3 points are: (1267, 1417), (1239, 4596) and (1229, 7748). And let me call these 3 points alignment points, these 3 points are the center of the face in each division, and let me name it critical point.

2. Go from each alignment point in 4 directions(up, down, left, right) to the edge of each picture, find minimal distance in all 4 directions, use these 4 directions to find the corner of each pictures.
	The four distance that I get are: up - 1120, down - 2407, left - 1226, right - 1785.

3. Use alignment points and direction distance to calculate the range of each picture, this guarantees the result images with the same size.
	Calculation shows the following ranges:
	red image: X [191, 3202], Y [147, 3675]
	green image: X [3370, 6381], Y [119, 3646]
	blue image: X [6522, 9533], Y [109, 3636]


4. The function parameters is a little different than what was asked, but it fulfills the same purpose.

 
