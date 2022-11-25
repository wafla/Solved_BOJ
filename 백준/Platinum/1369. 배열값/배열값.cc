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
pair<int, int> arr[1002][1002];
pair<int, int> ans[1002][1002];
int check(int a, int b)
{
    if (a < 0 && b < 0) // 배열 값이 둘 다 0 인경우
        return -1;
    if (a < 0)
        return b;
    if (b < 0)
        return a;
    return a < b ? a : b; // 2와 5중에 최소값이 답이다
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) // 10이 나오지 않는것이 최선이므로 10의 약수인 2와 5의 개수만 센다.
                                     // 어처피 답은 0의 개수만 세면 되기 때문에 다른 수들은 필요 없음
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                arr[i][j].X = -1;
                arr[i][j].Y = -1;
                continue;
            }
            int two = 0, five = 0, tmp = x;
            while (tmp)
            {
                if (tmp % 2 == 0)
                {
                    two++;
                    tmp /= 2;
                }
                else
                    break;
            }
            while (tmp)
            {
                if (tmp % 5 == 0)
                {
                    five++;
                    tmp /= 5;
                }
                else
                    break;
            }
            arr[i][j].X = two;
            arr[i][j].Y = five;
        }
    }

    ans[1][1].X = arr[1][1].X;
    ans[1][1].Y = arr[1][1].Y;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                continue;
            int a, b;
            // 2인 경우 
            a = (i == 1) ? -1 : ans[i - 1][j].X;
            b = (j == 1) ? -1 : ans[i][j - 1].X;
            ans[i][j].X = check(a, b);
            if (ans[i][j].X >= 0) // 배열의 2를 더해줌
                ans[i][j].X += arr[i][j].X;
            if (arr[i][j].X < 0) // 배열 값이 0이면 계산하면 안되므로 -1
                ans[i][j].X = -1;
            // 5인 경우
            a = (i == 1) ? -1 : ans[i - 1][j].Y;
            b = (j == 1) ? -1 : ans[i][j - 1].Y;
            ans[i][j].Y = check(a, b);
            if (ans[i][j].Y >= 0) // 배열의 5를 더해줌
                ans[i][j].Y += arr[i][j].Y;
            if (arr[i][j].Y < 0) // 배열 값이 0이면 계산하면 안되므로 -1
                ans[i][j].Y = -1;
        }
    }
    cout << min(ans[n][n].X, ans[n][n].Y);
}
//참고 : https://github.com/thregium/practice_baekjoon/blob/main/01000-01999/1369.c