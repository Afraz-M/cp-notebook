#include <bits/stdc++.h>
#define VI vector<int>
#define V vector
#define ll long long
#define Vll vector<ll>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = a; i > b; i--)

using namespace std;

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
V<T> gai(T n){
    V<T> res(n, 0);
    FOR(i, 0, n) {
        cin >> res[i];
    }
    return res;
}

template <typename T>
void printArr(T a){
    FOR(i, 0, a.size()) {
        cout << a[i] << " ";
    }
}


template <typename T>
class SegTree
{
public:
    vector<T> tree;
    int n;
    T defval;
    T (*comp)(T, T);
 
    SegTree(const vector<T> &arr, T (*comp)(T, T), T defval)
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
        for (T val : tree)
        {
            cout << val << " ";
        }
        cout << endl;
    }
 
    T rq(int a, int b)
    {
        a += n;
        b += n;
 
        T s = defval;
 
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
 
    void uq(int k, T x)
    {
        k += n;
        tree[k] -= x;
 
        for (k /= 2; k >= 1; k /= 2)
        {
            tree[k] = comp(tree[2 * k], tree[2 * k + 1]);
        }
    }
};


template <typename T>
class LazySegmentTree {
    public:
        vector<T> tree, lazy;
        T N;
        T defval;
        T (*comp)(T, T);
        

        LazySegmentTree(vector<T>& nums, T (*comp)(T, T), T defval)
            : comp(comp), defval(defval), N(nums.size() - 1) {
                tree.resize(4 * (N + 1), defval);
                lazy.resize(4 * (N + 1), 0);
                build(nums, 1, 0, N);
            }

        void push(T i, T l, T r){
            tree[i] += lazy[i];
            if(l != r) lazy[i * 2] += lazy[i], lazy[i * 2 + 1] += lazy[i];
            lazy[i] = 0;
        }
        void pull(T i) {tree[i] = comp(tree[i * 2], tree[i * 2 + 1]);}
        void build(vector<T>& v, T i, T l, T r) {
            if(l == r){
                tree[i] = v[l];
                return;
            }
            T m = (l + r) / 2;
            build(v, i * 2, l, m);
            build(v, i * 2 + 1, m + 1, r);
            pull(i);
        }
        void pa() {
            for(int i = 1; i < 4 * (N + 1); ++i) cout << tree[i] << endl;
            cout << endl;
        }
    private:
        void update(T a, T b, T v, T i, T l, T r) {
            push(i, l, r);
            if(b < l || a > r) return;
            if(a <= l && b >= r){
                lazy[i] += v;
                push(i, l, r);
                return;
            }
            T m = (l + r) / 2;
            update(a, b, v, i * 2, l, m);
            update(a, b, v, i * 2 + 1, m + 1, r);
            pull(i);
        }

        T queryRange(T a, T b, T i, T l, T r){
            push(i, l, r);
            if(b < l || a > r) return -1e18;
            if(a <= l && b >= r) return tree[i];
            T m = (l + r) / 2;
            return comp(queryRange(a, b, i * 2, l, m), queryRange(a, b, i * 2 + 1, m + 1, r));
        }
    public:
        void uq(T a, T b, T v) {
            update(a, b - 1, v, 1, 0, N);
        }

        T rq(T a, T b) {
            return queryRange(a, b - 1, 1, 0, N);
        }
};

template <typename T>
class FenwickTree {
    public:
    vector<T> tree;
    vector<T> arr;
    int size;

    FenwickTree(T n) {
        size = n;
        tree.resize(n + 1, 0);
        arr.resize(n, 0);
    }

    void update(T index, T value) {
		arr[index] += value;
        index++;
        while (index <= size ) {
            tree[index] += value;
            index += index & -index;
        }
    }

	void set(int ind, T val) { update(ind, val - arr[ind]); }

    T prefixSum(T index) {
        T sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    T rangeSum(T left, T right) {       // [left, right]
        left++, right++;
        return prefixSum(right) - prefixSum(left - 1);
    }
};

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

template <typename T>
T maxFunc(T a, T b) {
    return max(a, b);
}

template <typename T>
T sumFunc(T a, T b){
    return a + b;
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    VI arr(8, 0);
    arr = gai();
    printArr(arr);
    return 0;
}