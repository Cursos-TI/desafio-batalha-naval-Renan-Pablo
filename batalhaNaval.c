#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
    int i, j;
    char colunas[COLUNAS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[LINHAS][COLUNAS];

    // Preenche o tabuleiro com 0 (água)
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coloca navios (valor 3)
    tabuleiro[1][1] = 3;
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;

    tabuleiro[4][4] = 3;
    tabuleiro[5][4] = 3;
    tabuleiro[6][4] = 3;

    tabuleiro[2][7] = 3;
    tabuleiro[1][8] = 3;
    tabuleiro[0][9] = 3;

    tabuleiro[4][7] = 3;
    tabuleiro[5][8] = 3;
    tabuleiro[6][9] = 3;

    // MATRIZ DE HABILIDADE CONE (5x5)
    int habilidade[5][5];
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(j >= 2 - i && j <= 2 + i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }

    // APLICA CONE NO TABULEIRO (centro na linha 3, coluna 3)
    int linhaCentro = 3;
    int colunaCentro = 3;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            int x = linhaCentro - 2 + i;
            int y = colunaCentro - 2 + j;
            if(x >= 0 && x < 10 && y >= 0 && y < 10) {
                if(habilidade[i][j] == 1 && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 1;
                }
            }
        }
    }

    // MATRIZ DE HABILIDADE CRUZ (5x5)
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(i == 2 || j == 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }

    // APLICA CRUZ NO TABULEIRO (centro na linha 6, coluna 6)
    linhaCentro = 6;
    colunaCentro = 6;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            int x = linhaCentro - 2 + i;
            int y = colunaCentro - 2 + j;
            if(x >= 0 && x < 10 && y >= 0 && y < 10) {
                if(habilidade[i][j] == 1 && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 2;
                }
            }
        }
    }

    // MATRIZ DE HABILIDADE OCTAEDRO (5x5)
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if((i + j >= 2) && (i + j <= 6) && (j - i <= 2) && (i - j <= 2)) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }

    // APLICA OCTAEDRO NO TABULEIRO (centro na linha 5, coluna 2)
    linhaCentro = 5;
    colunaCentro = 2;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            int x = linhaCentro - 2 + i;
            int y = colunaCentro - 2 + j;
            if(x >= 0 && x < 10 && y >= 0 && y < 10) {
                if(habilidade[i][j] == 1 && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // EXIBE O TABULEIRO
    printf(" TABULEIRO BATALHA NAVAL\n");
    printf("   ");
    for(i = 0; i < COLUNAS; i++) {
        printf("%c ", colunas[i]);
    }
    printf("\n");

    for(i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1);
        for(j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
