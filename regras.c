#include "regras.h"
#include <stdio.h>

// Função para controlar a ordem dos turnos e jogadores
void controlar_turnos(Player jogadores[], int qtdJogadores, int *jogadorAtual, int *direcao) {
    *jogadorAtual += *direcao;
    if (*jogadorAtual >= qtdJogadores) {
        *jogadorAtual = 0;
    } else if (*jogadorAtual < 0) {
        *jogadorAtual = qtdJogadores - 1;
    }
}

// Função para aplicar regras das cartas especiais
void aplicar_regras_especiais(fila *Deck, fila *Descarte, Player jogadores[], int qtdJogadores, int *jogadorAtual, int *direcao, struct carta cartaJogada, struct carta *cartaTopo) {
    int proximoJogador = (*jogadorAtual + *direcao + qtdJogadores) % qtdJogadores;

    switch (cartaJogada.dado1) {
        case CARTA_COMPRAR_2: // Comprar 2 cartas
            for (int i = 0; i < 2; i++) {
                comprar_carta(Deck, &jogadores[proximoJogador]);
            }
            break;
        case CARTA_COMPRAR_4: // Comprar 4 cartas
            for (int i = 0; i < 4; i++) {
                comprar_carta(Deck, &jogadores[proximoJogador]);
            }
            printf("Escolha a nova cor (A, B, C, D): ");
            char novaCor;
            scanf(" %c", &novaCor);
            cartaTopo->dado2 = novaCor; // Atualiza a cor da carta jogada
            break;
        case CARTA_INVERTER: // Mudar direção
            *direcao *= -1;
            break;
        case CARTA_PULAR: // Pular jogador
            controlar_turnos(jogadores, qtdJogadores, jogadorAtual, direcao); // Pula o próximo jogador
            break;
        case CARTA_MUDAR_COR: // Mudar de cor
            printf("Escolha a nova cor (A, B, C, D): ");
            scanf(" %c", &novaCor);
            cartaTopo->dado2 = novaCor; // Atualiza a cor da carta jogada
            break;
        default:
            break;
    }
}

// Função para validar se a jogada do jogador é válida
int validar_jogada(struct carta cartaJogada, struct carta cartaTopo) {
    return (cartaJogada.dado1 == cartaTopo.dado1 || cartaJogada.dado2 == cartaTopo.dado2 || cartaJogada.dado1 == CARTA_COMPRAR_4 || cartaJogada.dado1 == CARTA_MUDAR_COR);
}

int verificar_carta(struct carta cartaJogada) {
    return ((cartaJogada.dado1 >= 0 && cartaJogada.dado1 <= 14) && cartaJogada.dado2 >= 'A' && cartaJogada.dado2 <= 'E');
}

// Função para implementar a lógica de fim de jogo
int verificar_fim_jogo(Player jogadores[], int qtdJogadores) {
    for (int i = 0; i < qtdJogadores; i++) {
        if (jogadores[i].qtd_cartas == 0) {
            printf("Jogador %d venceu!\n", jogadores[i].id);
            return 1;
        }
    }
    return 0;
}