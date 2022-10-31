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
int arr[9][9] = { 0 };
int tmp[10][9][9] = { 0 };
int n, m;
struct T {
    int x = -1;
    int y = -1;
    int num = -1;
};
void copy(int a, int b)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tmp[a][i][j] = tmp[b][i][j];
}
void solve(int dir, int i, int j, int M)
{
    if (dir == 0) // 왼쪽
    {
        while (1)
        {
            j--;
            if (j < 0 || tmp[M][i][j] == 6)
                break;
            if (tmp[M][i][j] == 0)
                tmp[M][i][j] = -1;
        }
    }
    else if (dir == 1) // 위쪽
    {
        while (1)
        {
            i--;
            if (i < 0 || tmp[M][i][j] == 6)
                break;
            if (tmp[M][i][j] == 0 )
                tmp[M][i][j] = -1;
        }
    }
    else if (dir == 2) // 오른쪽
    {
        while (1)
        {
            j++;
            if (j >= m || tmp[M][i][j] == 6)
                break;
            if (tmp[M][i][j] == 0)
                tmp[M][i][j] = -1;
        }
        /*for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << tmp[i][j] << " ";
            cout << '\n';
        }
        cout << '\n';*/
    }
    else if (dir == 3) // 아래쪽
    {
        while (1)
        {
            i++;
            if (i >= n || tmp[M][i][j] == 6)
                break;
            if (tmp[M][i][j] == 0)
                tmp[M][i][j] = -1;
        }
    }
}
void check(int dir, int i, int j, int num, int M) {
    if (num == -1)
        return;
    if (num == 1)
    {
        if (dir == 0) // 왼쪽
            solve(0, i, j, M);
        else if (dir == 1) // 위쪽
            solve(1, i, j, M);
        else if (dir == 2) // 오른쪽
            solve(2, i, j, M);
        else if (dir == 3) // 아래쪽
            solve(3, i, j, M);
    }
    else if (num == 2)
    {
        if (dir == 0 || dir == 2) 
        {
            solve(0, i, j, M);
            solve(2, i, j, M);
        }
        else if (dir == 1 || dir == 3) 
        {
            solve(1, i, j, M);
            solve(3, i, j, M);
        }
    }
    else if (num == 3)
    {
        if (dir == 0) 
        {
            solve(1, i, j, M);
            solve(2, i, j, M);
        }
        else if (dir == 1) 
        {
            solve(2, i, j, M);
            solve(3, i, j, M);
        }
        else if (dir == 2) 
        {
            solve(3, i, j, M);
            solve(0, i, j, M);
        }
        else if (dir == 3) 
        {
            solve(0, i, j, M);
            solve(1, i, j, M);
        }
    }
    else if (num == 4)
    {
        if (dir == 0)
        {
            solve(0, i, j, M);
            solve(1, i, j, M);
            solve(2, i, j, M);
        }
        else if (dir == 1)
        {
            solve(1, i, j, M);
            solve(2, i, j, M);
            solve(3, i, j, M);
        }
        else if (dir == 2)
        {
            solve(2, i, j, M);
            solve(3, i, j, M);
            solve(0, i, j, M);
        }
        else if (dir == 3)
        {
            solve(3, i, j, M);
            solve(0, i, j, M);
            solve(1, i, j, M);
        }
    }
    else if (num == 5)
    {
        solve(0, i, j, M);
        solve(1, i, j, M);
        solve(2, i, j, M);
        solve(3, i, j, M);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    vector<T> v(8);
    int idx = 0;
    int ans = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            tmp[9][i][j] = arr[i][j];
            if (arr[i][j] > 0 && arr[i][j] < 6)
                v[idx++] = { i,j,arr[i][j] };
        }
    for (int a = 0; a < 4; a++)
    {
        copy(0, 9);
        check(a, v[0].x, v[0].y, v[0].num, 0);
        for (int b = 0; b < 4; b++)
        {
            copy(1, 0);
            check(b, v[1].x, v[1].y, v[1].num, 1);
            for (int c = 0; c < 4; c++)
            {
                copy(2, 1);
                check(c, v[2].x, v[2].y, v[2].num, 2);
                for (int d = 0; d < 4; d++)
                {
                    copy(3, 2);
                    check(d, v[3].x, v[3].y, v[3].num, 3);
                    for (int e = 0; e < 4; e++)
                    {
                        copy(4, 3);
                        check(e, v[4].x, v[4].y, v[4].num, 4);
                        for (int f = 0; f < 4; f++)
                        {
                            copy(5, 4);
                            check(f, v[5].x, v[5].y, v[5].num, 5);
                            for (int g = 0; g < 4; g++)
                            {
                                copy(6, 5);
                                check(g, v[6].x, v[6].y, v[6].num, 6);
                                for (int h = 0; h < 4; h++)
                                {
                                    copy(7, 6);
                                    check(h, v[7].x, v[7].y, v[7].num, 7);
                                    int cnt = 0;
                                    for (int i = 0; i < n; i++)
                                        for (int j = 0; j < m; j++)
                                            tmp[8][i][j] = arr[i][j];
                                    for (int i = 0; i < n; i++)
                                    {
                                        for (int j = 0; j < m; j++)
                                        {
                                            for (int k = 0; k < 8; k++)
                                            {
                                                if (tmp[k][i][j] == -1)
                                                    tmp[8][i][j] = -1;
                                            }
                                        }
                                    }
                                    for (int i = 0; i < n; i++)
                                        for (int j = 0; j < m; j++)
                                            if (tmp[8][i][j] == 0)
                                                cnt++;
                                    ans = min(ans, cnt);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}