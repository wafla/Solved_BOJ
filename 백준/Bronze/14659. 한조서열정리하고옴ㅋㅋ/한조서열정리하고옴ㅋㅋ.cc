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
	vector<int> v(n);
	int ans = 0, cnt = 0;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int idx = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[idx] > v[i])
			cnt++;
		else
		{
			cnt = 0;
			idx = i;
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}