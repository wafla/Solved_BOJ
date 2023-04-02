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
	vector<int> a(n), b(n);
	map<int, int> M;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		M[a[i]]++;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j * j <= a[i]; j++)
		{
			if (a[i] % j == 0)
			{
				if (a[i] / j == j)
					b[i] += M[j];
				else
					b[i] += M[j] + M[a[i] / j];
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << b[i] - 1 << '\n';
}