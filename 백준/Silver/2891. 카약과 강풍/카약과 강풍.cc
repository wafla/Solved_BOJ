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
    int n, x, y;
    cin >> n >> x >> y;
    set<int> S;
    for (int i = 0; i < x; i++)
    {
        int num;
        cin >> num;
        S.insert(num);
    }
    for (int i = 0; i < y; i++)
    {
        int num;
        cin >> num;
        if (S.count(num))
        {
            S.erase(num);
            continue;
        }
        if (S.count(num - 1))
            S.erase(num - 1);
        else if (S.count(num + 1))
            S.erase(num + 1);
    }
    cout << S.size();
}