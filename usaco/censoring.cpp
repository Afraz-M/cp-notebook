#include<bits/stdc++.h>


using namespace std;

void setUSACO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if ((int)name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    string s, t, c;
    setUSACO("censor");
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++){
        c += s[i];
        if(c.size() > t.size() && 
        c.substr(c.size() - t.size()) == t){
            c.resize(c.size() - t.size());
        }
    }
    cout << c << endl;
}