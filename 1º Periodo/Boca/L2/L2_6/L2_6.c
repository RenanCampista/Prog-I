#include <stdio.h>

int main() {
  int s;
  double conta = 0, n, d, u, i;
  scanf("%d", &s);
  if(s == 1){
    n = d = 1;
    for (i = 1; i <= 99; i= i + 2){
      conta = conta + i/d;
      n = n + 2;
      d = d + 1;
    } 
  }
  else if(s == 2){
    n = 2;
    d = 50.0;
      for (i = 1; i <= 50; i++){
      conta = conta + n/d;
      n = n*2;
      d = d - 1;
    }

  }
  else if (s == 3){
    n = d = 1;
    u = 3;
    for (i = 1; i <= 10; i++){
      conta = conta + i/d;
      n = n + 1;
      d = d + u;
      u = u + 2;

    }
  }
   printf("%.6f", conta); 
  return 0;
}