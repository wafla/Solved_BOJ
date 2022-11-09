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
struct T {
    int x;
    int y;
    int cnt;
};
int arr[8][8] = { 0 };
int ans[8][8] = { 0 };
int n;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int fin;
int maxx;
vector<T> v;
int check(int x, int y) // 다른 전구와 충돌 없는지 확인
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        while (1)
        {
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                break;
            if (arr[nx][ny] == -1)
                break;
            if (arr[nx][ny] >= 0 && arr[nx][ny] <= 4)
                break;
            if (arr[nx][ny] == 9)
                return 0;
            nx += dx[i];
            ny += dy[i];
        }
    }
    return 1;
}
void board(int x, int y) // 숫자 주변 채우고 남은 전구 설치하기
{
    if (fin)
        return;
    if (y == n)
    {
        x++;
        y = 0;
    }
    if (x == n)
    {
        int tmp[8][8] = { 0 }; // 최종 점검
        vector<T> vv;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 9)
                {
                    tmp[i][j] = 9;
                    vv.push_back({ i,j,0 });
                }
                else if (arr[i][j] >= -1 && arr[i][j] <= 4)
                    tmp[i][j] = arr[i][j];
                else
                    tmp[i][j] = -2;
            }
        }
        for (int i = 0; i < vv.size(); i++)
        {
            int x = vv[i].x;
            int y = vv[i].y;
            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                while (1)
                {
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        break;
                    else if (tmp[nx][ny] == -2)
                        tmp[nx][ny] = 8;
                    else if (tmp[nx][ny] >= -1 && tmp[nx][ny] <= 4)
                        break;
                    nx += dx[j];
                    ny += dy[j];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tmp[i][j] == -2)
                    return;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 9)
                    ans[i][j] = 1;
                else
                    ans[i][j] = 0;
            }
        }
        fin = 1;
        return;
    }
    if (arr[x][y] == -2)
    {
        int chk = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j].x == nx && v[j].y == ny)
                {
                    chk = 1;
                    break;
                }
                if (chk)
                    break;
            }
            if (chk)
                break;
        }
        if (check(x, y) && !chk)
        {
            arr[x][y] = 9;
            board(x, y + 1);
            arr[x][y] = -2;
        }
    }
    board(x, y + 1);
}
void cnt(int x, int y, int num) // 숫자 칸 주변에 들어갈 경우 +1 하거나 -1
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int nx = v[i].x + dx[j];
            int ny = v[i].y + dy[j];
            if (nx == x && ny == y)
            {
                v[i].cnt += num;
                break;
            }
        }
    }
}
int check2(int x, int y) // 숫자 칸 주변에 들어갈 수 있는지(개수 맞는지) 확인
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int nx = v[i].x + dx[j];
            int ny = v[i].y + dy[j];
            if (nx == x && ny == y)
            {
                if (v[i].cnt + 1 > arr[v[i].x][v[i].y])
                    return 0;
            }
        }
    }
    return 1;
}
void select(int idx)
{
    if (fin)
        return;
    if (v.size() <= idx)
    {
        board(0, 0);
        if (fin)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << ans[i][j] << " ";
                cout << '\n';
            }
        }
        return;
    }
    if (v[idx].cnt == arr[v[idx].x][v[idx].y])
        select(idx + 1);
    for (int i = 0; i < 4; i++)
    {
        int nx = v[idx].x + dx[i];
        int ny = v[idx].y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
        if (arr[nx][ny] == -2)
        {
            if (check(nx, ny) && check2(nx,ny))
            {
                arr[nx][ny] = 9;
                cnt(nx, ny, 1);
                select(idx);
                cnt(nx, ny, -1);
                arr[nx][ny] = -2;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        fin = 0;
        maxx = 0;
        v.clear();
        memset(arr, 0, sizeof(arr));
        memset(ans, 0, sizeof(ans));
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] >= 0)
                    v.push_back({ i,j,0 });
            }
        }
        if (!v.empty())
            select(0);
    }
}