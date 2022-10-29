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
bool visit[500001] = { 0 };
char high[500001] = { 0 };
vector<vector<int>> v(500001);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    string str;
    cin >> str;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<pair<int, int>> Q;
    memset(high, 0, sizeof(high));
    high[1] = str[0];
    visit[1] = 1;
    Q.push({ 1, 2 });
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        if (str[cur.X - 1] < high[cur.Y - 1])
            continue;
        vector<int> vv;
        for (int i = 0; i < v[cur.X].size(); i++)
        {
            if (visit[v[cur.X][i]] == 0)
            {
                visit[v[cur.X][i]] = 1;
                char tmp = str[v[cur.X][i] - 1];
                if (high[cur.Y] < tmp)
                {
                    high[cur.Y] = tmp;
                    vv.clear();
                    vv.push_back(i);
                }
                else if (high[cur.Y] == tmp)
                    vv.push_back(i);
            }
        }
        for (int i = 0; i < vv.size(); i++)
            Q.push({ v[cur.X][vv[i]], cur.Y + 1 });
    }
    for (int i = 1; i <= n; i++)
    {
        if (high[i] == 0)
            break;
        cout << high[i];
    }
}