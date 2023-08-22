#include <stdio.h>

int main() {
  int i, inicio, fim,  j, primo = 0;
  scanf("%d%d", &inicio, &fim);

  printf("RESP:");
  for (i = inicio + 1; i < fim; i++){
    primo = 0;
    for (j = 1;  j <= i; j++){
          if (i % j == 0){
            primo++;
      }
    }
    if (primo == 2){
      printf("%d ", i);
    }
  }
  return 0;
}