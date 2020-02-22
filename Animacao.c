#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

//-> ANIMAÇÃO <-//

void cenacredito(void)
{
    int i ;
    char creditos[]="\t\t    CREDITOS :";
    char alunos[]="\n\n\t\tDESENVOLVEDORES :\n\n\n\tARIANE GABRIELA DE O. CAMPOS\n\n\tANA KAROLINY S. DE ARAUJO\n\n\tJOSEANNY DULCE S. SANTOS\n\n\tPAULO HENRIQUE M. B. DA SILVA";
    char professor[]="\n\n\t\tPROFESSOR :\n\n\tROBSON LOCATELLI MACEDO";
    char diciplina[]="\n\n\t\tDICIPLINA :\n\n\tALGORITMOS E ESTRUTURAS DE DADOS I\n\n\tLABORATORIO DE ALGORITMOS E ESTRUTURAS DE DADOS I\n\n\n";
    for(i=0; i<40; i++)
    {
        printf("\n");
    }
    printf("%s\n%s\n%s\n%s",creditos,alunos,professor,diciplina);
    for(i=0; i<30; i++)
    {
        Sleep(500);
        printf("\n");
    }
    system("cls");
}

void animacao(void)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tCARREGANDO");
        for(j=0; j<6; j++)
        {
            printf(".");
            Sleep(50);
        }
        Sleep(100);
        system("cls");
    }
}

void animacao1(void)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSAINDO");
        for(j=0; j<6; j++)
        {
            printf(".");
            Sleep(50);
        }
        Sleep(100);
        system("cls");
    }
}

void animacao2(void)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        printf("\n\n\n\n\tREALIZANDO DOAÇÃO");
        for(j=0; j<6; j++)
        {
            printf(".");
            Sleep(50);
        }
        Sleep(100);
        system("cls");
    }
}

void animacao3(void)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        printf("\n\n\n\n\tGERANDO RELATORIO");
        for(j=0; j<6; j++)
        {
            printf(".");
            Sleep(50);
        }
        Sleep(100);
        system("cls");
    }
}

void animacao5(void)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        printf("\n\n\n\n\tREMOVENDO LIVRO");
        for(j=0; j<6; j++)
        {
            printf(".");
            Sleep(50);
        }
        Sleep(100);
        system("cls");
    }
}

void animacao7(void)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        printf("\n\n\n\n\tREMOVENDO PESSOA");
        for(j=0; j<6; j++)
        {
            printf(".");
            Sleep(50);
        }
        Sleep(100);
        system("cls");
    }
}

void animacao8(void)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tVERIFICANDO");
        for(j=0; j<6; j++)
        {
            printf(".");
            Sleep(50);
        }
        Sleep(100);
        system("cls");
    }
}

void animacao9(void)
{
    printf("\n\n\n\n");
    printf("\t __________________________\n");
    printf("\t|                          |\n");
    printf("\t|       HISTORICO !!       |\n");
    printf("\t|__________________________|\n\n");
}
