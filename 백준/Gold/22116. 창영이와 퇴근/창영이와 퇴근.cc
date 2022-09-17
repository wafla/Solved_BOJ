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
int arr[1001][1001] = { 0 }, n;
bool v[1001][1001] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
typedef pair<int, pair<int, int>> T; //우선순위, 최대값, 좌표
void bfs()
{
	priority_queue<T, vector<T>, greater<T>> Q;
	Q.push({ 0,{0,0} });
	while (!Q.empty())
	{
		auto cur = Q.top();
		Q.pop();
		if (v[cur.Y.X][cur.Y.Y])
			continue;
		v[cur.Y.X][cur.Y.Y] = 1;
		if (cur.Y.X == n - 1 && cur.Y.Y == n - 1)
		{
			cout << cur.X << '\n';
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.Y.X + dx[i];
			int ny = cur.Y.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (v[nx][ny])
				continue;
			Q.push({ max(cur.X,abs(arr[nx][ny] - arr[cur.Y.X][cur.Y.Y])),{nx,ny} });
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	bfs();
}