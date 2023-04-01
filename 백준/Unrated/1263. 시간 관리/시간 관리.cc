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
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a > b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ y,x });
	}
	sort(v.begin(), v.end(), cmp);
	int t = v[0].X;
	for (int i = 0; i < v.size(); i++)
	{
		if (t > v[i].X)
			t -= t - v[i].X;
		t -= v[i].Y;
	}
	if (t < 0)
		cout << -1 << '\n';
	else
		cout << t << '\n';
}