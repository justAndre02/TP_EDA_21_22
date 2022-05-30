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

Job *CriaJob(int novoJob, int novoOp, int novoMaquina, int novoTempo)
{
    Job *nova = malloc(sizeof(Job));

    nova->job = novoJob;
    nova->ops = novoOp;
    return nova;
}

Job *InserirJob(Job *inicio, Job *nova)
{
    if (nova == NULL)
        return inicio;

    if (inicio == NULL)
    {
        inicio = nova;
        return (inicio);
    }
    else
    {
        Job *aux = inicio;
        Job *antAux = aux;
        while (aux != NULL && aux->job > nova->job)
        {
            antAux = aux;
            aux = aux->next;
        }
        if (aux == inicio)
        {
            nova->next = inicio;
            inicio = nova;
            return inicio;
        }
        if (aux != NULL)
        {
            nova->next = aux;
            antAux->next = nova;
        }
    }
    return inicio;
} 

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

