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
	int cnt[31][2] = { 0 };
	int p[100001] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		p[i] = p[i - 1] ^ a;
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 30; j++)
			cnt[j][(bool)(p[i] & (1 << j))]++;

	int ans = 0;
	for (int i = 0; i < 30; i++)
		ans += (1LL << i) * cnt[i][0] * cnt[i][1];
	cout << ans << '\n';
}
// 참고 : https://kth990303.tistory.com/187