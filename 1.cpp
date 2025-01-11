#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
namespace geo {

    class Point {
    public:
        int x, y;

        Point(int x, int y) : x(x), y(y) {}

        double distance(const Point& o) const {
            return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));
        }

        static int cmp(const Point& a, const Point& b) {
            if (a.x < b.x) return -1;
            if (a.x > b.x) return 1;
            if (a.y < b.y) return -1;
            if (a.y > b.y) return 1;
            return 0;
        }
    };

    int cross(const Point& o, const Point& a, const Point& b) {
        return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<geo::Point> pts;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        pts.push_back(geo::Point(x, y));
    }

    sort(pts.begin(), pts.end(), [](const geo::Point& a, const geo::Point& b) {
        return geo::Point::cmp(a, b) < 0;
    });

    vector<geo::Point> hull;

    for (const auto& p : pts) {
        while (hull.size() >= 2 && geo::cross(hull[hull.size() - 2], hull[hull.size() - 1], p) < 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    geo::Point s = hull[0];
    geo::Point e = hull.back();
    vector<geo::Point> bndry;

    for (auto it = pts.rbegin(); it != pts.rend(); ++it) {
        if (it->x == s.x && it->y != s.y) {
            bndry.push_back(*it);
        }
    }

    for (const auto& p : hull) {
        bndry.push_back(p);
    }

    double peri = 0;
    for (size_t i = 0; i < bndry.size() - 1; ++i) {
        peri += bndry[i].distance(bndry[i + 1]);
    }

    cout << round(peri) << endl;

    return 0;
}
