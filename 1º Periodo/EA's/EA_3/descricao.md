# Descrição

Faça um programa que simule uma urna eletrônica rudimentar que deve ler votos dos eleitores e no final retornar o resultado da eleição e alguns dados estatísticos. Para esse exercício é **obrigatório o uso de structs**.

Nessa eleição fictícia, vamos eleger o presidente e o primeiro ministro da República Internacional da Computação. Para essa eleição temos os seguinte candidatos:

- **Presidente**
    - Edsger Dijkstra: 
        - Número: 10
        - Partido: Partido do Melhor Caminho (PMC)
    - Alan Turing:
        - Número: 42
        - Partido: Partido dos Avanço Intelectual (PAI)
    - Carol Shaw:
        - Número: 26
        - Partido: Mulheres Programadoras Unidas (MPU)

- **Primeiro Ministro**:
    - Tim Berners-Lee: 
        - Número: 36
        - Partido: World Wide Web (WWW)
    - Linus Torvalds:
        - Número: 64
        - Partido: Linux (Linux)
    - Ada Lovelace:
        - Número: 18
        - Partido: Gamers Unidos (GU)


### Regras da eleição
- Cada eleitor pode votar apenas uma vez e caso o mesmo eleitor tente votar novamente, você deve anular a eleição. 
- Se o número de eleitores votando for maior do que o registrado, a eleição também deve ser anulada.
- O eleitor pode optar por votar em branco (**número 0**). 
- Se o eleitor votar em um cadidato inexistente, o voto dele será anulado.
- Vence a eleição quem obtiver mais votos válidos, ou seja, aqueles que não são brancos nem nulos. Porém, se a quantidade de votos validos for menor dos que os brancos e nulos, a urna deve retornar que ninguém foi eleito e que será necessário outra eleição.
- Se houver empate nos votos válidos, a urna deve avisar que houve empate, e que também será necessário outra eleição.


## Padrão de entrada e saída
O padrão de entrada para urna será: primeiro você recebe a quantidade de pessoas registradas para votar, na sequência, você recebe os votos no formato `<id_eleitor> <numero_presidente> <numero_primeiro_ministro>`. Cada voto por linha. A votação se encerra quando o caracter `P` for lido de (PARE A CONTAGEM).

O padrão de saída será:
- Para uma situação normal, em que existe vencedor para os dois cargos:

    ```
    FIM DA ELEICAO
    - PRESIDENTE ELEITO: <nome_presidente> (<partido>), <total_de_votos>, <porcentagem_de_votos_validos>
    - PRIMEIRO MINISTRO ELEITO: <nome_pm> (<partido>), <total_de_votos>, <porcentagem_de_votos_validos>
    - COMPARECIMENTO: <porcentagem_de_pessoas_que_votaram>
    - NULOS E BRANCOS: <total_nulos_brancos_presidente>, <total_nulos_brancos_pministro>
    ```
- Para o caso de eleição anulada:
    ```
    ELEICAO ANULADA
    ```

- Para caso de empate em qualquer um dos cargos:
    ```
    FIM DA ELEICAO
    - PRESIDENTE ELEITO: EMPATE
    - PRIMEIRO MINISTRO ELEITO: <nome_pm> (<partido>), <total_de_votos>, <porcentagem_de_votos_validos>
    - COMPARECIMENTO: <porcentagem_de_pessoas_que_votaram>
    - NULOS E BRANCOS: <total_nulos_brancos_presidente>, <total_nulos_brancos_pministro>
    ```

- Para caso dos votos válidos não ser maioria para algum dos cargos:
    ```
    FIM DA ELEICAO
    - PRESIDENTE ELEITO: SEM DECISAO
    - PRIMEIRO MINISTRO ELEITO: <nome_pm> (<partido>), <total_de_votos>, <porcentagem_de_votos_validos>
    - COMPARECIMENTO: <porcentagem_de_pessoas_que_votaram>
    - NULOS E BRANCOS: <total_nulos_brancos_presidente>, <total_nulos_brancos_pministro>
    ```

Saídas que são `string` devem ser maiúsculas e saídas `float` devem ter precisão de 2 casas decimais.


## Limite das datas
- `<quantidade_eleitores>`: inteiro
- `<id_eleitor>`: inteiro
- `<numero_presidente/primeiro_ministro>`: inteiro


## Exemplos
**Entrada:**
```
5
1 10 18
8 10 18
3 10 18 
P
```
**Saída:**
```
FIM DA ELEICAO
- PRESIDENTE ELEITO: EDSGER DIJKSTRA (PARTIDO DO MELHOR CAMINHO (PMC)), 3, 100.00% 
- PRIMEIRO MINISTRO ELEITO: ADA LOVELACE (MULHERES PROGRAMADORAS UNIDAS (MPU)), 3, 100.00%
- COMPARECIMENTO: 60.00%
- NULOS E BRANCOS: 0, 0
```
___
**Entrada:**
```
2
1 10 18
8 10 18
3 10 18 
P
```
**Saída:**
```
ELEICAO ANULADA
```

___
**Entrada:**
```
20
1 0 0
8 0 18
3 10 18 
P
```
**Saída:**
```
FIM DA ELEICAO
- PRESIDENTE ELEITO: SEM DECISAO 
- PRIMEIRO MINISTRO ELEITO: ADA LOVELACE (MULHERES PROGRAMADORAS UNIDAS (MPU)), 3, 66.67%
- COMPARECIMENTO: 15.00%
- NULOS E BRANCOS: 2, 1
```
___
**Entrada:**
```
5
1 0 0
8 0 18
1 10 18 
7 0 0 
17 0 0
P
```
**Saída:**
```
ELEICAO ANULADA
```
___


**ATENÇÃO:** o exercício é corrigido de maneira automática. Se você não seguir o padrão de entrada e saída, a nota retornada será ZERO.


