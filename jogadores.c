#include <stdio.h>
#include <stdlib.h>
#include "jogadores.h"
#include "lista.h"


// Iniciar jogadores
void iniciar_jogadores(Player jogadores[], int qtd_jogadores){
  
    for(int i = 0; i < qtd_jogadores; i++){ 
        jogadores[i].id = i + 1; // ID do jogador
        lista_inicializar(&jogadores[i].mao); // Inicializar a mão do jogador
        jogadores[i].qtd_cartas = 0; // Quantidade de cartas do jogador
    }
}

// Adicionar cartas ao jogador
void add_cartas(Player *jogador, T1 cor, T2 valor){
  
    lista_inserir_final(&jogador->mao, cor, valor); // Inserir carta na mão do jogador
  
    jogador->qtd_cartas++; // Incrementar a quantidade de cartas do jogador
}

// Remover cartas do jogador
void rmv_cartas(Player *jogador, T1 cor, T2 valor){
  
    if(lista_retirar_termo(&jogador->mao, cor, valor)){ // Remover carta da mão do jogador
        jogador->qtd_cartas--;
    }
 
    else{ // Se não conseguir remover a carta
        printf("Jogador não tem mais cartas %d!\n", jogador->id);
    }
}

// Mostrar mão do jogador
void mostrar_mao_player(Player *jogador){

    printf("Mao do jogador %d:\n", jogador->id); // Mostrar a mão do jogador
  
    iterador i = primeiro(&jogador->mao); // Criar um iterador para percorrer a mão do jogador
  
    while (!acabou(i)) { // Enquanto o iterador não chegar ao final da mão do jogador
        printf("Valor: %d, Cor: %c\n", i.posicao->dado1, i.posicao->dado2);
        proximo(&i); // Avançar o iterador para o próximo nó
    }

    // while(!acabou(i)){ // Enquanto o iterador não chegar ao final da mão do jogador
    //     printf("Valor: %d, Cor: %c\n", i.posicao->dado1, i.posicao->dado2);
    //     if(!proximo(i)) // Se o iterador chegar ao final da mão do jogador
    //         break;
    // }
  
    printf("Total de cartas: %d\n", jogador->qtd_cartas); // Mostrar o total de cartas do jogador
}

void distribuir_cartas(fila *Deck, Player jogadores[], int qtd_jogadores){
  
    for(int i = 0; i < qtd_jogadores; i++){ // Para cada jogador
        for(int j = 0; j < 7; j++){ // Distribuir 7 cartas para cada jogador
            add_cartas(&jogadores[i], Deck->dados[Deck->primeiro].dado1, Deck->dados[Deck->primeiro].dado2); // Adicionar carta na mão do jogador
            retira(Deck); // Retirar carta do baralho de compra
        }
    }
}

void comprar_carta(fila *Deck, Player *jogador){
    add_cartas(jogador, Deck->dados[Deck->primeiro].dado1, Deck->dados[Deck->primeiro].dado2); // Adicionar carta na mão do jogador
    retira(Deck); // Retirar carta do baralho de compra
    jogador->qtd_cartas++; // Incrementar a quantidade de cartas do jogador
}

void descartar_carta(fila *Descarte, Player *jogador, T1 cor, T2 valor){
    if(lista_retirar_termo(&jogador->mao, cor, valor)){ // Remover carta da mão do jogador
        jogador->qtd_cartas--;
        insere(Descarte, cor, valor); // Inserir carta no baralho de descarte
    }
    else{ // Se não conseguir remover a carta
        printf("Jogador não tem mais cartas %d!\n", jogador->id);
    }
}