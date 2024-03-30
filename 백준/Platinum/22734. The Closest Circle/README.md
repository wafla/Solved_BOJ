# [Platinum I] The Closest Circle - 22734 

[문제 링크](https://www.acmicpc.net/problem/22734) 

### 성능 요약

메모리: 7580 KB, 시간: 356 ms

### 분류

이분 탐색, 분할 정복, 기하학

### 제출 일자

2024년 3월 30일 23:03:44

### 문제 설명

<p>You are given <i>N</i> non-overlapping circles in xy-plane. The radius of each circle varies, but the radius of the largest circle is not double longer than that of the smallest.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/adc4d493-fcfa-4b43-8265-ffb340740106/-/preview/" style="width: 251px; height: 226px;"></p>

<p style="text-align: center;">Figure 1: The Sample Input</p>

<p>The distance between two circles <i>C</i><sub>1</sub> and <i>C</i><sub>2</sub> is given by the usual formula</p>

<p><mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 108.8%; position: relative;"> <mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-msqrt><mjx-sqrt><mjx-surd><mjx-mo class="mjx-lop"><mjx-c class="mjx-c221A TEX-S2"></mjx-c></mjx-mo></mjx-surd><mjx-box style="padding-top: 0.45em;"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-msub space="3"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.289em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-msub space="3"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.289em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-box></mjx-sqrt></mjx-msqrt><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-msub space="3"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-msub space="3"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><msqrt><mo stretchy="false">(</mo><msub><mi>x</mi><mn>1</mn></msub><mo>−</mo><msub><mi>x</mi><mn>2</mn></msub><msup><mo stretchy="false">)</mo><mn>2</mn></msup><mo>+</mo><mo stretchy="false">(</mo><msub><mi>y</mi><mn>1</mn></msub><mo>−</mo><msub><mi>y</mi><mn>2</mn></msub><msup><mo stretchy="false">)</mo><mn>2</mn></msup></msqrt><mo>−</mo><msub><mi>r</mi><mn>1</mn></msub><mo>−</mo><msub><mi>r</mi><mn>2</mn></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$$\sqrt{(x_1 - x_2)^2 + (y_1 - y_2)^2} - r_1 - r_2$$</span> </mjx-container></p>

<p>where (<i>x<sub>i</sub></i>, <i>y<sub>i</sub></i>) is the coordinates of the center of the circle <i>C<sub>i</sub></i>, and <i>r<sub>i</sub></i> is the radius of <i>C<sub>i</sub></i>, for <i>i</i> = 1, 2.</p>

<p>Your task is to write a program that finds the closest pair of circles and print their distance.</p>

### 입력 

 <p>The input consists of a series of test cases, followed by a single line only containing a single zero, which indicates the end of input.</p>

<p>Each test case begins with a line containing an integer <i>N</i> (2 ≤ <i>N</i> ≤ 100000), which indicates the number of circles in the test case. <i>N</i> lines describing the circles follow. Each of the <i>N</i> lines has three decimal numbers <i>R</i>, <i>X</i>, and <i>Y</i>. R represents the radius of the circle. <i>X</i> and <i>Y</i> represent the <i>x</i>- and <i>y</i>-coordinates of the center of the circle, respectively.</p>

### 출력 

 <p>For each test case, print the distance between the closest circles. You may print any number of digits after the decimal point, but the error must not exceed 0.00001.</p>

