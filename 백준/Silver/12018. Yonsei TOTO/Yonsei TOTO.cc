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
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int p, l;
		cin >> p >> l;
		vector<int> v(p);
		for (int j = 0; j < p; j++)
			cin >> v[j];
		sort(v.begin(), v.end(), cmp);
		if (p >= l)
			arr.push_back(v[l - 1]);
		else
			arr.push_back(1);
	}
	sort(arr.begin(), arr.end());
	int cnt = 0, sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
		if (sum > m)
			break;
		else
			cnt++;
	}
	cout << cnt << '\n';
}