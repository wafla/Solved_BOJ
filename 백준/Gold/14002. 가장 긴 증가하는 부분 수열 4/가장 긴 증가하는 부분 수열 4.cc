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
int dp[1001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	vector<int> v;
	int cnt = 0;
	v.push_back(arr[1]);
	for (int i = 2; i <= n; i++)
	{
		if (v[cnt] < arr[i])
		{
			v.push_back(arr[i]);
			cnt++;
			dp[i] = cnt;
		}
		else
		{
			int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[idx] = arr[i];
			dp[i] = idx;
		}
	}
	vector<int> ans;
	for (int i = n; i > 0; i--)
	{
		if (dp[i] == cnt)
		{
			ans.push_back(arr[i]);
			cnt--;
		}
	}
	int ans_size = ans.size();
	cout << ans_size << '\n';
	for (int i = 0; i < ans_size; i++)
	{
		cout << ans.back() << " ";
		ans.pop_back();
	}
}
// 참고 : https://cocoon1787.tistory.com/455