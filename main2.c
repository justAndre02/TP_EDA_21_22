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

#include "functions.h"

int main()
{
    Maquina *lista = NULL;
    Job *plano = NULL;

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
        printf("\n\nSELECIONE A SUA OPÇÃO: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            plano = InserirJob(plano, CriaJob(1, 1, 1, 4));
            plano = InserirJob(plano, CriaJob(1, 2, 2, 1));
            plano = InserirJob(plano, CriaJob(1, 3, 1, 1));
            plano = InserirJob(plano, CriaJob(1, 2, 1, 6));
            plano = InserirJob(plano, CriaJob(1, 4, 1, 4));
            plano = InserirJob(plano, CriaJob(2, 1, 1, 4));
            plano = InserirJob(plano, CriaJob(2, 2, 2, 1));
            plano = InserirJob(plano, CriaJob(3, 1, 1, 1));
            plano = InserirJob(plano, CriaJob(3, 2, 1, 6));
            plano = InserirJob(plano, CriaJob(3, 3, 1, 4));
            plano = InserirJob(plano, CriaJob(4, 1, 1, 4));
            plano = InserirJob(plano, CriaJob(4, 1, 2, 1));
            plano = InserirJob(plano, CriaJob(4, 1, 3, 4));
            plano = InserirJob(plano, CriaJob(4, 2, 1, 9));
            plano = InserirJob(plano, CriaJob(4, 2, 2, 8));
            EscreverJob(plano);
            ListaJob(plano);
            break;

        case 2:
            printf("\nQual a posição do Job a remover: ");
            scanf("%d", &opc);
            plano = RemoveJob(plano, opc);
            ListaJob(plano);
            break;

        case 3:
            printf("Escolha um job: ");
            scanf("%d", &jId);

            for (; plano; plano = plano->next)
            {
                if (jId == plano->job)
                {
                    printf("\nEste Job não existe\n");
                    system("pause");
                    main();
                }
            }

            printf("Escolha uma operação: ");
            scanf("%d", &oId);

            for (; plano; plano = plano->next)
            {
                if ((jId == plano->job) && (!(((plano->op) - 1) == (oId - 1))))
                {
                    printf("Não é possível criar esta operação porque não existe a operação %d\n", &oId - 1);
                    system("pause");
                    main();
                }
            }

            printf("Escolha uma maquina: ");
            scanf("%d", &mId);

            printf("Escolha um tempo: ");
            scanf("%d", &tId);

            plano = InserirJob(plano, CriaJob(jId, oId, mId, tId));

            EscreverJob(plano);
            ListaJob(plano);
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        default:
            system("pause");

            exit(0);

            break;
        }
    }
}