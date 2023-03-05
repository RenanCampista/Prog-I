#include <stdio.h>

int main() {
  int n, i, cont = 0;
  scanf("%d", &n);
  for (i = 2; i < n; i++){
    if (n % i == 0){
      cont += 1;
    }
  }
  if (cont == 0){
    printf("Primo");
  }else{
    printf("Nao primo");
  }
  return 0;
}