#include <stdlib.h>
#include "lista.h"

void lista_inicializar(lista *l){
  Node *n = (Node*)malloc(sizeof(Node));
  n->ant = n->prox = l->sentinela = n;
  l->quantidade = 0;
}

unsigned lista_quantidade(lista *l){
  return(l->quantidade);
}

void lista_inserir_inicio(lista *l, T1 data1, T2 data2){
  Node *n = (Node*)malloc(sizeof(Node));
  n->dado1 = data1;
  n->dado2 = data2;
  n->prox = l->sentinela->prox;
  n->ant = l->sentinela;
  l->sentinela->prox = n;
  n->prox->ant = n;
  l->quantidade++;
}

void lista_inserir_final(lista *l, T1 data1, T2 data2){
  Node *n = (Node*)malloc(sizeof(Node));
  n->dado1 = data1;
  n->dado2 = data2;
  n->prox = l->sentinela;
  n->ant = l->sentinela->ant;
  l->sentinela->ant = n;
  n->ant->prox = n;
  l->quantidade++;
}

int lista_retirar_inicio(lista *l){
  Node *n = l->sentinela->prox;
  if(n!=l->sentinela){
    n->prox->ant = n->ant;
    n->ant->prox = n->prox;
    free(n);
    l->quantidade--;
    return(1);
  }
  return(0);
}

int lista_retirar_final(lista *l){
  Node *n = l->sentinela->ant;
  if(n!=l->sentinela){
    n->prox->ant = n->ant;
    n->ant->prox = n->prox;
    free(n);
    l->quantidade--;
    return(1);
  }
  return(0);
}

iterador primeiro(lista *l){
  iterador i;
  i.estrutura = l;
  i.posicao = l->sentinela->prox;
  return(i);
}

iterador ultimo(lista *l){
  iterador i;
  i.estrutura = l;
  i.posicao = l->sentinela->ant;
  return(i);
}

int acabou(iterador i){
  if(i.posicao == i.estrutura->sentinela){
    return(1);
  }else{
    return(0);
  }
}

int proximo(iterador *i){
  if(!acabou(*i)){
    i->posicao = i->posicao->prox;
    return(1);
  }
  return(0);
}

int anterior(iterador *i){
  if(!acabou(*i)){
    i->posicao = i->posicao->ant;
    return(1);
  }
  return(0);
}

int lista_retirar_termo(lista *l, T1 data1, T2 data2){
  iterador i = primeiro(l);
  while(!acabou(i)){
    if((i.posicao->dado1 == data1) &&(i.posicao->dado2 == data2)){
      Node *n = i.posicao;
      n->prox->ant = n->ant;
      n->ant->prox = n->prox;
      free(n);
      l->quantidade--;
      return(1);
    }
    if(!proximo(&i))
      return(0);
  }
  return(0); 
}

void lista_destruir(lista *l){
  while(l->sentinela->prox != l->sentinela){
    lista_retirar_inicio(l);
  }
  free(l->sentinela);
}

int lista_vazia(lista *l){
  if(l->sentinela->prox == l->sentinela){
    return(1);
  } 
  return(0);
}

void lista_inserir_anterior(lista *l, iterador i, T1 data1, T2 data2){
  Node *n = (Node*)malloc(sizeof(Node));
  i.posicao->ant->prox = n;
  n->ant = i.posicao->ant;
  n->prox = i.posicao;
  i.posicao->ant = n;
  n->dado1 = data1;
  n->dado2 = data2;
  l->quantidade++;
}

void lista_inserir_seguinte(lista *l, iterador i, T1 data1, T2 data2){
  Node *n = (Node*)malloc(sizeof(Node));
  i.posicao->prox->ant = n;
  n->prox = i.posicao->prox;
  n->ant = i.posicao;
  i.posicao->prox = n;
  n->dado1 = data1;
  n->dado2 = data2;
  l->quantidade++;
}

int lista_retirar_anterior(lista *l, iterador i){
  if(lista_vazia(l) || (i.posicao->ant == l->sentinela)){
    return(0);
  }
  Node *n = i.posicao->ant;
  n->ant->prox = n->prox;
  n->prox->ant = n->ant;
  free(n);
  l->quantidade--;
  return(1);
}

int lista_retirar_seguinte(lista *l, iterador i){
  if(lista_vazia(l) || (i.posicao->prox == l->sentinela)){
    return(0);
  }
  Node *n = i.posicao->prox;
  n->ant->prox = n->prox;
  n->prox->ant = n->ant;
  free(n);
  l->quantidade--;
  return(1);
}