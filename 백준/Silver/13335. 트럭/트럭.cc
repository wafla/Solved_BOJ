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
	int n, w, L;
	cin >> n >> w >> L;
	deque<int> dq(n);
	queue<int> q;
	for (int i = 0; i < n; i++)
		cin >> dq[i];
	int ans = 0, sum = 0;
	while (!dq.empty() || sum)
	{
		if (q.size() >= w)
		{
			sum -= q.front();
			q.pop();
		}
		if (!dq.empty())
		{
			if (sum + dq.front() <= L)
			{
				sum += dq.front();
				q.push(dq.front());
				dq.pop_front();
			}
			else
				q.push(0);
		}
		else
			q.push(0);
		ans++;
	}
	cout << ans << '\n';
}