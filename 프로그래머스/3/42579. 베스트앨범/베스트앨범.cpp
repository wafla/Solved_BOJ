#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define X first
#define Y second
#define pi pair<int,int>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int,int>>> M;
    map<string, int> cnt;
    for (int i = 0; i < plays.size(); i++)
    {
        cnt[genres[i]] += plays[i];
        M[genres[i]].push_back({plays[i],i});
    }
    
    for (auto& genre : M)
    {
        sort(genre.Y.begin(), genre.Y.end(), [](pi& a, pi& b) {
            if (a.X == b.X) return a.Y < b.Y;
            return a.X > b.X;
            });
    }
    vector<pair<int, string>> v;
    for (auto i : cnt)
        v.push_back({ i.Y,i.X });
    sort(v.begin(), v.end(), greater<pair<int,string>>());
    
    for (auto& genre : v)
    {
        int x = 0;
        for (auto& song : M[genre.Y])
        {
            answer.push_back(song.Y);
            x++;
            if (x == 2)
                break;
        }
    }
    return answer;
}