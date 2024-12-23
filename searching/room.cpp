#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> rooms;
    for (long long i = 1; i <= n; ++i)
    {
        rooms.push(i);
    }

    vector<tuple<long long, int, long long>> intervals;

    for (long long i = 0; i < n; ++i)
    {
        long long start, end;
        cin >> start >> end;
        intervals.emplace_back(start, -1, i);
        intervals.emplace_back(end, 1, i);
    }

    sort(intervals.begin(), intervals.end());

    map<long long, long long> assigned;

    for (const auto &interval : intervals)
    {
        long long customer = get<2>(interval);
        if (get<1>(interval) == -1)
        {
            assigned[customer] = rooms.top();
            rooms.pop();
        }
        else
        {
            rooms.push(assigned[customer]);
        }
    }

    long long maxRoom = 0;
    for (const auto &it : assigned)
    {
        maxRoom = max(maxRoom, it.second);
    }
    cout << maxRoom << endl;

    vector<long long> res(n);
    for (long long i = 0; i < n; ++i)
    {
        res[i] = assigned[i];
    }
    for (long long i = 0; i < n; ++i)
    {
        cout << res[i] << (i < n - 1 ? " " : "\n");
    }

    return 0;
}