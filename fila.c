#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Inclua a biblioteca time.h
#include "fila.h"

void inicializar(fila *f) {     // Inicializa a fila
    f->dados = (struct carta *)malloc(MAX * sizeof(struct carta));
    if (f->dados == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    f->primeiro = 0;
    f->ultimo = -1;
    f->quantidade = 0;
    f->capacidade = MAX;
}

void destruir(fila *f) {       // Destrói a fila
    free(f->dados);
    f->dados = NULL;
    f->primeiro = 0;
    f->ultimo = -1;
    f->quantidade = 0;
    f->capacidade = 0;
}

int vazia(fila *f) {          // Verifica se a fila está vazia
    return f->quantidade == 0;
}

unsigned tamanho(fila *f) {  // Retorna o tamanho da fila
    return f->quantidade;
}

void insere(fila *f, T1 dado1, T2 dado2) {           // Insere um valor na fila
    if (f->quantidade == f->capacidade) {
        f->capacidade *= 2;
        f->dados = (struct carta *)realloc(f->dados, f->capacidade * sizeof(struct carta));
        if (f->dados == NULL) {
            fprintf(stderr, "Erro ao realocar memória\n");
            exit(EXIT_FAILURE);
        }
    }
    f->ultimo = (f->ultimo + 1) % (int)f->capacidade;
    f->dados[f->ultimo].dado1 = dado1;
    f->dados[f->ultimo].dado2 = dado2;
    f->quantidade++;
}

void retira(fila *f) {         // Retira um valor da fila
    if (!vazia(f)) {
        f->primeiro = (f->primeiro + 1) % (int)f->capacidade;
        f->quantidade--;
    } else {
        printf("Fila vazia!\n");
    }
}

void embaralhar(fila *Deck) {  // Embaralha as cartas do Deck
    srand((unsigned)time(NULL));  // Inicializa a semente do gerador de números aleatórios
    int i, j;
    struct carta temp;
    for (i = 0; i < (int)Deck->quantidade; i++) {
        j = rand() % (int)Deck->quantidade;
        temp = Deck->dados[i];
        Deck->dados[i] = Deck->dados[j];
        Deck->dados[j] = temp;
    }
}

void reabastecerDeck(fila *Deck, fila *Descarte) {  // Reabastece o Deck com as cartas do Descarte
    embaralhar(Descarte);
    while (!vazia(Descarte)) {
        insere(Deck, Descarte->dados[Descarte->primeiro].dado1, Descarte->dados[Descarte->primeiro].dado2);
        retira(Descarte);
    }
}

void imprime(fila *f) {        // Imprime a fila
    int i;
    for (i = 0; i < (int)f->quantidade; i++) {
        printf("Carta %d: %d %c\n", i + 1, f->dados[(f->primeiro + i) % (int)f->capacidade].dado1, f->dados[(f->primeiro + i) % (int)f->capacidade].dado2);
    }
}