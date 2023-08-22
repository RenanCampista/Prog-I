#include <stdio.h>

float Soma(float num1, float num2) {
    return num1 + num2;
}
float Subtracao(float num1, float num2) {
    return num1 - num2;
}
float Divisao(float num1, float num2) {
    return num1 / num2;
}
float Multiplicacao(float num1, float num2) {
    return num1 * num2;
}

int main(){
    float num1 = 0, num2 = 0, control = 0, op_1 = 0;
    char oper = 'x';

    do {
        scanf("%f %f %c", &num1, &num2, &oper);
        
        switch (oper) {
        case '+':
            op_1 = Soma(num1, num2);
            break;
        case '-':
            op_1 = Subtracao(num1, num2);
            break;
        case '/':
            op_1 = Divisao(num1, num2);
            break;
        case '*':
            op_1 = Multiplicacao(num1, num2);
            break;                                           
        default:
            break;
        } 
        control++;   

    } while (control == 0);
    

    while (scanf("%f %c", &num2, &oper) == 2) {
        switch (oper) {
        case '+':
            op_1 = Soma(op_1, num2);
            break;
        case '-':
            op_1 = Subtracao(op_1, num2);
            break;
        case '/':
            op_1 = Divisao(op_1, num2);
            break;
        case '*':
            op_1 = Multiplicacao(op_1, num2);
            break;                                           
        default:
            break;
        }  
    }
    
    printf("%.2f", op_1);

return 0;
}