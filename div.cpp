#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < n; i++)

using namespace std;

struct BIT {
    vector<vector<long long>> tree;
    int n;
    int m;
    BIT(int n, int m)
    {
        tree = vector<vector<long long>>(n, vector<long long> (m, 0));
        this->n = n;
        this->m = m;
    }
    void add(int a , int b, long long x) {
        int i = a;
        int j;
        while(i<n) {
            j = b;
            while(j<m) {
                tree[i][j] += x;
                j = (j | (j + 1));
            }
            i = (i | (i + 1));
        }
    }
    long long query(int a, int b) {
        long long s = 0;
        int i = a;
        int j;
        while(i>=0) {
            j = b;
            while(j>=0) {
                s += tree[i][j];
                j = (j & (j + 1)) - 1;
            }
            i = (i & (1 + i)) - 1;
        }
        return s;
    }
    long long query(int x1,int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2)
            return 0;
        else
            return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};

int main(){
    int n, q;
	cin >> n >> q;
	BIT bit(n, n);
	FOR(i, 0, n){
		FOR(j, 0, n){
			char c;
			cin >> c;
			bit.add(i, j, (int)(c == '*'));
		}
	}
    cout << bit.query(0, 0, 2, 2) << endl;
    return 0;
}