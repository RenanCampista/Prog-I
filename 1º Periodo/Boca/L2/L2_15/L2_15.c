#include <stdio.h>

int main(){
        //temp= ' ' || temp = '\n'
    int neg = 0, pos = 0, soma_neg = 0, soma_pos = 0, n = 0;
    char verif = ' ';
    do{
        verif = 'a';
        scanf("%d", &n);
        scanf("%c", &verif);
        if(n > -100 && n < 100){
                if(n > 0){
                pos += 1;
                soma_pos += n;
            }else if(n < 0){
                neg += 1;
                soma_neg += n;
            }
        }else{
            break;
        }
        
    } while (verif == ' ' || verif == '\n');
    printf("%d %d %d %d", neg, pos, soma_neg, soma_pos);
    return 0;
}