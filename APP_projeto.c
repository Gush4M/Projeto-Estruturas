#include"BBT_fase1.h"
#include"BBT_fase2.h"
#include"BBT_fase3.h"

int main() {
    char tabuleiro[8][8];
    char direcao = '>';
    int resultado1, resultado2, resultado3;//resultado das tentativas de cada fase.
    int contagem_erro = 0;

    Comandos c;//Comandos salvos em estrutura do tipo comandos.

    Fila *fila;//criando estrutura de dados para os comandos do tipo fila dinamica.
    fila = (Fila*)malloc(sizeof(Fila));
    inic(fila);

    No *pilha;
    //No *pilha2;//essa segunda pilha ira receber a sequencia de comandos na ordem certa.
    inicP(&pilha);//iniciando estrutura do tipo pilha.
    //inicP(&pilha2);


    //fase 1.
    /*primeiramente nesse loop irá ser impresso o primeiro tabuleiro, em seguida será perguntado para que o usuasio informe os dados necessarios
    (se o numero do comando for 0 encerra o loop de pergunta), será verificado se ele venceu a primeira faze, se sim é exibido uma mensagem de parabens e
    deve prosseguir para a proxima fase, se nao a contagem de erros sobe mais um e o tabuleiro é reiniciado na posição inicial.*/
    do{
        tb(tabuleiro);//preenchendo tabuleiro , padrão.
        printf("Fase 1\n");
        exibirTabuleiro(tabuleiro, direcao);//exibe o tabuleiro, com a direção.

        printf("\nComandos:\n");
        printf("1 - E F F\n");
        printf("2 - F D F\n");
        printf("3 - F F\n");
        printf("4 - D F\n");

        do{
            printf("Informe o numero do comando e a quantidade de vezes a ser repetido, EX: 1 2\n");//recebe os comandos e os coloca na fila.
            scanf("%d %d", &c.num, &c.vezes);
            if(c.num != 0) {
                enfileirarComandos(fila, c);
            }
        }while(c.num != 0);
        resultado1 = fase1(fila, tabuleiro, direcao);

        if(resultado1 != 1) {
            contagem_erro += 1;
            if(contagem_erro == 3) {
                printf("Que pena, suas tentativas se esgotaram.\n");
            }else {
                printf("\nQue pena, tente mais uma vez.\n");
            }

        }else {
            printf("\n*** Parabens! ***\nSeguindo para a fase 2.\n\n");
        }

    }while(resultado1 != 1 && contagem_erro != 3);

    //em cada faze ele tem direito a 3 erros.
    //é necessario resetar ele ao final de cada fase.
    contagem_erro = 0;

    //fase 2.
    /**/
    if(resultado1 == 1) {
       do {
            tb2(tabuleiro);
            printf("Fase 2\n");
            exibirTabuleiro(tabuleiro, direcao);

            printf("\nComandos:\n");
            printf("1 - F E\n");
            printf("2 - F F\n");
            printf("3 - F F F\n");
            printf("4 - F D\n");

            do{
                printf("Informe o numero do comando e a quantidade de vezes a ser repetido, EX: 1 2\n");//recebe os comandos e os coloca na fila.
                scanf("%d %d", &c.num, &c.vezes);
                if(c.num != 0) {
                    empilharComandos(&pilha, c);
                }
            }while(c.num != 0);
            //trasferirPilha(&pilha, &pilha2);
            resultado2 = fase2(&pilha, tabuleiro, direcao);

            if(resultado2 != 1) {
                contagem_erro += 1;
                if(contagem_erro == 3) {
                    printf("Que pena, suas tentativas se esgotaram.\n");
                }else {
                    printf("\nQue pena, tente mais uma vez.\n");
                }

            }else {
                printf("\n*** Parabens! ***\nSeguindo para a fase 3.\n\n");
            }

       }while(resultado2 != 1 && contagem_erro != 3);
    }

    contagem_erro = 0;

    //fase 3.
    /**/
    if(resultado2 == 1) {
        do {
            tb3(tabuleiro);
            printf("Fase 3\n");
            exibirTabuleiro(tabuleiro, direcao);

            printf("\nComandos:\n");
            printf("1 - D F F\n");
            printf("2 - E F\n");
            printf("3 - F D F\n");
            printf("4 - F F F\n");

            do{
                printf("Informe o numero do comando e a quantidade de vezes a ser repetido, EX: 1 2\n");//recebe os comandos e os coloca na fila.
                scanf("%d %d", &c.num, &c.vezes);
                if(c.num != 0) {
                    enfileirarComandos(fila, c);
                }
            }while(c.num != 0);
            resultado3 = fase3Pt1(fila, tabuleiro, direcao);

            if(resultado3 != 1) {
                contagem_erro += 1;
                if(contagem_erro == 3) {
                    printf("Que pena, suas tentativas se esgotaram.\n");
                }else {
                    printf("\nQue pena, tente mais uma vez.\n");
                }
            }else {//caso o resultado da primeira parte da fase 3 seja um ele avança para a parte da volta do player 'P'.
                printf("\nAgora retorne o player (P) para a posicao inicial.\n");
            }
        }while(resultado3 != 1 && contagem_erro != 3);
    }

    if(resultado3 == 1) {
        do{
            exibirTabuleiro(tabuleiro, '<');//vai exibir o tabuleiro ja com o player na posicao antiga do objetivo (O) e com direcao modificada para a partida.

            printf("\nComandos:\n");
            printf("1 - D F F\n");
            printf("2 - E F\n");
            printf("3 - F D F\n");
            printf("4 - F F F\n");

            do{
                printf("Informe o numero do comando e a quantidade de vezes a ser repetido, EX: 1 2\n");//recebe os comandos e os coloca na fila.
                scanf("%d %d", &c.num, &c.vezes);
                if(c.num != 0) {
                    empilharComandos(&pilha, c);
                }
            }while(c.num != 0);
            //trasferirPilha(&pilha, &pilha2);
            resultado3 = fase3Pt2(&pilha, tabuleiro, '<');

            if(resultado3 != 1) {
                contagem_erro += 1;
                if(contagem_erro == 3) {
                    printf("Que pena, suas tentativas se esgotaram.\n");
                }else {
                    printf("\nQue pena, tente mais uma vez.\n");
                }
            }else {
                printf("\n*** Parabens, voce e o MELHOR!! ***\n\n");
            }
        }while(resultado3 != 1 && contagem_erro != 3);
    }


    return 0;
}
