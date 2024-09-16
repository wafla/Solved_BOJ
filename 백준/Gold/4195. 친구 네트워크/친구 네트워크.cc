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
map<string, string> M;
map<string, int> dist;
map<string, bool> visited;
string find(string x)
{
    if (M[x] == x)
        return x;
    return M[x] = find(M[x]);
}
void merge(string a, string b)
{
    string pa = find(a);
    string pb = find(b);
    if (pa.compare(pb) == 0)
        return;
    else
    {
        M[pb] = pa;
        dist[pa] += dist[pb];
    }
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
        string a, b;
        M.clear();
        dist.clear();
        visited.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            if (!visited[a])
            {
                visited[a] = 1;
                M[a] = a;
                dist[a] = 1;
            }
            if (!visited[b])
            {
                visited[b] = 1;
                M[b] = b;
                dist[b] = 1;
            }
            merge(a, b);
            cout << dist[find(a)] << '\n';
        }
    }
}