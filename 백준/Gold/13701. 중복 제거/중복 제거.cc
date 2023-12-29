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
#include <bitset>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
bitset<33554432> bits;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	while (cin >> n)
	{
		if (bits[n])
			continue;
		bits[n] = 1;
		cout << n << " ";
	}
}