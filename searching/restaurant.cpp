#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; ++i)
    {
        int arrival, dep;
        cin >> arrival >> dep;
        arr.push_back({arrival, 1});
        arr.push_back({dep, -1});
    }

    sort(arr.begin(), arr.end());

    long long curr = 0;
    long long ans = LLONG_MIN;

    for (const auto &time : arr)
    {
        curr += time.second;
        ans = max(ans, curr);
    }

    cout << ans << endl;

    return 0;
}