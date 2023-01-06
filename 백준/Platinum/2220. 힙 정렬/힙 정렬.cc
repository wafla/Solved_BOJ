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
	vector<int> v(2);
	v[1] = 1;
	int idx = 1;
	for (int i = 2; i <= n; i++)
	{
		v.resize(i + 1);
		int tmp = idx;
		v[idx] = i;
		v[i] = 1;
		idx = i;
		while (tmp >= 2 && v[tmp] > v[tmp / 2])
		{
			swap(v[tmp], v[tmp / 2]);
			tmp /= 2;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << v[i] << " ";
}