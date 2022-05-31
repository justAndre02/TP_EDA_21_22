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

Job *CriaJob(Job *list, int jobid) 
{
    Job *novo = (Job *)malloc(sizeof(Job));

    novo->job = jobid;
    novo->first = novo->last = NULL;
    novo->next = list;

    return novo;
}

Maquina *CriaMaquina(Maquina *list, int opid,int maquinaid, int tempo)
{

    Maquina *novo = (Maquina *)malloc(sizeof(Maquina));

    novo->op = opid;
    novo->maquina = maquinaid;
    novo->tempo = tempo;
    novo->next = NULL;
    novo->prev = list;

    if (novo->prev)
    {
        novo->prev->next = novo;
    }
    return novo;
}

Job *InsereJob(Job *list, int jobid, int opid, int maquinaid, int tempo)
{

    Job *inicio = list;

    while (inicio)
    {

        if (inicio->job == jobid)
        {
            break;
        }

        if (inicio->job != jobid)
        {
            printf("Job não foi encontrado");
            exit(0);
        }

        inicio = inicio->next;

    }

    if (!inicio->last)
    {
        inicio->first = inicio->last = CriaMaquina(inicio->last, opid, maquinaid, tempo);
    }
    else
    {
        inicio->last = CriaMaquina(inicio->last, opid, maquinaid, tempo);
    }

    return list;
}

Job *LerJob(const char *nomeFicheiro)
{
    FILE *fp;
    fp = fopen(nomeFicheiro, "r");
    Job *inicio = NULL;

    if (fp == NULL)
    {
        perror("Failed to open file");
        exit(1);
    }

    while (!feof(fp))
    {
        char texto[100];
        int jobid;
        int opid;
        int maquinaid;
        int tempo;

        fgets(texto, 100, fp);
        sscanf(texto, "%d,%d,%d,%d", &jobid, &opid, &maquinaid, &tempo);
        inicio = CriaJob(inicio, jobid);
        inicio = InsereJob(inicio, jobid, opid, maquinaid, tempo);
    }

    fclose(fp);
    return inicio;
}

void ListaJob(Job *inicio){
    for (; inicio; inicio = inicio -> next){
        Maquina *atual = inicio->first;

        for (; atual;){

            printf("%d, %d, %d, %d\n", inicio->job, atual->op, atual->maquina, atual->tempo);
            atual = atual->next;
        }
    }      
}

void EscreveFicheiro(Job *list){
    
    FILE *fp;
    fp = fopen("dados.txt", "w+");

    for (; list; list = list->next){
        Maquina *inicio = list->first;

        for (;inicio;){
            fprintf(fp, "%d,%d,%d,%d\n", list->job, inicio->op, inicio->maquina, inicio->tempo);
            inicio = inicio->next;
        }
    }
    fclose(fp);
}

Job *RemoverJob(Job *inicio, int jobid)
{
    for (; inicio; inicio = inicio->next)
    {
        if (inicio->job == jobid)
        {
            Maquina *atual = inicio->first;

            for (; atual;)
            {
                if (inicio->first->next)
                {
                    inicio->first = inicio->first->next;
                    inicio->next->prev = NULL;
                }
                else
                {
                    inicio->first = NULL;
                    inicio->last = NULL;
                }
                free(atual);
                atual = atual->next;
            }
        }
    }
    return inicio;
}