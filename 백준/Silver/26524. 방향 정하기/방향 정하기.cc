#include<iostream>
#define ll long long
using namespace std;
ll arr[1000001]={0};
int main(){
    int n;
    cin >> n;
    arr[2]=2;
    for(int i=3;i<=n;i++)
    {
        arr[i]=(i*arr[i-1])%1000000007;
    }
    cout << arr[n];
}