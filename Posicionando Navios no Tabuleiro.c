#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // Água
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função genérica para posicionar um navio, seja horizontal ou vertical
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {  // Horizontal
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Verifica se cabe
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;  // Verifica sobreposição
            tabuleiro[linha][coluna + i] = 3;  // Posiciona o navio
        }
    } else {  // Vertical
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Verifica se cabe
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;  // Verifica sobreposição
            tabuleiro[linha + i][coluna] = 3;  // Posiciona o navio
        }
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posiciona o navio horizontal na linha 2 e coluna 3
    if (!posicionarNavio(tabuleiro, 2, 3, 'H')) {
        printf("Erro ao posicionar navio horizontal.\n");
        return 1;
    }

    // Posiciona o navio vertical na linha 5 e coluna 6
    if (!posicionarNavio(tabuleiro, 5, 6, 'V')) {
        printf("Erro ao posicionar navio vertical.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro do Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}