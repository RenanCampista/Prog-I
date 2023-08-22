#include <stdio.h>

typedef struct Produto {
    int codigo;
    float preco;
    int estoque;
} tProduto;

tProduto p1 = {0, 0.0, 0}, maior = {0, 0.0, 0}, menor = {0, 10000000000000.0, 0};
int quant_prodt = 0, i = 0;

tProduto LeProduto () {
    scanf("%d;%f;%d", &p1.codigo, &p1.preco, &p1.estoque);
}

int EhProduto1MaiorQ2 (tProduto p1, tProduto p2) {
    if (p2.preco > p1.preco) {
        return 1;
    } else return 0;
}

int EhProduto1MenorQ2 (tProduto p1, tProduto p2) {
    if (p2.preco < p1.preco) {
        return 1;
    } else return 0;
}

int TemProdutoEmEstoque (tProduto p) {
    if (p.estoque > 0) {
        return 1;
    } else return 0;
}

void ImprimeProduto (tProduto p) {
    if (TemProdutoEmEstoque(p1) == 0) {
        printf("FALTA:COD %d, PRE %.2f, QTD %d\n", p1.codigo, p1.preco, p1.estoque);
    }
    if (i == quant_prodt) {
        printf("MAIOR:COD %d, PRE %.2f, QTD %d\n", maior.codigo, maior.preco, maior.estoque);
        printf("MENOR:COD %d, PRE %.2f, QTD %d\n", menor.codigo, menor.preco, menor.estoque);
    }
}

int main() {
    
    //tProduto p1, maior = {0, 0.0, 0}, menor = {0, 10000000000000.0, 0};

    scanf("%d", &quant_prodt);

    for (i = 1; i <= quant_prodt; i++) {
        LeProduto();

        if (EhProduto1MaiorQ2(maior, p1) == 1) {
            maior = p1;
        }

        if (EhProduto1MenorQ2(menor, p1) == 1) {
            menor = p1;
        }
        ImprimeProduto (p1);
    }
    return 0;
}