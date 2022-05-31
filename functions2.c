/**
 * @file functions2.c
 * @author André (a21112@alunos.ipca.pt)
 * @brief Criação de listas
 * @version 0.1
 * @date 2022-01-01
 *
 *  Funções de manipulação de Listas Ligadas
 *
 *  Ficheiro baseado no repositório do professor
 * @see https://github.com/luferIPCA/LESI-EDA-2122/tree/master/Aulas/Aula%205%20-%20Listas%20Ligadas%20Gen%C3%A9ricas
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "functions2.h"



Job *LerJob(const char *nomeFicheiro)
{
    FILE *fp;
    char texto[MAX];
    
    Job *inicio = NULL;
    Job auxjob;
    Maquina auxop;
    Maquina auxmaq;

    fp = fopen(nomeFicheiro, "r+");
    if (fp == NULL)
    {
        perror("Failed to open file");
        exit(1);
    }

    while (!feof(fp))
    {
        sscanf(texto, "%d,%d,%d,%d", &auxjob.job, &auxop.op, &auxmaq.maquina, &auxmaq.tempo);
    }

    fclose(fp);
    return inicio;
}

void ListaJob(Job *inicio){
    Maquina *lista;
    if (inicio){
        printf("%d, %d, %d, %d\n", inicio->job, lista->op, lista->maquina, lista->tempo);
        ListaJob(inicio->next);
    }
}