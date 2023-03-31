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
int arr[10001] = { 0 }, n;
int tmp[10001] = { 0 };
vector<pair<int, int>> ans;
vector<pair<int,int>> check()
{
	vector<pair<int, int>> v;
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] != i)
		{
			x = i;
			int j = i;
			while (j < n && (arr[j] + 1 == arr[j + 1] || arr[j]-1==arr[j+1]))
				j++;
			y = j;
			v.push_back({ x,y });
			i = j;
		}
	}
	return v;
}
vector<pair<int, int>> check_t()
{
	vector<pair<int, int>> v;
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++)
	{
		if (tmp[i] != i)
		{
			x = i;
			int j = i;
			while (j < n && (tmp[j] + 1 == tmp[j + 1] || tmp[j] - 1 == tmp[j + 1]))
				j++;
			y = j;
			v.push_back({ x,y });
			i = j;
		}
	}
	return v;
}
int flip(int x, int y)
{
	for (int i = 1; i <= n; i++)
		tmp[i] = arr[i];
	int idx = y;
	for (int i = x; i <= idx; i++)
	{
		int t = tmp[idx];
		tmp[idx] = tmp[i];
		tmp[i] = t;
		idx--;
	}
	vector<pair<int, int>> v = check_t();
	if (v.size() == 1)
		return 1;
	else
		return 0;
}
void f(int x, int y)
{
	int idx = y;
	for (int i = x; i <= idx; i++)
	{
		int t = arr[idx];
		arr[idx] = arr[i];
		arr[i] = t;
		idx--;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 0; i < 2; i++)
	{
		vector<pair<int, int>> v = check();
		if (v.size() == 0)
			cout << 1 << " " << 1 << '\n';
		else if (v.size() == 1)
		{
			cout << v[0].X << " " << v[0].Y << '\n';
			f(v[0].X, v[0].Y);
		}
		else if (v.size() == 2)
		{
			int flag = 0;
			if (flip(v[0].X, v[0].Y))
			{
				cout << v[0].X << " " << v[0].Y << '\n';
				f(v[0].X, v[0].Y);
			}
			else if (flip(v[1].X, v[1].Y))
			{
				cout << v[1].X << " " << v[1].Y << '\n';
				f(v[1].X, v[1].Y);
			}
			else if (flip(v[0].X, v[1].X))
			{
				cout << v[0].X << " " << v[1].X << '\n';
				f(v[0].X, v[1].X);
			}
			else if (flip(v[0].Y, v[1].Y))
			{
				cout << v[0].Y << " " << v[1].Y << '\n';
				f(v[0].Y, v[1].Y);
			}
		}
		else if (v.size() == 3)
		{
			if (flip(v[0].X, v[1].Y))
			{
				cout << v[0].X << " " << v[1].Y << '\n';
				f(v[0].X, v[1].Y);
			}
			else if (flip(v[0].X, v[2].Y))
			{
				cout << v[0].X << " " << v[2].Y << '\n';
				f(v[0].X, v[2].Y);
			}
			else if (flip(v[1].X, v[2].Y))
			{
				cout << v[1].X << " " << v[2].Y << '\n';
				f(v[1].X, v[2].Y);
			}
		}
	}
}