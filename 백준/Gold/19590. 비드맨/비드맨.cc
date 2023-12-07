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
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int sum = 0, maxx = 0;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
		if (v[i] > maxx)
			maxx = v[i];
	}
	if (sum - maxx < maxx)
		cout << 2 * maxx - sum << '\n';
	else
	{
		if (sum % 2)
			cout << "1\n";
		else
			cout << "0\n";
	}
}