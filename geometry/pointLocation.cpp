#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    ll m1 = (y2-y1)*(x3-x2); 
    ll m2 = (y3-y2)*(x2-x1); 

    if (m2 > m1) 
    {
        cout<<"LEFT"<<"\n";
    }
    else if (m2 < m1) 
    {
        cout<<"RIGHT"<<"\n";
    }
    else 
    {
        cout<<"TOUCH"<<"\n";
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        solve();
    }
    return 0;
}