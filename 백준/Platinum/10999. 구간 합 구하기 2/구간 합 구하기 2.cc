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
vector<ll> lazyValue;
vector<bool> lazyExist;
static const int DEFAULT_VALUE = 0;
ll merge(ll left, ll right) {
	return left + right;
}
ll mergeBlock(ll value, ll size) {
	return value * size;
}
ll buildRec(const ll arr[], ll node, ll nodeLeft, ll nodeRight) {
	if (nodeLeft == nodeRight)
		return tree[node] = arr[nodeLeft];

	ll mid = nodeLeft + (nodeRight - nodeLeft) / 2;
	ll leftVal = buildRec(arr, node * 2, nodeLeft, mid);
	ll rightVal = buildRec(arr, node * 2 + 1, mid + 1, nodeRight);

	return tree[node] = merge(leftVal, rightVal);
}
void build(const ll arr[], ll size) {
	ll N = size;
	tree.resize(N * 4);
	lazyValue.resize(N * 4);
	lazyExist.resize(N * 4);
	buildRec(arr, 1, 0, N - 1);
}
ll pushDown(ll newValue, ll node, ll nodeLeft, ll nodeRight) {
	if (nodeLeft == nodeRight)
		return tree[node] += newValue;
	
	lazyExist[node] = true;
	lazyValue[node] += newValue;
	
	return tree[node] += mergeBlock(newValue, nodeRight - nodeLeft + 1);
}
ll updateRec(ll left, ll right, ll newValue, ll node, ll nodeLeft, ll nodeRight) {
	if (right < nodeLeft || nodeRight < left)
		return tree[node];
	
	if (nodeLeft == nodeRight)
		return tree[node] += newValue;
	
	if (left <= nodeLeft && nodeRight <= right) {
		lazyExist[node] = true;
		lazyValue[node] += newValue;
		return tree[node] += mergeBlock(newValue, nodeRight - nodeLeft + 1);
	}
	
	ll mid = nodeLeft + (nodeRight - nodeLeft) / 2;
	
	if (lazyExist[node]) {
		lazyExist[node] = false;
		pushDown(lazyValue[node], node * 2, nodeLeft, mid);
		pushDown(lazyValue[node], node * 2 + 1, mid + 1, nodeRight);
		lazyValue[node] = DEFAULT_VALUE;
	}
	
	ll leftVal = updateRec(left, right, newValue, node * 2, nodeLeft, mid);
	ll rightVal = updateRec(left, right, newValue, node * 2 + 1, mid + 1, nodeRight);
	
	return tree[node] = merge(leftVal, rightVal);
}
ll update(ll left, ll right, ll newValue) {
	return updateRec(left, right, newValue, 1, 1, n);
}
ll queryRec(ll left, ll right, ll node, ll nodeLeft, ll nodeRight) {
	if (right < nodeLeft || nodeRight < left)
		return DEFAULT_VALUE;
	
	if (left <= nodeLeft && nodeRight <= right)
		return tree[node];
	
	ll mid = nodeLeft + (nodeRight - nodeLeft) / 2;
	
	if (lazyExist[node]) {
		lazyExist[node] = false;
		pushDown(lazyValue[node], node * 2, nodeLeft, mid);
		pushDown(lazyValue[node], node * 2 + 1, mid + 1, nodeRight);
		lazyValue[node] = DEFAULT_VALUE;
	}
	
	return merge(queryRec(left, right, node * 2, nodeLeft, mid), queryRec(left, right, node * 2 + 1, mid + 1, nodeRight));
}
ll query(ll left, ll right) {
	return queryRec(left, right, 1, 1, n);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	build(arr, n);
	for (int i = 0; i < m + k; i++)
	{
		ll a, b, c, d;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			update(b, c, d);
		}
		else if (a == 2)
		{
			cin >> b >> c;
			cout << query(b, c) << '\n';
		}
	}
}
// 참고 : https://www.youtube.com/watch?v=dJpNh7R4LM8&t=678s&ab_channel=%EA%B0%9C%EB%B0%9C%EC%9E%90%EC%98%81%EB%A7%A8