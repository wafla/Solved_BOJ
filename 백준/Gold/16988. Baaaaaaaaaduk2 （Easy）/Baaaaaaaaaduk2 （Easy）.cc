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
int arr[23][23] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool visit[23][23] = { 0 };
int n, m, ans = 0;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
				arr[i][j] = 1;
			else
				cin >> arr[i][j];
		}
	}
	map<pair<pi, pi>, int> M;
	vector<vector<pi>> v;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			vector<pi> tmp;
			if (arr[i][j] == 2 && !visit[i][j])
			{
				queue<pi> Q;
				set<pi> S;
				Q.push({ i,j });
				v.resize(v.size() + 1);
				v[v.size() - 1].push_back({ i,j });
				visit[i][j] = 1;
				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (arr[nx][ny] == 0)
							S.insert({ nx,ny });
						if (arr[nx][ny] == 2 && !visit[nx][ny])
						{
							Q.push({ nx,ny });
							v[v.size() - 1].push_back({ i,j });
							visit[nx][ny] = 1;
						}
					}
				}
				for (auto k : S)
					tmp.push_back(k);
				if (tmp.size() == 1)
					M[{ {tmp[0].X, tmp[0].Y}, { -1,-1 }}] += v[v.size() - 1].size();
				else if (tmp.size() == 2)
					M[{ {tmp[0].X, tmp[0].Y}, { tmp[1].X,tmp[1].Y }}] += v[v.size() - 1].size();
			}
		}
	}
	vector<int> tmp;
	for (auto i : M)
	{
		int xx = i.X.X.X;
		int xy = i.X.X.Y;
		int yx = i.X.Y.X;
		int yy = i.X.Y.Y;
		int s = i.Y;
		if (yx == -1)
		{
			tmp.push_back(i.Y);
			continue;
		}
		auto x = M.find({ {xx,xy},{-1,-1} });
		auto y = M.find({ {yx,yy},{-1,-1} });
		int num_x = 0, num_y = 0;
		if (x != M.end())
			num_x = x->Y;
		if (y != M.end())
			num_y = y->Y;
		ans = max(ans, s + num_x + num_y);
	}
	sort(tmp.begin(), tmp.end());
	if (tmp.size() == 1)
		ans = max(ans, tmp[0]);
	else if (tmp.size() > 1)
		ans = max(ans, tmp[tmp.size() - 1] + tmp[tmp.size() - 2]);
	cout << ans << '\n';
}