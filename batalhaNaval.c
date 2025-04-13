#include <stdio.h>

int main() {
    int i, j;
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Título do tabuleiro
    printf(" TABULEIRO BATALHA NAVAL \n");

    // Imprime letras das colunas
    printf("   ");
    for(i = 0; i < 10; i++) {
        printf("%c ", colunas[i]);
    }
    printf("\n");

    int tabuleiro[10][10]; // Cria a matriz 10x10

    // Preenche o tabuleiro com 0 (água)
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coloca navio na horizontal
    tabuleiro[1][1] = 3;
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;

    // Coloca navio na vertical
    tabuleiro[4][4] = 3;
    tabuleiro[5][4] = 3;
    tabuleiro[6][4] = 3;

    // Imprime o tabuleiro com números
    for(i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // Número da linha
        for(j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}