#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"
#include "jogadores.h"

int main() {

    int qtdJogadores;

    scanf("%d", &qtdJogadores); // Recebe a quantidade de jogadores

    Player jogadores[qtdJogadores]; // Cria um vetor de jogadores

    iniciar_jogadores(jogadores, qtdJogadores); // Inicializa os jogadores
    
    fila Deck, Descarte; // Cria o baralho de compra e o baralho de descarte

    inicializar(&Deck); // Inicializa o baralho de compra
    inicializar(&Descarte); // Inicializa o baralho de descarte

    // Insere as cartas no baralho de compra
    for (int i = 0; i < 12; i++) {
        insere(&Deck, i, 'A');
        insere(&Deck, i, 'B');
        insere(&Deck, i, 'C');
        insere(&Deck, i, 'D');
    }

    // Cartas sem cor foram definidas como 'E'
    for (int i = 0; i < 4; i++) {
        insere(&Deck, 12, 'E');
        insere(&Deck, 13, 'E');
    }

    // Embaralha as cartas
    embaralhar(&Deck);

    // Distribui as cartas para os jogadores
    distribuir_cartas(&Deck, jogadores, qtdJogadores);

    for (int i = 0; i < qtdJogadores; i++) { // Printei as maos somente para teste
        mostrar_mao_player(&jogadores[i]);
    }

    while (1) // ******************* Substituir condição do while pelo Loop principal do jogo *******************
    {
        // **************   Manter  *******************

        // Verifica se o baralho de compra está ficando vazio e reabastece com as cartas do baralho de descarte
        if (tamanho(&Deck) < 1) {  // pode aumentar conforme a necessidade
            reabastecerDeck(&Deck, &Descarte);
        } 
    }
    
    return 0;
}