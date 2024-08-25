# [Gold II] 고장난 계산기 - 32124 

[문제 링크](https://www.acmicpc.net/problem/32124) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기, 자료 구조, 구현, 문자열

### 제출 일자

2024년 8월 25일 13:29:53

### 문제 설명

<p>진우는 정수론 기말고사 시험에서 사용할 계산기를 구매했다. 계산기는 법 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>P</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$P$</span></mjx-container>에 대해 음이 아닌 정수 간의 덧셈과 곱셈, 그리고 괄호를 이용한 연산의 우선순위 지정을 지원한다. 즉, 계산기는 아래 BNF 표기법에서 <code><expr></code>에 해당하는 형태의 수식의 값을 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>P</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$P$</span></mjx-container>로 나눈 나머지를 계산할 수 있다.</p>

<ul>
	<li><code><expr> ::= <term> | <expr> + <term></code></li>
	<li><code><term> ::= <factor> | <term> * <factor></code></li>
	<li><code><factor> ::= <number> | ( <expr> )</code></li>
	<li><code><number> ::= <digit> | <number> <digit></code></li>
	<li><code><digit> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9</code></li>
</ul>

<p>일반적으로 계산기는 덧셈보다 곱셈을 먼저, 괄호 밖에 있는 연산보다 괄호 안에 있는 연산을 먼저 계산하고, 우선 순위가 동등하다면 왼쪽에 있는 연산부터 계산한다. 하지만 이 계산기는 고장나서 덧셈과 곱셈의 우선 순위를 동등하게 취급하며, 우선 순위가 동등한 연산은 임의 순서대로 계산한다. 즉, <code>(2+2*2)+3</code>은 괄호 안에 있는 덧셈을 곱셈보다 먼저 계산해서 <code>(4*2)+3 = 11</code>로 계산할 수도 있고, 곱셈을 덧셈보다 먼저 계산해서 <code>(2+4)+3 = 9</code>로 계산할 수도 있다.</p>

<p>계산기가 고장났다는 사실을 시험 10분 전에 깨달은 진우는 급한대로 여는 괄호(<code>‘(’</code>)와 닫는 괄호(<code>‘)’</code>)를 적당히 추가해서 고장난 계산기에서도 항상 의도한 대로 계산되도록 수식을 변환해서 입력하려고 한다. 진우가 원래 계산하고자 했던 수식 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>가 주어지면, 고장난 계산기에서 항상 진우가 의도한 결과를 출력하도록 여는 괄호와 닫는 괄호를 적당히 삽입해서 수식을 변환하는 프로그램을 작성하라.</p>

### 입력 

 <p>첫 번째 줄에 수식의 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>와 법 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>P</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$P$</span></mjx-container>가 공백을 사이에 두고 주어진다.</p>

<p>두 번째 줄에 진우가 원래 계산하려고 했던 수식 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>가 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 변환된 수식 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>의 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>을 출력한다.</p>

<p>두 번째 줄에 변환된 수식 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>를 출력한다.</p>

