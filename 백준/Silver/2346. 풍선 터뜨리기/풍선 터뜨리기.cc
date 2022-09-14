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
	int n, arr[1001] = { 0 };
	bool v[1001] = { 0 };
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	vector<int> ans;
	memset(v, 0, sizeof(v));
	int idx = 1;
	while (1)
	{
		v[idx] = 1;
		ans.push_back(idx);
		int tmp = arr[idx];
		if (ans.size() == n)
			break;
		if (tmp > 0)
		{
			while (tmp)
			{
				if (idx == n)
					idx = 0;
				if (!v[idx + 1])
					tmp--;
				idx++;
				if (idx == n + 1)
					idx = 1;
			}
		}
		else
		{
			tmp = -tmp;
			while (tmp)
			{
				if (idx - 1 == 0)
					idx = n + 1;
				if (!v[idx - 1])
					tmp--;
				idx--;
				if (idx == 0)
					idx = n;
			}
		}
	}
	for (auto i : ans)
		cout << i << " ";
}