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
#include <bitset>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pi pair<int, int>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, ans = 0, cnt = 0;
	cin >> n;
	vector<pi> v;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ y,x });
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int x = v[0].X;
	for (int i = 0; i < n; i++)
	{
		if (v[i].X < x)
			x = v[i].X;
		x -= v[i].Y;
	}
	cout << x << '\n';
}