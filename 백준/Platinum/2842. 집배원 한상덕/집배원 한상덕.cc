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
#define x first
#define y second
using namespace std;
int n;
char arr[51][51] = { 0 };
int h[51][51] = { 0 }, dx[8]={-1,-1,-1,0,0,1,1,1}, dy[8]={-1,0,1,-1,1,-1,0,1};
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	vector<int> height;
	int num = 0, px, py;
	cin >> n;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'K')
				num++;
			if (arr[i][j] == 'P')
			{
				px = i;
				py = j;
			}
		}
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			cin >> h[i][j];
			height.push_back(h[i][j]);
		}
	sort(height.begin(), height.end());
	height.erase(unique(height.begin(), height.end()), height.end());
	int left = 0, right = 0, ans = 987654321;
	while (right < height.size())
	{
		while (1)
		{
			int check = 0;
			if (h[px][py] <= height[right] && h[px][py] >= height[left])
			{
				int cnt = 0;
				bool v[51][51] = { 0 };
				queue<pair<int, int>> Q;
				Q.push({ px,py });
				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();
					for (int i = 0;i < 8;i++)
					{
						int nx = cur.x + dx[i];
						int ny = cur.y + dy[i];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n)
							continue;
						if (h[nx][ny] > height[right] || h[nx][ny] < height[left])
							continue;
						if (arr[nx][ny] == '.' && v[nx][ny] == 0)
						{
							Q.push({ nx,ny });
							v[nx][ny] = 1;
						}
						if (arr[nx][ny] == 'K' && v[nx][ny] == 0)
						{
							Q.push({ nx,ny });
							v[nx][ny] = 1;
							cnt++;
						}
					}
				}
				if (cnt == num)
					check = 1;
			}
			if (check == 1)
			{
				int x = height[right] - height[left];
				if (x < ans)
					ans = x;
				left++;
			}
			else
				break;
		}
		right++;
	}
	cout << ans;
}
//참고: https://comyoung.tistory.com/279