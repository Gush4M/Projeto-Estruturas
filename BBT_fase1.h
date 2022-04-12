#include<stdio.h>
#include<stdlib.h>

typedef struct sComandos {
    int num;
    int vezes;
}Comandos;

typedef struct sNo {
    Comandos info;
    struct sNo *prox;
}No;

typedef struct sFila{
    No *inicio;
    No *fim;
}Fila;

void inic(Fila *ptr) {
    ptr->inicio = NULL;
    ptr->fim = NULL;
}

int vazia(Fila *ptr) {
    if(ptr->inicio == NULL) {
        return 1;
    }
    return 0;
}

No* alocarNo() {
    return (No*)malloc(sizeof(No));
}
void desalocarNo(No *q) {
    free(q);
}

void enfileirarComandos(Fila *ptr, Comandos c) {//enfilera comandos na fila.
    No *novo;
    novo = alocarNo();
    if(novo != NULL) {
        novo->info = c;
        novo->prox = NULL;
        if(vazia(ptr)) {
            ptr->inicio = novo;
        }else {
            (ptr->fim)->prox = novo;
        }
        ptr->fim = novo;
    }else {
        printf("Problema de alocacao.\n");
    }
}

Comandos desinfileirarComandos(Fila *ptr) {
    No *aux;
    Comandos c;
    if(!vazia(ptr)) {
        if(ptr->inicio == ptr->fim) {
            aux = ptr->inicio;
            ptr->inicio = NULL;
            ptr->fim = NULL;
        }else {
            aux = ptr->inicio;
            ptr->inicio = aux->prox;
        }
        c = aux->info;
        desalocarNo(aux);
        return c;
    }
}

void tb(char tabuleiro1[][8]) {
    for(int i=0;i<8;i++) {//varia as linhas.
        for(int j=0;j<8;j++) {//varia as colunas.
            if(i==0 && j==0){
                tabuleiro1[i][j] = 'P';
            }else if(i==1 && j==2) {
                tabuleiro1[i][j] = 'x';
            }else if(i==1 && j==3) {
                tabuleiro1[i][j] = 'x';
            }else if(i==1 && j==4) {
                tabuleiro1[i][j] = 'x';
            }else if(i==3 && j==5) {
                tabuleiro1[i][j] = 'x';
            }else if(i==3 && j==6) {
                tabuleiro1[i][j] = 'x';
            }else if(i==4 && j==1) {
                tabuleiro1[i][j] = 'x';
            }else if(i==4 && j==2) {
                tabuleiro1[i][j] = 'x';
            }else if(i==5 && j==4) {
                tabuleiro1[i][j] = 'x';
            }else if(i==6 && j==4) {
                tabuleiro1[i][j] = 'x';
            }else if(i==5 && j==7) {
                tabuleiro1[i][j] = 'x';
            }else if(i==6 && j==7) {
                tabuleiro1[i][j] = 'x';//
            }else if(i==6 && j==0) {
                tabuleiro1[i][j] = 'x';
            }else if(i==7 && j==0) {
                tabuleiro1[i][j] = 'x';
            }else if(i==7 && j==7) {
                tabuleiro1[i][j] = 'O';
            }else {
                tabuleiro1[i][j] = ' ';
            }
        }
    }
}

int linha(char tabuleiro[][8]) {//retorna a posicao da linha onde o 'P'(player) se encontra.
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(tabuleiro[i][j] == 'P') {
                return i;
            }
        }
    }

}

int coluna(char tabuleiro[][8]) {//retorna a posicao da coluna onde o 'P'(player) se encontra.
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(tabuleiro[i][j] == 'P') {
                return j;
            }
        }
    }

}

void exibirTabuleiro(char tabuleiro[][8], char direcao) {//exibe o tabuleiro junto com a direção.
    printf("\n");
    for(int i=0;i<8;i++) {
        printf("|---|---|---|---|---|---|---|---|\n");
        for(int j=0;j<8;j++) {
            printf("| %c ", tabuleiro[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("|---|---|---|---|---|---|---|---|\n");

    printf("\n|P %c|\n", direcao);

}

int fase1(Fila *ptr, char tabuleiro[][8], char direcao) {//executa os comandos para o funcionamento da fase 1.
    int resultado;//resultado da tentativa do usuario;

    int aux;//numero de ordens repetidas dentro de um comando.(usado para auxiliar)
    int aux1;//numero de vezes que um comando será realizado.(usado para auxiliar)

    int col;//coluna onde o 'P' se localiza.
    int lin;//linha em que o 'P' se localiza.

    Comandos c;//ira receber o comando retirado da estrutura de dados.

    while(!vazia(ptr)) {//ensquanto a lista de comandos nao estiver vazia o programam irá continuar executando e retirando os comandos.

        exibirTabuleiro(tabuleiro, direcao);

        switch((*ptr->inicio).info.num) {//no caso de o numero do comando selecionado estiver correto irá realizar as modificações no tabuleiro.

        case 1:
            aux = 0;
            aux1 = 0;
            while(aux1 != (*ptr->inicio).info.vezes) {//repetir o comando a quantidade de vezes presente no comando que esta no inicio da fila.
                if(direcao == '>') {
                    direcao = '^';
                    while(aux != 2) {
                        //necessario receber a posicao do 'P' todo momento em que ele se desloca.
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
                }else if(direcao == 'v') {
                    direcao = '>';
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
                }else if(direcao == '<') {
                    direcao = 'v';
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
                }else if(direcao == '^') {
                    direcao = '<';
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
                }
                aux1 += 1;
                aux = 0;
            }
            break;

        case 2:
            aux1 = 0;
            while(aux1 != (*ptr->inicio).info.vezes) {
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

                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin + 1][col] != 'x') {
                        if(lin + 1 != 8) {
                            tabuleiro[lin + 1][col] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
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

                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin][col - 1] != 'x') {
                        if(col - 1 != -1) {
                            tabuleiro[lin][col - 1] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
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

                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin - 1][col] != 'x') {
                        if(lin - 1 != -1) {
                            tabuleiro[lin - 1][col] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
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

                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin][col + 1] != 'x') {
                        if(col + 1 != 8) {
                            tabuleiro[lin][col + 1] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                }
                aux1 += 1;
            }
            break;

        case 3:
            aux1 = 0;
            aux = 0;
            while(aux1 != (*ptr->inicio).info.vezes) {
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

        case 4:
            aux1 = 0;
            while(aux1 != (*ptr->inicio).info.vezes) {
                if(direcao == '>') {
                    direcao = 'v';
                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin + 1][col] != 'x') {
                        if(lin + 1 != 8) {
                            tabuleiro[lin + 1][col] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                }else if(direcao == 'v') {
                    direcao = '<';
                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin][col - 1] != 'x') {
                        if(col - 1 != -1) {
                            tabuleiro[lin][col - 1] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                }else if(direcao == '<') {
                    direcao = '^';
                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin - 1][col] != 'x') {
                        if(lin - 1 != -1) {
                            tabuleiro[lin - 1][col] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                }else if(direcao == '^') {
                    direcao = '>';
                    col = coluna(tabuleiro);
                    lin = linha(tabuleiro);
                    if(tabuleiro[lin][col + 1] != 'x') {
                        if(col + 1 != 8) {
                            tabuleiro[lin][col + 1] = 'P';
                            tabuleiro[lin][col] = ' ';
                        }
                    }
                }
                aux1 += 1;
            }

            break;

        }
        c = desinfileirarComandos(ptr);//desinfileirar um comando ao final de cada case.
        printf("\n->Comando: %d\n->Numero de vezes que sera executado: %d\n", c.num, c.vezes);//exibir o comando retirado da estrutura de dados apos o seu movimento.
        exibirTabuleiro(tabuleiro, direcao);
    }

    //recebem a posicao de onde se encontra o 'P'(player) e verifica se ele está na posicão 7x7 que constitui uma vitoria da fase.
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


