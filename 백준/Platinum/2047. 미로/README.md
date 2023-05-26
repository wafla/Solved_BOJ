# [Platinum V] 미로 - 2047 

[문제 링크](https://www.acmicpc.net/problem/2047) 

### 성능 요약

메모리: 2072 KB, 시간: 8 ms

### 분류

너비 우선 탐색, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 트리

### 문제 설명

<p>유명한 영웅 백준은 퀘스트를 받아 혼자 모험을 하는 중에 미로를 발견하였다. 미로 주변으로 길이 없으므로 백준은 반드시 미로를 통과해야 한다.</p>

<p>백준은 이 미로를 잘 모르기 때문에 길이 나누어지면 그 중 무작위로 길을 택해 그쪽으로 이동할 것이다. 또한 백준은 완벽한 기억력을 가졌기 때문에 같은 길을 두 번 들어서는 일은 없고 더 이상 길이 없을 거라고 확신했을 때만 왔던 길을 돌아갈 것이다. 즉, 왔던 길을 돌아가기 전까지 안 가본 길은 다 둘러볼 것이다.</p>

<p>백준의 동료인 당신은 백준이 떠나고 뒤늦게 미로의 정보를 가지고 있는 지도를 발견하고는 백준이 미로를 탈출하는데 얼마나 걸릴지 궁금해서 걸음의 기댓값을 구하고자 한다. 당신은 미로를 잘 살펴본 결과 미로는 같은 지점으로 돌아오는 사이클이 없고 2×2 이상의 공간이 없다는 것을 알았다. 미로에는 입구와 출구가 각각 하나만 있고 길 옆에 출구가 있더라도 길이 나누어져 있다고 가정한다.</p>

<p>아래의 간단한 지도의 예를 보자.</p>

<pre>##s###
#....#
#t####</pre>

<p>입구는 "s"로 표시되어 있고 출구는 "t"로 표시되어 있다. </p>

<p>입구에서 남쪽으로 1칸 이동했을 때 길이 갈라지는데 여기서 서쪽을 선택하고 2칸 이동하면 출구를 찾을 수 있다. 반면 동쪽을 선택했을 시 4칸 이동하여 다시 돌아오고 남은길이 서쪽밖에 없으므로 서쪽으로 2칸 이동하면 출구를 찾을 수 있다.</p>

<p>따라서 백준이 입구에서 출구까지 나가는데 걸음의 기댓값은 <span style="line-height:1.6em"><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mfrac space="3"><mjx-frac><mjx-num><mjx-nstrut></mjx-nstrut><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-num><mjx-dbox><mjx-dtable><mjx-line></mjx-line><mjx-row><mjx-den><mjx-dstrut></mjx-dstrut><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c22C5"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mfrac space="3"><mjx-frac><mjx-num><mjx-nstrut></mjx-nstrut><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-num><mjx-dbox><mjx-dtable><mjx-line></mjx-line><mjx-row><mjx-den><mjx-dstrut></mjx-dstrut><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c22C5"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>+</mo><mfrac><mn>1</mn><mn>2</mn></mfrac><mo>⋅</mo><mo stretchy="false">(</mo><mn>4</mn><mo>+</mo><mn>2</mn><mo stretchy="false">)</mo><mo>+</mo><mfrac><mn>1</mn><mn>2</mn></mfrac><mo>⋅</mo><mn>2</mn><mo>=</mo><mn>5</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\( 1 + \frac{1}{2} \cdot (4 + 2) + \frac{1}{2} \cdot 2 = 5 \)</span></mjx-container> 이다.</span></p>

### 입력 

 <ul>
	<li>첫째 줄에는 테스트 케이스의 개수 n (0 < n ≤ 100) 이 주어진다.</li>
	<li>각 테스트 케이스에 대해서
	<ul>
		<li>첫째 줄에는 미로의 크기를 나타내는 두 정수 3 ≤ h, w ≤ 96 가 주어진다. </li>
		<li>다음 줄부터 h번에 걸쳐 문자가 w개 주어진다.
		<ul>
			<li>#은 벽이다.</li>
			<li>s와 t는 각각 입구와 출구다.</li>
			<li>.은 길이다.</li>
		</ul>
		</li>
		<li>미로의 경계는 입구와 출구를 제외하고 전부 벽이다.</li>
		<li>입구와 출구는 항상 미로의 경계에 있다.</li>
	</ul>
	</li>
</ul>

### 출력 

 <p>i번째 테스트 케이스에 대해 i번째 줄에 걸음의 기댓값을 반올림하여 둘째 자리까지 출력한다.</p>

