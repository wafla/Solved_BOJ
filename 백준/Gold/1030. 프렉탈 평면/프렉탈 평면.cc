#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <deque>
#include <set>
#define X first
#define Y second
using namespace std;
long long s, n, k, r1, r2, c1, c2;
int solve(long long div, long long x, long long y)
{
	if (div <= 1)
		return 0;
	long long range = div / n;
	if (x >= range * (n - k) / 2 && x < range * (n + k) / 2 && y >= range * (n - k) / 2 && y < range * (n + k) / 2)
		return 1;
	return solve(range, x % range, y % range);
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
	long long len = pow(n, s);
	for (int i = r1;i <= r2;i++)
	{
		for (int j = c1;j <= c2;j++)
			cout << solve(len, i, j);
		cout << '\n';
	}
}
//참고 : https://myprivatestudy.tistory.com/27