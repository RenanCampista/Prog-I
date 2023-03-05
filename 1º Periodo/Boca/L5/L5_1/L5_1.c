#include <stdio.h>
#include <math.h>

int maior (int notas[], int total) {
    int maior = -1, i = 0;
    for (i = 0; i < total; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    } 
    return maior;
}


int menor (int nota[], int qtd){
    int i = 0, menor = 101;
    for(i = 0; i < qtd; i++){
        if(nota[i] < menor){
            menor = nota[i];
        }
    }
    return menor;
}
int acimaMedia (int notas[], int total, float media) {
   int i = 0, cont = 0;
   for (i = 0; i < total; i++) {
        if (notas[i] > media) {
            cont++;
        }
    } 
    return cont;
}

float desvioPadrao (int notas[], int total, float media) {
    int i = 0;
    float desvio = 0, somatorio = 0;

    for (i = 0; i < total; i++) {
        somatorio += pow (((float)notas[i] - media), 2);
    }
    desvio = sqrt(somatorio / (float)total);
    return desvio;
}

int reprovado (int notas[], int total) {
    int i = 0, cont = 0;
    for (i = 0; i < total; i++) {
        if (notas[i] < 70) {
            cont++;
        }
    } return cont;
}
int main () {
    int alunos = 0, i = 1, soma = 0;
    float media;

    scanf("%d ", &alunos);
    int notas[alunos];

    for (i = 0; i < alunos; i++) {
        scanf("%d ", &notas[i]);
        soma += notas[i];
    }
    media = (float)(soma) / (float)(alunos);
    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d", menor(notas, alunos), maior(notas, alunos), media, desvioPadrao(notas, alunos, media), acimaMedia(notas, alunos, media), reprovado(notas, alunos));

    return 0;
}