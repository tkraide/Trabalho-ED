#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"

int main() {
    
    fila Deck, Descarte;

    inicializar(&Deck);
    inicializar(&Descarte);

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

    // Distribui as cartas

    while (1) // Substituir pelo Loop principal do jogo
    {
        // Verifica se o baralho de compra está ficando vazio e reabastece com as cartas do baralho de descarte
        if (tamanho(&Deck) < 5) {  // pode aumentar conforme a necessidade
            embaralhar(&Descarte);
            while (tamanho(&Descarte) > 0) {
                insere(&Deck, Descarte.dados[Descarte.primeiro].dado1, Descarte.dados[Descarte.primeiro].dado2);
                retira(&Descarte);
            }
        } 
    }

    // Imprime o deck inteiro
    //imprime(&Deck);
    
    return 0;
}