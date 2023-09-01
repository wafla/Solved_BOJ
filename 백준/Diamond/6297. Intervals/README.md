# [Diamond IV] Intervals - 6297 

[문제 링크](https://www.acmicpc.net/problem/6297) 

### 성능 요약

메모리: 7988 KB, 시간: 40 ms

### 분류

벨만–포드, 너비 우선 탐색, 그래프 이론, 그래프 탐색

### 문제 설명

<p>You are given n closed, integer intervals [a<sub>i</sub>, b<sub>i</sub>] and n integers c<sub>1</sub>, ..., c<sub>n</sub>.</p>

<p>Write a program that:</p>

<ul>
	<li>reads the number of intervals, their end points and integers c<sub>1</sub>, ..., c<sub>n</sub> from the standard input,</li>
	<li>computes the minimal size of a set Z of integers which has at least ci common elements with interval [a<sub>i</sub>, b<sub>i</sub>], for each i=1,2,...,n,</li>
	<li>writes the answer to the standard output.</li>
</ul>

### 입력 

 <p>The first line of the input contains an integer n (1 ≤ n ≤ 50000) -- the number of intervals. The following n lines describe the intervals. The (i+1)-th line of the input contains three integers a<sub>i</sub>, b<sub>i</sub> and c<sub>i</sub> separated by single spaces and such that 0 ≤ a<sub>i</sub> ≤ b<sub>i</sub> ≤ 50000 and 1 ≤ c<sub>i</sub> ≤ b<sub>i</sub> - a<sub>i</sub>+1.</p>

### 출력 

 <p>The output contains exactly one integer equal to the minimal size of set Z sharing at least ci elements with interval [ai, bi], for each i=1,2,...,n.</p>

