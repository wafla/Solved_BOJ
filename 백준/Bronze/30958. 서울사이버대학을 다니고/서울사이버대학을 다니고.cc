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
	cin.ignore();
	getline(cin, s);
	map<char, int> M;
	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		if(s[i]>=97 && s[i]<=122)
			M[s[i]]++;
		if (maxx < M[s[i]])
			maxx = M[s[i]];
	}
	cout << maxx << '\n';
}