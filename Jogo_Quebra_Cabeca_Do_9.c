/* DESCRI��O DO PROGRAMA: C�digo do programa do Jogo Das 8 Rainhas, que atrav�s de uma
   sequ�ncia l�gica dos numeros iniciais precisa-se manipular e raciocinar para atingir
   uma sequ�ncia l�gica final (Objetivo) proposto pelo usu�rio.


            PONTIF�CIA UNIVERSIDADE CAT�LICA DE CAMPINAS
            NOME DO ALUNO: MURILO DE PAULA ARAUJO
            RA: 17747775                       DATA DE ENTREGA: 17/12/2018
            PROFESSORA: �NGELA DE MENDON�A ENGELBRECHT
            CURSO: ENGENHARIA DE COMPUTA��O     PER�ODO: 2� SEMESTRE
            DISCIPLINA CURRICULAR: ALGOR�TMOS E PRGRAMA��O DE COMPUTADORES B

                    TRABALHO FINAL - "JOGO QUEBRA CABE�A DO 9"
*/

//################################# BIBLIOTECAS #################################

#include <stdlib.h>      // "Cabe�alho da Biblioteca de Prop�sito Geral Padr�o"
#include <stdio.h>       // "Cabe�alho Padr�o de (Entrada/Sa�da)"
#include <windows.h>     // "Utilizada para a Fun��o "Sleep"
#include <conio.h>       // "Utilizada para a Fun��o "Getche()" da Biblioteca
#define TamVet 9         // "Define a vari�vel "TamVet" como "9"

//###############################################################################


//################## PROT�TIPO DAS FUN��ES UTILIZADAS NA MAIN ###################

// FUN��O PARA MUDAR A COR DOS CAR�CTERES IMPRESSOS
void Muda_Cor (int cor);

// FUN��O PARA REFERENCIAR LINHAS E COLUNAS PARA IMPRESS�O
void Goto_xy (int lin, int col);

// FUN��O PARA IMPRIMIR O NOME DO JOGO
void Imprimir_Nome_Do_Jogo();

// FUN��O PARA IMPRIMIR O LOGO INCIAL DO JOGO
void Imprime_Logo();

//################### FUN��O PARA ESCOLHER ENTRE O JOGO 1 OU 2
int Escolher_Jogo();

// FUN��O PARA IMPRIMIR O CABE�ALHO INCIAL DO JOGO
void Impreme_Cabecalho_Inicial(int *Escolha);

// FUN��O PARA IMPRIMIR O CABE�ALHO DO JOGO
void Impreme_Cabecalho (int a, int b);

// FUN��O PARA IMPRIMIR MATRIZ QUE EST� SENDO JOGADA
void Imprime_Jogo (int linha_inicial, int col_inicial, int Vet[]);

// FUN��O PARA IMPRIMIR MATRIZ QUE EST� SENDO JOGADA COM O 9
void Imprime_Jogo_Com_9 (int linha_inicial, int col_inicial, int Vet[]);

// FUN��O PARA IMPRIMIR MATRIZ DO OBJETIVO
void Imprime_Objetivo (int linha_inicial, int col_inicial);

// FUN��O PARA IMPRIMIR MATRIZ DO OBJETIVO COM O 9
void Imprime_Objetivo_Com_9 (int linha_inicial, int col_inicial);

// FUN��O PARA "OBTER" UM N�MERO DE 0 A 9
int Busca_Numero (int Vet_Jogo[], int Vet_Acertos[], int Vet_Objetivo[], int a, int Tentativas, int T);

// FUN��O PARA TROCAR UM NUMERO OU CASA DE POSI��O
void Troca_Elementos (int vet[], int num, int i);

// FUN��O PARA VERIFICAR SE O OBJETIVO FOI ATINGIDO
int Verifica_Objetivo (int Vet_Jogo[], int n, int *b, int Vet_Acertos[]);

// FUN��O PARA ANALISAR NUMERO ESCOLHIDO E ALTERAR SUA POSICAO SE POSS�VEL
void Alterar_Posicoes (int Vet_Jogo[], int numero, int n, int *Tentativas);

// FUN��O PARA MOSTRAR O OBJETIVO PASSO A PASSO
void Mostrar_Objetivo_Passo_A_Passo (int Vet_Jogo[], int a);

// FUN��O PARA REINICIAR O GAME
void Reiniciar (int Vet_Inicial[], int Vet_Jogo[], int Vet_Acertos[], int *Obj, int *o, int *Tentativas);

// FUN��O PARA REINICIAR O GAME OU MOSTRAR A SOLU��O DO JOGO
void Verificar_Saida (int *Saida, int Caracter, int Tentativas, int *Escolha, int T);

// FUN��O PARA IMPRIMIR A SAIDA DO PROGRAMA
void Impressao_Saida();

// FUN��O PARA MOSTRAR O OBJETIVO PASSO A PASSO DO JOGO 2
void Mostrar_Objetivo_Passo_A_Passo_2 (int Vet_Jogo_2[], int a);

// FUN��O PARA VERIFICAR ESC
void Verificar_ESC (int *Escolha, int *Saida);
//###############################################################################

//#################################### MAIN #####################################
int main()
{
    int b;
    int Numero;
    int Objetivo;
    int n;
    int o;
    int Saida;
    int Tentativas;
    int Escolha;
    int Uma_vez;
    int T;


    Impreme_Cabecalho_Inicial(&Escolha);
    do
    {
        int Vet_Inicial [TamVet] = {5, 3, 7, 1, 4, 2, 8, 6, -1};
        int Vet_Jogo [TamVet] = {5, 3, 7, 1, 4, 2, 8, 6, -1};

        int Vet_Inicial_2 [TamVet] = {5, 1, 6, 7, 3, 8, 4, 2, -1};
        int Vet_Jogo_2 [TamVet] = {5, 1, 6, 7, 3, 8, 4, 2, -1};

        int Vet_Objetivo [TamVet] = {1, 2, 3, 4, 5, 6, 7, 8, -1};
        int Vet_Acertos [TamVet] = {0};

        Objetivo = 0;
        n = TamVet;
        o = 0;
        Saida = 115;
        Tentativas = 0;
        b=1;

        if(Escolha == 1)
        {
            T = 79;
            do
            {
                system("cls");
                Impreme_Cabecalho(o, b);
                Imprime_Jogo(20, 6, Vet_Jogo);
                Imprime_Objetivo(20, 31);
                Numero = Busca_Numero(Vet_Jogo, Vet_Acertos, Vet_Objetivo, o, Tentativas, T);

                if (Numero == 82 || Numero == 114) //Se numero for igual a r ou R na tabela ASCII
                    Reiniciar (Vet_Inicial, Vet_Jogo, Vet_Acertos, &Objetivo, &o, &Tentativas);

                if(Numero == 83 || Numero == 115) //Se numero for igual a s ou S na tabela ASCII
                {
                    Reiniciar (Vet_Inicial, Vet_Jogo, Vet_Acertos, &Objetivo, &o, &Tentativas);
                    Mostrar_Objetivo_Passo_A_Passo (Vet_Jogo, o);
                }

                Alterar_Posicoes (Vet_Jogo, Numero, n, &Tentativas);
                Objetivo = Verifica_Objetivo(Vet_Jogo, n, &o, Vet_Acertos);

                if (Numero == 27)  //Se numero for igual a esq na tabela ASCII
                {
                    Verificar_ESC (&Escolha, &Saida);
                    Objetivo = 1;
                }

            }
            while(Objetivo == 0 && Tentativas <= T);
        }
        else
        {
            T = 99;
            do
            {
                system("cls");
                Impreme_Cabecalho(o, b);
                Imprime_Jogo(20, 6, Vet_Jogo_2);
                Imprime_Objetivo(20, 31);
                Numero = Busca_Numero(Vet_Jogo_2, Vet_Acertos, Vet_Objetivo, o, Tentativas, T);

                if (Numero == 82 || Numero == 114) //Se numero for igual a r ou R na tabela ASCII
                    Reiniciar (Vet_Inicial_2, Vet_Jogo_2, Vet_Acertos, &Objetivo, &o, &Tentativas);

                if(Numero == 83 || Numero == 115) //Se numero for igual a s ou S na tabela ASCII
                {
                    Reiniciar (Vet_Inicial_2, Vet_Jogo_2, Vet_Acertos, &Objetivo, &o, &Tentativas);
                    Mostrar_Objetivo_Passo_A_Passo_2 (Vet_Jogo_2, o);
                }

                Alterar_Posicoes (Vet_Jogo_2, Numero, n, &Tentativas);
                Objetivo = Verifica_Objetivo(Vet_Jogo_2, n, &o, Vet_Acertos);

                if (Numero == 27)   //Se numero for igual a esq na tabela ASCII
                {
                    Verificar_ESC (&Escolha, &Saida);
                    Objetivo = 1;
                }
            }
            while(Objetivo == 0 && Tentativas <= T);
        }

        if (Numero > 48 && Numero < 56 && Tentativas < T)
        {
            system("cls");
            Impreme_Cabecalho(o, b);
            Imprime_Jogo_Com_9(20, 6, Vet_Jogo);
            Imprime_Objetivo_Com_9(20, 31);
        }
        if (Numero != 27)
        {
            Verificar_Saida (&Saida, Numero, Tentativas, &Escolha, T);
        }
    }
    while(Saida != 110 && Saida != 78);  //Se numero for igual a N ou n na tabela ASCII

    Impressao_Saida();
    return 0;
}
//###############################################################################


//############## FUN��O PARA MUDAR A COR DOS CAR�CTERES IMPRESSOS ###############
void Muda_Cor(int cor)
{
    /*
    0 = Preto		8 = Cinza
    1 = Azul		9 = Azul Claro
    2 = Verde		10 = Verde Claro
    3 = Verde-Agua	11= Verde-Agua Claro
    4 = Vermelho	12 = Vermelho Claro
    5 = Roxo		13 = Lilas
    6 = Amarelo		14 = Amarelo Claro
    7 = Branco		15 = Branco Brilhante
    */
    HANDLE Saida;
    Saida = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Saida,cor);
}
//###############################################################################


//########### FUN��O PARA REFERENCIAR LINHAS E COLUNAS PARA IMPRESS�O ###########
void Goto_xy(int lin, int col)
{
    HANDLE Saida;

    COORD Posicao;

    Saida = GetStdHandle(STD_OUTPUT_HANDLE);

    Posicao.X = col;
    Posicao.Y = lin;

    SetConsoleCursorPosition(Saida, Posicao);
}
//###############################################################################

//##################### FUN��O PARA IMPRIMIR O NOME DO JOGO #####################
void Imprimir_Nome_Do_Jogo()
{
    Muda_Cor(9);
    printf("\n \332\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\277");
    printf("\n \263     *****  *   * ***** ****  **** *****      \263");
    printf("\n \263     *   *  *   * *     *   * *  * *   *      \263");
    printf("\n \263     * * *  *   * ***** ****  **** *****      \263");
    printf("\n \263     *  **  *   * *     *   * * *  *   *      \263");
    printf("\n \263     ****** ***** ***** ****  *  * *   *      \263");
    printf("\n \300\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\331");

    Muda_Cor(12);
    printf("\n\n \332\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\277");
    printf("\n \263 ***** ***** ****  ***** ***** *****    ***** \263");
    printf("\n \263 *     *   * *   * *     *     *   *    *   * \263");
    printf("\n \263 *     ***** ****  ***** *     *****    ***** \263");
    printf("\n \263 *     *   * *   * *     *     *   *        * \263");
    printf("\n \263 ***** *   * ****  ***** ***** *   *    ***** \263");
    printf("\n \300\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\331");
}
//###############################################################################


//################## FUN��O PARA IMPRIMIR O LOGO INCIAL DO JOGO #################
void Imprime_Logo()
{
    system("cls");

    Muda_Cor(10);
    printf("\n\n \332\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\277");
    printf("\n \263");
    Muda_Cor(9);
    printf("    CRIADOR DO ALGORITMO DO JOGO      RA      ");
    Muda_Cor(10);
    printf("\263");
    printf("\n \263");
    Muda_Cor(12);
    printf("       MURILO DE PAULA ARAUJO      17747775   ");
    Muda_Cor(10);
    printf("\263");
    printf("\n \300\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304");
    printf("\304\304\304\304\304\304\304\304\304\304\304\304\331\n");

    Imprimir_Nome_Do_Jogo();
}
//###############################################################################

//################### FUN��O PARA ESCOLHER ENTRE O JOGO 1 OU 2 ##################
int Escolher_Jogo()
{
    int Escolha;
    Escolha = 0;

    do
    {
        Escolha = getch();

        if (Escolha == 49)
        {
            Imprime_Logo();
            Muda_Cor(10);
            printf("\n\n\n\n SELECIONE A TECLA 1 PARA JOGAR O PUZZLE MAIS FACIL!!!");
            Muda_Cor(12);
            printf("\n\n OU SELECIONE A TECLA 2 PARA JOGAR O PUZZLE MAIS DIFICIL!!!");
            Sleep(500);
            Imprime_Logo();
            Muda_Cor(9);
            printf("\n\n\n\n SELECIONE A TECLA 1 PARA JOGAR O PUZZLE MAIS FACIL!!!");
            Muda_Cor(12);
            printf("\n\n OU SELECIONE A TECLA 2 PARA JOGAR O PUZZLE MAIS DIFICIL!!!");
            Sleep(500);
        }

        if (Escolha == 50)
        {
            Imprime_Logo();
            Muda_Cor(9);
            printf("\n\n\n\n SELECIONE A TECLA 1 PARA JOGAR O PUZZLE MAIS FACIL!!!");
            Muda_Cor(10);
            printf("\n\n OU SELECIONE A TECLA 2 PARA JOGAR O PUZZLE MAIS DIFICIL!!!");
            Sleep(500);
            Imprime_Logo();
            Muda_Cor(9);
            printf("\n\n\n\n SELECIONE A TECLA 1 PARA JOGAR O PUZZLE MAIS FACIL!!!");
            Muda_Cor(12);
            printf("\n\n OU SELECIONE A TECLA 2 PARA JOGAR O PUZZLE MAIS DIFICIL!!!");
            Sleep(500);
        }
    }
    while(Escolha != 49 && Escolha != 50);

    Escolha = (Escolha - 48);

    return Escolha;
}
//###############################################################################

//############### FUN��O PARA IMPRIMIR O CABE�ALHO INCIAL DO JOGO ###############
void Impreme_Cabecalho_Inicial(int *Escolha)
{
    int Caracter;

    do
    {
        Imprime_Logo();
        Muda_Cor(10);
        printf("\n\n OBJETIVO: ");
        printf("ATRAVES DE UMA SEQUENCIA LOGICA DOS NUMEROS \n\t   ");
        printf("INICIAIS, PRECISA-SE ESTAR RACIOCINANDO E \n\t   ");
        printf("MANIPULANDO OS NUMEROS COM AS SETAS DO \n\t   ");
        printf("TECLADO OU SELECAO DE CADA NUMERO, PARA \n\t   ");
        printf("OBTER OU ATINGIR UMA SEQUENCIA LOGICA FINAL \n\t   ");
        printf("(OBJETIVO) PROPOSTO PELO USUARIO, NO QUAL \n\t   ");
        printf("SE ENCONTRA AO LADO DO JOGO QUE O USUARIO \n\t   ");
        printf("ESTARA JOGANDO!!!");

        Muda_Cor(12);
        printf("\n\n\n\n SELECIONE 'R' OU 'r' PARA REINICIAR O JOGO!!!");
        Muda_Cor(9);
        printf("\n SELECIONE 'S' OU 's' PARA VER A SOLUCAO DO OBJETIVO DO JOGO!");
        Muda_Cor(14);
        printf("\n SELECIONE A TECLA 'ESC' PARA SAIR DO JOGO");
        Muda_Cor(11);
        printf("\n\n            QUANDO ESTIVER PRONTO(A), ");
        printf("\n     PRESSIONE ENTER PARA INICIALIZAR O PUZZLE!");

        Caracter = getch();
        Muda_Cor(7);

    }
    while (Caracter != 13);
    Imprime_Logo();

    Muda_Cor(14);
    printf("\n\n\n\n\t\tNAO SE ESQUECA!!!\n\n");

    Muda_Cor(9);
    printf("\n\n PRESSIONE A LETRA");

    Muda_Cor(12);
    printf(" S ");

    Muda_Cor(9);
    printf("PARA VER A SOLUCAO DO JOGO!");

    Muda_Cor(12);
    printf("\n OU PRESSIONE A LETRA");

    Muda_Cor(9);
    printf(" R ");

    Muda_Cor(12);
    printf("PARA REINICIAR O JOGO!\n\n\n");
    Sleep(10000);

    Imprime_Logo();

    Muda_Cor(9);
    printf("\n\n\n\n SELECIONE A TECLA 1 PARA JOGAR O PUZZLE MAIS FACIL!!!");

    Muda_Cor(12);
    printf("\n\n OU SELECIONE A TECLA 2 PARA JOGAR O PUZZLE MAIS DIFICIL!!!");

    *Escolha = Escolher_Jogo();
}
//###############################################################################


//################## FUN��O PARA IMPRIMIR O CABE�ALHO DO JOGO ###################
void Impreme_Cabecalho(int a, int b)
{
    Imprimir_Nome_Do_Jogo();

    if(b==1)
    {
        Muda_Cor(10);
        printf("\n\n\n\t\t    QUANTIDADE");
    }
    else
        printf("\n\n\n\t\t              ");

    Muda_Cor(9);
    printf("\n\t  PUZZLE");
    Muda_Cor(10);
    if(b==1)
        printf("    DE NUMEROS");
    else
        printf("              ");

    Muda_Cor(12);
    printf("   OBJETIVO!");
    Muda_Cor(10);
    if(b==1)
    {
        printf("\n\t\t     NA CASA");
        printf("\n\t\t     CORRETA:");
    }

    if(a==0)
    {
        printf("\n\t\t      \332\304\304\304\304\277\n\t\t      "); //ZERO
        printf("\263    \263\n\t\t      \263    \263\n\t\t      "); //ZERO
        printf("\263    \263\n\t\t      \300\304\304\304\304\331"); //ZERO
    }
    else
    {
        if(a==1)
        {
            printf("\n\t\t        /\263\n\t\t       / \263\n\t\t\t \263"); //UM
            printf("\n\t\t\t \263\n\t\t       \304\304\301\304\304");      //UM
        }
        else
        {
            if(a==2)
            {
                printf("\n\t\t      \304\304\304\304\304\277\n\t\t\t   ");    // DOIS
                printf("\263\n\t\t      \332\304\304\304\304\331\n\t\t");     // DOIS
                printf("      \263\t\t\n\t\t      \300\304\304\304\304\304"); // DOIS
            }
            else
            {
                if(a==3)
                {
                    printf("\n\t\t      \304\304\304\304\304\277\n\t\t\t   ");   // TR�S
                    printf("\263\n\t\t      \304\304\304\304\304\264\n\t\t\t");  // TR�S
                    printf("   \263\n\t\t      \304\304\304\304\304\331");       // TR�S
                }
                else
                {
                    if(a==4)
                    {
                        printf("\n\t\t      \263    \263\n\t\t      ");     // QUATRO
                        printf("\263    \263\n\t\t      \300\304\304\304"); // QUATRO
                        printf("\304\264\n\t\t\t   \263\n\t\t\t   \263");   // QUATRO
                    }
                    else
                    {
                        if(a==5)
                        {
                            printf("\n\t\t      \332\304\304\304\304\304\n\t\t      "); // CINCO
                            printf("\263\n\t\t      \300\304\304\304\304\277\n\t\t\t"); // CINCO
                            printf("   \263\n\t\t      \304\304\304\304\304\331");      // CINCO
                        }
                        else
                        {
                            if(a==6)
                            {
                                printf("\n\t\t      \332\304\304\304\304\304\n\t\t      ");   // SEIS
                                printf("\263\n\t\t      \303\304\304\304\304\277\n\t\t    "); // SEIS
                                printf("  \263    \263\n\t\t      \300\304\304\304\304\331"); // SEIS
                            }
                            else
                            {
                                if(a==7)
                                {
                                    printf("\n\t\t     \304\304\304\304\304\277");    // SETE
                                    printf("\n\t\t\t  \263\n\t\t\t\304\304\305\304"); // SETE
                                    printf("\304\n\t\t\t  \263\n\t\t\t  \263");         //SETE
                                }
                                else
                                {
                                    if(a==8)
                                    {
                                        printf("\n\t\t      \332\304\304\304\304\277\n\t\t      \263"); // OITO
                                        printf("    \263\n\t\t      \303\304\304\304\304\264\n\t\t  "); // OITO
                                        printf("    \263    \263\n\t\t      \300\304\304\304\304\331"); // OITO
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
//###############################################################################


//############# FUN��O PARA IMPRIMIR MATRIZ QUE EST� SENDO JOGADA ###############
void Imprime_Jogo(int linha_inicial, int col_inicial, int Vet[])
{
    int l = linha_inicial;
    int c = col_inicial;

    Muda_Cor(9);
    Goto_xy(l,c);
    printf("\332\304\304\304\302\304\304\304\302\304\304\304\277");
    Goto_xy(l+1,c);

    if(Vet[0] == (-1))
        printf("\263   \263 %d \263 %d \263", Vet[1], Vet[2]);
    else
    {
        if(Vet[1] == (-1))
            printf("\263 %d \263   \263 %d \263", Vet[0], Vet[2]);
        else
        {
            if(Vet[2] == (-1))
                printf("\263 %d \263 %d \263   \263", Vet[0], Vet[1]);
            else
            {
                printf("\263 %d \263 %d \263 %d \263", Vet[0], Vet[1], Vet[2]);
            }
        }
    }


    Goto_xy(l+2,c);
    printf("\303\304\304\304\305\304\304\304\305\304\304\304\264");

    Goto_xy(l+3,c);
    if(Vet[3] == (-1))
        printf("\263   \263 %d \263 %d \263", Vet[4], Vet[5]);

    else
    {
        if(Vet[4] == (-1))
            printf("\263 %d \263   \263 %d \263", Vet[3], Vet[5]);

        else
        {
            if(Vet[5] == (-1))
                printf("\263 %d \263 %d \263   \263", Vet[3], Vet[4]);

            else
            {
                printf("\263 %d \263 %d \263 %d \263", Vet[3], Vet[4], Vet[5]);
            }
        }
    }


    Goto_xy(l+4,c);
    printf("\303\304\304\304\305\304\304\304\305\304\304\304\264");

    Goto_xy(l+5,c);
    if(Vet[6] == (-1))
        printf("\263   \263 %d \263 %d \263", Vet[7], Vet[8]);

    else
    {
        if(Vet[7] == (-1))
            printf("\263 %d \263   \263 %d \263", Vet[6], Vet[8]);

        else
        {
            if(Vet[8] == (-1))
                printf("\263 %d \263 %d \263   \263", Vet[6], Vet[7]);

            else
            {
                printf("\263 %d \263 %d \263 %d \263", Vet[6], Vet[7], Vet[8]);
            }
        }
    }


    Goto_xy(l+6,c);
    printf("\300\304\304\304\301\304\304\304\301\304\304\304\331");
}
//###############################################################################

//######### FUN��O PARA IMPRIMIR MATRIZ QUE EST� SENDO JOGADA COM O 9 ###########
void Imprime_Jogo_Com_9 (int linha_inicial, int col_inicial, int Vet[])
{
    int l = linha_inicial;
    int c = col_inicial;

    Muda_Cor(9);

    Goto_xy(l,c);
    printf("\332\304\304\304\302\304\304\304\302\304\304\304\277");

    Goto_xy(l+1,c);
    printf("\263 1 \263 2 \263 3 \263");

    Goto_xy(l+2,c);
    printf("\303\304\304\304\305\304\304\304\305\304\304\304\264");

    Goto_xy(l+3,c);
    printf("\263 4 \263 5 \263 6 \263");

    Goto_xy(l+4,c);
    printf("\303\304\304\304\305\304\304\304\305\304\304\304\264");

    Goto_xy(l+5,c);
    printf("\263 7 \263 8 \263 9 \263");

    Goto_xy(l+6,c);
    printf("\300\304\304\304\301\304\304\304\301\304\304\304\331");
}
//###############################################################################


//################## FUN��O PARA IMPRIMIR MATRIZ DO OBJETIVO ####################
void Imprime_Objetivo(int linha_inicial, int col_inicial)
{
    int l = linha_inicial;
    int c = col_inicial;

    Muda_Cor(12);

    Goto_xy(l,c);
    printf("\332\304\304\304\302\304\304\304\302\304\304\304\277");

    Goto_xy(l+1,c);
    printf("\263 1 \263 2 \263 3 \263");

    Goto_xy(l+2,c);
    printf("\303\304\304\304\305\304\304\304\305\304\304\304\264");

    Goto_xy(l+3,c);
    printf("\263 4 \263 5 \263 6 \263");

    Goto_xy(l+4,c);
    printf("\303\304\304\304\305\304\304\304\305\304\304\304\264");

    Goto_xy(l+5,c);
    printf("\263 7 \263 8 \263   \263");

    Goto_xy(l+6,c);
    printf("\300\304\304\304\301\304\304\304\301\304\304\304\331");
}
//###############################################################################

//############## FUN��O PARA IMPRIMIR MATRIZ DO OBJETIVO COM O 9 ################
void Imprime_Objetivo_Com_9 (int linha_inicial, int col_inicial)
{
    int l = linha_inicial;
    int c = col_inicial;

    Muda_Cor(12);

    Goto_xy(l,c);
    printf("\332\304\304\304\302\304\304\304\302\304\304\304\277");

    Goto_xy(l+1,c);
    printf("\263 1 \263 2 \263 3 \263");

    Goto_xy(l+2,c);
    printf("\303\304\304\304\305\304\304\304\305\304\304\304\264");

    Goto_xy(l+3,c);
    printf("\263 4 \263 5 \263 6 \263");

    Goto_xy(l+4,c);
    printf("\303\304\304\304\305\304\304\304\305\304\304\304\264");

    Goto_xy(l+5,c);
    printf("\263 7 \263 8 \263 9 \263");

    Goto_xy(l+6,c);
    printf("\300\304\304\304\301\304\304\304\301\304\304\304\331");
}
//###############################################################################


//################## FUN��O PARA "OBTER" UM N�MERO DE 0 A 9 #####################
int Busca_Numero(int Vet_Jogo[], int Vet_Acertos[], int Vet_Objetivo[], int a, int Tentativas, int T)
{
    int Caracter;
    int i;
    int b;

    Caracter = 0;
    b=1;

    do
    {
        system("cls");
        Impreme_Cabecalho(a, b);
        Imprime_Jogo (20, 6, Vet_Jogo);
        Imprime_Objetivo (20, 31);

        Muda_Cor(14);
        printf("\n\n\n\n NUMEROS QUE ESTAO NA CASA CORRETA: ");

        for(i=0; i<9; i++)
        {
            if(Vet_Acertos[i] != 0)
                printf(" %d", Vet_Acertos[i]);
        }

        Muda_Cor(12);
        printf("\n\n QUANTIDADE DE TENTATIVAS ( %d / %d )", Tentativas, (T+1));

        Muda_Cor(9);
        printf("\n\n ESCOLHA UMA CASA (NUMERO): ");
        Caracter = getch();



        if (Caracter == 82 || Caracter == 114)
        {
            return Caracter;
        }
        else
        {
            if (Caracter == 83 || Caracter == 115)
            {
                return Caracter;
            }
            else
            {
                if (Caracter == 27)
                    return Caracter;
            }
        }

    }
    while(Caracter < 48 || Caracter > 56);

    Caracter = (Caracter-48);
    return Caracter;
}
//###############################################################################


//############## FUN��O PARA TROCAR UM NUMERO OU CASA DE POSI��O ################
void Troca_Elementos (int vet[], int num, int i)
{
    int aux;

    aux = vet[num];
    vet[num] = vet[i];
    vet[i] = aux;
}
//###############################################################################


//############# FUN��O PARA VERIFICAR SE O OBJETIVO FOI ATINGIDO ################
int Verifica_Objetivo(int Vet[], int n, int *b, int Vet_Acertos[])
{
    int i;
    int d=0;
    *b=0;
    for(i=0; i<n; i++)
    {
        Vet_Acertos[i] = 0;
    }
    for(i=0; i<n; i++)
    {
        if(Vet[i] ==  (i+1))
        {
            Vet_Acertos[d] = Vet[i];
            d++;
        }
    }

    *b = d;
    if (*b>=8)
        return 1;
    else
        return 0;
}
//###############################################################################


//## FUN��O PARA ANALISAR NUMERO ESCOLHIDO E ALTERAR SUA POSICAO SE POSS�VEL ####
void Alterar_Posicoes (int Vet_Jogo[], int numero, int n, int *Tentativas)
{
    int i;
    int num;

    for(i=0; (i<n); i++)
    {
        if(numero == Vet_Jogo[i])
            num = i;
    }

    switch(num)
    {

    case 0:
        if (Vet_Jogo[1] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 1);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[3] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 3);
            *Tentativas = (*Tentativas+1);
        }
        break;

    case 1:
        if (Vet_Jogo[0] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 0);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[2] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 2);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[4] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 4);
            *Tentativas = (*Tentativas+1);
        }
        break;

    case 2:
        if (Vet_Jogo[1] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 1);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[5] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 5);
            *Tentativas = (*Tentativas+1);
        }
        break;

    case 3:
        if (Vet_Jogo[0] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 0);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[4] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 4);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[6] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 6);
            *Tentativas = (*Tentativas+1);
        }
        break;

    case 4:
        if (Vet_Jogo[1] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 1);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[3] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 3);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[5] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 5);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[7] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 7);
            *Tentativas = (*Tentativas+1);
        }
        break;

    case 5:
        if (Vet_Jogo[2] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 2);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[4] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 4);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[8] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 8);
            *Tentativas = (*Tentativas+1);
        }
        break;

    case 6:
        if (Vet_Jogo[3] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 3);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[7] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 7);
            *Tentativas = (*Tentativas+1);
        }
        break;

    case 7:
        if (Vet_Jogo[4] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 4);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[6] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 6);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[8] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 8);
            *Tentativas = (*Tentativas+1);
        }
        break;

    case 8:
        if (Vet_Jogo[5] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 5);
            *Tentativas = (*Tentativas+1);
        }

        if (Vet_Jogo[7] == -1)
        {
            Troca_Elementos (Vet_Jogo, (num), 7);
            *Tentativas = (*Tentativas+1);
        }
        break;
    }
}
//###############################################################################

//############### FUN��O PARA MOSTRAR O OBJETIVO PASSO A PASSO ##################
void Mostrar_Objetivo_Passo_A_Passo (int Vet_Jogo[], int a)
{
    int b;
    b=0;

    system("cls");
    Impreme_Cabecalho(a, b);
    Imprime_Jogo(20, 6, Vet_Jogo);
    Imprime_Objetivo(20, 31);

    Imprime_Jogo(20, 6, Vet_Jogo);
    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 7, 8);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 4, 7);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 5, 4);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 2, 5);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 1, 2);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 4, 1);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 5, 4);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 2, 5);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 1, 2);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 0, 1);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 3, 0);
    Imprime_Jogo(20, 6, Vet_Jogo);


    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 4, 3);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 1, 4);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 2, 1);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 5, 2);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 4, 5);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 7, 4);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 6, 7);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 3, 6);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 4, 3);
    Imprime_Jogo(20, 6, Vet_Jogo);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo, 5, 4);
    Imprime_Jogo(20, 6, Vet_Jogo);
    Sleep(1000);

    Troca_Elementos(Vet_Jogo, 8, 5);
    Imprime_Jogo(20, 6, Vet_Jogo);
    Sleep(1000);

    Imprime_Jogo_Com_9(20, 6, Vet_Jogo);
    Imprime_Objetivo_Com_9 (20, 31);
    Sleep(300);

    printf("\n\n");
}
//###############################################################################

//########## FUN��O PARA REINICIAR O GAME OU MOSTRAR A SOLU��O DO JOGO ##########
void Reiniciar (int Vet_Inicial[], int Vet_Jogo[], int Vet_Acertos[], int *Obj, int *o, int *Tentativas)
{
    int i = 0;
    *Obj = 0;
    *o = 0;
    *Tentativas = 0;

    for (i = 0; i < TamVet; i++)
    {
        Vet_Acertos [i] = 0;
    }

    for (i = 0; i < TamVet; i++)
    {
        Vet_Jogo[i] = Vet_Inicial[i];
    }
}
//###############################################################################

//######################### FUN��O PARA VERIFICAR SAIDA #########################
void Verificar_Saida (int *Saida, int Caracter, int Tentativas, int *Escolha, int T)
{
    Sleep(2000);
    if(Caracter == 83 || Caracter == 115) //Se caso a pessoa optar pela solu��o
    {
        do
        {
            system("cls");

            Imprimir_Nome_Do_Jogo();

            Muda_Cor(10);
            printf("\n\n\n   AGORA QUE JA VIU A SOLUCAO FICA MAIS FACIL!!!");
            printf("\n\t TENTE VOCE SOZINHO(A) AGORA!!!");

            Muda_Cor(12);
            printf("\n\n\n    DESEJA JOGAR O JOGO NOVAMENTE? <S ou N> ?");

            *Saida = getch();
        }
        while(*Saida != 78 && *Saida != 110 && *Saida != 83 && *Saida != 115);

    }

    else
    {
        if(Caracter > 48 || Caracter < 56 && Tentativas < T)
        {

            do
            {
                system("cls");

                Imprimir_Nome_Do_Jogo();

                Muda_Cor(9);
                printf("\n\n   O OBJETIVO DO JOGO FOI CONCLUIDO COM EXITO!!!\n");

                Muda_Cor(14);
                printf("\n\t           ___________      \n");
                printf("\t           '._==_==_=_.'     \n");
                printf("\t           .-\\:      /-.    \n");
                printf("\t          | (|:.     |) |    \n");
                printf("\t           '-|:.     |-'     \n");
                printf("\t             \\::.    /      \n");
                printf("\t              '::. .'        \n");
                printf("\t                ) (          \n");
                printf("\t              _.' '._        \n");
                printf("\t             '-------'       \n\n");

                Muda_Cor(12);
                printf("\n\n    DESEJA JOGAR O JOGO NOVAMENTE? <S ou N> ?");

                *Saida = getch();
            }
            while(*Saida != 78 && *Saida != 110 && *Saida != 83 && *Saida != 115);
        }

        else
        {
            if (Tentativas >= T)
            {

                do
                {
                    system("cls");

                    Imprimir_Nome_Do_Jogo();

                    Muda_Cor(10);
                    printf("\n\n\n\n\n   VOCE EXCEDEU O NUMERO MAXIMO DE TENTATIVAS!!!");
                    printf("\n  MAS NAO DESISTA ACREDITAMOS NA SUA CAPACIDADE!!!");

                    Muda_Cor(12);
                    printf("\n\n\n\n\n    DESEJA JOGAR O JOGO NOVAMENTE? <S ou N> ?");

                    *Saida = getch();
                }
                while(*Saida != 78 && *Saida != 110 && *Saida != 83 && *Saida != 115);
            }
        }
    }

    if (*Saida == 83 || *Saida == 115)
    {
        Imprime_Logo();
        Muda_Cor(9);
        printf("\n\n\n\n SELECIONE A TECLA 1 PARA JOGAR O PUZZLE MAIS FACIL!!!");
        Muda_Cor(12);
        printf("\n\n OU SELECIONE A TECLA 2 PARA JOGAR O PUZZLE MAIS DIFICIL!!!");

        *Escolha = Escolher_Jogo();
    }
}

//################## FUN��O PARA IMPRIMIR A SAIDA DO PROGRAMA ###################
void Impressao_Saida()
{
    system("cls");

    Imprimir_Nome_Do_Jogo();

    Muda_Cor(10);
    printf("\n\n\n\n    AGRADECEMOS POR TER JOGADO O NOSSO JOGO!!!");
    printf("\n       ESPERAMOS QUE TENHA GOSTADO DO JOGO");
    printf("\n             E POSSA JOGAR NOVAMENTE!!!\n\n\n\n\n\n");
    Muda_Cor(7);
}
//###############################################################################


//########### FUN��O PARA MOSTRAR O OBJETIVO PASSO A PASSO DO JOGO 2 ############
void Mostrar_Objetivo_Passo_A_Passo_2 (int Vet_Jogo_2[], int a)
{
    int b;
    b=0;

    system("cls");
    Impreme_Cabecalho(a, b);
    Imprime_Jogo(20, 6, Vet_Jogo_2);
    Imprime_Objetivo(20, 31);

    Imprime_Jogo(20, 6, Vet_Jogo_2);
    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 5, 8);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 4, 5);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 7, 4);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 6, 7);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 3, 6);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 0, 3);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 1, 0);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 4, 1);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 3, 4);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 0, 3);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 1, 0);
    Imprime_Jogo(20, 6, Vet_Jogo_2);


    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 2, 1);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 5, 2);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 4, 5);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 1, 4);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 0, 1);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 3, 0);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 4, 3);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 7, 4);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 6, 7);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 3, 6);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 4, 3);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 5, 4);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 8, 5);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 7, 8);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 6, 7);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 3, 6);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 4, 3);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 7, 4);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 8, 7);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 5, 8);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 4, 5);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 3, 4);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 6, 3);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 7, 6);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Troca_Elementos(Vet_Jogo_2, 8, 7);
    Imprime_Jogo(20, 6, Vet_Jogo_2);

    Sleep(1000);
    Imprime_Jogo_Com_9(20, 6, Vet_Jogo_2);
    Imprime_Objetivo_Com_9 (20, 31);
    Sleep(300);

    printf("\n\n");
}
//###############################################################################

//########################## FUN��O PARA VERIFICAR ESC ##########################
void Verificar_ESC (int *Escolha, int *Saida)
{
    Imprime_Logo();
    int Caracter;

    do
    {
        Muda_Cor(9);
        printf("\n\n\n\n\n\n    PRESSIONE");
        Muda_Cor(12);
        printf(" S ");
        Muda_Cor(9);
        printf("PARA CONFIRMAR SUA SAIDA DO GAME");

        Muda_Cor(12);
        printf("\n\n OU PRESSIONE");
        Muda_Cor(9);
        printf(" M ");
        Muda_Cor(12);
        printf("PARA SER DIRECIONADO AO MENU DE ESCOLHA");

        Caracter = getch();
    }
    while (Caracter != 77 && Caracter != 109 && Caracter != 83 && Caracter != 115);

    if(Caracter == 77 || Caracter == 109)
    {
        Imprime_Logo();
        Muda_Cor(9);
        printf("\n\n\n\n SELECIONE A TECLA 1 PARA JOGAR O PUZZLE MAIS FACIL!!!");
        Muda_Cor(12);
        printf("\n\n OU SELECIONE A TECLA 2 PARA JOGAR O PUZZLE MAIS DIFICIL!!!");

        *Escolha = Escolher_Jogo();
        *Saida = 115;
    }
    else
    {
        *Saida = 110;
    }
}
//###############################################################################

