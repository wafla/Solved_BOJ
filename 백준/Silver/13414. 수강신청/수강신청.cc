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
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int k, l;
	cin >> k >> l;
	map<string, vector<int>> M;
	set<string> S;
	for (int i = 0; i < l; i++)
	{
		string s;
		cin >> s;
		M[s].push_back(i);
		S.insert(s);
	}
	vector<pair<int, string>> ans;
	for (auto i : S)
		ans.push_back({ M[i].back(), i });
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size() && i < k; i++)
		cout << ans[i].Y << '\n';
}