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
#include <iomanip>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define T pair<pair<double, double>, double>
using namespace std;
vector<T> v;
int n;
double dist(T a,T b)
{
	return sqrt((a.X.X - b.X.X) * (a.X.X - b.X.X) + (a.X.Y - b.X.Y) * (a.X.Y - b.X.Y)) - a.Y - b.Y;
}
double solve(int l, int r)
{
	int size = r - l + 1;

	if (size == 2)
		return dist(v[l], v[r]);
	else if (size == 3)
		return min(dist(v[l], v[l + 1]), min(dist(v[l], v[r]), dist(v[l + 1], v[r])));

	int mid = (l + r) / 2;
	double ret = min(solve(l, mid), solve(mid + 1, r));

	vector<T> p;
	p.reserve(n);

	double line = (v[mid].X.X + v[mid + 1].X.X) / 2;
	double R = 0;
	for (int i = l; i <= r; i++)
		if (v[i].Y >= R)
			R = v[i].Y;

	for (int i = l; i <= r; i++)
		if (v[i].X.X >= line - ret - 2 * R && v[i].X.X <= line + ret + 2 * R)
			p.push_back({ { v[i].X.Y, v[i].X.X },v[i].Y });
	sort(p.begin(), p.end());

	for (int i = 0; i < p.size(); i++)
	{
		for (int j = i + 1; j < p.size(); j++)
		{
			if (p[j].X.X - p[i].X.X >= ret + 2 * R)
				break;
			ret = min(ret, dist(p[i], p[j]));
		}
	}

	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		v.clear();
		for (int i = 0; i < n; i++)
		{
			double r, x, y;
			cin >> r >> x >> y;
			v.push_back({ {x,y},r });
		}
		sort(v.begin(), v.end());
        cout.precision(12);
		cout << solve(0, n - 1) << '\n';
	}
}