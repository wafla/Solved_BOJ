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
int parent[20001] = { 0 };
int dist[20001] = { 0 };
int find(int x)
{
    if (parent[x] == x)
        return x;
    int pa = find(parent[x]);
    dist[x] += dist[parent[x]];
    return parent[x] = pa;
}
void merge(int a, int b)
{
    dist[a] = abs(a - b) % 1000;
    parent[a] = b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            dist[i] = 0;
            parent[i] = i;
        }
        while (1)
        {
            char op;
            cin >> op;
            if (op == 'O')
                break;
            int i, j;
            if (op == 'E')
            {
                cin >> i;
                find(i);
                cout << dist[i] << '\n';
            }
            else if (op == 'I')
            {
                cin >> i >> j;
                merge(i, j);
            }
        }
    }
}