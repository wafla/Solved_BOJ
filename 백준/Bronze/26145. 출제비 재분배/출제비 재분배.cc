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
ll arr[2001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + m; j++)
		{
			ll x;
			cin >> x;
			arr[j] += x;
			arr[i] -= x;
		}
	}
	for (int i = 0; i < n + m; i++)
		cout << arr[i] << " ";
}