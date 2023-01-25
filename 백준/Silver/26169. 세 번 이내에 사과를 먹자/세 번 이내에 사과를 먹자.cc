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
int arr[5][5] = { 0 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void dfs(int x, int y, int cnt, int sum)
{
	if (cnt >= 4)
		return;
	if (sum >= 2)
	{
		cout << 1;
		exit(0);
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
			continue;
		if (arr[nx][ny] == -1)
			continue;
		int tmp = arr[nx][ny];
		arr[nx][ny] = -1;
		dfs(nx, ny, cnt + 1, sum + tmp);
		arr[nx][ny] = tmp;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	int st, sy;
	cin >> st >> sy;
	if (arr[st][sy] == 1)
	{
		arr[st][sy] = -1;
		dfs(st, sy, 0, 1);
	}
	else
	{	
		arr[st][sy] = -1;
		dfs(st, sy, 0, 0);
	}
	cout << 0;
}