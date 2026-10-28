Spiral Matrix solution and breaking down the problems. 


1) We would have to divide the problem and try to scan the matrix from its boundaries.

```c++
vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };
```

We know that a matrix has 4 sides.
We would need 4 loops to iterate over the boundaries. 

Lets create these variables.

int m = mat.size(), n = mat[0].size(); where m is row and n is col

int top, right, bottom, left;

We have four sides : srow, scol, erow, ecol;


![1793175667896](image/note/1793175667896.png)


Now, we would have to iterate over these boundaries to access the elements.
We would need 4 for loops for that. 

First Loop :
