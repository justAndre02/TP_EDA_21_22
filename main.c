/**
 * @file main.c
 * @author André (a21112@alunos.ipca.pt)
 * @brief Menu responsável por chamar as funções criadas
 * @version 0.1
 * @date 2022-04-18
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

#include "functions.h"

int main()
{
    Maquina *lista = NULL;
    int opc;
    int numeroOp;
    float media = 0.0;

    while (true){
        printf("\n----------------------MENU----------------------");
        printf("\n1 - INSERIR OPERACAO");
        printf("\n2 - REMOVER OPERACAO");
        printf("\n3 - ALTERAR OPERACAO");
        printf("\n4 - DETERMINAR A QUANTIDADE MINIMA");
        printf("\n5 - DETERMINAR A QUANTIDADE MAXIMA");
        printf("\n6 - DETERMINAR A QUANTIDADE MEDIA");
        printf("\n7 - LEITURA DE UMA MAQUINA");
        printf("\n\nSELECIONE A SUA OPCAO: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            lista = InserirMaquina(lista, CriaMaquina(3,8,4));
            lista = InserirMaquina(lista, CriaMaquina(1,1,4));
            lista = InserirMaquina(lista, CriaMaquina(1,2,3));
            lista = InserirMaquina(lista, CriaMaquina(1,3,4));
            lista = InserirMaquina(lista, CriaMaquina(2,5,3));
            lista = InserirMaquina(lista, CriaMaquina(2,7,5));
            EscreverMaquina(lista);
            ListaMaquina(lista);
            break;
    
        case 2:
            lista = RemoveMaquina(lista ,1);
            ListaMaquina(lista);
            break;

        case 3:
            lista = AlteraMaquina(lista, 1, 1);
            break;

        case 4:
            printf("\nO tempo minimo para terminar o job e %d segundos\n", SomaMenorTempo(lista));
            break;

        case 5:
            printf("\nO tempo maximo para terminar o job e %d segundos\n", SomaMaiorTempo(lista));
            break;

        case 6:
            printf("Escolha a operacao: ");
            scanf("%d", &opc);
            media = mediaQuantidade(lista, opc);
            printf("A media desta operacao e %f segundos\n", media);
            setbuf(stdin, NULL);
            break;

        case 7:
            lista = LerMaquina("plano_de_processos.txt");
            ListaMaquina(lista);
            break;

        default:
            system("pause");

            exit(0);

            break;
        }
    }
}
