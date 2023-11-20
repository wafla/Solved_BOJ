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
	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
        if(s.size() == 3)
		    v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (auto i : v)
	{
		cout << i << '\n';
		return 0;
	}
}