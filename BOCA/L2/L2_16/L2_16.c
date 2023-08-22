#include <stdio.h>

int main(){
    int lista_1, lista_2, primeira_vez, ultima_vez, aparece = 0, cont = 0, menor = 32000;
    char verf = ' ';

   do{         
        verf = '\0';
        scanf("%i", &lista_1);
        scanf("%c", &verf);
            if(lista_1 >= -32000 && lista_1 <= 32000){
            if(menor > lista_1){
                menor = lista_1;
            }
        }
	}while(verf == ' ');
    
    while(scanf("%d", &lista_2)){
        if(lista_2 >= -32000 && lista_2 <= 32000){
            if(lista_2 == menor){
                aparece++;
                if(aparece == 1){
                    primeira_vez = cont;
                    aparece++;
                }if(aparece > 1){
                    ultima_vez = cont;
                    }
                }    
            }   
        ++cont; 
    }
    
    printf("%d ", menor);
    if(aparece == 0){
        printf("%d %d", cont, cont);
    }else{
        printf("%d %d", primeira_vez, ultima_vez);
    }
    return 0;
}