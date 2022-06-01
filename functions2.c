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

Maquina *CriaMaquina(Maquina *list, int opid, int maquinaid, int tempo)
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

void ListaJob(Job *inicio)
{
    for (; inicio; inicio = inicio->next)
    {
        Maquina *atual = inicio->first;

        for (; atual;)
        {

            printf("%d, %d, %d, %d\n", inicio->job, atual->op, atual->maquina, atual->tempo);
            atual = atual->next;
        }
    }
}

void EscreveFicheiro(Job *list)
{
    FILE *fp;
    fp = fopen("dados.txt", "w+");

    for (; list; list = list->next)
    {
        Maquina *inicio = list->first;

        for (; inicio;)
        {
            fprintf(fp, "%d,%d,%d,%d\n", list->job, inicio->op, inicio->maquina, inicio->tempo);
            inicio = inicio->next;
        }
    }
    fclose(fp);
}

Job *RemoverJob(Job *list, int jobid)
{
    for (; list; list = list->next)
    {
        if (list->job == jobid)
        {
            Maquina *inicio = list->first;

            for (; inicio;)
            {
                if (list->first->next)
                {
                    list->first = list->first->next;
                    list->next->prev = NULL;
                }
                else
                {
                    list->first = NULL;
                    list->last = NULL;
                }
                free(inicio);
                inicio = inicio->next;
            }
        }
    }
    return list;
}

Job *RemoverOperacao(Job *list, int jobid, int opid)
{
    for (; list; list = list->next)
    {
        if (list->job == jobid)
        {
            Maquina *inicio = list->first;

            for (; inicio; inicio = inicio->next)
            {
                if (inicio->op == opid)
                {
                    if (list->first->next)
                    {
                        list->first = list->first->next;
                        list->next->prev = NULL;
                    }
                    else
                    {
                        list->first = NULL;
                        list->last = NULL;
                    }
                    free(inicio);
                }
            }
        }
    }
    return list;
}

Job *EditarOperacao(Job *list,int jobid ,int opid, int novo_op)
{
    for (; list; list = list->next)
    {
        if (list->job == jobid)
        {
            Maquina *inicio = list->first;

            for (; inicio; inicio = inicio->next)
            {
                if (inicio->op == opid)
                {
                    inicio->op = novo_op;                
                }
            }
        }
    }
    return list;
}

Job *EditarMaquina(Job *list,int jobid ,int opid, int maquinaid, int nova_maquina)
{
    for (; list; list = list->next)
    {
        if (list->job == jobid)
        {
            Maquina *inicio = list->first;

            for (; inicio; inicio = inicio->next)
            {
                if (inicio->op == opid){

                    if (inicio->maquina == maquinaid){
                        
                        inicio->maquina = nova_maquina;                
                    }
                }
            }
        } 
    }
    return list;
}

Job *EditarTempo(Job *list,int jobid ,int opid, int maquinaid, int novo_tempo)
{

    for (; list; list = list->next)
    {
        if (list->job == jobid)
        {
            Maquina *inicio = list->first;

            for (; inicio; inicio = inicio->next)
            {
                if (inicio->op == opid){

                    if (inicio->maquina == maquinaid){
                        
                        inicio->tempo = novo_tempo;                
                    }
                }
            }
        }
    }
    return list;
}

void IniciaPlano(Cel p[][T], int codJob, int codOper) {

	for (int l = 0; l < M; l++){
		for (int col = 0; col < T; col++) {
			p[l][col].idjob = codJob;
			p[l][col].idop = codOper;
		}
	}
}

void OcupaVarios(Cel p[][T], int mId, int totTempo, Cel* c) {
	
	int col = 0;
	if (p[mId][col].idjob != -1){
		col++;
	}

	totTempo += col;

	for (; col < totTempo; col++) {
		p[mId][col].idjob = c->idjob;
		p[mId][col].idop = c->idop;
        p[mId][col].inicio = c->inicio;
	}

}

Ocupa(Cel p[][T], int mId, int tempo, int totTempo, int codJ, int codO) {
    FILE *fpt;

    fpt = fopen("plano.csv", "a");
	Cel c = { .idjob=codJ, .idop=codO , .inicio=tempo};
	OcupaVarios(p, mId, totTempo, &c);
	printf("\nPlano: Maquina: %d, Início: %d, Final: %d, Célula: Job - %d || Operação - %d\n", mId, tempo, totTempo, codJ, codO);

    fprintf(fpt, "M%d, Job %d - Operação %d, %d, %d\n", mId, codJ, codO, tempo, totTempo);
    fclose(fpt);
}

