#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <math.h>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
using namespace std;
ll ans[10] = { 0 }, n;
void cal(int x, int mul) // 자리수를 센다. 일의 자리, 십의 자리 ... 에 따라 개수가 다르므로 mul을 더해준다.
{
	while (x)
	{
		ans[x % 10] += mul;
		x /= 10;
	}
}
void solve(int a, int b, int mul) // 1부터 N까지 세는데 계산을 쉽게 하기 위해 1을 a로 N을 b로 범위를 나누고 a의 일의 자리를 0, b의 일의 자리를 9로 맞춘다.
{
	while (a % 10 && a <= b) // a의 뒷자리를 0으로 맞추기 위해서 +1씩 해주고 개수를 센다.
	{
		cal(a, mul);
		a++;
	}
	if (a > b) // a가 b보다 큰 경우 종료
		return;
	while (b % 10 != 9 && a <= b) // b의 뒷자리를 9로 맞추기 위해서 -1씩 해주고 개수를 센다.
	{
		cal(b, mul);
		b--;
	}

	ll tmp = b / 10 - a / 10 + 1; // 마지막 자리 수의 개수. 
	// 값을 0 ~ 9로 맞췄기 때문에 10 ~ 129의 경우 일의 자리 수는 1x 2x 3x ... 12x로 12개 나오고 이를 수식으로 표현한 것이다.

	for (int i = 0; i < 10; i++) // 값을 더해준다. 이때 일의 자리는 1개씩 십의 자리는 10개씩 ... 10배씩 늘어나기 때문에 mul을 곱해준다.
		ans[i] += tmp * mul;

	solve(a / 10, b / 10, mul * 10); // 다음 자리의 개수를 세러 간다.
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	solve(1, n, 1);
	for (int i = 0; i < 10; i++)
		cout << ans[i] << " ";
}
// 참고 : https://uyt8989.tistory.com/83?category=1068103