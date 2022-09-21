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
int arr[1001] = { 0 };
bool v[1001] = { 0 };
int ans;
void dfs(int idx)
{
	v[idx] = 1;
	if (v[arr[idx]] == 0)
		dfs(arr[idx]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		memset(v, 0, sizeof(v));
		ans = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		for (int i = 1; i <= n; i++)
			if (v[arr[i]] == 0)
			{
				ans++;
				dfs(arr[i]);
			}
		cout << ans << '\n';
	}
}