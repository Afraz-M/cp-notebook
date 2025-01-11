#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 4e6;
// phi[i] = how many pairs of numbers <=i are coprime
int phi[MAX_N + 1];
// // Store the values found to speed up the recursion process
// unordered_map<int, long long> memo;

// long long solve(long long n) {
// 	if (n <= MAX_N) { return phi[n]; }
// 	if (memo.count(n)) { return memo[n]; }

// 	long long d = sqrt(n);
// 	long long ans = 1LL * n * (n + 1) / 2;
// 	for (int i = 2; n / i > d; i++) { ans -= solve(n / i); }

// 	for (int i = d; i >= 1; i--) { ans -= 1LL * (n / i - n / (i + 1)) * solve(i); }
// 	memo[n] = ans;

// 	return ans;
// }

// std::vector <int> prime;
// bool is_composite[10];

// void sieve (int n) {
// 	std::fill (is_composite, is_composite + n, false);
// 	for (int i = 2; i < n; ++i) {
// 		if (!is_composite[i]) prime.push_back (i);
// 		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
// 			is_composite[i * prime[j]] = true;
// 			if (i % prime[j] == 0) break;
// 		}
// 	}
// }

int main() {
	// Precompute the values of phi as previously shown
	for (int i = 1; i <= MAX_N; i++) { phi[i] = i; }
	for (int i = 2; i <= MAX_N; i++) {
		// If i is prime
		if (phi[i] == i) {
			phi[i]--;
			for (int j = i + i; j <= MAX_N; j += i) { phi[j] = phi[j] / i * (i - 1); }
		}
	}

	// Prefix sums of phi
	for (int i = 2; i <= MAX_N; i++) { phi[i] += phi[i - 1]; }

	// int n;
	// while (cin >> n) {
	// 	if (n == 0) { break; }

	// 	long long ans = 0;
	// 	// for (int d = 1; d <= n; d++) { ans += d * (solve(n / d) - 1); }
	// 	cout << ans << '\n';
	// }
	// for(int i = 0; i <= MAX_N; i++){
	// 	cout << phi[i] << " ";
	// }
	cout << phi[4000000];
    // sieve(10);
    // for(int i = 0; i < prime.size() ; i++){
    //     cout << prime[i]  << " ";
    // }
}