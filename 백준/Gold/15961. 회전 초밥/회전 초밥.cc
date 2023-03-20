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
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	vector<int> v(2 * n);
	vector<int> num(d + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		v[i + n] = v[i];
	}
	int cnt = 0, ans = 0;
	for (int i = 0; i < k; i++)
	{
		if (num[v[i]] == 0)
			cnt++;
		num[v[i]]++;
	}
	if (num[c] == 0)
	{
		num[c] = 1;
		cnt++;
	}
	ans = max(ans, cnt);
	for (int i = k; i < n + k; i++)
	{
		if (v[i] != c && num[v[i]] == 0)
			cnt++;
		num[v[i]]++;
		num[v[i - k]]--;
		if (v[i - k] != c && num[v[i - k]] == 0)
			cnt--;
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}