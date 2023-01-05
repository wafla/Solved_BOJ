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
bool cmp(ll x, ll y)
{
	return x > y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	for(int k = 1; k<=t; k++)
	{
		int n;
		cin >> n;
		vector<ll> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), cmp);
		ll sum = 0;
		for (int i = 0; i < n; i++)
			sum += a[i] * b[i];
		cout << "Case #" << k << ": " << sum << '\n';
	}
}