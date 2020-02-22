#include <stdio.h>
#include <stdlib.h>
#include"Livros.h"
#include <locale.h>
#include <string.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0

//-> STRUCT DA MINHA PILHA DE LIVROS <-//

struct pilha
{
    PLista *primeiro;
};

struct lista
{
    Livro *informacao;
    PLista *proximo;
};

// -> STRUCT RESPONSAVEL PELOS DADOS DO BRINDE(LIVRO) <-

struct livro
{
    char nome[100];
    int ano;
    char autor[100];
};

//FUNCAO PARA CRIAR A PILHA.

Pilha *criarPilha(void)
{
    Pilha *p =(Pilha*)malloc(sizeof(Pilha));
    p->primeiro = NULL;
    return p;
}

//FUNCAO PARA LIBERAR A PILHA.

void liberaPilha(Pilha *p)
{
    PLista*aux=p->primeiro,*aux1;
    while(aux!=NULL)
    {
        if(aux->informacao != NULL)//VERIFICA SE CHEGOU A SER ALOCADA UMA STRUCT PARA OS DADOS DO LIVRO.
        {
            free(aux->informacao);//LIBERA A STRUCT.
        }

        aux1=aux->proximo;
        free(aux);//LIBERA O NO DA LISTA DA PILHA.
        aux=aux1;
    }
    free(p);//LIBERA MINHA PILHA.
    p=NULL;
}

//FUNCAO PARA INSERIR UM LIVRO NA PILHA.

void cadastrarLivro(Pilha *p, Livro *li)
{
    PLista *l = (PLista*)malloc(sizeof(PLista));//ALOCA O NO DA MINHA LISTA NA PILHA DE LIVROS.
    if(l == NULL)
    {
        printf("ERRO AO CADASTRAR UM NOVO LIVRO");
        exit(1);
    }
    l->informacao = li;

    l->proximo = p->primeiro;

    p->primeiro = l;
}

//FUNCAO PARA REMOVER UM LIVRO DA PILHA.

void removerLivro(Pilha *p,char *livro)
{
    PLista *aux;
    if(verificarPilha(p)!=1)
    {
        aux = p->primeiro;
        p->primeiro = aux->proximo;
        strcpy(livro, aux->informacao->nome);
        free(aux->informacao);//LIBERA A STRUCT ALOCADA.
        free(aux);//LIBERA O NO DA LISTA.
    }
}

//FUNCAO PARA EXIBIR PILHA.

void exibirLivros(Pilha *p)
{
    if(p->primeiro != NULL)
    {
        printf("\t|----------------------------------------|\n");
        printf("\t|            LIVROS CADASTRADOS          |\n");
        printf("\t|----------------------------------------|\n");

        PLista *temp;
        for(temp = p->primeiro; temp != NULL; temp = temp->proximo)
        {
            printf("\n\t NOME: %s",temp->informacao->nome);
            printf("\n\t AUTOR: %s",temp->informacao->autor);
            printf("\n\t ANO: %i",temp->informacao->ano);
            printf("\n\t----------------------------------------\n");
        }
        printf("\tPRESSIONE QUALQUER TECLA PARA CONTINUAR !!!\n");
        getch();
    }
    else
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("\t __________________________________________________________\n");
        printf("\t|                                                          |\n");
        printf("\t|  NAO A LIVROS ! POR FAVOR INSERIR UM LIVROS PRIMEIRO !!  |\n");
        printf("\t|__________________________________________________________|\n\n");
        printf("\t\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!!\n");
        getch();
    }
}

//FUNCAO PARA VERIFICAR SE A PILHA ESTA VAZIA.

int verificarPilha(Pilha *p)
{
    if(p->primeiro == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Livro *criarLivro(char *nome, int ano, char *autor)
{
    Livro *li =(Livro*)malloc(sizeof(Livro));//ARMAZENA OS DADOS DO LIVRO CADASTRADO.
    strcpy(li->nome,nome);
    li->ano = ano;
    strcpy(li->autor,autor);
    return li;
}
