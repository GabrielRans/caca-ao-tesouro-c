#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int opcao;
    int linha, coluna;
    int pontuacao;
    int tesourosEncontrados;
    int tesouros, armadilhas;

    char mapa[5][5];
    char tabuleiro[5][5];

    srand(time(NULL));



    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            mapa[linha][coluna] = '~';
            tabuleiro[linha][coluna] = '?';
        }
    }

    while (tesouros < 3) {
        linha = rand() % 5;
        coluna = rand() % 5;

        if (mapa[linha][coluna] == '~') {
            mapa[linha][coluna] = 'T';
            tesouros++;
        }
    }

    while (armadilhas < 2) {
        linha = rand() % 5;
        coluna = rand() % 5;

        if (mapa[linha][coluna] == '~') {
            mapa[linha][coluna] = 'A';
            armadilhas++;
        }
    }

    do {
        printf("\n==========================================\n");
        printf("            CACA AO TESOURO\n");
        printf("==========================================\n");
        printf("1 - Jogar\n");
        printf("2 - Como jogar\n");
        printf("3 - Sair\n");
        printf("\nEscolha uma opcao:");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida! Digite um numero.\n");

            while (getchar() != '\n');

            opcao = 0;
        }

        switch (opcao) {
            case 1:
            printf("\nIniciando partida...\n");

            pontuacao = 0;
            tesourosEncontrados = 0;
            tesouros = 0;
            armadilhas = 0;

            for (linha = 0; linha < 5; linha++) {
                for (coluna = 0; coluna < 5; coluna++) {
                    mapa[linha][coluna] = '~';
                    tabuleiro[linha][coluna] = '?';
                }
            }

            while (tesouros < 3) {
                linha = rand() % 5;
                coluna = rand() % 5;

                if (mapa[linha][coluna] == '~') {
                    mapa[linha][coluna] = 'T';
                    tesouros++;
                }
            }

            while (armadilhas < 2) {
                linha = rand() % 5;
                coluna = rand() % 5;

                if (mapa[linha][coluna] == '~') {
                    mapa[linha][coluna] = 'A';
                    armadilhas++;
                }
            }

            printf("\nTABULEIRO:\n");

            for (linha = 0; linha < 5; linha++) {
               for (coluna = 0; coluna < 5; coluna++) {
                  printf("%c ", tabuleiro[linha][coluna]);
               }
               printf("\n");
            }

            while (tesourosEncontrados < 3) {
                printf("\nDigite a linha (1-5): ");

                if (scanf("%d", &linha) != 1) {
                    printf("\nEntrada invalida! Digite um numero.\n");

                    while (getchar() != '\n');

                    continue;
                }
                
                printf("Digite a coluna (1-5): ");

                if (scanf("%d", &coluna) != 1) {
                    printf("\nEntrada invalida! Digite um numero.\n");

                    while (getchar() != '\n');
                    
                    continue;
                }
                
                if (linha < 1 || linha > 5 || coluna < 1 || coluna > 5) {
                    printf("\nCoordenada invalida! Escolha valores entre 1 e 5.\n");
                } else {
                    linha--;
                    coluna--;
                
                    if (tabuleiro[linha][coluna] != '?') {
                        printf("\nEssa posicao ja foi explorada!\n");
                    } else {
                        tabuleiro[linha][coluna] = mapa[linha][coluna];

                        switch (mapa[linha][coluna]) {
                            case 'T':
                                pontuacao += 100;
                                tesourosEncontrados++;
                                printf("\nVoce encontrou um TESOURO! +100 pontos\n");
                                printf("Tesouros encontrados: %d/3\n", tesourosEncontrados);
                                break;

                            case 'A':
                                pontuacao -= 50;
                                printf("\nVoce encontrou uma ARMADILHA! -50 pontos\n");
                                break;

                            case '~':
                                printf("\nApenas agua. nenhum ponto ganho ou perdido.\n");
                                break;
                        }
                        printf("Pontuacao atual: %d pontos\n", pontuacao);
                    }
                }
            }
            printf("\n===========================\n");
            printf("       FIM DO JOGO!\n");
            printf("=============================\n");
            printf("Tesouros encontrados: %d/3\n", tesourosEncontrados);
            printf("Pontuacao final: %d pontos\n", pontuacao);
            break;

            case 2:
            printf("\nCOMO JOGAR\n");
            printf("Encontre os tesouros escondidos no tabuleiro.\n");
            printf("\nCuidado com as armadilhas!\n");
            break;
            
            case 3:
            printf("\nObrigado por jogar!\n");
            break;
            
            default:
            printf("\nOpcao invalida. tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}