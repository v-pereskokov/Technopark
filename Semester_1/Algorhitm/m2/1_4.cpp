#include <cstdio>
#include <vector>
#include <string>
#include <Python.h>

using Word = std::string;
using Words = std::vector<Word>;

template <class IT>
void insertionSort(IT begin, IT end) {
  for (auto it = begin + 1; it != end; ++it) {
    for (auto jt = it - 1; jt != begin - 1; --jt) {
      if (*jt > *(jt + 1)) {
        std::swap(*jt, *(jt + 1));
      }
    }
  }
}

int main() {
  std::size_t n;
  scanf("%ld", &n);
  Words words;
  for (std::size_t i = 1; i <= n; ++i) {
    char word[255];
    scanf("%s", word);
    words.push_back(word);
  }
  insertionSort(words.begin(), words.end());
  for (auto i : words) {
    printf("%s\n", i.c_str());
  }
  return 0;
}
