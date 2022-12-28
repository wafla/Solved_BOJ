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
#define ll unsigned long long
using namespace std;
int solve(int x)
{
	if (x % 4 == 0)
		return x;
	else if (x % 4 == 1)
		return 1;
	else if (x % 4 == 2)
		return x + 1;
	else if (x % 4 == 3)
		return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int s, f, ans;
		cin >> s >> f;
		ans = solve(s - 1) ^ solve(f);
		cout << ans << '\n';
	}
}
// 참고 : https://appdevorsec.tistory.com/151