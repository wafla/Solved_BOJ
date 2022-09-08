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
#define INF 987654321
#define MOD 1000000007
using namespace std;
char arr[1501][1501] = { 0 };
int v[1501][1501]; //백조
int w[1501][1501] = { 0 }; //물
int r, c;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
vector <pair<int, int>> water; // 물 저장
typedef pair<int, pair<int, int>> T; //우선순위, x, y
void bfs_water() //얼음 녹이기
{
    priority_queue<T, vector<T>, greater<T>> Q;
    for (int i = 0; i < water.size(); i++)
    {
        w[water[i].X][water[i].Y] = 1;
        Q.push({ 1, {water[i].X,water[i].Y} });
    }
    while (!Q.empty())
    {
        auto cur = Q.top();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.Y.X + dx[i];
            int ny = cur.Y.Y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (arr[nx][ny] == 'X' && w[nx][ny] == 0)
            {
                w[nx][ny] = w[cur.Y.X][cur.Y.Y] + 1;
                Q.push({ w[nx][ny], {nx, ny}});
            }
        }
    }
}
void bfs_bird(int sx1, int sy1, int sx2, int sy2) //백조 영역 구하기
{
    priority_queue<T, vector<T>, greater<T>> Q;
    Q.push({ 1, {sx1, sy1} });
    v[sx1][sy1] = 1;
    arr[sx2][sy2] = 'L';
    while (!Q.empty())
    {
        auto cur = Q.top();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.Y.X + dx[i];
            int ny = cur.Y.Y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (arr[nx][ny] == 'L')
            {
                cout << cur.X - 1 << '\n';
                return;
            }
            else if (v[nx][ny] == 0 && w[nx][ny] <= cur.X)
            {
                v[nx][ny] = cur.X;
                Q.push({ cur.X, {nx,ny} });
            }
            else if (v[nx][ny] == 0)
            {
                v[nx][ny] = cur.X + 1;
                Q.push({ cur.X+1, {nx,ny} });
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> r >> c;
    int count = 0, sx1, sy1, sx2, sy2; //백조 1, 2 좌표
    memset(v, 0, sizeof(v));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'L')
            {
                if (count++ == 0)
                {
                    arr[i][j] = '.';
                    sx1 = i;
                    sy1 = j;
                    water.push_back({ i,j });
                }
                else
                {
                    arr[i][j] = '.';
                    sx2 = i;
                    sy2 = j;
                    water.push_back({ i,j });
                }
            }
            else if (arr[i][j] == '.')
                water.push_back({ i,j });
        }
    }
    bfs_water();
    bfs_bird(sx1, sy1, sx2, sy2);
}