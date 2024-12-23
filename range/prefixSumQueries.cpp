#include <bits/stdc++.h>
#define I int
#define V vector
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a; i > b; i--)

using namespace std;

template <typename T>
void read(T &x)
{
    cin >> x;
}

template <typename T, typename... Args>
void read(T &x, Args &...args)
{
    cin >> x;
    read(args...);
}

template <size_t Index = 0, typename... Args>
typename enable_if<Index == sizeof...(Args), void>::type
readTuple(tuple<Args...> &t)
{
}

template <size_t Index = 0, typename... Args>
    typename enable_if < Index<sizeof...(Args), void>::type
                         readTuple(tuple<Args...> &t)
{
    cin >> get<Index>(t);
    readTuple<Index + 1, Args...>(t);
}

template <typename... Args>
tuple<Args...> gai()
{
    tuple<Args...> t;
    readTuple(t);
    return t;
}

template <typename T>
vector<T> gai(T x)
{
    vector<T> input(x, 0);
    FOR(i, 0, x)
    {
        T num;
        cin >> input[i];
    }
    return input;
}

template <typename T>
class LazySegmentTree
{
public:
    vector<T> tree, lazy;
    int N;
    T defval;
    T(*comp) (T, T);

    LazySegmentTree(vector<T> &nums, T (*comp)(T, T), T defval)
        : comp(comp), defval(defval), N(nums.size() - 1), tree(4 * (N + 1), defval),
          lazy(4 * (N + 1), 0)
    {
        tree.resize(4 * (N + 1));
        lazy.resize(4 * (N + 1));
        build(nums, 1, 0, N);
    }

    void push(int i, int l, int r)
    {
        tree[i] += lazy[i];
        if (l != r)
            lazy[i * 2] += lazy[i], lazy[i * 2 + 1] += lazy[i];
        lazy[i] = 0;
    }
    void pull(int i) { tree[i] = comp(tree[i * 2], tree[i * 2 + 1]); }
    void build(vector<T> &v, int i, int l, int r)
    {
        if (l == r)
        {
            tree[i] = v[l];
            return;
        }
        T m = (l + r) / 2;
        build(v, i * 2, l, m);
        build(v, i * 2 + 1, m + 1, r);
        pull(i);
    }
    void pa()
    {
        for (int i = 1; i < 4 * (N + 1); ++i)
            cout << tree[i] << endl;
    }
    void update(int a, int b, T v, int i, int l, int r)
    {
        push(i, l, r);
        if (b < l || a > r)
            return;
        if (a <= l && b >= r)
        {
            lazy[i] += v;
            push(i, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(a, b, v, i * 2, l, m);
        update(a, b, v, i * 2 + 1, m + 1, r);
        pull(i);
    }

    T queryRange(int a, int b, int i, int l, int r)
    {
        push(i, l, r);
        if (b < l || a > r)
            return -1e18;
        if (a <= l && b >= r)
            return tree[i];
        int m = (l + r) / 2;
        return comp(queryRange(a, b, i * 2, l, m), queryRange(a, b, i * 2 + 1, m + 1, r));
    }
    void uq(int a, int b, T v)
    {
        update(a, b - 1, v, 1, 0, N);
    }

    T rq(int a, int b)
    {
        return queryRange(a, b - 1, 1, 0, N);
    }
};

template <typename T>
T maxFunc(T a, T b)
{
    return max(a, b);
}

template <typename T>
T sumFunc(T a, T b)
{
    return a + b;
}

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> nums(n + 1, 0), prefix(n + 1, 0);
    FOR(i, 1, n + 1)
    cin >> nums[i];
    FOR(i, 1, n + 1)
    {
        prefix[i] = (nums[i] + prefix[i - 1]);
    }
    LazySegmentTree<ll> lst(prefix, maxFunc, LLONG_MIN);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i;
            ll x;
            cin >> i >> x;
            lst.uq(i, n + 1, x - nums[i]);
            nums[i] = x;
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << lst.rq(a - 1, b + 1) - lst.rq(a - 1, a) << endl;
        }
    }
    return 0;
}