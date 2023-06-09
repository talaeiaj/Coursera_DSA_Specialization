#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
  int coordinate;
  char type;
  int index;

  bool operator<(const Event& other) const {
    return coordinate < other.coordinate || (coordinate == other.coordinate && type < other.type);
  }
};

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> count(points.size());
  vector<Event> events;
  for (int i = 0; i < starts.size(); i++) {
    events.push_back(Event{starts[i], 'l', i});
    events.push_back(Event{ends[i], 'r', i});
  }
  for (int i = 0; i < points.size(); i++) {
    events.push_back(Event{points[i], 'p', i});
  }

  sort(events.begin(), events.end());

  int number_of_segments = 0;
  for (const Event& e : events) {
    if (e.type == 'l') {
      number_of_segments++;
    } else if (e.type == 'r') {
      number_of_segments--;
    } else if (e.type == 'p') {
      count[e.index] = number_of_segments;
    }
  }

  return count;
}


int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
