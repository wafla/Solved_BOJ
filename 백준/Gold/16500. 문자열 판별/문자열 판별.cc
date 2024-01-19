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
#define T pair<int, pi>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string> v(n);
	vector<bool> dp(s.size() + 1);
	for (auto& i : v)
		cin >> i;
	dp[0] = 1;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (dp[i] && v[j][0] == s[i])
			{
				int flag = 1, idx = i;
				for (int k = 0; k < v[j].size(); k++)
				{
					if (idx >= s.size() || v[j][k] != s[idx])
					{
						flag = 0;
						break;
					}
					idx++;
				}
				if (flag)
					dp[idx] = 1;
			}
		}
	}
	cout << dp[s.size()] ? 1 : 0 << '\n';
}