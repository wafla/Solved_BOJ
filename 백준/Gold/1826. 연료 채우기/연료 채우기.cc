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
	int n, a, b;
	cin >> n;
	vector<pi> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].X >> v[i].Y;
	sort(v.begin(), v.end());
	cin >> a >> b;
	int pos = 0, num = b, cnt = 0;
	priority_queue<int, vector<int>> PQ;
	int idx = 0;
	while (1)
	{
		while (idx < v.size() && v[idx].X <= num)
		{
			PQ.push(v[idx].Y);
			idx++;
		}
		pos = num;
		if (pos >= a)
		{
			cout << cnt << '\n';
			return 0;
		}
		else
		{
			if (PQ.empty())
				break;
			else
			{
				num += PQ.top();
				PQ.pop();
				cnt++;
			}
		}
	}
	cout << -1 << '\n';
}