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
#define INF 987654321
#define MOD 1000000007
#define ll long long
using namespace std;
ll arr[1000001] = { 0 }, n, ans;
stack<ll> st;
int main()
{
	ans = 0;
	cin >> n;
	for (ll i = 1; i <= n; i++)
		cin >> arr[i];
	st.push(0);
	for (ll i = 1; i <= n + 1; i++)
	{
		while (!st.empty() && arr[st.top()] > arr[i])
		{
			ll x = st.top();
			st.pop();
			if (ans < arr[x] * (i - st.top() - 1))
				ans = arr[x] * (i - st.top() - 1);
		}
		st.push(i);
	}
	cout << ans << endl;
}