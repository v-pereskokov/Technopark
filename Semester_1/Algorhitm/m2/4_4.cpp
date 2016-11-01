#include <cstdio>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

using data_type = int;
using size_type = size_t;
using statistic_type = size_t;

bool less(const data_type lhs, const data_type rhs) {
  return lhs < rhs;
}

size_t random(const size_type begin, const size_type end) {
  std::mt19937 mt(time(0));
  auto rand = std::bind(std::uniform_int_distribution<size_t>(begin, end), std::mt19937(mt));
  return rand();
}

template <class IT, class comparator>
IT partition_(IT begin, IT end, comparator &comp) {
  IT pivot = end;
  IT it = begin - 1;
  for (IT jt = begin; jt != pivot; ++jt) {
    if (comp(*jt, *pivot)) {
      ++it;
      std::swap(*it, *jt);
    }
  }
  ++it;
  std::swap(*it, *pivot);
  return it;
}

template <class IT, class comparator>
IT partition1_(IT begin, IT end, comparator &comp) {
  IT pivot = begin;
  IT it = end - 1;
  for (IT jt = end - 1; jt != pivot; --jt) {
    if (comp(*pivot, *jt)) {
      std::swap(*it, *jt);
      --it;
    }
  }
  std::swap(*it, *pivot);
  return it;
}

template <class IT, class comparator>
IT randomPartition(IT begin, IT end, comparator &comp) {
  size_type pivot = random(0, std::distance(begin, end) - 1);
  if (pivot != 0) {
    std::swap(*begin, *(begin + pivot));
  }
  return partition1_(begin, end, comp);
}

template <class IT, class comparator>
data_type findStatistic(IT begin, IT end, statistic_type k, comparator &comp) {
  IT first = begin;
  size_type pivot = -1;
  while (pivot != k) {
    pivot = std::distance(randomPartition(begin, end, less), end - 1);
    std::cout << pivot << std::endl;
    if (k < pivot) {
      end = first + pivot;
    } else if (k > pivot) {
      k -= pivot + 1;
      begin = first + pivot + 1;
    }
  }
  return *(first + pivot);
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
  std::vector<data_type> v{21, -2, 0};
  quickSort(v.begin(), v.end(), less);
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
