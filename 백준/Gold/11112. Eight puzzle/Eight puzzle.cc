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
#define T pair<int, pair<string, int>>
using namespace std;
map<string, int> M;
set<string> S;
void copy(string& s, int x1, int x2)
{
    char tmp_x = s[x1];
    s[x1] = s[x2];
    s[x2] = tmp_x;
}
int check(string v)
{
    int flag = 0;
    flag = S.count(v) ? 1 : 0;
    S.insert(v);
    return flag;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string num = "12345678#";
    queue<T> Q;
    Q.push({ 0,{ num,8 } });
    S.insert(num);
    M[num] = 0;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        int x = cur.Y.Y;
        if (x % 3 == 0)
        {
            int x1 = x - 3, x2 = x + 1, x3 = x + 3;
            if (x1 > -1)
            {
                string tmp_ = cur.Y.X;
                copy(tmp_, x, x1);
                if (!check(tmp_) || M[tmp_] > cur.X + 1)
                {
                    Q.push({ cur.X + 1,{tmp_,x1}, });
                    M[tmp_] = cur.X + 1;
                }
            }
            if (x2 < 9)
            {
                string tmp_ = cur.Y.X;
                copy(tmp_, x, x2);
                if (!check(tmp_) || M[tmp_] > cur.X + 1)
                {
                    Q.push({ cur.X + 1,{tmp_,x2}, });
                    M[tmp_] = cur.X + 1;
                }
            }
            if (x3 < 9)
            {
                string tmp_ = cur.Y.X;
                copy(tmp_, x, x3);
                if (!check(tmp_) || M[tmp_] > cur.X + 1)
                {
                    Q.push({ cur.X + 1,{tmp_,x3}, });
                    M[tmp_] = cur.X + 1;
                }
            }
        }
        else if (x % 3 == 1)
        {
            int x1 = x - 3, x2 = x - 1, x3 = x + 1, x4 = x + 3;
            if (x1 > -1)
            {
                string tmp_ = cur.Y.X;
                copy(tmp_, x, x1);
                if (!check(tmp_) || M[tmp_] > cur.X + 1)
                {
                    Q.push({ cur.X + 1,{tmp_,x1}, });
                    M[tmp_] = cur.X + 1;
                }
            }
            if (x2 > -1)
            {
                string tmp_ = cur.Y.X;
                copy(tmp_, x, x2);
                if (!check(tmp_) || M[tmp_] > cur.X + 1)
                {
                    Q.push({ cur.X + 1,{tmp_,x2}, });
                    M[tmp_] = cur.X + 1;
                }
            }
            if (x3 < 9)
            {
                string tmp_ = cur.Y.X;
                copy(tmp_, x, x3);
                if (!check(tmp_) || M[tmp_] > cur.X + 1)
                {
                    Q.push({ cur.X + 1,{tmp_,x3}, });
                    M[tmp_] = cur.X + 1;
                }
            }
            if (x4 < 9)
            {
                string tmp_ = cur.Y.X;
                copy(tmp_, x, x4);
                if (!check(tmp_) || M[tmp_] > cur.X + 1)
                {
                    Q.push({ cur.X + 1,{tmp_,x4}, });
                    M[tmp_] = cur.X + 1;
                }
            }
        }
        else if (x % 3 == 2)
        {
            int x1 = x - 3, x2 = x - 1, x3 = x + 3;
            if (x1 > -1)
            {
                string tmp_ = cur.Y.X;
                copy(tmp_, x, x1);
                if (!check(tmp_) || M[tmp_] > cur.X + 1)
                {
                    Q.push({ cur.X + 1,{tmp_,x1}, });
                    M[tmp_] = cur.X + 1;
                }
            }
            if (x2 > -1)
            {
                string tmp_ = cur.Y.X;
                copy(tmp_, x, x2);
                if (!check(tmp_) || M[tmp_] > cur.X + 1)
                {
                    Q.push({ cur.X + 1,{tmp_,x2}, });
                    M[tmp_] = cur.X + 1;
                }
            }
            if (x3 < 9)
            {
                string tmp_ = cur.Y.X;
                copy(tmp_, x, x3);
                if (!check(tmp_) || M[tmp_] > cur.X + 1)
                {
                    Q.push({ cur.X + 1,{tmp_,x3}, });
                    M[tmp_] = cur.X + 1;
                }
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        string tmp;
        for (int i = 0; i < 9; i++)
        {
            char x;
            cin >> x;
            tmp.push_back(x);
        }
        if (S.count(tmp))
            cout << M[tmp] << '\n';
        else
            cout << "impossible\n";
    }
}