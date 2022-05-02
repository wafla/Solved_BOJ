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
#define x first
#define y second
using namespace std;
int parent[1000001] = { 0 };
int find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}
void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	parent[u] = v;
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int g, p, ans = 0;
	cin >> g >> p;
	for (int i = 1;i <= g;i++)
		parent[i] = i;
	for (int i = 1;i <= p;i++)    //union-find
	{
		int x;
		cin >> x;
		int docking = find(x);
		if (docking != 0)
		{
			merge(docking, docking - 1);
			ans++;
		}
		else
			break;
	}
	cout << ans;
}
//참고 : https://mygumi.tistory.com/245