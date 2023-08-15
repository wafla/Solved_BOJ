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
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> M;
	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		M[s[i]]++;
		if (M[s[i]] > maxx)
			maxx = M[s[i]];
	}
	cout << n - maxx << '\n';
}