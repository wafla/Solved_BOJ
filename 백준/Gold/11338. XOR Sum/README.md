# [Gold IV] XOR Sum - 11338 

[문제 링크](https://www.acmicpc.net/problem/11338) 

### 성능 요약

메모리: 2656 KB, 시간: 96 ms

### 분류

자료 구조(data_structures), 우선순위 큐(priority_queue)

### 문제 설명

<p>You will be given a list of Q (1 <= Q <= 100,000) instructions.</p>

<p>If the instructions is to "insert N", insert N into the list of numbers (there may be duplicates).</p>

<p>If the instruction is to "print" - print the XOR sum of the largest K (1<=K<=Q) elements in the list (or, if the list contains less than K elements, the XOR sum of all elements in the list).</p>

<p>XOR sum of a list of numbers is the result of XOR-ing all of them. XOR can be applied to two integers using the built in ^ operator in most languages (or xor in Haskell).</p>

<p>Note that XOR function has some useful properties, among them that if N^M=X then N=X^M and M=X^N.</p>

### 입력 

 <p>First line of the input contains an integer T (1 <= T <= 30) - the number of test cases. Each test case start with a line containing two integers Q and K (1 <= Q,K <= 100,000). Following are Q lines containing one instruction each.</p>

<p>Instructions are in either of the following two forms:</p>

<pre>insert N</pre>

<p>or</p>

<pre>print</pre>

<p>N is a non-negative integer less than 2^31.</p>

### 출력 

 <p>For each print statement output the sum of (at most) K largest elements in the current list. Note that the list is cleared between test cases.</p>

