#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment{
  int start, end;
};

struct CompareSegments{
  bool operator()(const Segment &s1, const Segment &s2) const
  {
    return s1.end < s2.end;
  }
};

vector<int> optimal_points(vector<Segment> &segments){
  vector<int> points;

  // Sort segments by their right endpoints using the functor
  std::sort(segments.begin(), segments.end(), CompareSegments());
  int last_point = segments[0].end;
  points.push_back(last_point);

  for (const Segment &segment : segments){
    if (segment.start > last_point){
      // Found a new non-overlapping segment
      last_point = segment.end;
      points.push_back(last_point);
    }
  }
  return points;
}

int main(){
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i){
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i){
    std::cout << points[i] << " ";
  }
}
