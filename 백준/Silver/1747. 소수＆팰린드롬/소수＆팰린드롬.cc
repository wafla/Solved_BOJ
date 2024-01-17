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
bool prime[1003002] = { 0 };
int maxx = 1003001;
int check(int num)
{
	string  s = to_string(num);
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] == s[s.size() - 1 - i])
			continue;
		else
			return 0;
	}
	return 1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	prime[1] = 1;
	for (int i = 2; i <= maxx; i++)
		if (!prime[i])
			for (int j = 2; i * j <= maxx; j++)
				prime[i * j] = 1;
	for (int i = n; i <= maxx; i++)
		if (!prime[i] && check(i))
		{
			cout << i << '\n';
			return 0;
		}
}