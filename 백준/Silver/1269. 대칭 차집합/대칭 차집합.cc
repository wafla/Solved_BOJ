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
	set<int> A;
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		int x;
		cin >> x;
		A.insert(x);
	}
	for (int i = 0;i < m;i++)
	{
		int x;
		cin >> x;
		if (A.count(x))
			A.erase(x);
		else
			A.insert(x);
	}
	cout << A.size();

}