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
#define MOD 10000000000
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<pi, int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < v.size(); i++)
		v[i] = i + 1;
	int idx = k - 1;
	string ans = "";
	ans += "<";
	while (v.size())
	{
		if (idx >= v.size())
			idx = idx - v.size();
		else
		{
			ans += to_string(v[idx]) + ", ";
			v.erase(v.begin() + idx);
			idx += k - 1;
		}
	}
	ans.erase(ans.begin() + ans.size() - 1);
	ans.erase(ans.begin() + ans.size() - 1);
	ans += ">";
	for (auto i : ans)
		cout << i;
}