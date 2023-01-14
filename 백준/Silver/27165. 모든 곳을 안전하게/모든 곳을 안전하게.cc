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
bool cmp(pair<int,int> x, pair<int,int> y)
{
	return x.X > y.X;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, x;
	cin >> n;
	vector<pair<int,int>> v(n + 1);
	vector<int> arr(n + 1);
	vector<int> cnt_v;
	int cnt = 0, ans_x, ans_y;
	for (int i = 0; i < n + 1; i++)
	{
		cin >> arr[i];
		if (arr[i] == 1)
		{
			cnt++;
			cnt_v.push_back(i);
		}
		v[i] = { arr[i],i };
	}
	sort(v.begin(), v.end(), cmp);
	cin >> x;
	if (cnt == 0)
	{
		for (int i = 0; i < n + 1; i++)
		{
			int nx = v[i].Y + x;
			if (nx <= n)
			{
				if (v[i].X <= 2)
				{
					cout << "NO\n";
					return 0;
				}
				if (arr[nx] >= 1)
				{
					cout << "YES\n";
					cout << v[i].Y << " " << nx << '\n';
					return 0;
				}
			}
		}
	}
	else if(cnt == 1)
	{
		int nx = cnt_v[0] + x;
		int ny = cnt_v[0] - x;
		if (nx <= n)
		{
			if (arr[nx] >= 1)
			{
				cout << "YES\n";
				cout << cnt_v[0] << " " << nx << '\n';
				return 0;
			}
		}
		if (ny >= 0)
		{
			if (arr[ny] >= 3)
			{
				cout << "YES\n";
				cout << ny << " " << cnt_v[0] << '\n';
				return 0;
			}
		}
		cout << "NO\n";
		return 0;
	}
	else if (cnt == 2)
	{
		if (abs(cnt_v[0] - cnt_v[1]) == x)
		{
			cout << "YES\n";
			cout << cnt_v[0] << " " << cnt_v[1] << '\n';
			return 0;
		}
		cout << "NO\n";
		return 0;
	}
	else
	{
		cout << "NO\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}