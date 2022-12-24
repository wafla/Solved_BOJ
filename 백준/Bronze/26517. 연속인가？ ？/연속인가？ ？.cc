#include<iostream>
#define ll long long
using namespace std;
int main(){
    ll k,a,b,c,d;
    cin >> k >> a >> b >> c >> d;
    if(a*k+b==c*k+d)
        cout << "Yes " << a*k+b;
    else
        cout << "No";
}