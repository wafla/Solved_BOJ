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
char arr[27][27] = { 0 };
struct point {
	int up = 0;
	int down = 0;
	int right = 0;
	int left = 0;
};
point points[27][27];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	int m_flag = 0, z_flag = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == '|')
			{
				if (arr[i + 1][j] == '.')
					points[i + 1][j].up = 1;
				if (arr[i - 1][j] == '.')
					points[i - 1][j].down = 1;
			}
			else if (arr[i][j] == '-')
			{
				if (arr[i][j - 1] == '.')
					points[i][j - 1].right = 1;
				if (arr[i][j + 1] == '.')
					points[i][j + 1].left = 1;
			}
			else if (arr[i][j] == '+')
			{
				if (arr[i + 1][j] == '.')
					points[i + 1][j].up = 1;
				if (arr[i - 1][j] == '.')
					points[i - 1][j].down = 1;
				if (arr[i][j - 1] == '.')
					points[i][j - 1].right = 1;
				if (arr[i][j + 1] == '.')
					points[i][j + 1].left = 1;
			}
			else if (arr[i][j] == '1')
			{
				if (arr[i + 1][j] == '.')
					points[i + 1][j].up = 1;
				if (arr[i][j + 1] == '.')
					points[i][j + 1].left = 1;
			}
			else if (arr[i][j] == '2')
			{
				if (arr[i - 1][j] == '.')
					points[i - 1][j].down = 1;
				if (arr[i][j + 1] == '.')
					points[i][j + 1].left = 1;
			}
			else if (arr[i][j] == '3')
			{
				if (arr[i - 1][j] == '.')
					points[i - 1][j].down = 1;
				if (arr[i][j - 1] == '.')
					points[i][j - 1].right = 1;
			}
			else if (arr[i][j] == '4')
			{
				if (arr[i + 1][j] == '.')
					points[i + 1][j].up = 1;
				if (arr[i][j - 1] == '.')
					points[i][j - 1].right = 1;
			}
		}
	}
	int x = 0, y = 0, sum = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (points[i][j].up + points[i][j].down + points[i][j].left + points[i][j].right > sum)
			{
				sum = points[i][j].up + points[i][j].down + points[i][j].left + points[i][j].right;
				x = i;
				y = j;
			}
		}
	}
	if (sum == 0)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] == 'Z')
				{
					if (i - 1 >= 0 && arr[i - 1][j] == '.')
						points[i - 1][j].down = 1;
					if (i + 1 < r && arr[i + 1][j] == '.')
						points[i + 1][j].up = 1;
					if (j - 1 >= 0 && arr[i][j - 1] == '.')
						points[i][j - 1].right = 1;
					if (j + 1 < c && arr[i][j + 1] == '.')
						points[i][j + 1].left = 1;
				}
				else if (arr[i][j] == 'M')
				{
					if (i - 1 >= 0 && arr[i - 1][j] == '.')
						points[i - 1][j].down = 1;
					if (i + 1 < r && arr[i + 1][j] == '.')
						points[i + 1][j].up = 1;
					if (j - 1 >= 0 && arr[i][j - 1] == '.')
						points[i][j - 1].right = 1;
					if (j + 1 < c && arr[i][j + 1] == '.')
						points[i][j + 1].left = 1;
				}
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (points[i][j].up + points[i][j].down + points[i][j].left + points[i][j].right > sum)
				{
					sum = points[i][j].up + points[i][j].down + points[i][j].left + points[i][j].right;
					x = i;
					y = j;
				}
			}
		}
	}
	cout << x + 1 << " " << y + 1 << " ";
	if (points[x][y].up == 1 && points[x][y].down == 1 && points[x][y].left == 1 && points[x][y].right == 1)
		cout << '+' << '\n';
	else if (points[x][y].left == 1 && points[x][y].right == 1)
		cout << '-' << '\n';
	else if (points[x][y].up == 1 && points[x][y].down == 1)
		cout << '|' << '\n';
	else if (points[x][y].down && points[x][y].right == 1)
		cout << '1' << '\n';
	else if (points[x][y].up == 1 && points[x][y].right == 1)
		cout << '2' << '\n';
	else if (points[x][y].up == 1 && points[x][y].left == 1)
		cout << '3' << '\n';
	else if (points[x][y].left == 1 && points[x][y].down == 1)
		cout << '4' << '\n';
}