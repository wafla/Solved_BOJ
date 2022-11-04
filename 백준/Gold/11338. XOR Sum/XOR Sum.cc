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
	int t;
	cin >> t;
	while (t--)
	{
		int q, k;
		cin >> q >> k;
		priority_queue<int, vector<int>, greater<int>> Q;
		int num = 0;
		for (int i = 0; i < q; i++)
		{
			string s;
			ll x;
			cin >> s;
			if (s[0] == 'i')
			{
				cin >> x;
				Q.push(x);
				num ^= x;
			}
			else if (s[0] == 'p')
			{
				while (Q.size() > k)
				{
					num ^= Q.top();
					Q.pop();
				}
				cout << num << '\n';
			}
		}
	}
}