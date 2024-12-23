#include <bits/stdc++.h>
#define VI vector<int>
#define ll long long
#define VLL vector<ll>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = a; i > b; i--)

using namespace std;

const int MAXN = 200001;

int n;
VLL a(4 * MAXN, 0);

void printArr(VLL a, int n){
    int i;
    FOR(i, 0, n - 1) {
        cout << a[i] << " ";
    }
}

void printArr(VI a){
    int i;
    FOR(i, 0, a.size()) {
        cout << a[i] << " ";
    }
}

class SegTree
{
public:
    vector<long long> tree;
    int n;
    long long defval;
    long long (*comp)(long long, long long);
 
    SegTree(const vector<long long> &arr, long long (*comp)(long long, long long), long long defval)
        : comp(comp), defval(defval)
    {
        n = arr.size();
        tree.resize(2 * n, 0);
        for (int i = 0; i < n; ++i)
        {
            tree[n + i] = arr[i];
        }
        for (int i = n - 1; i > 0; --i)
        {
            tree[i] = comp(tree[2 * i], tree[2 * i + 1]);
        }
    }
 
    void printTree()
    {
        for (long long val : tree)
        {
            cout << val << " ";
        }
        cout << endl;
    }
 
    long long rq(int a, int b)
    {
        a += n;
        b += n;
 
        long long s = defval;
 
        while (a < b)
        {
            if (a & 1)
            {
                s = comp(s, tree[a]);
                a++;
            }
            if (b & 1)
            {
                b--;
                s = comp(s, tree[b]);
            }
            a >>= 1;
            b >>= 1;
        }
 
        return s;
    }
 
    void uq(int k, long long x)
    {
        k += n;
        tree[k] -= x;
 
        for (k /= 2; k >= 1; k /= 2)
        {
            tree[k] = comp(tree[2 * k], tree[2 * k + 1]);
        }
    }
};


ll maxFunc(ll a, ll b) {
    return max(a, b);
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    FOR(i, 0, n) {cin >> a[i];}
    SegTree st(a, maxFunc, LLONG_MIN);
    auto doQuery = [&](ll room) -> int {
        int l = 0, r = n - 1, res = -1;
        while (l <= r){
            int mid = (l + r) / 2;
            if(st.rq(l, mid + 1) >= room) {
                r = mid - 1;
                if(st.rq(mid, mid + 1) >= room) res = mid;
            } else {
                l = mid + 1;
            }
        }
        if(res != -1) st.uq(res, room);
        return res;
    };
    VLL rooms(q, 0);
    FOR(i, 0, q) cin >> rooms[i];
    for(auto r : rooms){
        cout << doQuery(r) + 1 << " ";
    }
    // printArr(a,  2 * n + 1);
    return 0;
}