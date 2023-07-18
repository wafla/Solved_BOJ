#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, L;
	cin >> n >> L;
	vector<pi> v;
	int l = 0, r = 0, l_ans = 0, r_ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x > 0)
		{
			r_ans = max(r_ans, L - x);
			v.push_back({ x, i + 1 }); // 오른쪽
			r++;
		}
		else
		{
			l_ans = max(l_ans, -x);
			v.push_back({ -x, i + 1 }); // 왼쪽
			l++;
		}
	}
	sort(v.begin(), v.end());
	if (r_ans >= l_ans)
		cout << v[l].Y << " " << r_ans << '\n';
	else
		cout << v[l - 1].Y << " " << l_ans << '\n';
}
// 참고 : https://aerocode.net/391