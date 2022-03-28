/**
 * @file structs.h
 * @author André (a21112@alunos.ipca.pt)
 * @brief Lista Ligadas Simples
 * @version 0.1
 * @date 2022-03-28
 * 
 * Estruturas que vão ser usadas no projeto 
 * Ficheiro baseado no repositório do professor 
 * @see https://github.com/luferIPCA/LESI-EDA-2122/tree/master/Aulas/GereMaquinas
 * @copyright Copyright (c) 2022
 * 
 */
#include <string.h>
#include <stdio.h>

#define MAX 100
#define M 40

/**
 * @brief Estrutura de dados da maquina
 * 
 */
typedef struct Maquina{
    int proc;
    char nome[M];
    struct Maquina *next, *prev;
}Maquina;

/**
 * @brief Estrutura de dados de um job
 * 
 */
typedef struct Job{
	int cod;
	struct Job *next, *prev;
    struct Maquina *first, *last;
}Job;

Maquina* NovaMaquina(int proc, char*nome);
Maquina* InserirMaquina(Maquina* inicio, Maquina* nova);
bool ExisteMaquina(Maquina *inicio, int proc);
