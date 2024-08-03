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
#include <unordered_map>
#include <tuple>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define LINF 9223372036854775807
#define MOD 1000000000
#define ll long long
#define int long long
#define pi pair<int, int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int cnt[21] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j <= 20; j++)
			if (1 << j & x)
				cnt[j]++;
	}
	int ans = 0;
	for (int j = 0; j < 20; j++)
		ans += (1 << j) * cnt[j] * (n - cnt[j]);
	cout << ans << '\n';
}
// 참고 : https://blog.naver.com/jinhan814/222334243929