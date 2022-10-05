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
typedef pair<int, pair<int, int>> T;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool v[126][126] = { 0 };
int arr[126][126] = { 0 };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int cnt = 1;
    while (1)
    {
        memset(v, 0, sizeof(v));
        memset(arr, 0, sizeof(arr));
        int n;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        priority_queue<T, vector<T>, greater<T>> PQ;
        PQ.push({ arr[0][0],{0,0} });
        v[0][0] = 1;
        while (!PQ.empty())
        {
            auto cur = PQ.top();
            PQ.pop();
            if (cur.Y.X == n - 1 && cur.Y.Y == n - 1)
            {
                cout << "Problem " << cnt++ << ": " << cur.X << '\n';
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.Y.X + dx[i];
                int ny = cur.Y.Y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (v[nx][ny])
                    continue;
                v[nx][ny] = 1;
                PQ.push({ cur.X + arr[nx][ny], {nx,ny} });
            }
        }
    }
}