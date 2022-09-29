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
int arr[1501][1501] = { 0 };
bool v[1501][1501] = { 0 };
int dx[6] = { 0,1,1,0,-1,-1 }, dy[6] = { 1,1,0,-1,-1,0 };
int a, b, sx, sy;
struct T {
    int x;
    int y;
    string s;
};
void make()
{
    int num = 1;
    int x = 750, y = 750;
    //1 ~ 7 만들기
    arr[x][y] = 1; 
    arr[x - 1][y] = 2;
    arr[x][y + 1] = 3;
    arr[x + 1][y + 1] = 4;
    arr[x + 1][y] = 5;
    arr[x][y - 1] = 6;
    arr[x - 1][y - 1] = 7;
    if (a == 1){
        sx = x;
        sy = y;
    }
    else if (a == 2){
        sx = x - 1;
        sy = y;
    }
    else if (a == 3){
        sx = x;
        sy = y + 1;
    }
    else if (a == 4){
        sx = x + 1;
        sy = y + 1;
    }
    else if (a == 5){
        sx = x + 1;
        sy = y;
    }
    else if (a == 6){
        sx = x;
        sy = y - 1;
    }
    else if (a == 7) {
        sx = x - 1;
        sy = y - 1;
    }
    else if (a == 8) {
        sx = 748;
        sy = 749;
    }
    x = 749, y = 749;
    num = 8;
    int k = 2;
    while (1)
    {
        if (num > 1000000)
            break;
        x--;
        if (num == a && a != 8)
        {
            sx = x;
            sy = y;
        }
        arr[x][y] = num++;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (j == k - 1 && i == 0)
                    break;
                x = x + dx[i];
                y = y + dy[i];
                if (num == a)
                {
                    sx = x;
                    sy = y;
                }
                arr[x][y] = num++;
            }
        }
        k++;
    }
}
void bfs()
{
    queue<T> Q;
    Q.push({ sx,sy,to_string(arr[sx][sy]) });
    v[sx][sy] = 1;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        if (arr[cur.x][cur.y] == b)
        {
            cout << cur.s;
            return;
        }
        for (int i = 0; i < 6; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= 1501 || ny >= 1501)
                continue;
            if(arr[nx][ny]>1000000)
                continue;
            if (v[nx][ny])
                continue;
            v[nx][ny] = 1;
            Q.push({ nx,ny,cur.s + " " +to_string(arr[nx][ny])});
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> a >> b;
    make();
    bfs();
}