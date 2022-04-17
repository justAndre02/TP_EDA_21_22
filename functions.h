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
    int tempo;
    struct Maquina *next, *prev;
} Maquina;

typedef struct Operacao{
    int op;
    struct Maquina *next, *prev;
    struct Maquina*first, *last;
}Operacao;


Maquina *InserirMaquina(Maquina *lst, int proc, int tempo);
bool ExisteMaquina(Maquina *inicio, int proc);
Maquina *ProcuraMaquina(Maquina *inicio, int proc);
Maquina *LerMaquina(const char *nomeFicheiro);
Maquina *RemoveMaquina(Maquina* inicio, int proc);
void EscreverMaquina(Operacao *lst);
Maquina *MaiorTempo(Maquina *inicio);
Maquina *MenorTempo(Maquina *inicio);
float mediaQuantidade(Maquina *inicio);