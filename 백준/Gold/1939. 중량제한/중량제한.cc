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
int dist[10001] = { 0 };
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> v(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }

    int L1, L2;
    cin >> L1 >> L2;
    int ans = 0;
    priority_queue<pi, vector<pi>, greater<pi>> PQ;
    PQ.push({ L1, INF });
    while (PQ.size())
    {
        auto cur = PQ.top();
        PQ.pop();
        if (dist[cur.X] > cur.Y)
            continue;
        for (int i = 0; i < v[cur.X].size(); i++)
        {
            int nx = v[cur.X][i].X;
            int nw = v[cur.X][i].Y;

            int minn = min(cur.Y, nw);
            if (minn <= dist[nx])
                continue;
            else
            {
                dist[nx] = minn;
                PQ.push({ nx, minn });
            }
        }
    }
    cout << dist[L2] << '\n';
}