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
int h, w;
int arr[501][501] = { 0 };
bool v[501][501] = { 0 };
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> h >> w;
	int ans = h * w;
	for (int i = 0; i < w; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < x; j++)
		{
			arr[j][i] = 1;
			ans--;
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (j == 0 || j == w - 1)
			{
				if (arr[i][j] == 0 && v[i][j] == 0)
				{
					queue<pair<int, int>> Q;
					Q.push({ i,j });
					v[i][j] = 1;
					ans--;
					while (!Q.empty())
					{
						auto cur = Q.front();
						Q.pop();
						for (int k = 0; k < 2; k++)
						{
							int ny = cur.Y + dy[k];
							if (ny < 0 || ny >= w)
								continue;
							if (v[i][ny] == 0 && arr[i][ny] == 0)
							{
								v[i][ny] = 1;
								ans--;
								Q.push({ i, ny });
							}
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
}