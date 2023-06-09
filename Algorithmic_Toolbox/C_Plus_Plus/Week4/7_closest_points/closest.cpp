#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


struct Point {
  int x;
  int y;
};

double distance(const Point & p1,
  const Point & p2) {
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  return sqrt(dx * dx + dy * dy);
}

bool compareY(const Point & p1,
  const Point & p2) {
  return p1.y < p2.y;
}

double stripClosest(vector < Point > & strip, double d) {
  double min_distance = d;
  int size = strip.size();

  sort(strip.begin(), strip.end(), compareY);

  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min_distance; ++j) {
      double dist = distance(strip[i], strip[j]);
      min_distance = min(min_distance, dist);
    }
  }

  return min_distance;
}

double minimal_distance_helper(vector < Point > & points, int l, int r) {
  if (r - l <= 3) {
    double min_distance = numeric_limits < double > ::max();
    for (int i = l; i <= r; ++i) {
      for (int j = i + 1; j <= r; ++j) {
        double dist = distance(points[i], points[j]);
        min_distance = min(min_distance, dist);
      }
    }
    return min_distance;
  }

  int mid = (l + r) / 2;
  Point midPoint = points[mid];

  double dl = minimal_distance_helper(points, l, mid);
  double dr = minimal_distance_helper(points, mid + 1, r);
  double d = min(dl, dr);

  vector < Point > strip;
  for (int i = l; i <= r; ++i) {
    if (abs(points[i].x - midPoint.x) < d) {
      strip.push_back(points[i]);
    }
  }

  return min(d, stripClosest(strip, d));
}

double minimal_distance(vector < int > x, vector < int > y) {
  int n = x.size();
  vector < Point > points(n);

  for (int i = 0; i < n; ++i) {
    points[i] = {
      x[i],
      y[i]
    };
  }

  sort(points.begin(), points.end(), [](const Point & p1,
    const Point & p2) {
    return p1.x < p2.x;
  });

  return minimal_distance_helper(points, 0, n - 1);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}