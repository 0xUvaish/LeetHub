# Top View of Binary Tree
## Medium 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree</span></p>

<p><span style="font-size:18px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1<br>
&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp; \<br>
&nbsp;&nbsp; 2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3<br>
&nbsp; /&nbsp; \&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp; \<br>
4&nbsp;&nbsp;&nbsp; 5&nbsp; 6&nbsp;&nbsp; 7</span></p>

<p><span style="font-size:18px">Top view will be: 4 2 1 3 7<br>
<strong>Note: </strong>Return nodes from <strong>leftmost </strong>node to <strong>rightmost </strong>node.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>&nbsp;     1
  &nbsp;/&nbsp;&nbsp;&nbsp; \
  2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3
<strong>Output: </strong>2 1 3<strong>
</strong></span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>&nbsp;      10
 &nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \
  20&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; 30
 /&nbsp;&nbsp; \&nbsp;&nbsp;&nbsp;&nbsp;/&nbsp; &nbsp;&nbsp;\
40&nbsp;&nbsp; 60  90&nbsp; &nbsp;&nbsp;100
<strong>Output: </strong>40 20 10 30 100
</span></pre>

<p><strong><span style="font-size:18px">Your Task:</span></strong><br>
<span style="font-size:18px">Since this is a function problem. You don't have to take input. Just complete the function<strong>&nbsp;topView() </strong>that takes <strong>root node </strong>as parameter and returns a list of nodes visible from the top view from left to right.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N)<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤&nbsp;N ≤&nbsp;10<sup>5</sup><br>
1 ≤ Node Data ≤&nbsp;10<sup>5</sup></span><br>
&nbsp;</p>

<p><strong>Note:</strong>The <strong>Input/Ouput</strong> format and <strong>Example </strong>given are used for system's internal purpose, and should be used by a user for <strong>Expected Output </strong>only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.</p>
 <p></p>
            </div>