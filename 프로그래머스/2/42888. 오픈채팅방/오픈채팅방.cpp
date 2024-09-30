#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#define X first
#define Y second
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, pair<string,string>>> v;
    map<string, string> M;
    for(int i=0;i<record.size();i++)
    {
        string s = record[i];
        stringstream ss(s);
        string action, tmp, id, name;
        ss >> action >> id >> name;
        if(action=="Enter")
        { 
            M[id]=name;
            v.push_back({action,{id,name}});
        }
        else if(action=="Change")
        {
            M[id]=name;
            v.push_back({action,{id,name}});
        }
        else
        {
            action = "Leave";
            v.push_back({action,{id, ""}});
        }
    }
    for(int i=0;i<record.size();i++)
    {
        string s = "";
        if(v[i].X=="Enter")
        {
            s += M[v[i].Y.X] + "님이 들어왔습니다.";
            
        }
        else if(v[i].X=="Change")
        {
            continue;
        }
        else if(v[i].X=="Leave")
        {
            s += M[v[i].Y.X] + "님이 나갔습니다.";
        }
        answer.push_back(s);
    }
    return answer;
}