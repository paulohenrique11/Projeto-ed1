#ifndef LIVROS_H_INCLUDED
#define LIVROS_H_INCLUDED

typedef struct pilha Pilha;
typedef struct lista PLista ;
typedef struct livro Livro;

Pilha *criarPilha(void);//FUNCAO PARA CRIAR A PILHA.

void liberaPilha(Pilha *p);//FUNCAO  PARA LIBERAR A PILHA.
void cadastrarLivro(Pilha *p, Livro *livro);//FUNCAO  PARA INSERIR UM LIVRO NA PILHA.
void removerLivro(Pilha*p, char *livro);//FUNCAO  PARA REMOVER UM LIVRO DA PILHA.
void exibirLivros(Pilha*p);//FUNCAO  PARA EXIBIR PILHA.
int verificarPilha(Pilha *p);//FUNCAO  PARA VERIFICAR SE A PILHA ESTA VAZIA.

Livro *criarLivro(char *nome, int ano, char *autor);//FUNÇÃO PARA CADASTRAR O LIVRO.


#endif // LIVROS_H_INCLUDED
