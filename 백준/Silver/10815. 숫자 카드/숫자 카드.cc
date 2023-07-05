#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <math.h>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pi pair<int, int>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m, x;
	set<int> S;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		S.insert(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		if (S.count(x))
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	cout << '\n';
}