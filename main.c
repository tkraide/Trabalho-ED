#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"
#include "jogadores.h"
#include "regras.h"

int main() {
    int qtdJogadores;
    printf("Quantos jogadores vao jogar?: ");
    scanf("%d", &qtdJogadores); // Recebe a quantidade de jogadores

    Player jogadores[qtdJogadores]; // Cria um vetor de jogadores
    iniciar_jogadores(jogadores, qtdJogadores); // Inicializa os jogadores
    
    fila Deck, Descarte; // Cria o baralho de compra e o baralho de descarte
    inicializar(&Deck); // Inicializa o baralho de compra
    inicializar(&Descarte); // Inicializa o baralho de descarte

    // Insere as cartas no baralho de compra
    for (int i = 0; i < 11; i++) {
        insere(&Deck, i, 'A');
        insere(&Deck, i, 'B');
        insere(&Deck, i, 'C');
        insere(&Deck, i, 'D');
    }

    // Cartas especiais sem cor
    for (int i = 0; i < 4; i++) {
        insere(&Deck, CARTA_COMPRAR_4, 'E'); // Carta +4
        insere(&Deck, CARTA_MUDAR_COR, 'E'); // Carta Mudar de Cor
    }

    // Cartas Especiais com Cor
    for (int i = 0; i < 4; i++) {
        insere(&Deck, CARTA_INVERTER, 'A'); // Carta Inverter
        insere(&Deck, CARTA_INVERTER, 'B');
        insere(&Deck, CARTA_INVERTER, 'C');
        insere(&Deck, CARTA_INVERTER, 'D');

        insere(&Deck, CARTA_PULAR, 'A'); // Carta Pular
        insere(&Deck, CARTA_PULAR, 'B');
        insere(&Deck, CARTA_PULAR, 'C');
        insere(&Deck, CARTA_PULAR, 'D');

        insere(&Deck, CARTA_COMPRAR_2, 'A'); // Carta +2
        insere(&Deck, CARTA_COMPRAR_2, 'B');
        insere(&Deck, CARTA_COMPRAR_2, 'C');
        insere(&Deck, CARTA_COMPRAR_2, 'D');
    }

    // Embaralha as cartas
    embaralhar(&Deck);

    // Distribui as cartas para os jogadores
    distribuir_cartas(&Deck, jogadores, qtdJogadores);

    for (int i = 0; i < qtdJogadores; i++) { // Printei as maos somente para teste
        mostrar_mao_player(&jogadores[i]);
        printf("\n");
    }

    struct carta cartaTopo;
    retira(&Deck);
    cartaTopo = Deck.dados[Deck.primeiro];

    int jogadorAtual = 0;
    int direcao = 1;
    int primeiraJogada = 1; // Variável para controlar a primeira jogada

    while (1) {
        // Verifica se o baralho de compra está ficando vazio e reabastece com as cartas do baralho de descarte
        if (tamanho(&Deck) < 1) {
            reabastecerDeck(&Deck, &Descarte);
        }

        // Mostrar a mão do jogador atual
        mostrar_mao_player(&jogadores[jogadorAtual]);

        // Mostrar a última carta jogada, exceto na primeira jogada
        if (!primeiraJogada) {
            printf("Ultima carta jogada: Valor: %d, Cor: %c\n", cartaTopo.dado1, cartaTopo.dado2);
        }

        // Jogador faz uma jogada
        struct carta cartaJogada;
        char opcao;
        printf("Jogador %d, jogue uma carta (valor cor) ou passe a vez (p): ", jogadores[jogadorAtual].id);
        scanf(" %c", &opcao);

        if (opcao == 'p') {
            printf("Voce passou a vez e comprou uma carta.\n");
            comprar_carta(&Deck, &jogadores[jogadorAtual]);
        } else {
            ungetc(opcao, stdin); // Coloca a opção de volta no buffer de entrada
            scanf("%d %c", &cartaJogada.dado1, &cartaJogada.dado2);

            // Validar a jogada, exceto na primeira jogada
            if (primeiraJogada || validar_jogada(cartaJogada, cartaTopo)) {
                descartar_carta(&Descarte, &jogadores[jogadorAtual], cartaJogada.dado1, cartaJogada.dado2);
                cartaTopo = cartaJogada;
                aplicar_regras_especiais(&Deck, &Descarte, jogadores, qtdJogadores, &jogadorAtual, &direcao, cartaJogada, &cartaTopo);
                primeiraJogada = 0; // Desativar a flag da primeira jogada após a primeira jogada
            } else {
                printf("Jogada invalida! Compre uma carta.\n");
                comprar_carta(&Deck, &jogadores[jogadorAtual]);
            }
        }

        // Verificar fim de jogo
        if (verificar_fim_jogo(jogadores, qtdJogadores)) {
            break;
        }

        // Controlar turnos
        controlar_turnos(jogadores, qtdJogadores, &jogadorAtual, &direcao);
    }

    return 0;
}