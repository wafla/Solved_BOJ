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
int arr[100001] = { 0 }, dp[100001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}
	int maxx = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] <= arr[i + 1] && dp[i] + 1 > dp[i + 1])
		{
			dp[i + 1] = dp[i] + 1;
			if (maxx < dp[i + 1])
				maxx = dp[i + 1];
		}
	}
	for (int i = 0; i < n; i++)
		dp[i] = 1;
	for (int i = n - 1; i > 0; i--)
	{
		if (arr[i] <= arr[i - 1] && dp[i] + 1 > dp[i - 1])
		{
			dp[i - 1] = dp[i] + 1;
			if (maxx < dp[i - 1])
				maxx = dp[i - 1];
		}
	}
	cout << maxx;
}