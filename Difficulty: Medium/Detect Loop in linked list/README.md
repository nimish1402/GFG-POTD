<h2><a href="https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1">Detect Loop in linked list</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18.6667px;">You are given the <strong>head </strong>of a singly linked list. Your task is to determine if the linked list contains a <strong>loop</strong>. A loop exists in a linked list if the next pointer of the last node points to any other node in the list (including itself), rather than being null.</span></p>
<p><span style="font-size: 14pt;"><strong>Custom Input format:</strong><br>A<strong> head </strong>of a singly linked list<strong> </strong>and a<strong> </strong><strong>pos </strong>(1-based index) which denotes the position of the node to which the last node points to. </span><span style="font-size: 18.6667px;">If <strong>pos </strong>= 0, it means the last node points to null, indicating there is no loop.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>head: 1 -&gt; 3 -&gt; 4, pos = 2
<strong>Output: </strong>true<strong>
Explanation: </strong>There exists a loop as last node is connected back to the second node.<strong><br></strong><strong><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700099/Web/Other/blobid1_1718699705.png" width="400" height="160" style="filter: invert(0);"></strong><br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>head:<strong> </strong>1 -&gt; 8 -&gt; 3 -&gt; 4, pos = 0
<strong>Output: </strong>false<strong>
Explanation: </strong>There exists no loop in given linked list.<strong><br></strong><strong><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700099/Web/Other/blobid2_1718699755.png" width="400" height="100" style="filter: invert(0);"></strong><br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>head: 1 -&gt; 2 -&gt; 3 -&gt; 4, pos = 1
<strong>Output: </strong>true<strong>
Explanation: </strong>There exists a loop as last node is connected back to the first node.<strong><br></strong></span><span style="font-size: 14pt;"><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700332/Web/Other/blobid2_1718609744.png" width="400" height="160" style="filter: invert(0);"></span><br><br></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong></span><br><span style="font-size: 14pt;">1 ≤ number of nodes ≤ 10<sup>4</sup><br>1 ≤ node-&gt;data ≤ 10<sup>3&nbsp; &nbsp; &nbsp; &nbsp;</sup></span><span style="font-size: 18.6667px;"><br></span><span style="font-size: 14pt;">0&nbsp;</span><span style="font-size: 18.6667px;">≤&nbsp;</span><span style="font-size: 14pt;">pos&nbsp;</span><span style="font-size: 18.6667px;">≤ Number of nodes in Linked List</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>VMWare</code>&nbsp;<code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>OYO Rooms</code>&nbsp;<code>Samsung</code>&nbsp;<code>Snapdeal</code>&nbsp;<code>D-E-Shaw</code>&nbsp;<code>Hike</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Walmart</code>&nbsp;<code>MAQ Software</code>&nbsp;<code>Adobe</code>&nbsp;<code>SAP Labs</code>&nbsp;<code>Qualcomm</code>&nbsp;<code>Veritas</code>&nbsp;<code>Mahindra Comviva</code>&nbsp;<code>Lybrate</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Linked List</code>&nbsp;<code>two-pointer-algorithm</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;