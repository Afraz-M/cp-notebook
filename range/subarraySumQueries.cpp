#include <bits/stdc++.h>
#define VI vector<int>
#define V vector
#define ll long long
#define VLL vector<ll>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = a; i > b; i--)

using namespace std;

const ll MAXN = 2000001;

template <typename T>
void read(T &x) {
    cin >> x;
}

template <typename T, typename... Args>
void read(T &x, Args&... args) {
    cin >> x;
    read(args...);
}


template <size_t Index = 0, typename... Args>
typename enable_if<Index == sizeof...(Args), void>::type
readTuple(tuple<Args...> &t) {
}

template <size_t Index = 0, typename... Args>
typename enable_if<Index < sizeof...(Args), void>::type
readTuple(tuple<Args...> &t) {
    cin >> get<Index>(t);
    readTuple<Index + 1, Args...>(t);
}

template <typename... Args>
tuple<Args...> gai() {
    tuple<Args...> t;
    readTuple(t);
    return t;
}

template <typename T> 
T gai(T n){
    V<T> res(n, 0);
    FOR(i, 0, n) {
        cin >> res[i];
    }
    return res;
}

template <typename T>
void printArr(T a){
    FOR(i, 0, 7) {
        cout << a[i] << " ";
    }
}

struct Node
{
    ll M, L, R, S;
    Node operator+(Node b) {
        return {max(max(M, b.M), R + b.L), max(L, S + b.L),
                max(b.R, R + b.S), S + b.S};
    }
};

ll a[MAXN];
Node segTree[2 * (MAXN + 1)];

void build(ll l, ll r, ll i = 1) {
    // cout << l << " " << r << " " << i << endl;
    if(l == r) {
        segTree[i] = {max(0ll, a[l]), max(0ll, a[l]), max(0ll, a[l]), a[l]};
    } else {
        ll m = (l + r) / 2;
        build(l, m, i * 2);
        build(m + 1, r, i * 2 + 1);
        segTree[i] = segTree[i * 2] + segTree[i * 2 + 1];
    }
}

void update(ll k, ll a, ll l, ll r, ll i){
    if(l == r) {
        segTree[i] = {max(0ll, a), max(0ll, a), max(0ll, a), a};      
    } else {
        ll m = (l + r) / 2;
        if (k <= m) {
            update(k, a, l, m, i * 2);
        } else {
            update(k, a, m + 1, r, i * 2 + 1);
        }
        segTree[i] = segTree[i * 2] + segTree[i * 2 + 1];
    }
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    FOR(i, 0, n) {
        cin >> a[i];
    }
    build(0, n, 1);
    while(q--){
        ll k, x;
        cin >> k >> x;
        update(k - 1, x, 0, n, 1);
        cout << segTree[1].M << endl;
    }
    return 0;
}