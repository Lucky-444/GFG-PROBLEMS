<h2><a href="https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1">Disjoint set (Union-Find)</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p data-start="199" data-end="296"><span style="font-size: 14pt;">You are given n elements numbered from 1 to n . Initially, each element is in its own group.</span></p>
<p data-start="298" data-end="372"><span style="font-size: 14pt;">You need to process k queries. Each query is one of the following types:</span></p>
<ol data-start="374" data-end="677">
<li data-start="374" data-end="511">
<p data-start="377" data-end="511"><span style="font-size: 14pt;"><strong data-start="377" data-end="390">UNION x z</strong> –&nbsp;</span><span style="font-size: 18.6667px;">Merge the groups of x and z by making the&nbsp;<strong style="font-size: 18.6667px;">ultimate representative</strong> of x to the <span style="font-size: 18.6667px;">ultimate representative</span>&nbsp;of z. After merging, the&nbsp;<span style="font-size: 18.6667px;">ultimate representative</span>&nbsp;of z becomes the&nbsp;<span style="font-size: 18.6667px;">ultimate representative</span>&nbsp;of the whole group.</span></p>
</li>
<li data-start="512" data-end="677">
<p data-start="515" data-end="677"><span style="font-size: 14pt;"><strong data-start="515" data-end="525">FIND x</strong> – Output the ultimate representative of the group containing element x. The representative is the element that acts as the "leader" of the group.</span></p>
</li>
</ol>
<p><span style="font-size: 14pt;"><strong>Note: </strong>The <strong>ultimate representative</strong> of an element is the root of its group, i.e., the element whose parent is itself. Initially, every element is the leader of its own group.</span></p>
<p><strong><span style="font-size: 18.6667px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 5, k = 4, queries[] = {{find 4}, {find 1}, {unionSet 3 1}, {find 3}}
<strong>Output: </strong>4 1 1
<strong>Explanation:</strong>
1. The parent of 4 is 4. Hence the output is 4.
2. The parent of 1 is 1. Hence the output is 1.
3. After performing unionSet 3 1, parent of 3 becomes 1, since, parent of 1 is currently 1 itself.
4. The parent of 3 is now 1. Hence, the output is 1.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n , k &lt;= 100</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Samsung</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>union-find</code>&nbsp;<code>Algorithms</code>&nbsp;