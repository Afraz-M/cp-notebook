#include <bits/stdc++.h>
#define VI vector<int>
#define V vector
#define ll long long
#define VLL vector<ll>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = a; i > b; i--)

using namespace std;

template <typename T> 
V<T> gai(T n){
    V<T> res(n, 0);
    FOR(i, 0, n) {
        cin >> res[i];
    }
    return res;
}

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

    T rangeSum(T left, T right) {
        left++, right++;
        return prefixSum(right) - prefixSum(left - 1);
    }
};


int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
	cin >> n >> q;
	V<ll> nums(n, 0), pref(n + 1, 0), ans(q, 0);
	V<V<pair<ll, ll>>> queries(n + 1);
	nums = gai<ll>(n);
	FOR(i, 0 ,q){
		int s, e;
		cin >> s >> e;
		s--, e--;
		queries[s].push_back({e, i});
	}
	FOR(i, 1, n + 1){pref[i] = pref[i - 1] + nums[i - 1];}
	FenwickTree <ll>contrib(n);
	V<pair<ll, ll>> maxes;
	ROF(i, n - 1, -1){
		while(!maxes.empty() and maxes.back().first <= nums[i]) {
			maxes.pop_back();
			contrib.set(maxes.size(), 0);
		}
		ll len = (maxes.empty() ? n : maxes.back().second) - i;
		contrib.set(maxes.size(), nums[i] * len);
		maxes.push_back({nums[i] , i});
		for(pair<int, int> query : queries[i]) {
			ll end = query.first;
			ll idx = query.second;
			ll low = 0, high = maxes.size() - 1;
			ll valid = -1;
			while (low <= high){
				ll mid = (low + high) / 2;
				if(maxes[mid].second <= end) {
					valid = mid;
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
			ll sum1 = contrib.rangeSum(valid + 1, maxes.size() - 1);
			ll sum2 = (end - maxes[valid].second + 1) * maxes[valid].first;
			ll sub = pref[end + 1] - pref[i];
			ll res = sum1 + sum2 - sub;
			ans[idx] = res;
		}
	}

	FOR(i, 0, q){
		cout << ans[i] << '\n';
	}
    return 0;
}