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
bool visited[10000001] = { 0 };
vector<ll> prime;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	ll a, b, ans = 0;
	cin >> a >> b;
	for (ll i = 2; i <= 10000000; i++)
	{
		if (visited[i])
			continue;
		prime.push_back(i);
		for (ll j = 1; i * j <= 10000000; j++)
			visited[i * j] = 1;
	}
	for (ll i = 0; i < prime.size(); i++)
	{
		ll num = prime[i];
		ll tmp = num;
		while (tmp <= b / num) // tmp * num <= b는 오버플로우 날 수 있음
		{
			tmp *= num;
			if (tmp >= a)
				ans++;
		}
	}
	cout << ans;
}
// 참고 : https://mapocodingpark.blogspot.com/2020/06/1456.html