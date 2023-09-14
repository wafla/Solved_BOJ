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
vector<vector<pi>> v(1000001);
vector<bool> visit(1000001);
int n;
int dp[1000001][2] = {0}; // 0 - 일반인, 1 - 얼리어답터
void dfs(int idx)
{
	if (visit[idx])
		return;
	visit[idx] = 1;
	dp[idx][1] = 1;
	for (int i = 0; i < v[idx].size(); i++)
	{
		int nx = v[idx][i].X;
		if (!visit[nx])
		{
			dfs(nx);
			dp[idx][0] += dp[nx][1];
			dp[idx][1] += min(dp[nx][0], dp[nx][1]);
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back({ y,1 });
		v[y].push_back({ x,1 });
	}
	dfs(1);
	cout << min(dp[1][0], dp[1][1]) << '\n';
}
// 참고 : https://hqjang.tistory.com/104