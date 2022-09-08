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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	ll cnt = 0;
	set<ll> S;
	vector<ll> ans;
	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		S.insert(x);
	}
	for (int i = 0; i < m; i++)
	{
		ll x;
		cin >> x;
		if (S.count(x) == 1)
		{
			ans.push_back(x);
			cnt++;
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt << '\n';
	for (auto i : ans)
		cout << i << " ";
}