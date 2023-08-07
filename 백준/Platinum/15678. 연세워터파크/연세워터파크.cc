#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, d, x;
	cin >> n >> d;
	cin >> x;
	int ans = x;
	priority_queue<pi> PQ;
	PQ.push({ x,0 });
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		while (1)
		{
			if (i - PQ.top().Y > d)
				PQ.pop();
			else
				break;
		}
		pi tmp = PQ.top();
		PQ.push({ max(tmp.X + x, x), i });
		if (ans < PQ.top().X)
			ans = PQ.top().X;
	}
	cout << ans << '\n';
}
// 참고 : https://measurezero.tistory.com/72