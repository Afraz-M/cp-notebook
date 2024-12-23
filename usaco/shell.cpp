#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("shell.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> shell(3);
    vector<int> counter(3);
    for(int i = 0; i < 3; i++) { 
        shell[i] = i; 
    }
    for(int i = 0; i < n; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        a--, b--, g--;
        swap(shell[a], shell[b]);
        counter[shell[g]]++;
    }
    freopen("shell.out", "w", stdout);
    cout << max({counter[0], counter[1], counter[2]}) << endl;
    return 0;
}