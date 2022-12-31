# [Gold II] Herding - 6837 

[문제 링크](https://www.acmicpc.net/problem/6837) 

### 성능 요약

메모리: 3980 KB, 시간: 68 ms

### 분류

너비 우선 탐색(bfs), 자료 구조(data_structures), 깊이 우선 탐색(dfs), 분리 집합(disjoint_set), 그래프 이론(graphs), 그래프 탐색(graph_traversal), 강한 연결 요소(scc)

### 문제 설명

<p>Oh no! A number of stray cats have been let loose in the city, and as the City Cat Catcher, you have been assigned the vital task of retrieving all of the cats. This is an ideal opportunity to test your latest invention, a cat trap which is guaranteed to retrieve every cat which walks into a square-shaped subsection of the city.</p>

<p>Fortunately, you have the assistance of one of the world’s foremost cat psychologists, who has the amazing ability of predicting, given a square subsection of the city, exactly which of the four cardinal directions (north, east, south or west) the cat will head. While this information is handy, you still don’t know where all the cats currently are.</p>

<p>In order to prove the cost-effectiveness of your method to the City it would, of course, be important to minimize the number of traps used.</p>

### 입력 

 <p>The input will begin with a line consisting of two numbers n and m, separated by a space (1 ≤ n, m ≤ 1000). The city will be an n × m grid of square subsections. The next n lines will each consist of a string of length m, consisting of the letters ‘N’, ‘E’, ‘S’, or ‘W’, representing north, east, south and west, respectively. (The first character of the first line will be the northwesternmost point.) The direction in the square is the direction which cats will head if they are in that square. The cat psychologist assures you that cats have no interest in leaving the city.</p>

### 출력 

 <p>Output the minimum number of traps needed.</p>

