/**
 * @file functions2.h
 * @author André (a21112@alunos.ipca.pt)
 * @brief Listas duplamente ligadas
 * @version 0.1
 * @date 2022-05-30
 * 
 * Estruturas usadas no projeto, bem como todas as funções
 * 
 * Ficheiro baseado no repositório do professor
 * 
 * @see https://github.com/luferIPCA/LESI-EDA-2122/tree/master/Aulas/Planeamento
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdbool.h>
#define MAX 100
#define M 4
#define T 10

typedef struct Maquina{
    int maquina;
    int op;
    int tempo;
    struct Maquina* next, *prev;
}Maquina;

typedef struct Job{
    int job;
    struct Job *next, *prev;
    struct Maquina* first, last;
}Job;

typedef struct Cel{
    int idjob;
    int idop;
}Cel;

Job *CriaJob(Job *list, int jobid);
Maquina *CriaMaquina(Maquina *list, int opid,int maquinaid, int tempo); 
Job *InsereJob(Job *list, int jobid, int opid, int maquinaid, int tempo);
Job *LerJob(const char *nomeFicheiro);
void ListaJob(Job *inicio, Maquina *lista);