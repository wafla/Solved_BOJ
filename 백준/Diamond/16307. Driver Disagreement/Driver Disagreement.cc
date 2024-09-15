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
int n, A, B;
int visible[100001] = { 0 };
int route[100001][2] = { 0 };
int parent[100001] = { 0 };
int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void merge(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> A >> B;
    for (int i = 0; i < n; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        route[i][0] = l;
        route[i][1] = r;
        visible[i] = x;
    }
    for (int i = 0; i < 100001; i++)
        parent[i] = i;
    queue<pair<pi, int>> Q;
    Q.push({ {A,B}, 0 });
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        int a = cur.X.X;
        int b = cur.X.Y;
        int cnt = cur.Y;
        if (find(a) == find(b)) // (a,b)=indistinguishable 이고 (b,c)=indistinguishable 이면 (a,c)=indistinguishable 이다.
            continue;
        if (visible[a] != visible[b])
        {
            cout << cnt << '\n';
            return 0;
        }
        merge(a, b);
        Q.push({ {route[a][0],route[b][0]},cnt + 1 });
        Q.push({ {route[a][1],route[b][1]},cnt + 1 });
    }
    cout << "indistinguishable\n";
}
// 참고 : https://justicehui.github.io/icpc/2019/12/25/BOJ16307/