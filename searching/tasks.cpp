#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);

    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    // Sort tasks based on the first element of each pair
    sort(tasks.begin(), tasks.end());

    long long time = 0, res = 0;
    for (const auto& t : tasks) {
        time += t.first;
        res += (t.second - time);
    }

    cout << res << endl;
    return 0;
}
