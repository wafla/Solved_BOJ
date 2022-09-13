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
bool v[1000001] = { 0 };
int cal(int x)
{
	int cnt = 0;
	int tmp = x;
	while (tmp)
	{
		tmp /= 10;
		cnt++;
	}
	int num = 0;
	while (cnt--)
	{
		num += x % 10 * pow(10, cnt);
		x /= 10;
	}
	return num;
}
void bfs(int t, int n)
{
	memset(v, 0, sizeof(v));
	queue<pair<int,int>> Q; //숫자, 카운트
	Q.push({ 1,1 });
	v[1] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		if (cur.X == n)
		{
			cout << "Case #" << t << ": " << cur.Y << '\n';
			return;
		}
		if (cur.X > 1000000)
			continue;
		int x = cal(cur.X);
		if (v[x] == 0)
		{
			v[x] = 1;
			Q.push({ x, cur.Y + 1 });
		}
		if (v[cur.X + 1] == 0)
		{
			v[cur.X + 1] = 1;
			Q.push({ cur.X + 1, cur.Y + 1 });
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int num;
		cin >> num;
		bfs(i, num);
	}
}