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
int parent[100001] = { 0 };
int dist[100001] = { 0 };
int find(int x)
{
    if (parent[x] == x)
        return x;
    int px = find(parent[x]);
    dist[x] += dist[parent[x]];
    return parent[x] = px;
}
void merge(int a, int b, int w)
{
    int px = find(a);
    int py = find(b);
    if (px != py)
    {
        dist[py] = -dist[b] + dist[a] + w;
        parent[py] = px;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    while (1)
    {
        cin >> n >> m;
        if (!n && !m)
            break;
        for (int i = 0; i < 100001; i++)
        {
            dist[i] = 0;
            parent[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b, w;
            char tmp;
            cin >> tmp;
            if (tmp == '!')
            {
                cin >> a >> b >> w;
                merge(a, b, w);
            }
            else if (tmp == '?')
            {
                cin >> a >> b;
                if (find(a) != find(b))
                    cout << "UNKNOWN\n";
                else
                    cout << dist[b] - dist[a] << '\n';
            }
        }
    }
}
// 참고 : https://ioqoo.tistory.com/34