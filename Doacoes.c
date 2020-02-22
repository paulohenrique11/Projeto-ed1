#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include "Livros.h"
#include "Pessoas.h"
#include "Doacoes.h"
#include "Animacao.h"


int realizarDoacao(Pilha *p, Fila *f, Lista *l)
{
    animacao8();
    char nome[50];
    char doacao[20];
    char livro[50];
    int totald = 0;

    if(verificarFila(f) != 1 && verificarPilha(p) == 1)
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("\t _________________________________________________________________________\n");
        printf("\t|                                                                         |\n");
        printf("\t|   NÃO FOI POSSIVEL REALIZAR A DOAÇÃO ! POR FAVOR CADASTRAR BRINDES !!   |\n");
        printf("\t|_________________________________________________________________________|\n\n");
        printf("\t\t\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!!");
        getch();
    }
    else if(verificarFila(f) == 1 && verificarPilha(p) != 1)
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("\t ________________________________________________________________________\n");
        printf("\t|                                                                        |\n");
        printf("\t|  NÃO FOI POSSIVEL REALIZAR A DOAÇÃO ! POR FAVOR CADASTRAR DOADORES !!  |\n");
        printf("\t|________________________________________________________________________|\n\n");
        printf("\t\t\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!!");
        getch();

    }
    else if(verificarFila(f) == 1 && verificarPilha(p) == 1)
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("\t _______________________________________________________________________\n");
        printf("\t|                                                                       |\n");
        printf("\t|                 NÃO FOI POSSIVEL REALIZAR A DOAÇÃO !!                 |\n");
        printf("\t|                                                                       |\n");
        printf("\t|               POR FAVOR CADASTRAR DOADORES E BRINDES !!               |\n");
        printf("\t|_______________________________________________________________________|\n\n");
        printf("\t\t\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!!");
        getch();
    }
    else
    {
        removerLivro(p,livro);
        removerPessoa(f,nome,doacao);
        preencherLista(l,nome,doacao,livro);
        totald++;
        animacao2();
    }
    return totald;
}
