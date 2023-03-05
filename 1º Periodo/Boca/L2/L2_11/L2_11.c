#include <stdio.h>

int main() {
  int n = 0, m = 0, a = 0, b = 0, x = 0, i = 0, res = 0;
  scanf("%d %d", &n, &m);

  if (n < m && n >= 1000 && m <= 9999) {
    for (i = n + 1; i < m; ++i) {
      a = i / 100;
      b = (i-a*100);
      x = a + b;
      res = x * x;
      if (res == i) {
        printf("%d\n", i);
      }
    }
  }
  return 0;
}