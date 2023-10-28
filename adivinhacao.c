#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    // imprime cabecalho do jogo
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhacao *\n");
    printf("******************************************\n");

    int segundos = time(0);
    srand(segundos);

    int numeroGrande = rand();

    int numerosecreto = numeroGrande % 100;

    int chute;
    int tentativas = 1;
    int acertou = 0;
    double pontos = 1000;

    int nivelDificuldade;
    printf("Qual o nivel de dificuldade que voce deseja jogar?\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha:");
    scanf("%d", &nivelDificuldade);

    int numeroDeTentativas;

    switch (nivelDificuldade)
    {
    case 1:
        numeroDeTentativas = 20;
        break;

    case 2:
        numeroDeTentativas = 15;
        break;

    default:
        numeroDeTentativas = 6;
        break;
    }

    for (int i = 1; i <= numeroDeTentativas; i++)
    {

        printf("Tentativa %d\n", tentativas);
        printf("Qual o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0)
        {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if (acertou)
        {
            break;
        }

        else if (maior)
        {
            printf("Seu chute foi maior que o número secreto\n");
        }

        else
        {
            printf("Seu chute foi menor que o numero secreto\n");
        }

        tentativas++;

        double pontosperdidos = (abs)(chute - numerosecreto) / (double)2;

        pontos = pontos - pontosperdidos;
    }

    printf("Fim de jogo!\n");

    if (acertou)
    {
        
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");
        printf("Parabéns! Você ganhou!\n");
        printf("Voce acertou em %d tentativas\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    }
    else
    {
        printf("Você perdeu!Tente de novo!\n");
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
    }

    return 0;
}