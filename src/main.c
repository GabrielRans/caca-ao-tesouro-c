#include <stdio.h>

int main(void) {
    int opcao;
    char tabuleiro[5][5];

    int linha, coluna;

    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            tabuleiro[linha][coluna] = '~';
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

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            printf("\nIniciando partida...\n");

            printf("\nTABULEIRO:\n");

            for (linha = 0; linha < 5; linha++) {
               for (coluna = 0; coluna < 5; coluna++) {
                  printf("%c ", tabuleiro[linha][coluna]);
               }
               printf("\n");
            }
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