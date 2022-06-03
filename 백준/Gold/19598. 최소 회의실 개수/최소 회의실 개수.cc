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
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0;i < n;i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> Q;
	Q.push(v[0].Y);
	for (int i = 1;i < n;i++)
	{
		Q.push(v[i].Y);
		if (Q.top() <= v[i].X)
			Q.pop();
	}
	cout << Q.size();
}