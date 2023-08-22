#include <stdio.h>

int verifica_letra(char c) {
    // Retorna verdadeiro se for uma letra
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int main() {
    int i = 0, j = 0, k;
    char c, texto[501][501];

    /*
        -Eu acho mais pratico fazer a leitura na funcao main ao inves de uma função para issso
        -Dessa forma eu consigo aproveitar a variavel i (saber qual é a ultima linha)
        -Mas da para ler com uma funcao
    */

    while (scanf("%c", &c) == 1) {
        if (verifica_letra(c)) {
            texto[i][j] = c;
            j++;
            /*
                -Aqui eu posso fazer texto[i][j] = c, pois estou passando caracter por caracter
                -Se fosse passar uma string completa para outra teria que usar a funçao strcpy() da biblioteca string.h
                    - Ex:
                        strcpy(string_destino, string_com_o_conteudo);

                -Como eu to copiando caracter por caracter, eu preciso aumentar j que seria "as colunas" da matriz
                    -Dessa forma os caracters da palavra ficam na mesma linha
            */
        } else if (j > 0) {
            texto[i][j] = '\0';
            i++;
            j = 0;
            /*
                - A condicao j > 0 garante que apenas palavras com pelo menos um caractere sejam consideradas
                - Dessa forma, evita-se adicionar palavras vazias quando há múltiplos espaços consecutivos ou pontuações.
                    -Por exemplo, senao fizesse isso, eu teria problemas com palavras compostas
                - O caracter '\0' indica final de string. Isso faz com que eu tenha varias strings ao inves de uma só, permitindo inverter a ordem das palavras mas nao a ordem das letras
                - Alem disso, sem o final de string, o programa poderia nao entender onde cada palavra termina e assim imprimir respostas erradas
                - i++ para ir para a proxima palavra ja que a anterior foi totalmente lida
                - j = 0 pois a linha seguinte (ja que fiz i++) está vazia então assim eu vou para o inicio dela
            */
        }
    }

    // Imprimir o texto de trás para frente
    for (k = i; k >= 0; k--) {
        /*
            - k inicia na ultima linha
                - Por isso preferi ler a sem fazer uma funçao, fica mais pratico para aproveitar a variavel
                - É claro, vc pode fazer uma funcao para imprimir e passar o valor de "i" para a funçao
            - k vai decrementando para inverter a ordem
        */

        j = 0; //Isso faz com que sempre comece pelo inicio da linha
        while (texto[k][j] != '\0') {
            printf("%c", texto[k][j]);
            j++;
            /*
                -Observe que k sempre mantem o valor, para printar uma linha por vez
                -Imagine que em uma palavra, cada letra está na mesma linha "k" e mas em uma coluna "j" diferente
            */
        }
        printf(" "); // Espaço entre as palavras
        //Note que na matriz só a letras e o caracter final de string, por isso tenho que imprimir o espaço    
    }

    return 0;
}
