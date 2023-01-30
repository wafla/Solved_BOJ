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
	int t, s;
	cin >> t >> s;
	if (t <= 11)
		cout << 280 << '\n';
	else if (t <= 16)
	{
		if (s == 1)
			cout << 280 << '\n';
		else
			cout << 320 << '\n';
	}
	else
		cout << 280 << '\n';
}