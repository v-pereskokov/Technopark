#include <stdio.h>

int pyramid(int n, int limit) {
  if (n == 1 || n == 0 || limit == 1)
    return 1;
  int res = 0;
  for (int i = n > limit ? limit : n; i > 0; --i) {
    res += pyramid(n - i, i);
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", pyramid(n, n));
  return 0;
}
