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
int num(string str)
{
    return ((str[0] - 48) * 10 + str[1] - 48) * 60 + str[3] * 10 + str[4];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    queue<string> v1, v2;
    int ans_1 = 0, ans_2 = 0, sum_1 = 0, sum_2 = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        string s;
        cin >> x >> s;
        if (x == 1)
        {
            sum_1++;
            v1.push(s);
            if (sum_1==sum_2)
            {
                if (num(s) > num(v2.front()))
                {
                    ans_2 += num(s) - num(v2.front());
                    while (v2.empty()==0 && num(s) > num(v2.front()))
                        v2.pop();
                }
                while (v1.empty() == 0 && num(s) >= num(v1.front()))
                    v1.pop();
            }
        }
        else if (x == 2)
        {
            sum_2++;
            v2.push(s);
            if (sum_1 == sum_2)
            {
                if (num(s) > num(v1.front()))
                {
                    ans_1 += num(s) - num(v1.front());
                    while (v1.empty()==0 && num(s) > num(v1.front()))
                        v1.pop();
                }
                while (v2.empty() == 0 && num(s) >= num(v2.front()))
                    v2.pop();
            }
        }
    }
    if (sum_1 > sum_2)
        ans_1 += num("48:00") - num(v1.front());
    else if (sum_1 < sum_2)
        ans_2 += num("48:00") - num(v2.front());

    if (ans_1 / 60 > 9)
        cout << ans_1 / 60 << ":";
    else
        cout << 0 << ans_1 / 60 << ":";
    if (ans_1 % 60 > 9)
        cout << ans_1 % 60 << '\n';
    else
        cout << 0 << ans_1 % 60 << '\n';

    if (ans_2 / 60 > 9)
        cout << ans_2 / 60 << ":";
    else
        cout << 0 << ans_2 / 60 << ":";
    if (ans_2 % 60 > 9)
        cout << ans_2 % 60 << '\n';
    else
        cout << 0 << ans_2 % 60 << '\n';
}