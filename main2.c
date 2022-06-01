/**
 * @file main2.c
 * @author André (a21112@alunos.ipca.pt)
 * @brief Menu responsável por chamar as funções  da fase 2
 * @version 0.1
 * @date 2022-06-01
 *
 * Main que chama todas as funções criadas no ficheiro "functions.c"
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

    int opc = 0;
    int jId;
    int oId;
    int mId;
    int tId;

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
        printf("\n7 - LEITURA DO FICHEIRO");
        printf("\n\nSELECIONE A SUA OPÇÃO: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            lista = CriaJob(lista, 1);
            lista = InsereJob(lista, 1, 1, 1, 6);
            printf("Insira um Job: ");
            scanf("%d,%d,%d,%d", &jId, &oId, &mId, &tId);

            lista = CriaJob(lista, 2);
            lista = InsereJob(lista, 2, 1, 2, 3);
            printf("Insira um Job: ");
            scanf("%d,%d,%d,%d", &jId, &oId, &mId, &tId);
            lista = InsereJob(lista, jId, oId, mId, tId);

            lista = CriaJob(lista, 3);
            lista = InsereJob(lista, 3, 1, 3, 4);
            printf("Insira um Job: ");
            scanf("%d,%d,%d,%d", &jId, &oId, &mId, &tId);
            lista = InsereJob(lista, jId, oId, mId, tId);

            lista = CriaJob(lista, 4);
            lista = InsereJob(lista, 4, 1, 4, 7);
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
            printf("Em qual Job deseja inserir a operação: \n");
            scanf("%d", &jId);
            lista = CriaJob(lista, jId);
            printf("Insira a operação: ");
            scanf("%d,%d,%d", &oId, &mId, &tId);
            lista = InsereJob(lista, jId, oId, mId, tId);
            EscreveFicheiro(lista);
            ListaJob(lista);
            break;

        case 4:
            //ListaJob(lista);
            RemoverOperacao(lista, 1, 1);
            ListaJob(lista);
            break;

        case 5:
            break;

        case 6:
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