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
    Maquina *inicio;
    Operacao* nova;
    inicio = NULL;
    nova = NULL;
    int opc;

    printf("----------------------MENU----------------------");
    printf("\nO que deseja fazer:");
    scanf("%d", &opc);
}
