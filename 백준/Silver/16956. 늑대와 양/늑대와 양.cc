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
char arr[511][511] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == 'S')
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c)
						continue;
					if (arr[nx][ny] == 'W')
						cnt++;
				}
				if (cnt > 0)
				{
					cout << 0 << '\n';
					return 0;
				}
			}
		}
	}
	cout << 1 << '\n';
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == '.')
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c)
						continue;
					if (arr[nx][ny] == 'W')
						arr[i][j] = 'D';
				}
			}
			cout << arr[i][j];
		}
		cout << '\n';
	}
}