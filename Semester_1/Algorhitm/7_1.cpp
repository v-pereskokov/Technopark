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
  std::vector<Athlete> athletes;
  int weight;
  int power;
  size_t n = 0;
  while (scanf("%d %d", &weight, &power) || n <= 100000) {
    athletes.push_back(Athlete(weight, power));
    ++n;
  }
  std::sort(athletes.begin(), athletes.end(),
            [](Athlete lhs, Athlete rhs){ return lhs._power < rhs._power; });
  printf("%d\n", maxPyramid(athletes));
  return 0;
}
