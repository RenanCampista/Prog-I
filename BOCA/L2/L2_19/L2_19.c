#include <stdio.h>

int main() {
    int i = 0, qtd_del = 0;

    //DADOS DE LEITURA DOS ATLETAS
    int id = 0, n1 = 0, n2 = 0, n3 = 0;
    char sexo;

    //AUX PARA ORDENAR AS NOTAS
    int nota_maior = 0, nota_meio = 0, nota_menor = 0; 
    
    //DADOS DA DELEGACAO
    int soma_mas = 0, soma_fem = 0, maior_soma_mas = 0, maior_soma_fem = 0, id_camp_mas = 0, id_camp_fem = 0;

    //MELHORES ATLETAS
    int melhor_id_mas = 0, melhor_nota_mas = 0, seg_nota_mas = 0, terc_nota_mas = 0, melhor_id_fem = 0, melhor_nota_fem = 0, seg_nota_fem = 0, terc_nota_fem = 0;

    //PIORES ATLETAS
    int pior_id_mas =0, pior_nota_mas = 11, seg_pior_mas = 11, terc_pior_mas = 11, pior_id_fem = 0, pior_nota_fem = 11,  seg_pior_fem = 11, terc_pior_fem = 11;

    scanf("%d", &qtd_del);

    for (i = 1; i <= qtd_del; i++) {
        while(1) {
            scanf("%d", &id);
            if (id == -1) {
                printf("MELHORES ATLETAS DA DELEGACAO %d\n", i);
                printf("MASCULINO: %d FEMININO: %d\n", melhor_id_mas, melhor_id_fem);
                printf("PIORES ATLETAS DA DELEGACAO %d\n", i);
                printf("MASCULINO: %d FEMININO: %d\n\n", pior_id_mas, pior_id_fem);

                //LIMPANDO VARIAVEIS
                soma_mas = 0, soma_fem = 0;
                melhor_id_mas = 0, melhor_nota_mas = 0, seg_nota_mas = 0, terc_nota_mas = 0, melhor_id_fem = 0, melhor_nota_fem = 0, seg_nota_fem = 0, terc_nota_fem = 0;
                pior_id_mas =0, pior_nota_mas = 11, seg_pior_mas = 11, terc_pior_mas = 11, pior_id_fem = 0, pior_nota_fem = 11,  seg_pior_fem = 11, terc_pior_fem = 11;
                break;
            }
            else {
                scanf("%c %d %d %d", &sexo, &n1, &n2, &n3);

                if (sexo == 'M') {
                    //ORDENAR AS NOTAS
                    if (n1 >= n2 && n1 >= n3) {
                        nota_maior = n1;
                        if (n2 >= n3) {
                            nota_meio = n2;
                            nota_menor = n3;
                        } else {
                            nota_meio = n3;
                            nota_menor = n2;           
                        }
                    } else if (n2 >= n1 && n2 >= n3) { 
                        nota_maior = n2;
                        if (n1 >= n3) {
                            nota_meio = n1;
                            nota_menor = n3;
                        } else {
                            nota_meio = n3;
                            nota_menor = n1;
                        }
                    } else {
                        nota_maior = n3;
                        if (n1 >= n2) {
                            nota_meio = n1;
                            nota_menor = n2;
                        } else {
                            nota_meio = n2;
                            nota_menor = n1;
                        }
                    }

                    //PEGANDO A MAIOR NOTA DO ATLETA PARA SOMAR
                    soma_mas += nota_maior;

                    //MELHOR ATLETA
                    if (nota_maior > melhor_nota_mas) {
                        melhor_nota_mas = nota_maior;
                        seg_nota_mas = nota_meio;
                        terc_nota_mas = nota_menor;
                        melhor_id_mas = id;
                    } else if (nota_maior == melhor_nota_mas) {
                        if (nota_meio > seg_nota_mas) {
                            melhor_nota_mas = nota_maior;
                            seg_nota_mas = nota_meio;
                            terc_nota_mas = nota_menor;
                            melhor_id_mas = id;
                        } else if (nota_meio == seg_nota_mas) {
                            if (nota_menor > terc_nota_mas) {
                                melhor_nota_mas = nota_maior;
                                seg_nota_mas = nota_meio;
                                terc_nota_mas = nota_menor;
                                melhor_id_mas = id;
                            }
                        }
                    }

                    //PIOR ATLETA
                    if (nota_maior < pior_nota_mas) {
                        pior_nota_mas = nota_maior;
                        seg_pior_mas = nota_meio;
                        terc_pior_mas = nota_menor;
                        pior_id_mas = id;
                    } else if (nota_maior == pior_nota_mas) {
                        if (nota_meio < seg_pior_mas) {
                            pior_nota_mas = nota_maior;
                            seg_pior_mas = nota_meio;
                            terc_pior_mas = nota_menor;
                            pior_id_mas = id;
                        } else if (nota_meio == seg_pior_mas) {
                            if (nota_menor <= terc_pior_mas) {
                                pior_nota_mas = nota_maior;
                                seg_pior_mas = nota_meio;
                                terc_pior_mas = nota_menor;
                                pior_id_mas = id;
                            }
                        }
                    }

                } else if (sexo == 'F') {
                    //ORDENAR AS NOTAS
                    if (n1 >= n2 && n1 >= n3) {
                        nota_maior = n1;
                        if (n2 >= n3) {
                            nota_meio = n2;
                            nota_menor = n3;
                        } else {
                            nota_meio = n3;
                            nota_menor = n2;           
                        }
                    } else if (n2 >= n1 && n2 >= n3) { 
                        nota_maior = n2;
                        if (n1 >= n3) {
                            nota_meio = n1;
                            nota_menor = n3;
                        } else {
                            nota_meio = n3;
                            nota_menor = n1;
                        }
                    } else {
                        nota_maior = n3;
                        if (n1 >= n2) {
                            nota_meio = n1;
                            nota_menor = n2;
                        } else {
                            nota_meio = n2;
                            nota_menor = n1;
                        }
                    }

                    //PEGANDO A MAIOR NOTA DO ATLETA PARA SOMAR
                    soma_fem += nota_maior;

                    //MELHOR ATLETA
                    if (nota_maior > melhor_nota_fem) {
                        melhor_nota_fem = nota_maior;
                        seg_nota_fem = nota_meio;
                        terc_nota_fem = nota_menor;
                        melhor_id_fem = id;
                    } else if (nota_maior == melhor_nota_fem) {
                        if (nota_meio > seg_nota_fem) {
                            melhor_nota_fem = nota_maior;
                            seg_nota_fem = nota_meio;
                            terc_nota_fem = nota_menor;
                            melhor_id_fem = id;
                        } else if (nota_meio == seg_nota_fem) {
                            if (nota_menor > terc_nota_fem) {
                                melhor_nota_fem = nota_maior;
                                seg_nota_fem = nota_meio;
                                terc_nota_fem = nota_menor;
                                melhor_id_fem = id;
                            }
                        }
                    }

                    //PIOR ATLETA
                    if (nota_maior < pior_nota_fem) {
                        pior_nota_fem = nota_maior;
                        seg_pior_fem = nota_meio;
                        terc_pior_fem = nota_menor;
                        pior_id_fem = id;
                    } else if (nota_maior == pior_nota_fem) {
                        if (nota_meio < seg_pior_fem) {
                            pior_nota_fem = nota_maior;
                            seg_pior_fem = nota_meio;
                            terc_pior_fem = nota_menor;
                            pior_id_fem = id;
                        } else if (nota_meio == seg_pior_fem) {
                            if (nota_menor <= terc_pior_fem) {
                                pior_nota_fem = nota_maior;
                                seg_pior_fem = nota_meio;
                                terc_pior_fem = nota_menor;
                                pior_id_fem = id;
                            }
                        }
                    }
                }

                //VERIFICANDO AS DELEGACOES CAMPEAS
                if (soma_mas > maior_soma_mas) {
                    maior_soma_mas = soma_mas;
                    id_camp_mas = i;
                }

                if (soma_fem > maior_soma_fem) {
                    maior_soma_fem = soma_fem;
                    id_camp_fem = i;
                }

                //LIMPANDO AS VARIAVEIS
                nota_maior = 0, nota_meio = 0, nota_menor = 0; 
            }
            
        }
    }
    
    printf("DELEGACAO CAMPEA:\n");
    printf("MASCULINO: %d FEMININO: %d", id_camp_mas, id_camp_fem);

    return 0;
}