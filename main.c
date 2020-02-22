#include <stdio.h>
#include <stdlib.h>
#include"Doacoes.h"
#include"Livros.h"
#include"Pessoas.h"
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include "Animacao.h"

int main()
{
    SetConsoleTitle("CAMPANHA DO AGASALHO !!!");
    setlocale(LC_ALL,"Portuguese");
    int op = 0, totald = 0, totalp = 0,totalL=0;

    char nomePessoa[100];
    char doacao[100];
    char CPF[50];

    char nomeLivro[100];
    int ano;
    char autor[100];
    int gerou = 0;

    Pilha *p = criarPilha();
    Fila *f = criarFila();
    Lista *l = criarLista();


    printf("\n\n\n");
    printf("\t __________________________________________\n");
    printf("\t|  ______________________________________  |\n");
    printf("\t| |                                      | |\tA instituição de caridade GAME OF THRONES em parceria com DAENERYS TARGARYEN\n");
    printf("\t| |                                      | |\n");
    printf("\t| |                                      | |\testão realizando a CAMPANHA DO AGASALHO!!!\n");
    printf("\t| |         CAMPANHA DO AGASALHO         | |\n");
    printf("\t| |                                      | |\tPara cada peça de roupa doada ganhe um livro de BRINDE!!!\n");
    printf("\t| |                                      | |\n");
    printf("\t| |           PATROCINADORES :           | |\n");
    printf("\t| |                                      | |\n");
    printf("\t| |                                      | |\n");
    printf("\t| | GAME OF THRONES | DAENERYS TARGARYEN | |\n");
    printf("\t| |                                      | |\n");
    printf("\t| |                                      | |\n");
    printf("\t| |______________________________________| |\n");
    printf("\t|__________________________________________|\n");
    printf("\n\n\n");
    printf("\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!");
    getch();
    system("cls");

    while(op!=1)
    {
        system("cls");
        printf("\n\n\tCAMPANHA DO AGASALHO!!\n");
        printf("\t __________________________________________\n");
        printf("\t|   OPÇÃO    |          FUNÇÕES            |\n");
        printf("\t|------------|-----------------------------|\tDADOS DA CAMPANHA EM TEMPO REAL !!!\n");
        printf("\t|     1      |       FILA DE DOADORES      |\n");
        printf("\t|------------|-----------------------------|\n");
        printf("\t|     2      |      CADASTRO DE BRINDES    |\tDOAÇÕES : %i\n",totald);
        printf("\t|------------|-----------------------------|\n");
        printf("\t|     3      |       REALIZAR DOAÇÕES      |\tPARTICIPANTES NA FILA : %i\n",totalp);
        printf("\t|------------|-----------------------------|\n");
        printf("\t|     4      |      ESTOQUE DE DOAÇÕES     |\tTOTAL DE BRINDES CADASTRADOS : %i \n",totalL);
        printf("\t|------------|-----------------------------|\n");
        printf("\t|     5      |    HISTORICO DE DOADORES    |\n");
        printf("\t|------------|-----------------------------|\n");
        printf("\t|     6      |       GERAR RELATORIO       |\n");
        printf("\t|------------|-----------------------------|\n");
        printf("\t|     7      |       SAIR DO PROGRAMA      |\n");
        printf("\t|____________|_____________________________|\n");
        op=getch();

        switch(op)
        {
        case 49://TABELA ASCII -> 1.
            while(op!=0)
            {
                system("cls");
                printf("\n\n\tCAMPANHA DO AGASALHO!!\n");
                printf("\t __________________________________________\n");
                printf("\t|   OPÇÃO    |          FUNÇÕES            |\n");
                printf("\t|------------|-----------------------------|\n");
                printf("\t|     1      |    FILA DE DOADORES         |\n");
                printf("\t|------------|-----------------------------|\n");
                printf("\t|\t ____|_____________________________|_______\n");
                printf("\t|\t|   OPÇÃO    |          FUNÇÕES            |\n");
                printf("\t|\t|------------|-----------------------------|\n");
                printf("\t|\t|     1      |      CADASTRAR DOADOR       |\n");
                printf("\t|\t|------------|-----------------------------|\n");
                printf("\t|\t|     2      |      EXIBIR DOADORES        |\n");
                printf("\t|\t|------------|-----------------------------|\n");
                printf("\t|\t|     3      |      MENU PRINCIPAL         |\n");
                printf("\t|\t|____________|_____________________________|\n");
                printf("\t|____________|_____________________________|\n");
                op=getch();
                switch(op)
                {
                case 49://TABELA ASCII -> 1.
                    system("cls");
                    printf("\n\n\n");
                    printf("                                  \n");
                    printf("   DIGITE O NOME DA PESSOA  :       ");
                    fflush(stdin);
                    scanf(" %[^\n]",nomePessoa);
                    printf("\n\n\n");
                    printf("                                  \n");
                    printf("   DIGITE O CPF DA PESSOA  :       ");
                    fflush(stdin);
                    scanf(" %[^\n]",CPF);
                    printf("\n\n\n");
                    printf("                                  \n");
                    printf("   DIGITE O QUE DESEJA DOAR  :      ");
                    fflush(stdin);
                    scanf(" %[^\n]",doacao);
                    cadastrarPessoa(f,criarPessoa(nomePessoa, CPF, doacao));
                    totalp++;
                    break;
                case 50://TABELA ASCII -> 2.
                    system("cls");
                    exibirPessoas(f);
                    break;
                case 51://TABELA ASCII -> 3.
                    op = 0;
                    system("cls");
                    animacao();
                    break;
                default:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n");
                    printf("\t __________________________________________\n");
                    printf("\t|                                          |\n");
                    printf("\t|              OPÇÃO INVALIDA              |\n");
                    printf("\t|__________________________________________|\n\n");
                    printf("\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!\n");
                    getch();
                    system("cls");
                    animacao();
                    break;
                }
            }
            break;
        case 50://TABELA ASCII -> 2.
            while(op != 0)
            {
                system("cls");
                printf("\n\n\tCAMPANHA DO AGASALHO!!\n");
                printf("\t __________________________________________\n");
                printf("\t|   OPÇÃO    |          FUNÇÕES            |\n");
                printf("\t|------------|-----------------------------|\n");
                printf("\t|     1      |    FILA DE DOADORES         |\n");
                printf("\t|------------|-----------------------------|\n");
                printf("\t|     2      |    CADASTRO DE BRINDES      |\n");
                printf("\t|------------|-----------------------------|\n");
                printf("\t|\t ____|_____________________________|_______\n");
                printf("\t|\t|   OPÇÃO    |          FUNÇÕES            |\n");
                printf("\t|\t|------------|-----------------------------|\n");
                printf("\t|\t|     1      |      CADASTRAR LIVRO        |\n");
                printf("\t|\t|------------|-----------------------------|\n");
                printf("\t|\t|     2      |      EXIBIR LIVROS          |\n");
                printf("\t|\t|------------|-----------------------------|\n");
                printf("\t|_______|     3      |      MENU PRINCIPAL         |\n");
                printf("\t\t|____________|_____________________________|\n");
                op = getch();
                switch(op)
                {
                case 49://TABELA ASCII -> 1.
                    system("cls");
                    printf("\n\n\n");
                    printf("                                  \n");
                    printf("     DIGITE O NOME DO LIVRO :       ");
                    fflush(stdin);
                    scanf(" %[^\n]",nomeLivro);
                    printf("\n\n\n");
                    printf("                                  \n");
                    printf("      DIGITE O AUTOR DO LIVRO :     ");
                    fflush(stdin);
                    scanf(" %[^\n]",autor);
                    printf("\n\n\n");
                    printf("                                  \n");
                    printf("     DIGITE O ANO DO LIVRO :       ");
                    fflush(stdin);
                    scanf("%i",&ano);
                    cadastrarLivro(p, criarLivro(nomeLivro, ano, autor));
                    totalL++;
                    break;
                case 50://TABELA ASCII -> 2.
                    system("cls");
                    exibirLivros(p);
                    break;
                case 51://TABELA ASCII -> 3.
                    op = 0;
                    system("cls");
                    animacao();
                    break;
                default:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n");
                    printf("\t __________________________________________\n");
                    printf("\t|                                          |\n");
                    printf("\t|              OPÇÃO INVALIDA              |\n");
                    printf("\t|__________________________________________|\n\n");
                    printf("\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!\n");
                    getch();
                    system("cls");
                    animacao();
                    break;
                }
            }
            break;
        case 51://TABELA ASCII -> 3.
            system("cls");
            int aux = realizarDoacao(p,f,l);
            if(aux == 1)
            {
                totald++;
                totalp--;
                totalL--;
            }
            system("cls");
            break;
        case 52://TABELA ASCII -> 4.
            system("cls");
            estoqueDoacoes(l);
            break;
        case 53://TABELA ASCII -> 5.
            system("cls");
            historicoDoadores(l);
            break;
        case 54://TABELA ASCII -> 6.
            system("cls");
            animacao3();
            relatorio(l);
            gerou = 1;
            break;
        case 55://TABELA ASCII -> 7.
            liberaPilha(p);
            liberaFila(f);
            liberaLista(l);
            op = 1;
            system("cls");
            animacao1();
            if(gerou == 0 && totald != 0)
            {
                printf("\t _________________________________________________________________\n");
                printf("\t|                                                                 |\n");
                printf("\t|   POR FAVOR, GERE O RELATORIO SE NÃO SEUS DADOS SERÃO PERDIDOS! |\n");
                printf("\t|_________________________________________________________________|\n\n");
                printf("\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!");
                getch();
                op=0;
            }
            break;
        default:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n");
            printf("\t __________________________________________\n");
            printf("\t|                                          |\n");
            printf("\t|              OPÇÃO INVALIDA              |\n");
            printf("\t|__________________________________________|\n\n");
            printf("\tPRESSIONE QUALQUER TECLA PARA CONTINUAR   !!\n");
            getch();
            system("cls");
            animacao();
            break;
        }
    }
    cenacredito();
    return 0;
}
