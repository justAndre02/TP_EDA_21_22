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

#include "functions.h"

Job *CriaJob(int novoJob, int novoOp, int novoProc, int novoTempo)
{
    Job *nova = malloc(sizeof(Job));
    nova->job = novoJob;
    nova->op = novoOp;
    nova->proc = novoProc;
    nova->tempo = novoTempo;
    nova->next = NULL;
    nova->prev = NULL;
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

void EscreverJob(Job *lst)
{
    FILE *fp;
    fp = fopen("plano_de_processos2.txt", "w+");

    for (; lst; lst->next)
    {
        fprintf(fp, "%d,%d,%d,%d\n", lst->job, lst->op, lst->proc, lst->tempo);
        lst = lst->next;
    }
    fclose(fp);
}

Job *LerJob(const char *nomeFicheiro)
{
    FILE *fp;
    fp = fopen(nomeFicheiro, "r+");
    Job *inicio = NULL;

    if (fp == NULL)
    {
        perror("Failed to open file");
        exit(1);
    }

    while (!feof(fp))
    {
        int op;
        int job;
        int proc;
        int tempo;
        fscanf(fp, "%d,%d,%d,%d",&job, &op, &proc, &tempo);
        if (!feof(fp))
        {
            inicio = InserirJob(inicio, CriaJob(job, op, proc, tempo));
        }
    }
    return inicio;
}

void ListaJob(Job *inicio)
{
    if (inicio)
    {
        printf("%d, %d, %d ,%d\n", inicio->job, inicio->op, inicio->proc, inicio->tempo);
        ListaJob(inicio->next);
    }
}

Job *RemoveJob(Job *inicio, int job)
{
    if (inicio == NULL)
        return NULL;

    if (inicio->job == job)
    {
        Job *next = inicio->next;
        free(inicio);
    }

    Job *original = inicio;
    while (inicio->next && inicio->next->job == job)
    {
        inicio = inicio->next;
    }
    if (inicio->next)
    {
        Job *next = inicio->next->next;
        free(inicio->next);
        inicio->next = next;
    }

    return original;
}