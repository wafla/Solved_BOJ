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
	int n, m, arr[51] = { 0 };
	cin >> n >> m;
	deque<int> D(n);
	for (int i = 0; i < n; i++)
		D[i] = i + 1;
	for (int i = 0; i < m; i++)
		cin >> arr[i];
	int idx = 0, ans = 0;
	while (idx < m)
	{
		if (D.front() == arr[idx])
		{
			D.pop_front();
			idx++;
		}
		else if (D.back() == arr[idx])
		{
			D.pop_back();
			idx++;
			ans++;
		}
		else
		{
			int num;
			for (int i = 0; i < D.size(); i++)
				if (D[i] == arr[idx])
				{
					num = i;
					break;
				}
			if (num < D.size() - num)
			{
				while (D.front() != arr[idx])
				{
					int x = D.front();
					D.pop_front();
					D.push_back(x);
					ans++;
				}
			}
			else
			{
				while (D.back() != arr[idx])
				{
					int x = D.back();
					D.pop_back();
					D.push_front(x);
					ans++;
				}
			}
		}
	}
	cout << ans;
}