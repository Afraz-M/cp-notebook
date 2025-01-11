#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

pii newCardinal(const pii &currCardinal, const string &direction) {
    vector<pii> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    map<string, int> dirToInt = {{"left", 3}, {"right", 1}, {"straight", 0}, {"back", 2}};
    int idx = find(begin(dirs), end(dirs), currCardinal) - begin(dirs);
    int newIdx = (idx + dirToInt[direction]) % 4;
    return dirs[newIdx];
}

pii dirDifference(const string &inDir, const string &endDir, pii tple) {
    vector<string> directions = {"straight", "right", "back", "left"};
    int diff = (find(directions.begin(), directions.end(), endDir) - directions.begin() -
                (find(directions.begin(), directions.end(), inDir) - directions.begin()) + 4) % 4;
    for (int i = 0; i < diff; ++i) {
        tple = {tple.second, -tple.first};
    }
    return tple;
}

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> instructions;
    for (int i = 0; i < n; ++i) {
        string direction;
        int distance;
        cin >> direction >> distance;
        instructions.emplace_back(direction, distance);
    }

    pii src, dest;
    cin >> src.first >> src.second;
    cin >> dest.first >> dest.second;

    vector<pii> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    pii end = src;
    pii facing = dirs[0];

    for (const auto &instruction : instructions) {
        string dir = instruction.first;
        int dist = instruction.second;
        pii newFacing = newCardinal(facing, dir);
        end.first += newFacing.first * dist;
        end.second += newFacing.second * dist;
        facing = newFacing;
    }

    vector<pii> suffixTree;
    pii curr = src;
    facing = dirs[0];
    suffixTree.push_back({end.first - src.first, end.second - src.second});

    for (const auto &instruction : instructions) {
        string dir = instruction.first;
        int dist = instruction.second;
        pii newFacing = newCardinal(facing, dir);
        curr.first += newFacing.first * dist;
        curr.second += newFacing.second * dist;
        facing = newFacing;
        suffixTree.push_back({end.first - curr.first, end.second - curr.second});
    }

    int oldInstIdx = -1;
    string ansDirection;

    curr = src;
    facing = dirs[0];

    for (size_t i = 0; i < instructions.size(); ++i) {
        if (oldInstIdx != -1) break;

        string dir = instructions[i].first;
        int dist = instructions[i].second;

        vector<string> directions = {"straight", "right", "back", "left"};
        for (const string &newDir : directions) {
            if (newDir == dir) continue;

            pii newSuffix = dirDifference(dir, newDir, suffixTree[i]);
            if (curr.first + newSuffix.first == dest.first && curr.second + newSuffix.second == dest.second) {
                oldInstIdx = i;
                ansDirection = newDir;
                break;
            }
        }

        pii newFacing = newCardinal(facing, dir);
        curr.first += newFacing.first * dist;
        curr.second += newFacing.second * dist;
        facing = newFacing;
    }

    if (oldInstIdx == -1) {
        cout << "No" << endl;
    } else {
        cout << "Yes\n";
        cout << instructions[oldInstIdx].first << " " << instructions[oldInstIdx].second << "\n";
        cout << ansDirection << " " << instructions[oldInstIdx].second << endl;
    }

    return 0;
}
