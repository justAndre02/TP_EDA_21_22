/**
 * @file functions.c
 * @author André (a21112@alunos.ipca.pt)
 * @brief Criação de listas
 * @version 0.1
 * @date 2022-03-25
 *
 *  Funções de mainpulação de Listas Ligadas
 *
 *  Ficheiro baseado no repositório do professor
 * @see https://github.com/luferIPCA/LESI-EDA-2122/tree/master/Aulas/GereMaquinas
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

/**
 * @brief Cria uma nova Maquina
 *
 * @param proc      novo processo
 * @param tempo     novo tempo
 * @return Maquina*
 */
Maquina *NovaMaquina(int proc, int tempo)
{
    Maquina *nova = (Maquina *)malloc(sizeof(Maquina));
    nova->proc = proc;
    strcpy(nova->tempo, tempo);
    nova->next = NULL;
    return nova;
}

/**
 * @brief Insere a maquina ordenada pelo na lista
 *
 * @param inicio        inicio da lista
 * @param nova          inserção da nova maquina
 * @return      Inicio da nova Lista
 */
Maquina *InserirMaquina(Maquina *inicio, Maquina *nova)
{
    if (ExisteMaquina(inicio, nova->proc))
        return inicio;

    if (inicio == NULL)
    {
        inicio = nova;
    }
    else
    {
        Maquina *aux = inicio;
        Maquina *aux2 = NULL;
        while (aux && aux->proc < nova->proc)
        {
            aux2 = aux;
            aux = aux->next;
        }
        if (aux2 == NULL)
        {
            nova->next = inicio;
            inicio = nova;
        }
        else
        {
            aux2->next = nova;
            nova->next = aux;
        }
    }
    return inicio;
}

/**
 * @brief Verifica se uma maquina existe
 *
 * @param inicio        inicio da lista
 * @param proc          id da maquina a procurar
 * @return true
 * @return false
 */
bool ExisteMaquina(Maquina *inicio, int proc)
{
    if (inicio == NULL)
        return false;
    Maquina *aux = inicio;
    while (aux != NULL)
    {
        if (aux->proc == proc)
            return true;
        aux = aux->next;
    }
    return false;
}

/**
 * @brief Encontra uma maquina e devolve o seu endereço
 *
 * @param inicio        inicio da lista
 * @param proc          id da maquina a encontrar
 * @return Endereço da maquina
 */
Maquina *ProcuraMaquina(Maquina *inicio, int proc)
{
    if (inicio == NULL)
        return NULL; // lista vazia
    else
    {
        Maquina *aux = inicio;
        while (aux != NULL)
        {
            if (aux->proc == proc)
            {
                return (aux); // encontrei
            }
            aux = aux->next;
        }
        return NULL;
    }
}

Maquina *LerMaquina(const char *nomeFicheiro)
{
    FILE *fp;
    Maquina *inicio = NULL;

    while (!feof(stdin))
    {
        char string[1000];
        char nome[1000];
        float nota;
        fgets(string, 1000, stdin);
        sscanf(string, "%s,%f", nome, &nota);
        if (!feof(stdin))
        {
            if (strlen(nome) > 99)
            {
                printf("IGNORED>>%s>>%.4f\n", string, nota);
            }
            else
            {
                inicio = InserirMaquina();
            }
        }
    }
