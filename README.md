# Fall 2021 CS 3353 PA 01 Template Repo
For this project we were tasked with creating a placement algorithm that can take a list of paintings and place them on a wall, making sure that none of the paintings are overlapping.  We also had to create 3 different algorithms (brute force, most expensive first, custom algorithm) that ideally would maximize the total value of the paintings placed on the wall.  Before I talk about the 3 algorithms in more detail, I want to share what my intial thought process was when I started the project.

The first thing I did once I read through the assignment was create a painting class.  This painting class holds all the necessary information about each painting (price, id, length, width etc.).  I then created a readInput class that would open and read the input file and store all the paintings and their information in a vector of painting objects. My main placement algorithm would take this vector as a parameter and start by placing the first painting in the top left corner of the wall.  Whenever I placed a painting I pushed the painting to a new vector and recorded the x,y values for the top left and bottoms right corners of the painting.  I could then place the next painting to the right of the previous checking to make sure it wouldnt exceed the boundaries of the wall, if it did I would place the painting at 1 + the max y value for all paintings already on the wall and at x=0. Once I had this placement algorithm I began working on the brute force, most expensive first, and custom algorithms.

For the most expensive first algorithm, I simply sorted the vector of paintings in descending order by price.  I then took the sorted vector and passed it as a parameter to my placement algorithm.

The brute force algorithm requires you to test all the possible combinations of paintings that can be placed on the wall in order to find the optimal solution. For this algorithm, I took the initial vector of paintings and created a new vector for each possible combination of the paintings and placed them in a vector of vectors.  I then ran each one of these vectors through my placment algorithm in order to determine which combination of paintings resulted in the maximum value.

For the custom algorithm, I figured that to maximize the value of paintings on the wall it was important to use all of the paintings that had a small size but also a high price.  I took my initial vector of paintings and calculated the average price. I then created a new vector and only added paintings that had an above average price.  I then sorted this vector by size insuring that I would place paintings with the smallest sizes but above average prices first.


I used the same "placement algorithm" for all three of these methods.  The brute force algorithm obviously always resulted with the highest possible value, but the other 2 algorithms were always close in value when the painting list was less than 10. We only had to use the brute force algorithm when our list of paintings was less than 10.  However, for the other 2 methods, I found that my custom algorithm was more optimal than the most exepensive first algorithm as the size of the list increased.  When the list was below a size of 10 these methods always resulted in approximately the same total value.


SAMPLE INPUT:

1024 768   (length and height of wall)

9          (number of paintings)

12 300 1000 700  (ID price length height)

9 200 300 100

23 250 400 400

1 100 100 100

3 150 200 150

6 200 350 200

8 125 100 100

11 400 400 250

12 225 200 200

SAMPLE OUTPUT FOR BRUTE FORCE:

1900              (total price of paintings on wall)

9 200 300 100 0 0  (ID price length height topleftcornerX topleftcornerY)

23 250 400 400 300 0

12 225 200 200 700 0

1 100 100 100 900 0

11 400 400 250 0 400

11 400 400 250 400 400

8 125 100 100 0 650

6 200 350 200 100 650

SAMPLE OUTPUT FOR MOST EXPENSIVE FIRST:

1550

11 400 400 250 0 0

23 250 400 400 400 0

12 225 200 200 0 400

9 200 300 100 200 400

3 150 200 150 0 600

6 200 350 200 200 600

8 125 100 100 550 600

SAMPLE OUTPUT FOR CUSTOM ALGO:

1525

12 225 200 200 0 0

11 400 400 250 200 0

23 250 400 400 600 0

9 200 300 100 0 400

1 100 100 100 300 400

3 150 200 150 0 500

6 200 350 200 200 500

