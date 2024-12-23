#include <iostream>
#include <vector>
#include <map>

using namespace std;

void test() {
    int N, X;
    cin >> N >> X;
    vector<int> T(N);

    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    long long prefixSum = 0;
    long long res = 0;
    map<long long, int> Sum;
    Sum[0] = 1;

    for (int x : T) {
        prefixSum += x;
        res += Sum[prefixSum - X];
        Sum[prefixSum]++;
    }
    
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test();
    return 0;
}
