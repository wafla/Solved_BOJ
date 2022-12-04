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
int arr[100001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int maxx = -INF;
	int sum = 0;
	int idx = 0;
	while (idx < k)
	{
		sum += arr[idx];
		idx++;
	}
	if (maxx < sum)
		maxx = sum;
	for (; idx < n; idx++)
	{
		sum -= arr[idx - k];
		sum += arr[idx];
		if (maxx < sum)
			maxx = sum;
	}
	cout << maxx;
}