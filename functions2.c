/**
 * @file functions2.c
 * @author André (a21112@alunos.ipca.pt)
 * @brief Criação de listas
 * @version 0.1
 * @date 2022-01-01
 *
 * Funções de manipulação de Listas Ligadas
 *
 * Ficheiro baseado no repositório do professor
 * 
 * @see https://github.com/luferIPCA/LESI-EDA-2122/tree/master/Aulas/Planeamento
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "functions2.h"

/**
 * @brief Função encarregue de criar um Job
 * 
 * @param list Lista da struct Job
 * @param jobid Identificação de um Job
 * @param novo Apontador que percorre toda a lista
 * 
 * @return Job criado
 */
Job *CriaJob(Job *list, int jobid)
{
    Job *novo = (Job *)malloc(sizeof(Job));

    novo->job = jobid;
    novo->first = novo->last = NULL;
    novo->next = list;

    return novo;
}

/**
 * @brief Função encarregue de criar uma Máquina
 * 
 * @param list Lista da struct Maquina
 * @param opid Identificação de uma operação
 * @param maquinaid Identificação de uma máquina
 * @param tempo Valor temporal de uma máquina
 * @param novo Apontador que percorre toda a lista
 * 
 * @return Operação criada
 */
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

/**
 * @brief Função responsável po inserir um Job na lista
 * 
 * @param list Lista da struct Job
 * @param jobid Identificação de um Job
 * @param opid Identificação de uma operação
 * @param maquinaid Identificação de uma máquina
 * @param tempo Valor temporal de uma máquina
 * @param inicio Apontador que percorre toda a lista
 * 
 * @return Lista de Jobs
 */
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

/**
 * @brief Função que lê toda a informação de um ficheiro e insere na memória
 * 
 * @param nomeFicheiro Nome do ficheiro a ler
 * @param inicio Apontador que percorre toda a lista
 * 
 * @return Lista de Jobs
 */
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

/**
 * @brief Função que lista toda informação armazenada na memória
 * 
 * @param inicio Lista da estrutura Job
 * @param atual Apontador que percorre toda a lista da estrutura Maquina
 */
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

/**
 * @brief Função que escreve num ficheiro toda a informação armazenada na memória
 * 
 * @param list Lista da estrutura Job
 * @param inicio Apontador que percorre toda a lista da estrutura Maquina
 */
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

/**
 * @brief Função que remove todos os Jobs com o mesmo Id
 * 
 * @param list Lista da estrutura Job
 * @param jobid Id do Job a remover
 * @param inicio Apontador que percorre toda a lista da estrutura Maquina
 * 
 * @return Lista de Jobs atualizada
 */
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

/**
 * @brief Função que remove todas as operações com o mesmo Id do mesmo Job
 * 
 * @param list Lista da estrutura Job
 * @param jobid Identificação de um Job
 * @param opid Operação a remover
 * @param inicio Apontador que percorre toda a lista da estrutura Maquina
 * 
 * @return Lista de Jobs atualizada
 */
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

/**
 * @brief Função que altera a identificação de uma operação de um determinado Job
 * 
 * @param list Lista da estrutura Job
 * @param jobid Identificação de um Job
 * @param opid Operação a alterar
 * @param novo_op Identificação da nova operação
 * @param inicio Apontador que percorre toda a lista da estrutura Maquina
 * 
 * @return Lista de Jobs atualizada
 */
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

/**
 * @brief Função que muda a máquina de uma determinada operação 
 * 
 * @param list Lista da estrutura Job
 * @param jobid Identificação de um Job
 * @param opid Operação da máquina a alterar
 * @param maquinaid Máquina a editar
 * @param nova_maquina Identificação da nova máquina
 * @param inicio Apontador que percorre toda a lista da estrutura Maquina
 * 
 * @return Lista de Jobs atualizada
 */
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

/**
 * @brief Função que altera o tempo de uma máquina de uma determinada operação
 * 
 * @param list Lista da estrutura Job
 * @param jobid Identificação de um Job
 * @param opid Operação da máquina cujo tempo vai ser alterado
 * @param maquinaid Máquina respetiva ao tempo a mudar
 * @param novo_tempo Novo tempo a inserir
 * 
 * @return Lista de Jobs atualizada
 */
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

/**
 * @brief Inicia uma tabela constituída por linhas de máquinas e colunas de tempo
 * 
 * @param p Plano a criar
 * @param codJob Job da célula a criar
 * @param codOper Operação de célula 
 * @param l Linhas da tabela
 * @param col Colunas da tabela
 */
void IniciaPlano(Cel p[][T], int codJob, int codOper) {

	for (int l = 0; l < M; l++){
		for (int col = 0; col < T; col++) {
			p[l][col].idjob = codJob;
			p[l][col].idop = codOper;
		}
	}
}

/**
 * @brief Criação da células a introduzir
 * 
 * @param p Plano criado
 * @param mId Máquina a inserir
 * @param totTempo Tempo a inserir
 * @param c Célula criada
 * @param col Colunas alocadas na tabela
 */
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

/**
 * @brief Insere as células selecionadas e lista as linhas da tabela num ficheiro .csv
 * 
 * @param p Plano criado
 * @param mId Máquina a inserir
 * @param tempo Inicio do tempo de uma máquina
 * @param totTempo Tempo a inserir
 * @param codJ Job a inserir numa célula
 * @param codO Operação a inserir numa célula
 */
Ocupa(Cel p[][T], int mId, int tempo, int totTempo, int codJ, int codO) {
    FILE *fpt;

    fpt = fopen("plano.csv", "a");
	Cel c = { .idjob=codJ, .idop=codO , .inicio=tempo};
	OcupaVarios(p, mId, totTempo, &c);
	printf("\nPlano: Maquina: %d, Início: %d, Final: %d, Célula: Job - %d || Operação - %d\n", mId, tempo, totTempo, codJ, codO);

    fprintf(fpt, "M%d, Job %d - Operação %d, %d, %d\n", mId, codJ, codO, tempo, totTempo);
    fclose(fpt);
}

