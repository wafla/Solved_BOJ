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
ll arr[1000001] = { 0 };
int n;
vector<ll> min_tree;
void buildRec(const ll arr[], ll node, ll nodeLeft, ll nodeRight)
{
	if (nodeLeft == nodeRight)
	{
		min_tree[node] = arr[nodeLeft];
		return;
	}
	ll mid = nodeLeft + (nodeRight - nodeLeft) / 2;
	buildRec(arr, node * 2, nodeLeft, mid);
	buildRec(arr, node * 2 + 1, mid + 1, nodeRight);
	min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
	return;
}
void build(const ll arr[], ll size)
{
	ll N = size;
	min_tree.resize(N * 4);
	buildRec(arr, 1, 0, N - 1);
}
ll queryRec(ll left, ll right, ll node, ll nodeLeft, ll nodeRight)
{
	if (right < nodeLeft || nodeRight < left)
		return INF;
	if (left <= nodeLeft && nodeRight <= right)
		return min_tree[node];
	
	ll mid = nodeLeft + (nodeRight - nodeLeft) / 2;
	ll l, r;
	l = queryRec(left, right, node * 2, nodeLeft, mid);
	r = queryRec(left, right, node * 2 + 1, mid + 1, nodeRight);
	return min(l, r);
}
ll query(ll left, ll right)
{
	return queryRec(left, right, 1, 1, n);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	build(arr, n);
	for (int i = 0; i < m; i++)
	{
		ll a, b;
		cin >> a >> b;
		cout << query(a, b) << '\n';
	}
}