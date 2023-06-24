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
#include <bitset>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pi pair<int, int>
using namespace std;
int n, m, k;
int arr[101][101] = { 0 };
int A[101][101] = { 0 };
int dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 };
deque<int> T[101][101];
void spring_summer_fall()
{
	vector<pair<pi, int>> v;
	vector<pi> vv;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (T[i][j].size() == 0)
				continue;
			sort(T[i][j].begin(), T[i][j].end());
			int size = T[i][j].size();
			for (int x = 0; x < size; x++)
			{
				int num = T[i][j].front();
				T[i][j].pop_front();
				if (arr[i][j] >= num)
				{
					arr[i][j] -= num;
					T[i][j].push_back(num + 1);
				}
				else
				{
					v.push_back({ {i,j},num / 2 });
					continue;
				}
				if ((num + 1) % 5 == 0)
				{
					for (int z = 0; z < 8; z++)
					{
						int nx = i + dx[z];
						int ny = j + dy[z];
						if (nx < 1 || nx > n || ny < 1 || ny > n)
							continue;
						vv.push_back({ nx,ny });
					}
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
		arr[v[i].X.X][v[i].X.Y] += v[i].Y;
	for (int i = 0; i < vv.size(); i++)
		T[vv[i].X][vv[i].Y].push_back(1);
}
void winter()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] += A[i][j];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = 5;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> A[i][j];
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		T[x][y].push_back(z);
	}
	for (int i = 0; i < k; i++)
	{
		spring_summer_fall();
		winter();
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans += T[i][j].size();
	cout << ans << '\n';
}