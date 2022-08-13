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
int arr[126][126] = { 0 };
int v[126][126] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int cnt = 1;
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		memset(v, 0, sizeof(v));
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				v[i][j] = INF;
			}
		}
		queue <pair<int, int>> Q;
		Q.push({ 0,0 });
		v[0][0] = arr[0][0];
		while (!Q.empty())
		{
			auto cur = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;
				if (arr[nx][ny] + v[cur.X][cur.Y] < v[nx][ny])
				{
					v[nx][ny] = arr[nx][ny] + v[cur.X][cur.Y];
					Q.push({ nx,ny });
				}
			}
		}
		cout << "Problem " << cnt++ << ": " << v[n - 1][n - 1] << '\n';
	}
}