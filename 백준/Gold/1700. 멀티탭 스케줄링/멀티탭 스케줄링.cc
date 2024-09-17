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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> schedule;
    set<int> now;
    vector<int> v(k);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
        schedule[x].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (!now.count(v[i]))
            now.insert(v[i]);
        schedule[v[i]].erase(schedule[v[i]].begin());
    }

    int ans = 0;
    for (int i = n; i < k; i++)
    {
        int nxt = v[i];
        if (!now.count(nxt))
        {
            if (now.size() < n)
                now.insert(nxt);
            else
            {
                auto maxx = max_element(now.begin(), now.end(), [&](int a, int b) {
                    if (schedule[a].empty()) return false;  // a가 더 늦게 사용됨 (사용되지 않음)
                    if (schedule[b].empty()) return true;   // b가 더 늦게 사용됨 (사용되지 않음)
                    return schedule[a][0] < schedule[b][0];
                    });
                ans++;
                now.erase(*maxx);
                now.insert(nxt);
            }
        }
        schedule[nxt].erase(schedule[nxt].begin());
    }
    cout << ans << '\n';
}