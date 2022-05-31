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
    int jId = 0;
    int oId = 0;
    int mId = 0;
    int tId = 0;

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
            lista = InsereJob(lista, 1, 1, 1, 1);
            lista = InsereJob(lista, 1, 1, 2, 4);
            lista = InsereJob(lista, 1, 2, 3, 3);
            lista = InsereJob(lista, 1, 2, 4, 8);
            lista = InsereJob(lista, 1, 3, 5, 9);
            lista = InsereJob(lista, 1, 3, 6, 5);

            lista = CriaJob(lista, 2);
            lista = InsereJob(lista, 2, 1, 1, 3);
            lista = InsereJob(lista, 2, 2, 1, 6);
            lista = InsereJob(lista, 2, 2, 2, 4);


            EscreveFicheiro(lista);
            ListaJob(lista);
            break;

        case 2:
            ListaJob(lista);
            printf("\nQual Job deseja remover: ");
            scanf("%d", &jId);
            lista = RemoverJob(lista, jId);
            ListaJob(lista);
            break;

        case 3:

            break;

        case 4:
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