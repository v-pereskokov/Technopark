#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using data = unsigned long long int;
using container = std::vector<data>;

data findMax(container &target) {
  data max = target[0];
  for (int i = 1; i < target.size(); i++)
    if (target[i] > max)
      max = target[i];
  return max;
};

void countSort(container &target, int radix) {
  container buffer(target.size());
  container count(10, 0);
  int i;
  for (i = 0; i < target.size(); i++) {
    count[(target[i] / radix) % 10]++;
  }
  for (i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  for (i = target.size() - 1; i >= 0; i--) {
    buffer[--count[(target[i] / radix) % 10]] = target[i];
  }
  for (i = 0; i < target.size(); i++) {
    target[i] = buffer[i];
  }
};

void radixSort(container &target) {
  data max = findMax(target);
  for (int radix = 1; max / radix > 0; radix *= 10) {
//    countSort(target, radix);
    std::stable_sort(target.begin(), target.end(), [radix](const data a, const data b){ return (a / radix % 10) < (b / radix % 10);});
  }
}

//int main() {
//  size_t n;
//  scanf("%lu", &n);
//  std::vector<data> v;
//  for (size_t i = 1; i <= n; ++i) {
//    data element;
//    //  while (scanf("%lld", &element) == 1) {
//    scanf("%lld", &element);
//    v.push_back(element);
//  }
////  radixSort(v);
//  std::sort(v.begin(), v.end());
//  for (auto i : v) {
//    printf("%lld ", i);
//  }
//  printf("\n");
//  return 0;
//}

bool issorted(const std::vector<data> &vector) {
  for (size_t i = 1; i < vector.size(); ++i) {
    if (vector[i] < vector[i - 1]) {
      return false;
    }
  }
  return true;
}

void test() {
  srand(42);
  for (size_t i = 1; i <= 500; ++i) {
    std::vector<data> vector;
    size_t n = rand() % 10000 + 2;
    for (size_t j = 0; j < n; ++j) {
      vector.push_back(rand() % 1000000 + 1);
    }
    vector[0] = (1000000);
    std::vector<data> copy(vector);
//    std::sort(copy.begin(), copy.end());
    radixSort(vector);
    for (size_t j = 0; j < vector.size(); ++j) {
      if (!issorted(vector)) {
        std::cout << "size: " << vector.size() << "\n";
        for (auto a : copy) {
          std::cout << a << std::endl;
        }
        return;
      }
    }
  }
}

int main() {
  test();
////  size_t n;
////  scanf("%lu", &n);
//  std::vector<data> v;
////  for (size_t i = 1; i <= n; ++i) {
//    data element;
//  while (scanf("%lld", &element) == 1) {
//    v.push_back(element);
//  }
////  radixSort(v);
//  std::sort(v.begin(), v.end());
//  for (auto i : v) {
//    printf("%lld\n", i);
//  }
////  printf("\n");
  return 0;
}
