#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

vector<int> gai() {
    int l, r;
    cin >> l >> r;
    return {l, r};
}

void test() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> intervals;
    vector<int> contained(n, 0); 
    vector<int> contains(n, 0);
    for (int i = 0; i < n; ++i) {
        auto interval = gai();
        intervals.push_back({{interval[0], interval[1]}, i});
    }


    sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
        return a.first.first < b.first.first || 
               (a.first.first == b.first.first && a.first.second > b.first.second);
    });

    int maxR = numeric_limits<int>::min();
    for (const auto &interval : intervals) {
        int l = interval.first.first, r = interval.first.second, i = interval.second;
        if (r <= maxR) {
            contained[i] = 1;
        }
        maxR = max(maxR, r);
    }

    int minR = numeric_limits<int>::max();
    for (int j = n - 1; j >= 0; --j) {
        int l = intervals[j].first.first, r = intervals[j].first.second, i = intervals[j].second;
        if (r >= minR) {
            contains[i] = 1;
        }
        minR = min(minR, r);
    }

    for (const auto &val : contains) {
        cout << val << " ";
    }
    cout << "\n";
    for (const auto &val : contained) {
        cout << val << " ";
    }
    cout << "\n";
}

int main() {
    test();
    return 0;
}
