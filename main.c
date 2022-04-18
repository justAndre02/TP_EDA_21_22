/**
 * @file main.c
 * @author André (a21112@alunos.ipca.pt)
 * @brief
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

    printf("----------------------MENU----------------------");
    printf("\n1 - INSERIR UMA MAQUINA");
    printf("\n2 - REMOVER UMA MAQUINA");
    printf("\n3 - ALTERAR UMA MAQUINA");
    printf("\n4 - DETERMINAR A QUANTIDADE MINIMA");
    printf("\n5 - DETERMINAR A QUANTIDADE MAXIMA");
    printf("\n6 - DETERMINAR A QUANTIDADE MEDIA");
    printf("\n7 - LEITURA DE UMA MAQUINA");
    printf("\n\nSELECIONE A SUA OPCAO: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        printf("teste");
        lista = InserirMaquina(lista, 1, 1, 1);
        lista = InserirMaquina(lista, 1, 2, 4);
        lista = InserirMaquina(lista, 1, 3, 3);
        ListaMaquina(lista);
        printf("teste");
        break;
    
    case 2:
        lista = RemoveMaquina(lista , 1);
        ListaMaquina(lista);
        break;

    case 3:
        printf("\nteste");
        break;

    case 4:
        printf("\nteste");
        break;

    case 5:
        printf("\nteste");
        break;

    case 6:
        printf("\nteste");
        break;

    case 7:
        printf("\nteste");
        break;

    default:
        system("pause");

        exit(0);

        break;
    }
}
