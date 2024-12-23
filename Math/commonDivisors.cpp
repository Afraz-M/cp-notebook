#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

vector<int> nums(MAXN + 1, 0);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        nums[x]++;
    }

    for(int i = MAXN; i > 0; i--){
        int di = 0;
        for(int j = i; j <= MAXN; j += i){ di += nums[j];}
        if(di >= 2){
                cout << i << endl;
                return 0;
        }
    }
}