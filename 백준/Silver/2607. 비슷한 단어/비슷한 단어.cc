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
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	int ans = 0;
	char arr[102][28] = { 0 };
	for (int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			arr[i][s[j] - 'A']++;
	}
	for (int i = 1; i < t; i++)
	{
		int cnt = 0, flag = 0, num = 0;
		for (int j = 0; j < 26; j++)
		{
			if (abs(arr[0][j] - arr[i][j]) == 0)
				continue;
			else if (abs(arr[0][j] - arr[i][j]) == 1)
			{
				cnt++;
				num += arr[0][j] - arr[i][j];
			}
			else
				cnt = 987654321;
		}
		if (cnt < 3 && (num == 0 || num == 1 || num == -1))
			ans++;
	}
	cout << ans << '\n';
}