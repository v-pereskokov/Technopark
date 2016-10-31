#include <cstdio>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

using data_type = int;
using size_type = size_t;

bool less(const data_type &lhs, const data_type &rhs) {
  return lhs < rhs;
}

template <class IT, class comparator>
IT partition_(IT begin, IT end, comparator &comp) {
  IT pivot = end;
  IT it = begin - 1;
  for (IT jt = begin; jt != pivot; ++jt) {
    if (!less(*pivot, *jt)) {
      ++it;
      std::swap(*it, *jt);
    }
  }
  ++it;
  std::swap(*it, *pivot);
  return it;
}

size_t random(const size_type begin, const size_type end) {
  std::mt19937 mt(time(0));
  auto rand = std::bind(std::uniform_int_distribution<size_t>(begin, end), std::mt19937(mt));
  return rand();
}

template <class IT, class comparator>
IT randomPartition(IT begin, IT end, comparator &comp) {
  size_type pivot = random(0, std::distance(begin, end) - 1);
  std::swap(*begin, *(begin + pivot));
  return partition_(begin, end, comp);
}

template <class IT, class comparator>
void quickSort(IT begin, IT end, comparator &comp) {
  if (begin < end) {
    IT pivot = randomPartition(begin, end, comp);
    quickSort(begin, pivot - 1, comp);
    quickSort(pivot + 1, end, comp);
  }
}

int main() {
  std::vector<data_type> v{-8, 2, 3, 5, 1, 0, 1, 5, 6};
  quickSort(v.begin(), v.end(), less);
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
