#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    string answer;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='z')
        {
            answer.push_back('0');
            i+=3;
        }
        else if(s[i]=='o')
        {
            answer.push_back('1');
            i+=2;
        }
        else if(s[i]=='t')
        {
            if(s[i+1]=='w')
            {
                answer.push_back('2');
                i+=2;
            }
            else if(s[i+1]=='h')
            {
                answer.push_back('3');
                i+=4;
            }
        }
        else if(s[i]=='f')
        {
            if(s[i+1]=='o')
            {
                answer.push_back('4');
                i+=3;
            }
            else if(s[i+1]=='i')
            {
                answer.push_back('5');
                i+=3;
            }
        }
        else if(s[i]=='s')
        {
            if(s[i+1]=='i')
            {
                answer.push_back('6');
                i+=2;
            }
            else if(s[i+1]=='e')
            {
                answer.push_back('7');
                i+=4;
            }
        }
        else if(s[i]=='e')
        {
            answer.push_back('8');
            i+=4;
        }
        else if(s[i]=='n')
        {
            answer.push_back('9');
            i+=3;
        }
        else
            answer.push_back(s[i]);
    }
    int x = stoi(answer);
    return x;
}