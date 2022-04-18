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
 * @see https://github.com/luferIPCA/LESI-EDA-2122/tree/master/Aulas/GereMaquinas
 * @copyright Copyright (c) 2022
 *
 */
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define MAX 100
#define M 40

/**
 * @brief Estrutura de dados da maquina
 *
 */
typedef struct Maquina
{
    int proc;
    int op;
    int tempo;
    struct Maquina *next, *prev;
} Maquina;


Maquina *InserirMaquina(Maquina *lst, int op, int proc, int tempo);
bool ExisteMaquina(Maquina *inicio, int proc);
Maquina *ProcuraMaquina(Maquina *inicio, int proc);
Maquina *LerMaquina(const char *nomeFicheiro);
Maquina *RemoveMaquina(Maquina* inicio, int proc);
void EscreverMaquina(Maquina *lst);
Maquina *MaiorTempo(Maquina *inicio);
Maquina *MenorTempo(Maquina *inicio);
float mediaQuantidade(Maquina *inicio);
Maquina *AlteraMaquina(Maquina *inicio, int elemento, int index);
void ListaMaquina(Maquina *inicio);