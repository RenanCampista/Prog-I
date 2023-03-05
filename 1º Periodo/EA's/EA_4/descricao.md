# Descrição
Faça um programa que receba um conjunto de datas e retorne o dia da semana que cada uma das datas ocorreu. Por exemplo, a data `19-11-1990` (19 de Novembro de 1990) ocorreu numa Segunda-Feira.

O algoritmo para calcular o dia da semana para uma data do calendário Gregoriano é o seguinte:

- **Passo 1:** Para um dado ano, considere apenas os últimos 2 dígitos, que chamaremos de `AA`. Some `AA` a sua divisão interia por `4`, ou seja, `AA + (AA div 4)`. Na sequência, calcule o resto da divisão por `7` do resultado da soma anterior. Esse será o nosso **código do ano**.

- **Passo 2:** Precisamos de obter um **código para o mês**. Usaremos os seguinte valores: 

    - Janeiro: 0
    - Fevereiro: 3
    - Março: 3
    - Abril: 6
    - Maio: 1
    - Junho: 4
    - Julho: 6,
    - Agosto: 2
    - Setembro: 5
    - Outubro: 0
    - Novembro: 3
    - Dezembro: 5

- **Passo 3:** O século também influencia no cálculo desse algoritmo. Logo, Considerando datas do século 17 até 23, usaremos os seguintes **códigos de século**:
    - 1700s: 4
    - 1800s: 2
    - 1900s: 0
    - 2000s: 6
    - 2100s: 4
    - 2200s: 2
    - 2300s: 0

- **Passo 4:** Outra informação importante é se o ano é bissexto! Se sim e o mês é `Janeiro` ou `Fevereiro`, temos que subtrair 1 do resultado do passo 5. Anos bissextos ocorrem quando o ano é divível por `4`, exceto em anos que também são divisíveis por `100`. Porém, se o ano for divisível por `400`, ele é bissexto.

- **Passo 5:** Ok, para calcular o dia da semana, fazemos: `dia_aux = codigo do ano + codigo do mês + codigo do século + dia do mês`. 
**Se for ano bissexto, subtraia 1**. Por fim, calcule o resto da divisão por `7` de `dia_aux`. Isso retornará um valor entre `0` e `6`, que representa o dia da semana.
    - 0 = Domingo
    - 1 = Segunda
    - 2 = Terça
    - 3 = Quarta
    - 4 = Quinta
    - 5 = Sexta
    - 6 = Sabado


## Exemplo explicado: 
Considere a data `19-11-1990`:
- Passo 1: `90 + 90 div 4 = 112`. Calculando o código do ano: `122 % 7 = 0`
- Passo 2: mes de `novembro = 3`
- Passo 3: seculo `19 = 0`
- Passo 4: não é bissexto
- Passo 5: `0 + 3 + 0 + 19 = 22`, como não é bissexto, não subtrai 1. O resto da divisao de 22 por 7 é 1. Logo, o dia 19 de Novembro de 1990 foi uma `Segunda`.

## Limite das datas
Todas as datas estarão no intervalo de `1 de Janeiro de 1700 até 31 de Dezembro de 2300`.

## Padrão de entrada e saída
Seu programa deverá ler uma ou mais datas no formato `DD-AAAA-MM`. As datas serão separadas por espaço e o caracter `!` representa o final da leitura. A saída será o dia da semana separado por vírgula e espaço.

## Exemplos

___
Entrada: `19-11-1990 14-10-2020 02-01-1900 !`

Saída: `SEGUNDA, QUARTA, TERCA`
___

Entrada: `07-09-1822 !`

Saída: `SABADO`
___

Entrada: `01-01-1758  02-05-2222 !`

Saída: `DOMINGO, QUINTA`
___


**ATENÇÃO:** o exercício é corrigido de maneira automática. Se você não seguir o padrão de entrada e saída, a nota retornada será ZERO.