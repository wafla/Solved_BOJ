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
		int n;
		cin >> n;
		vector<int> v(n);
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			if (v[i] == 2)
				cnt++;
		}
		int chk = 0, num = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] == 2)
			{
				num++;
				cnt--;
			}
			if (num == cnt)
			{
				chk = i + 1;
				break;
			}
		}
		if (!chk)
			cout << -1 << '\n';
		else
			cout << chk << '\n';
	}
}