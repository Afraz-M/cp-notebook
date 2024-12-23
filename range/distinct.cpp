#include <bits/stdc++.h>
#define VI vector<int>
#define V vector
#define ll long long
#define VLL vector<ll>
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
    int size;

    FenwickTree(T n) {
        size = n;
        tree.resize(n + 1, 0);
    }

    FenwickTree(V<T> arr) {
        tree.resize(arr.size());
        tree = arr;
    }

    void update(T index, T value) {
        index++;
        while (index <= size ) {
            tree[index] += value;
            index += index & -index;
        }
    }

    T prefixSum(T index) {
        T sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    T rangeSum(T left, T right) {      
        left++, right++;
        return prefixSum(right) - prefixSum(left - 1);
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
    int n, q;
    cin >> n >> q;
    V<int> nums(n, 0);
    nums = gai<int>(n);
    V<V<pair<int, int>>> queries(n);
    FOR(i, 0, q){
        int a, b;
        cin >> a >> b;
        a--, b--;
        queries[a].push_back({b, i});
    }
    FenwickTree <ll>ft(n);
    map<int, int> li;
    VI res(q, -1);
    ROF(i, n - 1, -1){
        int val = nums[i];
        if(li.count(val) > 0) ft.update(li[val], -1);
        li[val] = i;
        ft.update(i, 1);
        for(auto &q: queries[i]){
            res[q.second] = ft.rangeSum(0, q.first);
        } 
    };
    for(auto&r : res){
        cout << r << endl;
    }
    return 0;
}