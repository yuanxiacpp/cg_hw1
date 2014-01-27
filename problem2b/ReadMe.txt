The basic idea of this problem is almost the same as the previous one (problem 2a). 

1. remove all the surrouding white by finding boundaries of non-white area from 4 directions. 

2. Notation: x - height, y - width. One assumption: I assumed all three sub images are aligned correctly on y direction. Then, I chose 3 points (x/6, y/2), (x/2, y/2), (5*x/6, y/2). 

3. From these 3 points, go up and down until reach the edge(approximate to a dark value) to find the range of x for each sub image

4. use these ranges to cut out all three subimages. 

5. Assume the center point of all each subimage is the critical point, then use the algorithm from problem2a to align them together to get the final result.
