#ifndef FILA_H
#define FILA_H

#define MAX 10 // Define um tamanho inicial para a fila

typedef int T1;
typedef char T2;

struct carta {
    T1 dado1;
    T2 dado2;
};

typedef struct {
    struct carta *dados;
    int primeiro, ultimo;
    unsigned int quantidade;
    unsigned int capacidade;
} fila;

void inicializar(fila *f);
void destruir(fila *f);
int vazia(fila *f);
unsigned tamanho(fila *f);
void insere(fila *f, T1 dado1, T2 dado2);
void retira(fila *f);
void embaralhar(fila *Deck);
void reabastecerDeck(fila *Deck, fila *Descarte);
void imprime(fila *f);

#endif