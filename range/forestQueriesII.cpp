#include <bits/stdc++.h>
#define VI vector<int>
#define V vector
#define ll long long
#define Vll vector<ll>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = a; i > b; i--)

using namespace std;

struct BIT {
    V<Vll> tree;
    int n;
    int m;
    BIT(int n, int m)
    {
        tree = V<Vll>(n, Vll (m, 0));
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

    ll query(int a, int b) {
        ll s = 0;
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

    ll query(int x1,int y1, int x2, int y2) {    // [(x1,  y1), (y1, y2)]
        if (x1 > x2 || y1 > y2)
            return 0;
        else
            return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
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
    FOR(i, 0, q){
        int t;
        cin >> t;
        if(t == 1) {
            int y, x;
            cin >> x >> y;
            y--, x--;
            if (bit.query(x,y,x,y) == 1) {
                bit.add(x, y, -1);
            } else {
                bit.add(x, y, 1);
            }
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            cout << bit.query(x1, y1, x2, y2) << endl;
        }
    }
}