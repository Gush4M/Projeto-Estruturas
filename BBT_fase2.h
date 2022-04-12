#include<stdio.h>
#include<stdlib.h>

void inicP(No **topo) {
    *topo = NULL;
}

int vaziaP(No *topo) {
    if(topo == NULL) {
        return 1;
    }else {
        return 0;
    }
}

void empilharComandos(No **topo, Comandos c) {
    No *novo;
    novo = alocarNo();

    if(novo != NULL) {
        novo->info = c;
        novo->prox = *topo;
        *topo = novo;
    }
}

Comandos desempilharComandos(No **topo) {
    No *q;
    if(!vaziaP(*topo)) {
        Comandos c;
        q = *topo;
        *topo = q->prox;
        c = q->info;
        desalocarNo(q);
        return c;//retorna o comando que foi desalocado da pilha.
    }
}

//Essa função trasfere os comandos da primeira pilha para a segunda na ordem inversa(a correta para execução dos comandos).
/*void trasferirPilha(No **topo, No **topo2) {
    Comandos c;
    if(!vaziaP(*topo)) {
        while(*topo != NULL) {
            c = desempilharComandos(topo);
            empilharComandos(topo2, c);
        }
    }
}*/

void tb2(char tabuleiro1[][8]) {
    for(int i=0;i<8;i++) {//varia as linhas.
        for(int j=0;j<8;j++) {//varia as colunas.
            if(i==0 && j==0){
                tabuleiro1[i][j] = 'P';
            }else if(i==0 && j==2) {
                tabuleiro1[i][j] = 'x';
            }else if(i==1 && j==2) {
                tabuleiro1[i][j] = 'x';
            }else if(i==2 && j==2) {
                tabuleiro1[i][j] = 'x';
            }else if(i==1 && j==4) {
                tabuleiro1[i][j] = 'x';
            }else if(i==2 && j==4) {
                tabuleiro1[i][j] = 'x';
            }else if(i==2 && j==0) {
                tabuleiro1[i][j] = 'x';
            }else if(i==3 && j==0) {
                tabuleiro1[i][j] = 'x';
            }else if(i==4 && j==4) {
                tabuleiro1[i][j] = 'x';
            }else if(i==4 && j==5) {
                tabuleiro1[i][j] = 'x';
            }else if(i==4 && j==6) {
                tabuleiro1[i][j] = 'x';
            }else if(i==5 && j==3) {
                tabuleiro1[i][j] = 'x';
            }else if(i==6 && j==3) {
                tabuleiro1[i][j] = 'x';
            }else if(i==6 && j==1) {
                tabuleiro1[i][j] = 'x';
            }else if(i==7 && j==1) {
                tabuleiro1[i][j] = 'x';
            }else if(i==7 && j==7) {
                tabuleiro1[i][j] = 'O';
            }else {
                tabuleiro1[i][j] = ' ';
            }
        }
    }
}

int fase2(No **topo, char tabuleiro[][8], char direcao) {
    int resultado;//resultado da tentativa do usuario;

    int aux;//numero de ordens repetidas dentro de um comando.(usado para auxiliar)
    int aux1;//numero de vezes que um comando será realizado.(usado para auxiliar)

    int col;//coluna onde o 'P' se localiza.
    int lin;//linha em que o 'P' se localiza.

    Comandos c;//ira receber o comando retirado da estrutura de dados.

    while(!vaziaP(*topo)) {
        exibirTabuleiro(tabuleiro, direcao);

        switch((*topo)->info.num) {
        case 1:
            aux1 = 0;
            while(aux1 != (*topo)->info.vezes) {
                if(direcao == '>') {
                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin][col + 1] != 'x') {
                        if(col + 1 != 8) {
                            tabuleiro[lin][col + 1] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                    direcao = '^';

                }else if(direcao == 'v') {
                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin + 1][col] != 'x') {
                        if(lin + 1 != 8) {
                            tabuleiro[lin + 1][col] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                    direcao = '>';

                }else if(direcao == '<') {
                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin][col - 1] != 'x') {
                        if(col - 1 != -1) {
                            tabuleiro[lin][col - 1] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                    direcao = 'v';

                }else if(direcao == '^') {
                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin - 1][col] != 'x') {
                        if(lin - 1 != -1) {
                            tabuleiro[lin - 1][col] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                    direcao = '<';
                }
                aux1 += 1;
            }
            break;

        case 2:
            aux1 = 0;
            aux = 0;
            while(aux1 != (*topo)->info.vezes) {
                if(direcao == '>') {
                    while(aux != 2) {
                        col = coluna(tabuleiro);
                        lin = linha(tabuleiro);
                        if(tabuleiro[lin][col + 1] != 'x') {
                            if(col + 1 != 8) {
                                tabuleiro[lin][col + 1] = 'P';
                                tabuleiro[lin][col] = ' ';
                            }
                        }
                        aux += 1;
                    }

                }else if(direcao == 'v') {
                    while(aux != 2) {
                        col = coluna(tabuleiro);
                        lin = linha(tabuleiro);
                        if(tabuleiro[lin + 1][col] != 'x') {
                            if(lin + 1 != 8) {
                                tabuleiro[lin + 1][col] = 'P';
                                tabuleiro[lin][col] = ' ';
                            }
                        }
                        aux += 1;
                    }

                }else if(direcao == '<') {
                    while(aux != 2) {
                        col = coluna(tabuleiro);
                        lin = linha(tabuleiro);
                        if(tabuleiro[lin][col - 1] != 'x') {
                            if(col - 1 != -1) {
                                tabuleiro[lin][col - 1] = 'P';
                                tabuleiro[lin][col] = ' ';
                            }
                        }
                        aux += 1;
                    }

                }else if(direcao == '^') {
                    while(aux != 2) {
                        col = coluna(tabuleiro);
                        lin = linha(tabuleiro);
                        if(tabuleiro[lin - 1][col] != 'x') {
                            if(lin - 1 != -1) {
                                tabuleiro[lin - 1][col] = 'P';
                                tabuleiro[lin][col] = ' ';
                            }
                        }
                        aux += 1;
                    }
                }
                aux1 += 1;
                aux = 0;
            }
            break;

        case 3:
            aux1 = 0;
            aux = 0;
            while(aux1 != (*topo)->info.vezes) {
                if(direcao == '>') {
                    while(aux != 3) {
                        col = coluna(tabuleiro);
                        lin = linha(tabuleiro);
                        if(tabuleiro[lin][col + 1] != 'x') {
                            if(col + 1 != 8) {
                                tabuleiro[lin][col + 1] = 'P';
                                tabuleiro[lin][col] = ' ';
                            }
                        }
                        aux += 1;
                    }

                }else if(direcao == 'v') {
                    while(aux != 3) {
                        col = coluna(tabuleiro);
                        lin = linha(tabuleiro);
                        if(tabuleiro[lin + 1][col] != 'x') {
                            if(lin + 1 != 8) {
                                tabuleiro[lin + 1][col] = 'P';
                                tabuleiro[lin][col] = ' ';
                            }
                        }
                        aux += 1;
                    }

                }else if(direcao == '<') {
                    while(aux != 3) {
                        col = coluna(tabuleiro);
                        lin = linha(tabuleiro);
                        if(tabuleiro[lin][col - 1] != 'x') {
                            if(col - 1 != -1) {
                                tabuleiro[lin][col - 1] = 'P';
                                tabuleiro[lin][col] = ' ';
                            }
                        }
                        aux += 1;
                    }

                }else if(direcao == '^') {
                    while(aux != 3) {
                        col = coluna(tabuleiro);
                        lin = linha(tabuleiro);
                        if(tabuleiro[lin - 1][col] != 'x') {
                            if(lin - 1 != -1) {
                                tabuleiro[lin - 1][col] = 'P';
                                tabuleiro[lin][col] = ' ';
                            }
                        }
                        aux += 1;
                    }
                }
                aux1 += 1;
                aux = 0;
            }
            break;

        case 4:
            aux1 = 0;
            while(aux1 != (*topo)->info.vezes) {
                if(direcao == '>') {
                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin][col + 1] != 'x') {
                        if(col + 1 != 8) {
                            tabuleiro[lin][col + 1] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                    direcao = 'v';

                }else if(direcao == 'v') {
                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin + 1][col] != 'x') {
                        if(lin + 1 != 8) {
                            tabuleiro[lin + 1][col] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                    direcao = '<';

                }else if(direcao == '<') {
                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin][col - 1] != 'x') {
                        if(col - 1 != -1) {
                            tabuleiro[lin][col - 1] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                    direcao = '^';

                }else if(direcao == '^') {
                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin - 1][col] != 'x') {
                        if(lin - 1 != -1) {
                            tabuleiro[lin - 1][col] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                    direcao = '>';
                }
                aux1 += 1;
            }
            break;
        }
        c = desempilharComandos(topo);
        printf("\n->Comando: %d\n->Numero de vezes que sera executado: %d\n", c.num, c.vezes);//exibir o comando retirado da estrutura de dados apos o seu movimento.
        exibirTabuleiro(tabuleiro, direcao);
    }

    col = coluna(tabuleiro);
    lin = linha(tabuleiro);
    if(col == 7 && lin == 7) {
        resultado = 1;
        return resultado;
    }else {
        resultado = 0;
        return resultado;
    }
}


