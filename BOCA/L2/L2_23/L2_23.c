#include <stdio.h>
#include <string.h>

int main(){
    char texto[200];
    int i, cont = 0, controlador = 0;
    fgets(texto, 200, stdin);

        
    for(i = 0; i < strlen(texto); i++){
        if(cont == 0 && texto[i] == '.'){
            break;
        }
        if(texto[i] == '('){
            cont -= 1;
        }else if(texto[i] == ')'){
            cont += 1;
        }
        if(cont == 0){
            controlador = 0;
        }
        if(cont < 0 ){
            if(controlador != 0){
            printf("%c", texto[i]);
            }
            if(texto[i] == '('){
                controlador = 1;
            }  
        }

    }

    return 0;
}