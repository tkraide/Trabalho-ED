#ifndef LISTA_H
#define LISTA_H

typedef int T1;
typedef char T2;

struct node{
  T1 dado1;
  T2 dado2;
  struct node *ant, *prox;
};

typedef struct{
  struct node *sentinela;
  unsigned quantidade;
}lista;

typedef struct{
  lista *estrutura;
  struct node *posicao;
}iterador;

typedef struct node Node;


// Alterei as funções de remover para colocar as cartas descartadas no baralho de descarte e retornar para o baralho de compra
// quando o baralho de compra acabar


void lista_inicializar(lista *l); // inicializa a lista

unsigned lista_quantidade(lista *l); // retorna a quantidade de elementos da lista

void lista_inserir_inicio(lista *l, T1 data1, T2 data2); // insere um novo elemento no inicio da lista

void lista_inserir_final(lista *l, T1 data1, T2 data2); // insere um novo elemento no final da lista

int lista_retirar_inicio(lista *l); // remove um elemento do inicio da lista. Retorna 0 caso a lista estiver vazia. Caso contrário, retorna 1

int lista_retirar_final(lista *l); // remove um elemento do final da lista. Retorna 0 caso a lista estiver vazia. Caso contrário, retorna 1

int lista_retirar_termo(lista *l, T1 data1, T2 data2); // remove o termo específico da lista que contenha data1 e data2 como dado1 e dado2, respectivamente. Retorna 1 se conseguir retirar e 0 se não conseguir retirar

iterador primeiro(lista *l); // cria um iterador apontando pro inicio da lista

iterador ultimo(lista *l); // cria um iterador apontando pro final da lista

int proximo(iterador *i); // passa o iterador pro próximo elemento da lista. Retorna 1 se conseguir e 0 se passar do final da lista

int anterior(iterador *i); // passa o iterador pro elemento anterior da lista. Retorna 1 se conseguir e 0 se passar do inicio da lista

int acabou(iterador i); // verifica se o iterador atingiu o final da lista. Retorna 1 se sim, e 0 se não

void lista_destruir(lista *l); // destrói a lista. Para reutilizá-la, é necessária a chamada da função lista_inicializar

int lista_vazia(lista *l); // retorna 1 se a lista estiver vazia

void lista_inserir_anterior(lista *l, iterador i, T1 data1, T2 data2); // insere um elemento na posição anterior ao iterador

void lista_inserir_seguinte(lista *l, iterador i, T1 data1, T2 data2); // insere um elemento na posição seguinte ao iterador

int lista_retirar_anterior(lista *l, iterador i); // remove um elemento na posição anterior ao iterador. Retorna 0 se a lista estiver vazia ou o iterador aponta para o primeiro elemento da lista. Retorna 1 se conseguir remover

int lista_retirar_seguinte(lista *l, iterador i); // remove um elemento na posição seguinte ao iterador. Retorna 0 se a lista estiver vazia ou o iterador aponta para o último elemento da lista. Retorna 1 se conseguir retirar

#endif