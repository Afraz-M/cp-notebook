#include<bits/stdc++.h>
#define VI vector<int>
using namespace std;

int main(){
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    VI limit(100);
    VI bessie(100);
    int start = 0;
    for(int i = 0; i < n; i++){
        int len, lim;
        cin >> len >> lim;
        for(int j = start; j < start + len; j++){
            limit[j] = lim;
        }
        start += len;
    }
    start = 0;
    for(int i = 0; i < n; i++){
        int len, lim;
        cin >> len >> lim;
        for(int j = start; j < start + len; j++){
            bessie[j] = lim;
        }
        start += len;
    }
    int res = 0;
    for(int i = 0; i < 100; i++){
        res = max(res, bessie[i] - limit[i]);
    }
    cout << res << "\n";
    return 0;
}