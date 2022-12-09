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
ll a[3] = { 0 }, x[3] = { 0 };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    for (int i = 0; i < 3; i++)
        cin >> x[i];
    ll cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        if (a[i] > x[i])
        {
            a[i] -= x[i];
            cnt += x[i];
            x[i] = 0;
        }
        else
        {
            x[i] -= a[i];
            cnt += a[i];
            a[i] = 0;
        }
    }
    int idx = 0;
    int check = 0;
    while (1)
    {
        if (check == 3)
            break;
        if (idx == 0)
        {
            if (a[idx] == 0)
            {
                int k = x[idx] / 3;
                if (k == 0)
                    check++;
                else
                    check = 0;
                x[idx + 1] += k;
                x[idx] %= 3;
            }
            else
            {
                if (a[idx] > x[idx])
                {
                    a[idx] -= x[idx];
                    cnt += x[idx];
                    x[idx] = 0;
                }
                else
                {
                    x[idx] -= a[idx];
                    cnt += a[idx];
                    a[idx] = 0;
                }
            }
        }
        else if (idx == 1)
        {
            if (a[idx] == 0)
            {
                int k = x[idx] / 3;
                if (k == 0)
                    check++;
                else
                    check = 0;
                x[idx + 1] += k;
                x[idx] %= 3;
            }
            else
            {
                if (a[idx] > x[idx])
                {
                    a[idx] -= x[idx];
                    cnt += x[idx];
                    x[idx] = 0;
                }
                else
                {
                    x[idx] -= a[idx];
                    cnt += a[idx];
                    a[idx] = 0;
                }
            }
        }
        else if (idx == 2)
        {
            if (a[idx] == 0)
            {
                int k = x[idx] / 3;
                if (k == 0)
                    check++;
                else
                    check = 0;
                x[0] += k;
                x[idx] %= 3;
            }
            else
            {
                if (a[idx] > x[idx])
                {
                    a[idx] -= x[idx];
                    cnt += x[idx];
                    x[idx] = 0;
                }
                else
                {
                    x[idx] -= a[idx];
                    cnt += a[idx];
                    a[idx] = 0;
                }
            }
        }
        idx++;
        if (idx == 3)
            idx = 0;
    }
    cout << cnt;
}