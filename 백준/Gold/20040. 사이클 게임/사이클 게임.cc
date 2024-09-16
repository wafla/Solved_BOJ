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
#include <unordered_map>
#include <tuple>
#include <numeric>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define LINF 9223372036854775807
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int, int>
#define ti tuple<int, int, int>
using namespace std;
int parent[500001] = { 0 };
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
void merge(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if (pa < pb)
        parent[pb] = pa;
    else
        parent[pa] = pb;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    iota(parent, parent + n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b))
        {
            cout << i << '\n';
            return 0;
        }
        else
            merge(a, b);
    }
    cout << 0 << '\n';
}