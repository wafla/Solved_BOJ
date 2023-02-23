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
struct T {
	int x, y, d;
};
bool cmp(T x, T y)
{
	if (x.d == y.d)
		return x.y < y.y;
	else
		return x.d < y.d;
}
int arr[16][16] = { 0 };
int tmp[16][16] = { 0 };
int ans = 0;
int n, m, d;
bool v[16] = { 0 };
int attack(int a, int b, int c, int idx) // 적 제거
{
	int killed = 0;
	vector<T> point[3];
	for (int i = 0; i < idx; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tmp[i][j] == 1)
			{
				if (abs(idx - i) + abs(a - j) <= d)
					point[0].push_back({ i,j, abs(idx - i) + abs(a - j) });
				if (abs(idx - i) + abs(b - j) <= d)
					point[1].push_back({ i,j, abs(idx - i) + abs(b - j) });
				if (abs(idx - i) + abs(c - j) <= d)
					point[2].push_back({ i,j, abs(idx - i) + abs(c - j) });
			}
		}
	}
	for (int i = 0; i < 3; i++)
		if(!point[i].empty())
			sort(point[i].begin(), point[i].end(), cmp);
	for (int i = 0; i < 3; i++)
	{
		if (point[i].empty())
			continue;
		int x = point[i][0].x;
		int y = point[i][0].y;
		if (tmp[x][y] == 1)
		{
			killed++;
			tmp[x][y] = 0;
		}
	}
	return killed;
}
void check(int a, int b, int c) // 시뮬레이션
{
	int ans_tmp = 0;
	for (int i = n; i >= 1; i--)
		ans_tmp += attack(a, b, c, i);
	if (ans_tmp > ans)
		ans = ans_tmp;
	return;
}
void select(int idx, int cnt) // 3개 고르기
{
	if (cnt == 3)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tmp[i][j] = arr[i][j];
		vector<int> num;
		for (int i = 0; i < m; i++)
			if (v[i])
				num.push_back(i);
		check(num[0], num[1], num[2]);
		return;
	}
	for (int i = idx; i < m; i++)
	{
		if (!v[i])
		{
			v[i] = 1;
			select(i, cnt + 1);
			v[i] = 0;
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < m; i++)
		select(i, 0);
	cout << ans << '\n';
}