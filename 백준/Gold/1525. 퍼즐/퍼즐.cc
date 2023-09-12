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
#define T pair<int, pair<string, int>>
using namespace std;
set<string> S;
int check(string v)
{
	int flag = 0;
	flag = S.count(v) ? 1 : 0;
	S.insert(v);
	return flag;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string tmp, num = "123456780";
	int idx = 0;
	for (int i = 0; i < 9; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
			idx = i;
		tmp.push_back(x + 48);
	}
	check(tmp);
	priority_queue<T,vector<T>,greater<T>> Q;
	Q.push({ 0,{ tmp,idx } });
	while (!Q.empty())
	{
		auto cur = Q.top();
		Q.pop();
		if (cur.Y.X == num)
		{
			cout << cur.X << '\n';
			return 0;
		}
		int x = cur.Y.Y;
		if (x % 3 == 0)
		{
			int x1 = x - 3, x2 = x + 1, x3 = x + 3;
			if (x1 > -1)
			{
				string tmp_ = cur.Y.X;
				char tmp_x = tmp_[x];
				tmp_[x] = tmp_[x1];
				tmp_[x1] = tmp_x;
				if (!check(tmp_))
					Q.push({ cur.X + 1,{tmp_,x1},});
			}
			if (x2 < 9)
			{
				string tmp_ = cur.Y.X;
				char tmp_x = tmp_[x];
				tmp_[x] = tmp_[x2];
				tmp_[x2] = tmp_x;
				if (!check(tmp_))
					Q.push({ cur.X + 1,{tmp_,x2}, });
			}
			if (x3 < 9)
			{
				string tmp_ = cur.Y.X;
				char tmp_x = tmp_[x];
				tmp_[x] = tmp_[x3];
				tmp_[x3] = tmp_x;
				if (!check(tmp_))
					Q.push({ cur.X + 1,{tmp_,x3}, });
			}
		}
		else if (x % 3 == 1)
		{
			int x1 = x - 3, x2 = x - 1, x3 = x + 1, x4 = x + 3;
			if (x1 > -1)
			{
				string tmp_ = cur.Y.X;
				char tmp_x = tmp_[x];
				tmp_[x] = tmp_[x1];
				tmp_[x1] = tmp_x;
				if (!check(tmp_))
					Q.push({ cur.X + 1,{tmp_,x1}, });
			}
			if (x2 > -1)
			{
				string tmp_ = cur.Y.X;
				char tmp_x = tmp_[x];
				tmp_[x] = tmp_[x2];
				tmp_[x2] = tmp_x;
				if (!check(tmp_))
					Q.push({ cur.X + 1,{tmp_,x2}, });
			}
			if (x3 < 9)
			{
				string tmp_ = cur.Y.X;
				char tmp_x = tmp_[x];
				tmp_[x] = tmp_[x3];
				tmp_[x3] = tmp_x;
				if (!check(tmp_))
					Q.push({ cur.X + 1,{tmp_,x3}, });
			}
			if (x4 < 9)
			{
				string tmp_ = cur.Y.X;
				char tmp_x = tmp_[x];
				tmp_[x] = tmp_[x4];
				tmp_[x4] = tmp_x;
				if (!check(tmp_))
					Q.push({ cur.X + 1,{tmp_,x4}, });
			}
		}
		else if (x % 3 == 2)
		{
			int x1 = x - 3, x2 = x - 1, x3 = x + 3;
			if (x1 > -1)
			{
				string tmp_ = cur.Y.X;
				char tmp_x = tmp_[x];
				tmp_[x] = tmp_[x1];
				tmp_[x1] = tmp_x;
				if (!check(tmp_))
					Q.push({ cur.X + 1,{tmp_,x1}, });
			}
			if (x2 > -1)
			{
				string tmp_ = cur.Y.X;
				char tmp_x = tmp_[x];
				tmp_[x] = tmp_[x2];
				tmp_[x2] = tmp_x;
				if (!check(tmp_))
					Q.push({ cur.X + 1,{tmp_,x2}, });
			}
			if (x3 < 9)
			{
				string tmp_ = cur.Y.X;
				char tmp_x = tmp_[x];
				tmp_[x] = tmp_[x3];
				tmp_[x3] = tmp_x;
				if (!check(tmp_))
					Q.push({ cur.X + 1,{tmp_,x3}, });
			}
		}
	}
	cout << -1 << '\n';
}