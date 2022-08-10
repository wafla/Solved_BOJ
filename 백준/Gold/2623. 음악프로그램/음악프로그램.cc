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
vector<int> v[1001];
vector<int> ans;
int arr[1001] = { 0 };
int n, m;
void solve()
{
	queue<int> Q;
	for (int i = 1; i <= n; i++)
		if (!arr[i])
			Q.push(i);
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		ans.push_back(cur);
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			arr[next]--;
			if (!arr[next])
				Q.push(next);
		}
	}
	if (ans.size() != n)
		cout << 0 << '\n';
	else
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int num;
	cin >> n >> m;
	while (m--)
	{
		cin >> num;
		int prev;
		cin >> prev;
		for (int i = 0; i < num - 1; i++)
		{
			int x;
			cin >> x;
			v[prev].push_back(x);
			arr[x]++;
			prev = x;
		}
	}
	solve();
}
//참고 : https://seokjin2.tistory.com/54