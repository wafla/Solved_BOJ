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
int parent[300001] = { 0 };
bool v[300001] = { 0 };
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
    parent[pa] = pb;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, l;
    cin >> n >> l;
    iota(parent, parent + l, 0);
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        int flag = 0;
        if (!v[a])
        {
            v[a] = 1;
            merge(a, b);
        }
        else if (!v[b])
        {
            v[b] = 1;
            merge(b, a);
        }
        else if (!v[find(a)])
        {
            v[find(a)] = 1;
            merge(find(a), b);
        }
        else if (!v[find(b)])
        {
            v[find(b)] = 1;
            merge(find(b), a);
        }
        else
            flag = 1;
        if (!flag)
            cout << "LADICA\n";
        else
            cout << "SMECE\n";
    }
}