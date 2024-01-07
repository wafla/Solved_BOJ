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
bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	cin.ignore();
	vector<string> v1;
	vector<string> v2;
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		if (s.size() > 7)
		{
			if (s.substr(0, 7) == "boj.kr/")
				v2.push_back(s);
			else
				v1.push_back(s);
		}
		else
			v1.push_back(s);
	}
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	for (auto i : v1)
		cout << i << '\n';
	for (auto i : v2)
		cout << i << '\n';
}
