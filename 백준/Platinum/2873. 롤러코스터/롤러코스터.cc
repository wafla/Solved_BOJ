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
int arr[1001][1001] = { 0 };
int dx[4] = { 0,1,0,1 }, dy[4] = { 1,0,-1,0 };
int n, m;
struct min_point {
	int num;
	int x;
	int y;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	min_point minn({ INF,0,0 });
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0))
			{
				if (arr[i][j] < minn.num)
				{
					minn.num = arr[i][j];
					minn.x = i;
					minn.y = j;
				}
			}
		}
	}
	if (n % 2 == 0 && m % 2 == 0)
	{
		int x = 1, y = 1;
		while (x < n || y < m)
		{
			int tmp_y = y;
			if (tmp_y % 2 == 1 && (tmp_y == minn.y || tmp_y + 1 == minn.y))
			{
				int cnt = 1;
				while (cnt < 2 * n - 1)
				{
					for (int k = 0; k < 4; k++)
					{
						if (cnt >= 2 * n - 1)
							break;
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (minn.x == nx && minn.y == ny)
						{
							if (k == 0)
								k = 2;
							else if (k == 2)
								k = 0;
							continue;
						}
						if (k == 0)
							cout << 'R';
						else if (k == 1)
							cout << 'D';
						else if (k == 2)
							cout << 'L';
						else if (k == 3)
							cout << 'D';
						x = nx;
						y = ny;
						cnt++;
					}
				}
				if (y < m)
				{
					cout << 'R';
					y++;
				}
			}
			else
			{
				if (x == 1)
				{
					while (x < n)
					{
						cout << 'D';
						x++;
					}
				}
				else if (x == n)
				{
					while (x > 1)
					{
						cout << 'U';
						x--;
					}
				}
				if (y < m)
				{
					cout << 'R';
					y++;
				}
			}
		}
	}
	else if (n % 2 == 0 && m % 2 == 1)
	{
		int x = 1, y = 1;
		while (x < n || y < m)
		{
			while (x < n)
			{
				cout << 'D';
				x++;
			}
			if (x == n && y == m)
				break;
			cout << 'R';
			y++;
			while (x > 1)
			{
				cout << 'U';
				x--;
			}
			cout << 'R';
			y++;
		}
	}
	else
	{
		int x = 1, y = 1;
		while (x < n || y < m)
		{
			while (y < m)
			{
				cout << 'R';
				y++;
			}
			if (x == n && y == m)
				break;
			cout << 'D';
			x++;
			while (y > 1)
			{
				cout << 'L';
				y--;
			}
			cout << 'D';
			x++;
		}
	}
}