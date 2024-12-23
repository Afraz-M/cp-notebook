#include <bits/stdc++.h>
#define VI vector<int>
#define ll long long
#define VLL vector<ll>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = a; i > b; i--)

using namespace std;

void printArr(VLL a, int n){    
    FOR(i, 0, n) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printArr(VLL a){
    FOR(i, 0, (int) a.size()) {
        cout << a[i] << " ";
    }
    cout << endl;
}

VLL gai(int n) {
    VLL result;
    ll num;
    while(n--) {
        cin >> num;
        result.push_back(num); 
    }
    return result;
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

class FenwickTree {
    public:
    vector<ll> tree;
    int size;

    FenwickTree(int n) {
        size = n;
        tree.resize(n + 1, 0);
    }

    FenwickTree(VLL arr) {
        tree.resize(arr.size());
        tree = arr;
    }

    void update(int index, ll value) {
        while (index <= size ) {
            tree[index] += value;
            index += index & -index;
        }
    }

    ll prefixSum(int index) {
        ll sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    ll rangeSum(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }
};

ll maxFunc(ll a, ll b) {
    return max(a, b);
}

ll sumFunc(ll a, ll b){
    return a + b;
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    VLL list(n, 0), queries(n, 0);
    list = gai(n);
    queries = gai(n);
    FenwickTree tree(n);
    FOR(i, 1, n + 1) {
        tree.update(i, 1);
    }
    auto doQuery = [&](ll q) -> void {
        int l = 1, res, r = n;
        while(l <= r) {
            int mid = (l + r) / 2;
            int temp = tree.prefixSum(mid);
            int temp2 = tree.prefixSum(mid - 1);
            if(temp == q && temp2 == q - 1) {
                res = mid;
                break;
            } else if(temp >= q) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        tree.update(res, -1);
        cout << list[res - 1] << " ";
    };
    for(auto q : queries) {
        doQuery(q);
    }
    return 0;
}