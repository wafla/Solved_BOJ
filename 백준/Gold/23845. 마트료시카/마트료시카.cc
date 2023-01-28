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
	int n;
	cin >> n;
	vector<ll> v(n);
	map<ll, ll> M;
	set<ll> S;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		M[v[i]]++;
		S.insert(v[i]);
	}
	while (!S.empty())
	{
		vector<ll> num;
		ll maxx = *S.begin();
		for (auto it = S.begin(); it != S.end(); it++)
		{
			if (it != S.begin())
			{
				ll x = *it;
				auto z = it;
				if (x - 1 == *(--z))
				{
					M[*z]--;
					num.push_back(*z);
					maxx = x;
				}
				else
					break;
			}
		}
		M[maxx]--;
		num.push_back(maxx);
		ans += num.size() * num[num.size() - 1];
		for (auto i : num)
			if (M[i] == 0)
				S.erase(i);
	}
	cout << ans << '\n';
}