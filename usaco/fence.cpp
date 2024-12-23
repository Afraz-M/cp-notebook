#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    vector<int> paint(100, 0);
    int a, b, c, d, res;
    res = 0;
    cin >> a >> b >> c >> d;
    for (int i = a; i < b; i++) paint[i] = 1;
    for (int i = c; i < d; i++) paint[i] = 1;
    for (int i = 0; i < paint.size(); i++){
        if (paint[i] == 1){
            res += 1;
        }
    }
    cout << res;
    return 0;
}