#include <string>
#include <vector>
#include <queue>
#define X first
#define Y second
#define pi pair<int,int>
#define T pair<pi, int>
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
    queue<T> Q; // 좌표, 방향
    Q.push({{0, 0}, 0});
    Q.push({{0, 0}, 1});
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        int x = cur.X.X;
        int y = cur.X.Y;
        int dir = cur.Y;
        for(int k=0;k<4;k++)
        {
            for(int cnt=1;;cnt++)
            {
                int nx = x + dx[k] * cnt;
                int ny = y + dy[k] * cnt;
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny]==1)
                    break;
                int nw = 0;
                if(dir == k)
                    nw += 100 * cnt;
                else
                    nw += 500 + 100 * cnt;
                if(arr[nx][ny] > arr[x][y] + nw)
                {
                    arr[nx][ny] = arr[x][y] + nw;
                    Q.push({{nx,ny},k});
                }
            }
        }
    }
    return arr[n-1][n-1];
}