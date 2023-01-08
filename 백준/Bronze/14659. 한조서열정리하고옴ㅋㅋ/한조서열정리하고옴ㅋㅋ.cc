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
	vector<int> v(n);
	int ans = 0, cnt;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] > v[j])
				cnt++;
			else
			{
				i = j - 1;
				break;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}