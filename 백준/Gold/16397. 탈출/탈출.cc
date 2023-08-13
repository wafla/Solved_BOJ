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
bool visit[100001] = { 0 };
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, t, g;
	const int num = 99999;
	cin >> n >> t >> g;
	queue<pi> Q;
	Q.push({ n,0 });
	visit[n] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		if (cur.Y > t)
			continue;
		if (cur.X == g)
		{
			cout << cur.Y << '\n';
			return 0;
		}
		int nx = cur.X + 1;
		if (nx <= num && !visit[nx])
		{
			visit[nx] = 1;
			Q.push({ nx,cur.Y + 1 });
		}
		nx = cur.X * 2;
		if (nx <= num)
		{
			if (nx == 0)
				continue;
			string s = to_string(nx);
			if (s[0] == '0')
				s.erase(s.begin());
			else
				s[0]--;
			nx = stoi(s);
			if (!visit[nx])
			{
				visit[nx] = 1;
				Q.push({ nx,cur.Y + 1 });
			}
		}
	}
	cout << "ANG\n";
}