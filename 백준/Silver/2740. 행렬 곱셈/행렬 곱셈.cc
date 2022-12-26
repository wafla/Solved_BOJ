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
	int n, m, k;
	cin >> n >> m;
	int a[101][101] = { 0 }, b[101][101] = { 0 }, c[101][101] = { 0 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	cin >> m >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			cin >> b[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int sum = 0;
			for (int p = 0; p < m; p++)
				sum += a[i][p] * b[p][j];
			c[i][j] = sum;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << c[i][j] << " ";
		cout << '\n';
	}
}