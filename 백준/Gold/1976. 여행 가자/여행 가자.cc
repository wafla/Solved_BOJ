#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
int parent[201] = { 0 };
vector<int> arr;
int getParent(int parent[], int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent, parent[x]);
}
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
		return 0;
	else
		return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
			parent[i] = i;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a;
			cin >> a;
			if (a == 1)
				unionParent(parent, i, j);
		}
	}
	int sum = 0;
	arr.push_back(0);
	for (int i = 1; i <= m; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin()+1, arr.end());
	for (int i = 1; i <= m; i++)
		sum += parent[arr[i]];
	if (sum == arr[1] * m)
		cout << "YES";
	else
		cout << "NO";
}
//참고 : https://blog.naver.com/ndb796/221230967614