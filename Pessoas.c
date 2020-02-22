#include <stdio.h>
#include <stdlib.h>
#include"Pessoas.h"
#include <locale.h>
#include <string.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0

//-> STRUCT DA MINHA FILA <-//

struct fila
{
    FLista *inicio;
    FLista *fim;
};

struct lista
{
    Doador *informacao;
    FLista *proximo;
};

// -> STRUCT RESPONSAVEL PELOS DADOS DO DOADOR NA FILA <-//

struct doador
{
    char nome[100];
    char CPF[50];
    char doacao[100];
};

//FUNÇÃO PARA CRIAR A FILA.

Fila *criarFila(void)
{
    Fila *f = (Fila*)malloc(sizeof(Fila));//CRIA FILA VAZIA.
    if(f == NULL)
    {
        printf("Erro! Na criação da fila.");//VERIFICA DE FOI ALOCADO.
        exit(1);
    }
    f->inicio = f->fim = NULL;
    return f;
}

//FUNÇÃO PARA LIBERAR A FILA.

void liberaFila(Fila*f)
{
    FLista *l = f->inicio;
    while(l != NULL)
    {
        FLista * temp = l->proximo;
        if(l->informacao!=NULL)//VERIFICA SE FOI ALOCADO A STRUCT.
        {
            free(l->informacao);//LIBERA A STRUCT.
        }
        free(l);
        l = temp;
    }
    free(f);
}

//-> FUNCAO PARA CADASTRA AS PESSOAS NA FILA DE DOAÇÕES.

void cadastrarPessoa(Fila *f, Doador *d)
{
    FLista *l = (FLista*)malloc(sizeof(FLista));
    if(l == NULL)
    {
        printf("ERRO! Ao cadastrar doador.");
        exit(1);
    }
    l->informacao = d;
    l->proximo = NULL;

    if(f->fim != NULL)
    {
        f->fim->proximo = l;
    }
    else
    {
        f->inicio = l;
    }
    f->fim = l;
}

//-> FUNÇÃO PARA REMOVER PESSOAS DA FILA <-//

void removerPessoa(Fila *f,char *nome,char *doacao)
{
    FLista *aux;
    if(verificarFila(f)!= 1)
    {
        aux = f->inicio;
        f->inicio = aux->proximo;
        strcpy(nome, aux->informacao->nome);
        strcpy(doacao, aux->informacao->doacao);
        free(aux->informacao);//LIBERA A STRUCT ALOCADA.
        free(aux);//LIBERA O NO DA LISTA.
    }
}

//FUCAO PARA EXIBIR A FILA DE DOACOES.

void exibirPessoas(Fila *f)
{
    int qtdPessoas = 1;
    if(f->inicio != NULL)
    {
        printf("\t|----------------------------------------|\n");
        printf("\t|         DOADORES CADASTRADOS           |\n");
        printf("\t|----------------------------------------|\n");

        FLista *temp;
        for(temp = f->inicio; temp != NULL; temp = temp->proximo)
        {
            printf("\n\tNOME: %s",temp->informacao->nome);
            printf("\n\tCPF: %s",temp->informacao->CPF);
            printf("\n\tDOACAO: %s",temp->informacao->doacao);
            printf("\n\t----------------------------------------\n");
            qtdPessoas++;
        }
        printf("\tPRESSIONE QUALQUER TECLA PARA CONTINUAR !!!\n");
        getch();
    }
    else
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("\t __________________________________________________________\n");
        printf("\t|                                                          |\n");
        printf("\t|  NAO A PESSOAS ! POR FAVOR INSERIR UM PESSOA PRIMEIRO !!  |\n");
        printf("\t|__________________________________________________________|\n\n");
        printf("\t\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!!\n");
        getch();
    }

}

//FUNCAO  PARA VERIFICAR SE A FILA ESTA VAZIA.

int verificarFila(Fila *f)
{
    if(f->inicio == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Doador *criarPessoa(char *nome, char *CPF, char *doacao)
{
    Doador *d =(Doador*)malloc(sizeof(Doador));//ARMAZENA OS DADOS DOS DOADORES.
    strcpy(d->nome,nome);
    strcpy(d->CPF,CPF);
    strcpy(d->doacao,doacao);

    return d;
}
