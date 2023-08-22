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
int n, m;
int arr[101][101] = { 0 };
int r[101][101] = { 0 };
vector<int> v;
void find(int s, int e)
{
	if (r[s][e] == 0)
	{
		v.push_back(s);
		v.push_back(e);
		return;
	}
	find(s, r[s][e]);
	v.pop_back();
	find(r[s][e], e);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			arr[i][j] = INF;
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (arr[x][y] > z)
			arr[x][y] = z;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
					continue;
				if (arr[i][j] > arr[i][k] + arr[k][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
					r[i][j] = k;
				}
			}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == INF)
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == INF)
				cout << 0 << '\n';
			else
			{
				v.clear();
				find(i, j);
				cout << v.size() << " ";
				for (auto k : v)
					cout << k << " ";
				cout << '\n';
			}
		}
	}
}
// 참고 : https://yabmoons.tistory.com/441