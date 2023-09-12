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
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int x;
		cin >> x;
		cout << "Case #" << i << ": ";
		if (x > 4500)
			cout << "Round 1\n";
		else if (x > 1000)
			cout << "Round 2\n";
		else if (x > 25)
			cout << "Round 3\n";
		else
			cout << "World Finals\n";
	}
}