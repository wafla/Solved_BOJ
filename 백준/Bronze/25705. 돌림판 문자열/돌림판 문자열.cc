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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    string pan, str;
    cin >> n >> pan >> m >> str;
    int arr[26] = { 0 }, arr2[26] = { 0 };
    for (int i = 0; i < n; i++)
        if (arr[pan[i] - 97] == 0)
            arr[pan[i] - 97] = 1;
    for (int i = 0; i < m; i++)
        if (arr2[str[i] - 97] == 0)
            arr2[str[i] - 97] = 1;
    int check = 0;
    for (int i = 0; i < 26; i++)
        if (arr2[i] == 1 && arr[i] == 0)
            check = 1;
    if (check)
    {
        cout << -1;
        return 0;
    }
    string s;
    int pan_idx = 0, str_idx = 0, cnt = 0;
    while (1)
    {
        if (s == str)
            break;
        if (pan[pan_idx] == str[str_idx])
        {
            s = s + str[str_idx];
            str_idx++;
        }
        pan_idx++;
        cnt++;
        if (pan_idx == n)
            pan_idx = 0;
    }
    cout << cnt;
}