#include <bits/stdc++.h>
#define VI vector<int>
#define ll long long
#define VLL vector<ll>
#define FOR(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int MAXN = 1000000;


VLL glai() {
    string line;
    getline(cin, line); 
    stringstream ss(line); 
    VLL result;
    ll num;

    while (ss >> num) {
        result.push_back(num);
    }
    
    return result;
}


class SegTree
{
public:
    long long defval;
    long long (*comp)(long long, long long);
    vector<long long> tree;
    int n;
 
    SegTree(const vector<long long> &arr, long long (*comp)(long long, long long), long long defval)
        : defval(defval), comp(comp)
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
        tree[k] += x;
 
        for (k /= 2; k >= 1; k /= 2)
        {
            tree[k] = comp(tree[2 * k], tree[2 * k + 1]);
        }
    }
};

ll sumFunc(ll a, ll b){
    return a + b;
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    cin.ignore(1000, '\n');
    VLL salary(n, 0);
    salary = glai();
    vector<tuple<char, ll, ll>> queries;
    FOR(i, 0, q) {
        ll a, b;
        char k;
        cin >> k >> a >> b;
        tuple<char, ll, ll> t = make_tuple(k, a, b);
        queries.push_back(t);
    }
    VLL freq(MAXN, 0);
    vector<multiset<ll>> theMap(MAXN);
    FOR(i, 0, n) {
        ll ele = floor(salary[i] / 1000);
        freq[ele] += 1;  
        theMap[ele].insert(salary[i]);
    }
    VI res;
    SegTree ST(freq, sumFunc, 0);
    for(auto& query : queries) {
        char k;
        ll a, b;
        tie(k, a, b) = query;
        if(k == '!') {
            ll emp = salary[a - 1];
            ll ele = floor(emp / 1000);
            theMap[ele].erase(theMap[ele].find(emp));
            ll ele2 = floor(b / 1000);
            theMap[ele2].insert(b);
            salary[a - 1] = b;
            ST.uq(ele, -1);
            ST.uq(ele2, 1);
        } else {
            ll sum = 0;
            ll l = floor(a / 1000);
            ll r = floor(b / 1000);
            if(l != r) {
            for(ll i : theMap[l]){
                if (i >= a) {
                    sum += 1;
                }
            }
            for(ll i : theMap[r]){
                if (i <= b) {
                    sum += 1;
                }
            }
            l += 1;
            r -= 1;
            if(l <= r){
                sum += ST.rq(l, r + 1);
            }
            } else {
                for(int i : theMap[l]){
                    if (i >= a && i <= b) {
                        sum += 1;
                    }
                }
            }
            res.push_back(sum);
        }
    }
    for(auto& i:res) {
        cout << i << endl;
    }
    return 0;
}