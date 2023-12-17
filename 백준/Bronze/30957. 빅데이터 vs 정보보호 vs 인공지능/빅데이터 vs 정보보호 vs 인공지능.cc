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
	string s;
	cin >> s;
	map<char, int> M;
	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		M[s[i]]++;
		if (maxx < M[s[i]])
			maxx = M[s[i]];
	}
	if (M['B'] == maxx && M['S'] == maxx && M['A'] == maxx)
		cout << "SCU\n";
	else if (M['B'] == maxx && M['S'] == maxx)
		cout << "BS\n";
	else if (M['B'] == maxx && M['A'] == maxx)
		cout << "BA\n";
	else if (M['S'] == maxx && M['A'] == maxx)
		cout << "SA\n";
	else if (M['B'] == maxx)
		cout << "B\n";
	else if (M['S'] == maxx)
		cout << "S\n";
	else if (M['A'] == maxx)
		cout << "A\n";
}