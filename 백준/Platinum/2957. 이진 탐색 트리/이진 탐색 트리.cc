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
	set<int> S;
	map<int, ll> M;
	int x;
	cin >> x;
	S.insert(x);
	S.insert(0);
	S.insert(n + 1);
	M[x] = 0;
	M[0] = 0;
	M[n + 1] = 0;
	cout << "0\n";
	ll sum = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		auto mn = S.upper_bound(x);
		auto mx = mn--;
		S.insert(x);
		M[x] = max(M[*mn], M[*mx]) + 1;
		sum += M[x];
		cout << sum << '\n';
	}
}