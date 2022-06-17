#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <deque>
#include <set>
#define X first
#define Y second
using namespace std;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int num, arr[5] = { 0 };
	cin >> num;
	vector<int> v1, v2;
	for (int i = 0;i < 6;i++)
	{
		int x, y;
		cin >> x >> y;
		v1.push_back(x);
		v2.push_back(y);
		arr[x]++;
	}
	for (int i = 0;i < 6;i++)
	{
		v1.push_back(v1[i]);
		v2.push_back(v2[i]);
	}
	int ans;
	for (int i = 0;i < 6;i++)
	{
		if (arr[v1[i]] == 1 && arr[v1[i + 1]] == 1)
		{
			ans = v2[i] * v2[i + 1] - v2[i + 3] * v2[i + 4];
			cout << ans * num;
			break;
		}
	}
}