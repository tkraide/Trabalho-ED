#ifndef JOGADORES_H
#define JOGADORES_H

#include "lista.h" 
#include "fila.h"

typedef struct{
  int id;
  lista mao;
  int qtd_cartas;
} Player;

void iniciar_jogadores(Player jogadores[], int qtd_jogadores);              // Iniciar jogadores
void add_cartas(Player *jogadores, T1 cor, T2 valor);                       // Adicionar cartas ao jogador
void rmv_cartas(Player *jogadores, T1 cor, T2 valor);                       // Remover cartas do jogador
void mostrar_mao_player(Player *jogadores);                                 // Mostrar mão do jogador
void distribuir_cartas(fila *Deck, Player jogadores[], int qtd_jogadores);  // Distribuir cartas para os jogadores
void comprar_carta(fila *Deck, Player *jogador);                            // Comprar carta
void descartar_carta(fila *Descarte, Player *jogador, T1 cor, T2 valor);    // Descartar carta

#endif
