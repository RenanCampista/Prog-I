# Descrição

Dado um conjunto de entradas `N` e um número alvo `x`, retorne os índices de dois números que a soma é igual a `x`. 

Para facilitar a tarefa, você pode assumir que existe **exatamente** uma ou nenhuma solução, Além disso, você não pode usar o mesmo elemento duas vezes.

## Padrão de entradas

O conjunto de elemetos será delimetado por `[]` e separados por vígula. Após a leitura dos elementos, você vai ler o número alvo `x`.

Exemplo: `[1, 2, 3, 4, 5], 9`

## Limite de entradas

- `N`: um conjunto de números inteiros com tamanho maior do que 2 e menor do que 100

- `x`: um número inteiro

## Exemplo explicado:

**Exemplo 1:**

- Entrada: `[1, 2, 3, 4, 5], 9`
- Saída: `[3, 4]`

Portanto, `N = [1, 2, 3, 4, 5]` e `x = 9`. O resultado `[3, 4]` é porque `N[3] + N[4] = x`, ou seja, `4 + 5 = 9`.

**Exemplo 2:**

- Entrada: `[1, 2, 3, 4, 5], 50`
- Saída: `[]`

A saída é vazia porque não existe solução em que a soma de dois elementos é igual a `50`

## Outros exemplos:

**Exemplo 3:**
- Entrada: `[2, 7, 11, 15], 9`
- Saída: `[0, 1]`

**Exemplo 4:**
- Entrada: `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 520, 50, 120, 147, 10005], 521`
- Saída: `[0, 11]`

___
**ATENÇÃO: o** exercício é corrigido de maneira automática. Se você não seguir o padrão de entrada e saída, a nota retornada será ZERO.
