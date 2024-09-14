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
struct T {
    int x,y,d;
};
char R[1026][1026][2] = { 0 }; // 0 - Rule A, 1 - Rule B
bool v[1026][1026] = { 0 };
int h, w, r, c, d, flag = 0;
T nxt[1026][1026][4] = { 0 };
int dist[1026][1026][4] = { 0 };
int cnt[1026][1026][4] = { 0 };
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= h || y >= w)
        return 0;
    return 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> h >> w >> r >> c >> d;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> R[i][j][0];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> R[i][j][1];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                dist[i][j][k] = 1;

                int nd = (k + (R[i][j][1] - '0')) % 4;
                int nx = i + dx[nd];
                int ny = j + dy[nd];

                if (check(nx, ny))
                    nxt[i][j][k] = { nx, ny, nd };
                else
                    nxt[i][j][k] = { -1,-1,0 };
            }
        }
    }

    int ans = 0, num = 0, x = r, y = c;
    stack<T> st;
    while (check(x, y))
    {
        int moved = 0;
        num++;
        while (check(x, y) && v[x][y]) // 먼지 X
        {
            if (cnt[x][y][d] == num) // 사이클 발생
            {
                x = -1;
                break;
            }
            st.push({ x,y,d });
            cnt[x][y][d] = num;
            moved += dist[x][y][d];

            auto cur = nxt[x][y][d];
            x = cur.x;
            y = cur.y;
            d = cur.d;
        }

        if (check(x, y) && !v[x][y]) // 먼지 O
        {
            while (!st.empty())
            {
                auto now = st.top();
                st.pop();
                auto next = nxt[now.x][now.y][now.d];
                nxt[now.x][now.y][now.d] = nxt[next.x][next.y][next.d];
                dist[now.x][now.y][now.d] += dist[next.x][next.y][next.d];
            }
            ans += moved + 1;
            v[x][y] = 1;
            int nd = (d + (R[x][y][0] - '0')) % 4;
            x += dx[nd];
            y += dy[nd];
            d = nd;
        }
    }
    cout << ans << '\n';
}
// 참고 : https://killle.tistory.com/27