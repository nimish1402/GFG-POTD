<h2><a href="https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1">Distance of nearest cell having 1</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a binary grid of <strong>n*m</strong>. Find the distance of the nearest 1 in the grid&nbsp;for each cell.<br>The distance is calculated as&nbsp;<strong>|i<sub>1</sub>&nbsp; - i<sub>2</sub>| + |j<sub>1</sub>&nbsp;- j<sub>2</sub>|</strong>, where i<sub>1</sub>, j<sub>1</sub>&nbsp;are the row number and column number of the current cell, and i<sub>2</sub>, j<sub>2</sub>&nbsp;are the row number and column number of the nearest cell having value 1.</span>&nbsp;<span style="font-size: 18px;">There should be atleast one 1 in the grid.</span></p>
<p><span style="font-size: 18px;"><strong>Examples</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: <br></strong>grid = [[0,1,1,0], [1,1,0,0], [0,0,1,1]]
<strong>Output: <br></strong>[[1,0,0,1], [0,0,1,1], [1,1,0,0]]
<strong>Explanation: <br></strong>The grid is-
0 1 1 0&nbsp;
1 1 0 0&nbsp;
0 0 1 1&nbsp;
- 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at (0,1), (0,2), (0,2), (2,3), (1,0) and (1,1) respectively.
</span><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/701275/Web/Other/blobid0_1745302650.jpg" width="183" height="162" style="filter: invert(0);"> </pre>
<pre><span style="font-size: 18px;"><strong>Input: <br></strong>grid = [[1,0,1], [1,1,0], [1,0,0]]
<strong>Output: <br></strong>[[0,1,0], [0,0,1], [0,1,2]]
<strong>Explanation:</strong></span><span style="font-size: 18px;">&nbsp;<br>The grid is-
1 0 1
1 1 0
1 0 0
- 0's at (0,1), (1,2), (2,1) and (2,2) are at a  distance of 1, 1, 1 and 2 from 1's at (0,0), (0,2), (2,0) and (1,1) respectively.
</span><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/701275/Web/Other/blobid1_1745302675.jpg" width="196" height="173" style="filter: invert(0);"> </pre>
<p><span style="font-size: 18px;"><strong>Yout Task:</strong><br>You don't need to read or print anything, Your task is to complete the function&nbsp;<strong>nearest()&nbsp;</strong>which takes the grid as an input parameter and returns a matrix of the same dimensions where the value at index (i, j) in the resultant matrix signifies the <strong>minimum distance</strong> of 1 in the matrix from grid[i][j].</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n, m ≤ 500</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Matrix</code>&nbsp;<code>Graph</code>&nbsp;<code>BFS</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;