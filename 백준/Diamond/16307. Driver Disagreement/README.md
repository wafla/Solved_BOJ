# [Diamond I] Driver Disagreement - 16307 

[문제 링크](https://www.acmicpc.net/problem/16307) 

### 성능 요약

메모리: 6372 KB, 시간: 32 ms

### 분류

너비 우선 탐색, 자료 구조, 분리 집합, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 9월 16일 03:00:06

### 문제 설명

<p>Alice and Bob are travelling in Italy. They are travelling by car and unfortunately they took a wrong turn. Now they are stuck in the city centre of Pisa. (You may know that you need an allowance to drive in the city centre, so they are at risk of getting a fine.) As they were not fully prepared for this, they have a map, but no GPS. The map lists all intersections. At each intersection you can go either left or right (you cannot go straight or take a U-turn, as many streets are one-way).</p>

<p>Of course, they paid attention when entering Pisa and tried to follow on the map. Unfortunately, Alice thinks they are at intersection A, while Bob believes they are now at intersection B. You can imagine this is quite a stressful situation. Instead of figuring out how to get out of Pisa, they want to know who is right first. On the map it is indicated from which intersections you can see the leaning tower of Pisa. So they believe they can conduct an experiment: drive a bit and take the same actions on the map starting from A and B. They can trace the route they drive on the map for both of their starting points. As soon as the tower of Pisa should be visible for one of them but not for the other, they can look out of the window to see who is right. You may assume exactly one of them is right.</p>

### 입력 

 <ul>
	<li>The first line of the input has three space-separated integers. The first integer, 2 ≤ n ≤ 10<sup>5</sup> is the number of intersections. The next two integers are 0 ≤ A, B < n, the intersections that Alice and Bob respectively think they are currently at. In particular A ≠ B.</li>
	<li>Then follow n lines. The i’th of these lines (0 ≤ i < n) has three space-separated integers: l<sub>i</sub> r<sub>i</sub> t<sub>i</sub>. If you are at intersection i and take a left turn, you arrive at l<sub>i</sub>, while a right turn brings you to r<sub>i</sub>. The number t<sub>i</sub> = 1 if you can see the leaning tower of Pisa from intersection i. Otherwise t<sub>i</sub> = 0.</li>
</ul>

### 출력 

 <p>Print the minimal number of turns it takes to show either person correct. If no experiment can tell whether Alice or Bob is correct, print “<code>indistinguishable</code>”.</p>

