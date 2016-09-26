#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using u_int = unsigned int;

template <class IT>
IT BinarySearch(IT begin, IT end, int element) {
  IT first = begin;
  IT last = end;
  --last;
  while (first < last) {
    IT mid = first + ((last - first) / 2);
    if (element <= *mid)
      last = mid;
    else
      first = mid + 1;
  }
  return (first == end || *first != element ) ? end : first;
}

bool search(std::vector<int> *A, std::vector<int> *B) {
  auto begin_A = A->begin();
  auto end_A = A->end();
  auto index = begin_A;
  for (auto it = B->begin(); it < B->end(); ++it) {
    index = BinarySearch(index, end_A, (*it));
    if (index == end_A)
      return false;
  }
  return true;
}

int main() {
  u_int n, m;
  scanf("%d %d", &n, &m);
  if (n > 0 && m > 0 && n <= 10000 && m <= 10000 && n > m) {
    int element;
    std::vector<int> A;
    for (std::size_t i = 1; i <= n; ++i) {
      scanf("%d", &element);
      A.push_back(element);
    }
    std::vector<int> B;
    for (std::size_t i = 1; i <= m; ++i) {
      scanf("%d", &element);
      B.push_back(element);
    }
    if (search(&A, &B)) {
      for (auto i : B)
        printf("%d ", i);
      printf("\n");
    }
  }
  return 0;
}
