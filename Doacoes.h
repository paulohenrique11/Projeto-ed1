#ifndef DOACOES_H_INCLUDED
#define DOACOES_H_INCLUDED
#include "Livros.h"
#include "Pessoas.h"

//CRIA A LISTA.

typedef struct lista Lista;
typedef struct listano Listano;
typedef struct dados Dados;

Lista *criarLista(void);//CRIAR A LISTA.
void liberaLista(Lista*l);//LIBERA A LISTA.

void preencherLista(Lista *l,char *nome,char *doacao,char *livro);

int verificarLista(Lista *l);
////////////////////////////////////////////////////////////
int realizarDoacao(Pilha *p,Fila *f,Lista *l);
////////////////////////////////////////////////////////////
void estoqueDoacoes(Lista *l);
////////////////////////////////////////////////////////////
void historicoDoadores(Lista *l);
////////////////////////////////////////////////////////////
void relatorio(Lista *l);
////////////////////////////////////////////////////////////

#endif // DOACOES_H_INCLUDED
