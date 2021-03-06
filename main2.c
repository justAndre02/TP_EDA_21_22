/**
 * @file main2.c
 * @author André (a21112@alunos.ipca.pt)
 * @brief Menu responsável por chamar as funções  da fase 2
 * @version 0.1
 * @date 2022-06-01
 *
 * Main que chama todas as funções criadas no ficheiro "functions2.c"
 * Contém um menu interativo básico
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>

#include "functions2.h"

int main()
{
    Job *lista = NULL;

    Cel plano[M][T];

    FILE *ficheiro;
    int opc = 0;
    int jId;
    int oId;
    int mId;
    int tId;
    int nova;
    int inicio;
    int final;

    while (true)
    {
        SetConsoleOutputCP(65001);
        printf("\n----------------------MENU----------------------");
        printf("\n1 - INSERIR JOB");
        printf("\n2 - REMOVER JOB");
        printf("\n3 - INSERIR OPERAÇÃO NUM JOB");
        printf("\n4 - REMOVER OPERAÇÃO DE UM JOB");
        printf("\n5 - ALTERAR OPERAÇÃO DE UM JOB");
        printf("\n6 - PROPOSTA DE ESCALONAMENTO");
        printf("\n7 - LEITURA DOS DADOS");
        printf("\n\nSELECIONE A SUA OPÇÃO: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            printf("!Escreva todos os campos!\n");
            lista = CriaJob(lista, 1);
            printf("Insira um Job: ");
            scanf("%d,%d,%d,%d", &jId, &oId, &mId, &tId);
            lista = InsereJob(lista, jId, oId, mId, tId);

            lista = CriaJob(lista, 2);
            printf("Insira um Job: ");
            scanf("%d,%d,%d,%d", &jId, &oId, &mId, &tId);
            lista = InsereJob(lista, jId, oId, mId, tId);

            lista = CriaJob(lista, 3);
            printf("Insira um Job: ");
            scanf("%d,%d,%d,%d", &jId, &oId, &mId, &tId);
            lista = InsereJob(lista, jId, oId, mId, tId);

            lista = CriaJob(lista, 4); 
            printf("Insira um Job: ");
            scanf("%d,%d,%d,%d", &jId, &oId, &mId, &tId);
            lista = InsereJob(lista, jId, oId, mId, tId);

            EscreveFicheiro(lista);
            ListaJob(lista);
            break;

        case 2:
            ListaJob(lista);
            printf("\nQual Job deseja remover: ");
            scanf("%d", &jId);
            RemoverJob(lista, jId);
            ListaJob(lista);
            break;

        case 3:
            ListaJob(lista);
            printf("Em qual Job deseja inserir a operação: ");
            scanf("%d", &jId);
            lista = CriaJob(lista, jId);
            printf("!Escreva todos os campos!\n");
            printf("Insira a operação: ");
            scanf("%d,%d,%d", &oId, &mId, &tId);
            lista = InsereJob(lista, jId, oId, mId, tId);
            EscreveFicheiro(lista);
            ListaJob(lista);
            break;

        case 4:
            printf("Escolha um Job: ");
            scanf("%d", &jId);
            printf("\nRemova a operação desejada: ");
            scanf("%d", &oId);
            RemoverOperacao(lista, jId, oId);
            EscreveFicheiro(lista);
            ListaJob(lista);
            break;

        case 5:
            printf("O que deseja alterar numa operação?\n");
            printf("1 - Id da Operação\n");
            printf("2 - Maquina\n");
            printf("3 - Tempo\n");
            printf("Escolha: ");
            scanf("%d", &opc);
            if (opc == 1){
                printf("Escolha o Job da operação a alterar: ");
                scanf("%d", &jId);
                printf("Escolha a operação a alterar: ");
                scanf("%d", &oId);
                printf("Escolha a nova operação: ");
                scanf("%d", &nova);
                EditarOperacao(lista, jId, oId, nova);
                EscreveFicheiro(lista);
                ListaJob(lista);
            }else if (opc == 2){
                printf("Escolha o Job da operação a alterar: ");
                scanf("%d", &jId);
                printf("Escolha a operação da máquina a alterar: ");
                scanf("%d", &oId);
                printf("Escolha a máquina a alterar: ");
                scanf("%d", &mId);
                printf("Escolha a nova máquina: ");
                scanf("%d", &nova);
                EditarMaquina(lista, jId, oId, mId, nova);
                EscreveFicheiro(lista);
                ListaJob(lista);
            }else if (opc == 3){
                printf("Escolha o Job da operação a alterar: ");
                scanf("%d", &jId);
                printf("Escolha a operação da máquina a alterar: ");
                scanf("%d", &oId);
                printf("Escolha a máquina do tempo a alterar: ");
                scanf("%d", &mId);
                printf("Escolha a novo tempo: ");
                scanf("%d", &nova);
                EditarTempo(lista, jId, oId, mId, nova);
                EscreveFicheiro(lista);
                ListaJob(lista);
            }
            else{
                printf("Operação inválida\n");
                main();
            }
            
            break;

        case 6:
            printf("________________________________\n");
            printf("|Apenas escolha Jobs existentes|\n");
            printf("********************************\n");
            printf("\nEscolha uma máquina: ");
            scanf("%d", &mId);
            printf("Escolha o inicio do processo: ");
            scanf("%d", &inicio);
            printf("Escolha o final do processo: ");
            scanf("%d", &final);
            printf("Escolha um Job: ");
            scanf("%d", &jId);
            printf("Escolha uma operação: ");
            scanf("%d", &oId);
            Ocupa(plano, mId, inicio, final, jId, oId);
            break;

        case 7:
            lista = LerJob("dados.txt");
            ListaJob(lista);
            break;

        default:
            system("pause");

            exit(0);

            break;
        }
    }
}