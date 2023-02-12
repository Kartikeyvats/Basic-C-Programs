#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    Point(int x=0, int y=0): x(x), y(y) {}
};

int N;
vector<Point> P;

bool cmpX(const Point &a, const Point &b) {
    return a.x < b.x;
}

bool cmpY(const Point &a, const Point &b) {
    return a.y < b.y;
}

double dist(Point A, Point B) {
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

double closest_pair(int left, int right) {
    if (right-left <= 1) return 1e9;
    int mid = (left+right)/2;
    double d = min(closest_pair(left, mid), closest_pair(mid, right));
    vector<Point> strip;
    for (int i=left; i<right; i++) {
        if (abs(P[i].x-P[mid].x) < d) {
            strip.push_back(P[i]);
        }
    }
    sort(strip.begin(), strip.end(), cmpY);
    for (int i=0; i<strip.size(); i++) {
        for (int j=i+1; j<strip.size() && strip[j].y-strip[i].y < d; j++) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }
    return d;
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        P.push_back(Point(x, y));
    }
    sort(P.begin(), P.end(), cmpX);
    cout << closest_pair(0, N) << endl;
    return 0;
}
