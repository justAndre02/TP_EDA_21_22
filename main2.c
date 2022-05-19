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

#include "functions.h"

int main(){
    Maquina *lista = NULL;
    Job *hash = NULL;

    int opc;

    while(true){
        printf("\n----------------------MENU----------------------");
        printf("\n1 - INSERIR JOB");
        printf("\n2 - REMOVER JOB");
        printf("\n3 - ALTERAR JOB");
        printf("\n4 - INSERIR OPERAÇÃO NUM JOB");
        printf("\n5 - REMOVER OPERAÇÃO DE UM JOB");
        printf("\n6 - ALTERAR OPERAÇÃO DE UM JOB");
        printf("\n7 - PROPOSTA DE ESCALONAMENTO");
        scanf("%d", &opc);
        switch (opc) {
            case 1: 
                break;

            case 2: 
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
                break;
        }
    }
}