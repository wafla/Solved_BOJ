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
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	map<ll, ll> M;
	set<ll> S;
	S.insert(-1);
	S.insert(n);
	M[-1] = 0;
	M[n] = 0;
	int x;
	cin >> x;
	M[x] = 1;
	S.insert(x);
	ll sum = 1;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		auto mx = S.upper_bound(x);
		auto mn = mx--;
		S.insert(x);
		M[x] = max(M[*mx], M[*mn]) + 1;
		sum += M[x];
	}
	cout << sum << '\n';
}