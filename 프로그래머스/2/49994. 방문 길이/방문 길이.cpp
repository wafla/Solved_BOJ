#include <string>
#include <map>
#define pi pair<int,int>
using namespace std;
int dx[4] = {1,-1,0,0}, dy[4]={0,0,1,-1};
map<pair<pi, pi>, int> M;
int solution(string dirs) {
    int answer = 0;
    int x = 0, y = 0;
    for(int i=0;i<dirs.size();i++)
    {
        int nx = x, ny = y;
        if(dirs[i]=='U')
        {
            if(y + 1 <= 5)
                ny = y + 1;
        }
        else if(dirs[i]=='D')
        {
            if(y - 1 >= -5)
                ny = y - 1;
        }
        else if(dirs[i]=='L')
        {
            if(x + 1 <= 5)
                nx = nx + 1;
        }
        else if(dirs[i]=='R')
        {
            if(x - 1 >= -5)
                nx = nx - 1;
        }
        pi tx = {x,y};
        pi ty = {nx,ny};
        if(tx>ty)
            swap(tx,ty);
        if(M[{tx,ty}]==0 && tx!=ty)
        {
            M[{tx,ty}]=1;
            answer++;
        }
        x = nx; y = ny;
    }
    return answer;
}