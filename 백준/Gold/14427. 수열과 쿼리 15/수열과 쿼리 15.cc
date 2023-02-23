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
#define T pair<int,int>
using namespace std;
int arr[100001] = { 0 };
map<int, int> M;
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	priority_queue<T, vector<T>, greater<T>> PQ;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		PQ.push({ arr[i], i + 1 });
		M[i + 1] = arr[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c;
			PQ.push({ c, b });
			M[b] = c;
		}
		else if (a == 2)
		{
			while(M[PQ.top().Y] != PQ.top().X)
				PQ.pop();
			cout << PQ.top().Y << '\n';
		}
	}
}