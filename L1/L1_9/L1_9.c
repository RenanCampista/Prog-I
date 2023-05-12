#include <stdio.h>

int main(){
    char letra;
    scanf("%c", &letra);
    if(letra >= 97 && letra <= 122){
        printf("%c(%d)", letra - 32, letra - 32);
    }else if(letra >= 65 && letra <= 90){
        printf("A letra deve ser minuscula!");
    }else{
        printf("Nao e letra!");
    }
    return 0;
}