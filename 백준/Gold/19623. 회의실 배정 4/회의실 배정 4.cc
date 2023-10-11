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
using namespace std;
vector<pair<pi, int>> v;
vector<int> dp, s_time;
int n;
int solve(int idx)
{
	if (idx >= n)
		return 0;
	int& ret = dp[idx];
	if (ret != -1)
		return ret;
	// 안겹치는 다음 시작 시간 찾기
	int x = lower_bound(s_time.begin(), s_time.end(), v[idx].X.Y) - s_time.begin();
	ret = max(solve(idx + 1), v[idx].Y + solve(x));
	return ret;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].X.X >> v[i].X.Y >> v[i].Y;
	sort(v.begin(), v.end());
	
	dp.resize(n, -1);
	s_time.resize(n);
	for (int i = 0; i < n; i++)
		s_time[i] = v[i].X.X;

	cout << solve(0) << '\n';
}
// 참고 : https://leesh111112.tistory.com/486