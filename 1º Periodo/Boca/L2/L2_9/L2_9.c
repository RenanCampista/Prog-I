#include <stdio.h>

int main() {
  int i, inicio, fim,  j, primo, verificador, k, multiplo;
  scanf("%d%d", &inicio, &fim);

  for (i = inicio + 1; i < fim; i++){
    primo = 0;
    for (j = 1;  j <= i; j++){
        if (i % j == 0){
          primo++;
      }
    }
    if (primo == 2){
      printf("%d\n", i);
      verificador = i;
      multiplo = 0;
      for (k = verificador + 1; k < fim; k++){
          if (k % verificador == 0){
            printf("%d ", k);
            multiplo++;
        }    
      }
      if(multiplo == 0){
        printf("*");
      }
      printf("\n");
    }     
  }
  return 0;
}