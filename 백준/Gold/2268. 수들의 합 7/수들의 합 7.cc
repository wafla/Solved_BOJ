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
vector<ll> tree;
ll merge(ll left, ll right)
{
	return (left + right);
}
ll buildRec(const ll arr[], ll node, ll nodeLeft, ll nodeRight)
{
	if (nodeLeft == nodeRight)
		return tree[node] = arr[nodeLeft];

	ll mid = nodeLeft + (nodeRight - nodeLeft) / 2;
	ll leftVal = buildRec(arr, node * 2, nodeLeft, mid);
	ll rightVal = buildRec(arr, node * 2 + 1, mid + 1, nodeRight);

	return tree[node] = merge(leftVal, rightVal);
}
void build(const ll arr[], ll size)
{
	ll N = size;
	tree.resize(N * 4);
	buildRec(arr, 1, 0, N - 1);
}
ll queryRec(ll left, ll right, ll node, ll nodeLeft, ll nodeRight)
{
	if (right < nodeLeft || nodeRight < left)
		return 0;
	if (left <= nodeLeft && nodeRight <= right)
		return tree[node];
	
	ll mid = nodeLeft + (nodeRight - nodeLeft) / 2;
	return merge(queryRec(left, right, node * 2, nodeLeft, mid), queryRec(left, right, node * 2 + 1, mid + 1, nodeRight));
}
ll query(ll left, ll right)
{
	return queryRec(left, right, 1, 1, n);
}
ll updateRec(ll index, ll newValue, ll node, ll nodeLeft, ll nodeRight)
{
	if (index < nodeLeft || nodeRight < index)
		return tree[node];
	if (nodeLeft == nodeRight)
		return tree[node] = newValue;
	ll mid = nodeLeft + (nodeRight - nodeLeft) / 2;
	ll leftVal = updateRec(index, newValue, node * 2, nodeLeft, mid);
	ll rightVal = updateRec(index, newValue, node * 2 + 1, mid + 1, nodeRight);
	return tree[node] = merge(leftVal, rightVal);
}
ll update(ll index, ll newValue)
{
	return updateRec(index, newValue, 1, 1, n);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int m;
	cin >> n >> m;
	build(arr, n);
	for (int i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
		{
			if (b > c)
				swap(b, c);
			cout << query(b, c) << '\n';
		}
		else if (a == 1)
			update(b, c);
	}
}