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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int m, n;
	cin >> m >> n;
	int x = 0, y = 0, dir = 0; // 0 - 오른쪽 1 - 아래쪽 2 - 왼쪽 3 - 위쪽
	for (int i = 0; i < n; i++)
	{
		string s;
		int num;
		cin >> s >> num;
		if (s[0] == 'M')
		{
			if (dir == 0)
				x += num;
			else if (dir == 1)
				y -= num;
			else if (dir == 2)
				x -= num;
			else if (dir == 3)
				y += num;
			if (x > m || x < 0 || y > m || y < 0)
			{
				cout << -1;
				return 0;
			}
		}
		else if (s[0] == 'T')
		{
			if (num == 0)
			{
				if (dir == 0)
					dir = 3;
				else if (dir == 1)
					dir = 0;
				else if (dir == 2)
					dir = 1;
				else if (dir == 3)
					dir = 2;
			}
			else if (num == 1)
			{
				if (dir == 0)
					dir = 1;
				else if (dir == 1)
					dir = 2;
				else if (dir == 2)
					dir = 3;
				else if (dir == 3)
					dir = 0;
			}
		}
	}
	cout << x << " " << y;
}