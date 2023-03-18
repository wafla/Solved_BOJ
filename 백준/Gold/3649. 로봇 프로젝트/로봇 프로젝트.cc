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
int L = 10000000;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int x;
	while (cin >> x)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		int left = 0, right = n - 1;
		int flag = 0;
		while (left < right)
		{
			if (v[left] + v[right] == x * L)
			{
				flag = 1;
				cout << "yes " << v[left] << " " << v[right] << '\n';
				break;
			}
			else if (v[left] + v[right] > x * L)
				right--;
			else if (v[left] + v[right] < x * L)
				left++;
		}
		if (!flag)
			cout << "danger\n";
	}
}