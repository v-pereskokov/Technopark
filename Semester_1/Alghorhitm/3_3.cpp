#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using u_int = unsigned int;

int BinarySearch(std::vector<int> *vector, int element) {
  int first = 0;
  int count = vector->size();
  int last = count;
  while(first < last) {
    int mid = first + ((last - first) >> 1);
    if(element <= (*vector)[mid])
      last = mid;
    else
      first = mid + 1;
  }
  return (first == count || (*vector)[first] != element ) ? -1 : first;
}

bool search(std::vector<int> *A, std::vector<int> *B) {
  int index = 0;
  for (std::size_t i = 0; i < B->size(); ++i) {
    bool flag = true;
    if (BinarySearch(A, (*B)[i]) == -1)
      flag = false;
    if (!flag)
      return flag;
  }
  return true;
}

int main() {
  u_int n, m;
  scanf("%d %d", &n, &m);
  if (n > 0 && m > 0 && n <= 10000 && m <= 10000 && n > m) {
    int element;
    std::vector<int> A;
    for (std::size_t i = 1; i <= n && scanf("%d", &element); ++i) {
      A.push_back(element);
    }
    std::vector<int> B;
    for (std::size_t i = 1; i <= m && scanf("%d", &element); ++i) {
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
