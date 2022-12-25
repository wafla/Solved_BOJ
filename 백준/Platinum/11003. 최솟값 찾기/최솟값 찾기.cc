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
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push({ x,i });
		while (pq.top().Y <= i - l)
			pq.pop();
		cout << pq.top().X << " ";
	}
}