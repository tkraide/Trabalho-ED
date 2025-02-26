#ifndef REGRAS_H
#define REGRAS_H

#include "jogadores.h"
#include "fila.h"

#define CARTA_COMPRAR_2 10
#define CARTA_COMPRAR_4 11
#define CARTA_INVERTER 12
#define CARTA_PULAR 13
#define CARTA_MUDAR_COR 14

// Função para controlar a ordem dos turnos e jogadores
void controlar_turnos(Player jogadores[], int qtdJogadores, int *jogadorAtual, int *direcao);

// Função para aplicar regras das cartas especiais
void aplicar_regras_especiais(fila *Deck, fila *Descarte, Player jogadores[], int qtdJogadores, int *jogadorAtual, int *direcao, struct carta cartaJogada, struct carta *cartaTopo);

// Função para validar se a jogada do jogador é válida
int validar_jogada(struct carta cartaJogada, struct carta cartaTopo);

// Função para implementar a lógica de fim de jogo
int verificar_fim_jogo(Player jogadores[], int qtdJogadores);

#endif