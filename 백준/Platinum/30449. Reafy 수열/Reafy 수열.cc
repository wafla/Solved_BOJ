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
#define pi pair<int,int>
using namespace std;
int dp[5001][5001] = { 0 };
bool cmp(pi &a, pi &b)
{
	return a.X * b.Y < a.Y * b.X;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<pi> v;
	v.emplace_back(1,1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i][j] = j ? dp[j][i % j] : i; // j와 i % j의 최대 공약수
			if (dp[i][j] == 1) 
				v.emplace_back(j, i);
		}
	}
	nth_element(v.begin(), v.begin() + k - 1, v.end(), cmp);
	cout << v[k - 1].X << " " << v[k - 1].Y << '\n';
}