#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    int x, y;
};

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

double dist(const Point& p1, const Point& p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double bruteForceClosestPair(const vector<Point>& points, int start, int end) {
    double minDist = numeric_limits<double>::max();
    for (int i = start; i < end; ++i) {
        for (int j = i + 1; j < end; ++j) {
            minDist = min(minDist, dist(points[i], points[j]));
        }
    }
    return minDist;
}

double closestPair(vector<Point>& x, vector<Point>& y, int start, int end) {
    int n = end - start;
    
    if (n <= 3) {
        return bruteForceClosestPair(x, start, end);
    }
    
    int mid = (start + end) / 2;
    vector<Point> yLeft, yRight;
    
    for (const Point& p : y) {
        if (p.x <= x[mid].x) {
            yLeft.push_back(p);
        } else {
            yRight.push_back(p);
        }
    }
    
    double dl = closestPair(x, yLeft, start, mid);
    double dr = closestPair(x, yRight, mid, end);
    double d = min(dl, dr);
    
    vector<Point> strip;
    for (const Point& p : y) {
        if (abs(p.x - x[mid].x) < d) {
            strip.push_back(p);
        }
    }
    
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; ++j) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }
    
    return d;
}

double closestPair(vector<Point>& points) {
    vector<Point> x = points;
    vector<Point> y = points;
    
    sort(x.begin(), x.end(), compareX);
    sort(y.begin(), y.end(), compareY);
    
    return closestPair(x, y, 0, points.size());
}

int main() {
    vector<Point> points = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {9, 12}};
    
    double closestDistance = closestPair(points);
    
    cout << "The closest pair distance is: " << closestDistance << endl;
    
    return 0;
}

