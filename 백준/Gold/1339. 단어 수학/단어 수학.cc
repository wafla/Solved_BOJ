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
	map<char, int> M;
	vector<string> vs;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		vs.push_back(s);
		for (int j = s.size() - 1; j >= 0; j--)
			M[s[s.size() - 1 - j]] += pow(10, j);
	}
	vector<pair<int, char>> v;
	for (auto i : M)
		v.push_back({i.second, i.first});
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int num = 9;
	for (auto i : v)
		M[i.Y] = num--;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < vs[i].size(); j++)
			vs[i][j] = M[vs[i][j]] + 48;
		ans += stoi(vs[i]);
	}
	cout << ans << '\n';
}