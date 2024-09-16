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
int parent[51] = { 0 };
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
    
    int num;
    cin >> num;
    vector<int> truth(num);
    for (auto& i : truth)
        cin >> i;
    for (int i = 1; i < num; i++)
        merge(truth[i - 1], truth[i]);

    vector<vector<int>> v(m);
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < tmp; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
        for (int j = 1; j < tmp; j++)
            merge(v[i][j - 1], v[i][j]);
    }
   
    int ans = 0;
    int root;
    if (!truth.size())
        root = 0;
    else
        root = find(truth[0]);
    for (int i = 0; i < m; i++)
    {
        int flag = 0;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (find(v[i][j]) == root)
                continue;
            else
                flag = 1;
        }
        if (flag)
            ans++;
    }
    cout << ans << '\n';
}