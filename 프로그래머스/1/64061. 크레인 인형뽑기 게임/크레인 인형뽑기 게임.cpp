#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int ans = 0;
    vector<int> v;
    
    for(int i=0;i<moves.size();i++)
    {
        int now = moves[i] - 1;
        for(int j=0;j<board.size();j++)
        {
            if(board[j][now])
            {
                v.push_back(board[j][now]);
                board[j][now]=0;
                break;
            }
        }
        while(v.size()>1)
        {
            int a = v[v.size()-1];
            int b = v[v.size()-2];
            if(a==b)
            {
                v.pop_back();
                v.pop_back();
                ans+=2;
            }
            else
                break;
        }
    }
    
    return ans;
}