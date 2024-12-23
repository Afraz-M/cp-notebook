#include<bits/stdc++.h>
using namespace std;
const vector<string> NAMES{"Bessie", "Elsie", "Mildred"};
int main(){

    int n;
    cin >> n;
    vector<tuple<int,string,int>> update;
    for(int i = 0; i < 7; i++){
        int day, change;
        string cow;
        cin >> day >> cow >> change;
        update.push_back(tie(day, cow, change));
    }

    sort(update.begin(), update.end());
    map<string, int> outputs;
    int res = 0;
    for(const auto name : NAMES) { outputs[name] = 7; }
    vector<string> display = NAMES;
    for(const tuple<int, string, int> u : update) {
        outputs[get<1>(u)] += get<2>(u);
        int winner = 0;
        for(const auto output : outputs){
            int o;
            string i;
            tie(i, o) = output;
            winner = max(winner, o);
        }
        vector<string> new_display;
        for(const auto output : outputs){
            int o;
            string i;
            tie(i, o) = output;
            if (o == winner) {
                new_display.push_back(i);
            }
        }
        res += new_display != display;
        display = new_display;
    }
    cout << res << endl;
    return 0;
}