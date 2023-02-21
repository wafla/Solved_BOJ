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
ll arr[100001] = { 0 };
int n;
vector<pair<ll,ll>> tree;
pair<ll,ll> merge(pair<ll,ll> left, pair<ll,ll> right)
{
	return min(left, right);
}
pair<ll,ll> buildRec(const ll arr[], ll node, ll nodeLeft, ll nodeRight)
{
	if (nodeLeft == nodeRight)
		return { tree[node].X = arr[nodeLeft], tree[node].Y = nodeLeft + 1 };

	ll mid = nodeLeft + (nodeRight - nodeLeft) / 2;
	pair<ll,ll> leftVal = buildRec(arr, node * 2, nodeLeft, mid);
	pair<ll,ll> rightVal = buildRec(arr, node * 2 + 1, mid + 1, nodeRight);

	return tree[node] = merge(leftVal, rightVal);
}
void build(const ll arr[], ll size)
{
	ll N = size;
	tree.resize(N * 4);
	buildRec(arr, 1, 0, N - 1);
}
pair<ll,ll> queryRec(ll left, ll right, ll node, ll nodeLeft, ll nodeRight)
{
	if (right < nodeLeft || nodeRight < left)
		return { INF,INF };
	if (left <= nodeLeft && nodeRight <= right)
		return tree[node];
	
	ll mid = nodeLeft + (nodeRight - nodeLeft) / 2;
	return merge(queryRec(left, right, node * 2, nodeLeft, mid), queryRec(left, right, node * 2 + 1, mid + 1, nodeRight));
}
pair<ll,ll> query(ll left, ll right)
{
	return queryRec(left, right, 1, 1, n);
}
pair<ll,ll> updateRec(ll index, ll newValue, ll node, ll nodeLeft, ll nodeRight)
{
	if (index < nodeLeft || nodeRight < index)
		return tree[node];
	if (nodeLeft == nodeRight)
		return { tree[node].X = newValue, tree[node].Y = nodeLeft };
	ll mid = nodeLeft + (nodeRight - nodeLeft) / 2;
	pair<ll,ll> leftVal = updateRec(index, newValue, node * 2, nodeLeft, mid);
	pair<ll,ll> rightVal = updateRec(index, newValue, node * 2 + 1, mid + 1, nodeRight);
	return tree[node] = merge(leftVal, rightVal);
}
pair<ll,ll> update(ll index, ll newValue)
{
	return updateRec(index, newValue, 1, 1, n);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	build(arr, n);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			update(b, c);
		else if (a == 2)
			cout << query(b, c).Y << '\n';
	}
}