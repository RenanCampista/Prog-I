# Descrição

Considere que você esteja implementando um programa para receber e validar a senha de um usuário. Seu programa deve receber como entrada duas strings (`S1` e `S2`), que representam as senhas do usuário, e uma chave de criptografia. Para uma senha ser válida ela deve respeitar as seguintes regras:

A) Ter no mínimo `8` caracteres e no máximo `20`

B) Conter pelo menos um caracter maiúsculo (`[A-Z]`)

C) Conter pelo menos um caracter minúsculo (`[a-z]`)

D) Conter pelo menos um número (`[0-9]`)

E) Conter pelo menos um caracter especial (`[!@#$%&]`)

F) E `S1` tem que ser igual a `S2`

Se todos os itens forem cumpridos, você deve preparar essa senha para ser salva. Porém, nunca se deve salvar uma senha de usuário da maneira que ele digita. É necessário uma criptografia. Obviamente, não estamos em uma disciplina de criptografia, mas podemos implementar um bem simples (na prática ela não é aplicável, mas já é um começo para entender os conceitos básicos) chamada **Criptografia XOR.** 

___
- **Dica para vida**: se você tentar recuperar a senha de algum serviço e ele te enviar um email com a sua senha, troque-a imediatamente que ela não é mais segura
___

## Criptografia XOR

Como nome sugere, ela é baseado na operação XOR (OU exclusivo). Antes de prosseguir, vamos entender a operação XOR. A tabela verdade dessa operação é definida da seguinte forma: 


| A | B | Resultado |
|---|---|-----------|
| 0 | 0 | 0         |
| 0 | 1 | 1         |
| 1 | 0 | 1         |
| 1 | 1 | 0         |

Basicamente, o resultado de `A` **XOR** `B` só é verdadeiro quando os bits possuem valores diferentes!

Bom, agora que sabemos mais sobre o XOR, vamos entender como fazer uma criptografia simples usando esse operador. Primeiramente, uma criptografia terá uma string alvo e uma chave. Se você não entende a nomenclatura, considere que um algoritmo de criptografia deve modificar o valor original de uma string para um valor diferente (criptografado). Porém, ele deve ser capaz de recuperar esse valor. Por isso temos a chave! Dado o valor alterado juntamente com a chave, conseguimos recuperar o valor original (essa é a ideia básica, na pratica isso é muito mais complexo). 

Como uma string nada mais é do que um conjunto de caracteres, vamos começar do mais simples e criptografar um caracterer. Considere um caractere `cc` e um número inteiro `chave` que representará nossa chave de criptografia. Como sabemos, um caracter é mapeado para um valor inteiro que por sua vez é mapeado para um binário. Esses valores são regidos pela **tabela ASCII**. Então vamos supor que `cc='A'` e `chave = 98`. De acordo com a tabela ASCII, `cc` tem valor inteiro igual a `48`, o que em binário é `01000001`. Por sua vez, convertendo `chave` para binário, temos `01100010`. 

Se aplicarmos a operação `cc` **XOR** `chave` teremos:

```
cc =     01000001 
chave =  01100010 
------------------
resp =   00100011
```
Se convertermos `resp` para inteiro, temos `35`, que segundo a tabela ASCII é o caracter `#`, que aqui representa nosso caracter criptografado. Usando nossa chave de criptografia, temos que recuperar o valor original de `cc`. Uma característica interessante da operação XOR é que se aplicarmos `resp` **XOR** `chave` vamos obter o valor original de `cc`:

```
resp =    00100011
chave =   01100010 
-------------------------
cc =      01000001
```

Nesse ponto, você já deve ter entendido que temos um algoritmo básico de criptografia apenas utilizado o XOR. Para criptografar uma string, basta fazer isso para todos os caracteres da mesma considerando a chave informada.

- **Dica:** Em C, o operador `^` aplica XOR binário em variáveis. Para o exemplo acima, seria:
    ```
    char cc = 'A', resp;
    int chave = 98;        
    resp = cc ^ chave;
    ```
    Em outras palavras, ele "converte" a variável para binário para você!

## Padrão de entradas

Você vai receber duas strings representando a senha e um valor inteiro representando a chave da seguinte forma:

`S1, S2, chave`

## Padrão de saída

Primeiro você deve avaliar cada um dos itens necessários para a senha ser válida. Se algum deles apresentar algum problema, você deve retornar `ITEM <A-F> INVALIDO.`  Sendo <A-F> o **PRIMEIRO item da sequência que não foi cumprido.** Se todos os itens forem cumpridos, você deve imprimir a senha criptografada. 

## Limite de entradas

As strings `S1` e `S2` terão tamanhos de no máximo `20` caracteres e chave será um inteiro (`int`). Em todos os testes privados, serão considerados apenas entradas e chaves que gerem caracteres **legíveis** da tabela ASCII.

## Exemplos

- Entrada: `andre123, andre123, 20`
- Saída: `ITEM B INVALIDO` 
___
- Entrada: `Andr3!, andre123, 20`
- Saída: `ITEN A INVALIDO`
___
- Entrada: `Andre123!, Andre123!, 20`
- Saída: `Uzpfq%&'5`
___
- Entrada: `Andre123!, Andre123!, 8`
- Saída: `Iflzm9:;)`
___


**ATENÇÃO:** o exercício é corrigido de maneira automática. Se você não seguir o padrão de entrada e saída, a nota retornada será ZERO.

