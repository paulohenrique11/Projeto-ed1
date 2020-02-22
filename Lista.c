#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "Doacoes.h"
#include "Pessoas.h"
#include "Livros.h"
#include "Animacao.h"
#define TRUE 1
#define FALSE 0

//-> STRUCT DA MINHA LISTA QUE FICA RESPONSAVEL PELOS DADOS DEPOIS DA DOAÇÃO <-//

struct lista
{
    Listano *primeiro;
};

struct listano
{
    Dados *infor;
    Listano *prox;
};

struct dados
{
    char nome[50];
    char doacao[20];
    char livro[50];
};

//-> CRIAR A LISTA VAZIA <-//

Lista *criarLista(void)
{
    Lista *l = (Lista*)malloc(sizeof(Lista));
    if(l == NULL)
    {
        printf("ERRO AO CRIAR A LISTA !!\n\n");
        exit(1);
    }
    l->primeiro = NULL;
    return l;
}

//-> LIBERA A LISTA <-//

void liberaLista(Lista*l)
{
    Listano *aux = l->primeiro, *aux1;
    while(aux != NULL)
    {
        aux1 = aux->prox;
        if(aux->infor!=NULL)//VERIFICA SE CHEGOU A SER ALOCADO UMA STRUCT.
        {
            free(aux->infor);//LIBERA A STRUCT.
        }
        free(aux);//LIBERA O NO DA LISTA.
        aux = aux1;
    }
    free(l);//LIBERA A LISTA.
    l=NULL;
}

//-> MANIPULAÇÃO DA LISTA <-//

void preencherLista(Lista *l,char *nome,char *doacao,char *livro)
{
    Listano *novo = (Listano*)malloc(sizeof(Listano));//CRIA UM NOVO NO DA LISTA.
    if(novo == NULL)
    {
        printf("ERRO EM CRIAR O NO DA LISTA !!\n\n");
        exit(1);
    }
    novo->infor = (Dados*)malloc(sizeof(Dados));//ALOCA UM ESPAÇO PARA UMA STRUCT PARA ARMAZENAR OS DADOS.

    if(novo->infor == NULL)
    {
        printf("ERRO EM ALOCAR ESPAÇO PARA A STRUCT !!\n\n");
        exit(1);
    }

    strcpy(novo->infor->nome, nome);
    strcpy(novo->infor->doacao, doacao);//PASSANDO OS DADOS PARA A STRUCT ALOCADA LOGO ACIMA.
    strcpy(novo->infor->livro, livro);

    novo->prox = l->primeiro;
    l->primeiro = novo;
}

int verificarLista(Lista *l)
{
    if(l->primeiro == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//-> ESTOQUE <-//

void estoqueDoacoes(Lista *l)
{
    int totald = 1;
    Listano *aux=l->primeiro;
    if(verificarLista(l)!= 1)
    {
        animacao9();
        while(aux!=NULL)
        {
            printf("\t%iº %s\n\n", totald, aux->infor->doacao);
            aux = aux->prox;
            totald++;
        }
        printf("\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!");
        getch();
    }
    else
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("\t _______________________________________________________________________________________\n");
        printf("\t|                                                                                       |\n");
        printf("\t|  NÃO FOI POSSIVEL VISUALIZAR O ESTOQUE ! POR FAVOR REALIZAR PRIMEIRO AS DOAÇÕES !!    |\n");
        printf("\t|_______________________________________________________________________________________|\n\n");
        printf("\t\t\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!!\n");
        getch();
    }
}

// -> HISTORICO DE DOADORES <- //

void historicoDoadores(Lista *l)
{
    Listano *aux = l->primeiro;
    if(verificarLista(l)!= 1)
    {
        animacao9();
        while(aux != NULL)
        {
            printf("\tDOADOR: %s\n\tGANHOU O LIVRO: %s\n\n",aux->infor->nome, aux->infor->livro);
            aux = aux->prox;

        }
        printf("\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!");
        getch();
    }
    else
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("\t _______________________________________________________________________________________\n");
        printf("\t|                                                                                       |\n");
        printf("\t|  NÃO FOI POSSIVEL VISUALIZAR O HISTORICO ! POR FAVOR REALIZAR PRIMEIRO AS DOAÇÕES !!  |\n");
        printf("\t|_______________________________________________________________________________________|\n\n");
        printf("\t\t\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!!\n");
        getch();
    }
}

// -> RELATORIO <- //

void relatorio(Lista *l)
{
    FILE *arq1 = fopen("relatorio.txt","wt");
    FILE *arq2 = fopen("doacoes.txt","wt");
    if(arq1 == NULL)
    {
        printf("ERRO EM CRIAR O ARQUIVO relatorio.txt !!\n\n");
        exit(1);
    }
    if(arq2 == NULL)
    {
        printf("ERRO EM CRIAR O ARQUIVO doacoes.txt !!\n\n");
        exit(1);
    }
    Listano*aux;

    fprintf(arq1,"\n| RELATORIO |\n\n");
    fprintf(arq2,"\n| LISTA DE DOAÇÕES |\n\n");

    for(aux=l->primeiro; aux!=NULL; aux=aux->prox)
    {
        fprintf(arq1,"\nDOADOR : %s\nDOAÇÃO : %s\nBRINDE : %s\n",aux->infor->nome, aux->infor->doacao, aux->infor->livro);
        fprintf(arq2,"\nDOAÇÃO : %s\n\n", aux->infor->doacao);
    }
    fclose(arq1);
    fclose(arq2);
}
