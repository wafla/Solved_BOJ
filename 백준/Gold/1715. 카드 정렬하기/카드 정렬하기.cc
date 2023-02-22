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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i = 0; i < n; i++)
	{
		int x; 
		cin >> x;
		PQ.push(x);
	}
	ll ans = 0;
	while (PQ.size()>1)
	{
		int a = PQ.top();
		PQ.pop();
		int b = PQ.top();
		PQ.pop();
		ans += a + b;
		PQ.push(a + b);
	}
	cout << ans << '\n';
}