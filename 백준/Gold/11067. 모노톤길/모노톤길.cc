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
#define LINF 9223372036854775807
#define MOD 10000000000
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<pi, int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<vector<int>> v(100001);
		map<int, pi> M;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
		}
		int num = 1;
		int y = 0;
		for (int i = 0; i < 100001; i++)
		{
			if (!v[i].size())
				continue;
			sort(v[i].begin(), v[i].end());
			if (v[i][0] != y)
				sort(v[i].begin(), v[i].end(), greater<int>());
			for (int j = 0; j < v[i].size(); j++)
				M[num++] = { i,v[i][j] };
			y = v[i][v[i].size() - 1];
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int tmp;
			cin >> tmp;
			cout << M[tmp].X << " " << M[tmp].Y << '\n';
		}
	}
}