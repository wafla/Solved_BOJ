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
    int num;
    int mo;
    int dir; // 1은 반시계 -1은 시계
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    queue<T> Q;
    Q.push({ m,3,1 });
    Q.push({ m,3,-1 });
    while (1)
    {
        auto cur = Q.front();
        Q.pop();
        if (cur.mo == k)
        {
            cout << cur.num;
            break;
        }
        if (cur.dir == -1 && cur.num - 1 == 0)
            Q.push({ n,cur.mo - 1, -1 });
        else if (cur.dir == -1)
            Q.push({ cur.num - 1,cur.mo - 1,-1 });
        if (cur.dir == 1 && cur.num + 1 > n)
            Q.push({ 1,cur.mo + 1,1 });
        else if (cur.dir == 1)
            Q.push({ cur.num + 1,cur.mo + 1,1 });
    }
}