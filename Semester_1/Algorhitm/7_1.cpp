#include <stdio.h>
#include <vector>

struct Athlete {
  Athlete(const int weight, const int power)
  : _weight(weight), _power(power) {}
  
  int _weight;
  int _power;
};

int maxPyramid(const std::vector<Athlete> &athletes) {
  int num = 0;
  int sum = 0;
  for (size_t i = 0; i < athletes.size(); ++i) {
    if (athletes[i]._power >= sum) {
      sum += athletes[i]._weight;
      ++num;
    }
  }
  return num;
}

int main() {
  int n;
  scanf("%d", &n);
  if (n > 0 && n <= 100000) {
    std::vector<Athlete> athletes;
    int weight;
    int power;
    for (size_t i = 0; i < n; ++i) {
      scanf("%d %d", &weight, &power);
      athletes.push_back(Athlete(weight, power));
      std::sort(athletes.begin(), athletes.end(), [](Athlete lhs, Athlete rhs){ return lhs._power < rhs._power; });
    }
    printf("%d\n", maxPyramid(athletes));
  }
  return 0;
}