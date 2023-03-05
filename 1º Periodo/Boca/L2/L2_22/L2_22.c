#include <stdio.h>
#include<stdlib.h>
 
int main(void){
    int num = 0, soma = 0, divisao = 0, RestoDivisao = 0;
    long int parametro = 100000000000000;

    scanf("%i", &num);

    if(num>=0){

        if(num<10 && num>=0){
            printf("RESP:%i", num);
            goto fim;
        }

        if(num>9 && num<(100*parametro)){

            inicio:

            do{
                divisao = num/(10*parametro);
                if(divisao==0){
                    break;
                }

                RestoDivisao=num%(10*parametro);
                soma = divisao+RestoDivisao;  
                num=soma;

            }while(1);

            parametro/=10;

            if(parametro>0){
                goto inicio;
            }
        }

        

        printf("RESP:%i", soma);
    }

    fim:
    return 0;
}