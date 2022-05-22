/**
 * @file structs.h
 * @author André (a21112@alunos.ipca.pt)
 * @brief Lista Ligadas Simples
 * @version 0.1
 * @date 2022-04-18
 *
 * Estruturas que vão ser usadas no projeto
 * 
 * Ficheiro baseado no repositório do professor
 *
 * @see https://github.com/luferIPCA/LESI-EDA-2122/tree/master/Aulas/GereMaquinas
 * @copyright Copyright (c) 2022
 *
 */
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define MAX 100
#define M 7
#define T 100

/**
 * @brief Estrutura de dados da maquina
 * 
 * @param proc Maquina
 * @param op Operação
 * @param tempo Tempo 
 */
typedef struct Maquina
{
    int proc;
    int op;
    int tempo;
    struct Maquina *next, *prev;
} Maquina;

/**
 * @brief Estrutura de dados do job
 * 
 * @param job Job
 */
typedef struct Job{
    int job;
    int proc;
    int op;
    int tempo;
    struct Job *next, *prev;
    struct Maquina *first, *last;
} Job;

Maquina *CriaMaquina(int novoOp, int novoProc, int novoTempo);
Maquina *InserirMaquina(Maquina *inicio, Maquina *nova);
bool ExisteMaquina(Maquina *inicio, int proc);
Maquina *ProcuraMaquina(Maquina *inicio, int proc);
Maquina *LerMaquina(const char *nomeFicheiro);
Maquina *RemoveMaquina(Maquina* inicio, int proc);
void EscreverMaquina(Maquina *lst);
Maquina *MaiorTempo(Maquina *inicio, int op);
Maquina *MenorTempo(Maquina *inicio, int op);
float mediaQuantidade(Maquina *inicio, int numeroOp);
Maquina *AlteraMaquina(Maquina *inicio, int elemento, int index);
void ListaMaquina(Maquina *inicio);
int SomaMenorTempo(Maquina *inicio);
int SomaMaiorTempo(Maquina *inicio);

Job *CriaJob(int novoJob, int novoOp, int novoProc, int novoTempo);
Job *InserirJob(Job *inicio, Job *nova);
void EscreverJob(Job *lst);
Job *LerJob(const char *nomeFicheiro);
void ListaJob(Job *inicio);
Job *RemoveJob(Job *inicio, int job);