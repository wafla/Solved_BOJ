#include <string>
#include <vector>
#include <queue>
#define X first
#define Y second
#define pi pair<int,int>
#define T pair<pi, pi>
using namespace std;
int arr[26][26]={0};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int solution(vector<vector<int>> board) {
    int n = board.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j] = 987654321;
    arr[0][0] = 0;
    priority_queue<T, vector<T>, greater<T>> PQ; // 비용, 방향, 좌표
    PQ.push({{0,0}, {0,0}});
    PQ.push({{0,1}, {0,0}});
    while(!PQ.empty())
    {
        auto cur = PQ.top();
        PQ.pop();
        int w = cur.X.X;
        int dir = cur.X.Y;
        int x = cur.Y.X;
        int y = cur.Y.Y;
        if(x==n-1 && y==n-1)
            continue;
        for(int k=0;k<4;k++)
        {
            for(int cnt=1;;cnt++)
            {
                int nx = x + dx[k] * cnt;
                int ny = y + dy[k] * cnt;
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny]==1)
                    break;
                int nw = w;
                if(dir == k)
                    nw += 100 * cnt;
                else
                    nw += 500 + 100 * cnt;
                if(arr[nx][ny] > nw)
                {
                    arr[nx][ny] = nw;
                    PQ.push({{nw,k},{nx,ny}});
                }
            }
        }
    }
    return arr[n-1][n-1];
}