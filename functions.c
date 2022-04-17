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
#include <assert.h>

#include "functions.h"


/**
 * @brief               Insere a maquina ordenada pelo na lista
 *
 * @param inicio        inicio da lista
 * @param nova          inserção da nova maquina
 * @return              Inicio da nova Lista
 */
Maquina *InserirMaquina(Maquina *inicio, int proc, int tempo)
{
    if (!lst || strcmp(proc, lst->proc) < 0){

        Maquina *nova = (Maquina *) malloc(sizeof(Maquina));
        assert(nova);
        strcpy(nova->proc, proc);
        nova->tempo = tempo;

        nova->next = inicio;
        inicio = nova;
    }
    else{
        inicio->next = InserirMaquina(inicio->next, proc, tempo);
    }

    return inicio;
}

/**
 * @brief               Verifica se uma maquina existe
 *
 * @param inicio        inicio da lista
 * @param proc          id da operação a procurar
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
 * @brief               Encontra uma maquina e devolve o seu endereço
 *
 * @param inicio        inicio da lista
 * @param proc          id da operação a encontrar
 * @return              Endereço da maquina
 */
Maquina *ProcuraMaquina(Maquina *inicio, int proc)
{
    if (inicio == NULL)
        return NULL; 
    else
    {
        Maquina *aux = inicio;
        while (aux != NULL)
        {
            if (aux->proc == proc)
            {
                return (aux); 
            }
            aux = aux->next;
        }
        return NULL;
    }
}

/**
 * @brief           Remove um elemento da lista ordenada dada qualquer posição
 * 
 * @param inicio    inicio da lista
 * @param proc      id da operação a remover
 * @return next
 * @return original 
 */
Maquina *RemoveMaquina(Maquina* inicio, int proc){
    if (inicio == NULL) return NULL;
    if (strcmp(inicio->proc, proc) == 0) {
        Maquina* next = inicio -> next;
        free(inicio -> proc);
        free(inicio);
        return next;
    }

    Maquina *original = inicio;
    while (inicio->next && strcmp(inicio->next->proc, proc) != 0) {
        inicio = inicio->next;
    }
    if (inicio->next) {
        Maquina *next = inicio->next->next;
        free(inicio->next->proc);
        free(inicio->next);
        inicio->next = next;
    }

    return original;
}

/**
 * @brief                 Lê um ficheiro de texto linha a linha
 * 
 * @param nomeFicheiro    Identificação do ficheiro a ler
 * @return                Conteúdo do ficheiro de texto 
 */
Maquina *LerMaquina(const char *nomeFicheiro)
{
    FILE *fp;
    Maquina *inicio = NULL;

    while (!feof(stdin))
    {
        char string[1000];
        int op;
        int proc;
        int tempo;
        fgets(string, 1000, stdin);
        sscanf(string, "%d,%d,%d", &op, &proc, &tempo);
        if (!feof(stdin))
        {
            if (strlen(proc) > 99)
            {
                printf("IGNORED>>%s\n", string);
            }
            else
            {
                inicio = InserirMaquina(inicio, proc, tempo);
            }
        }
    }
}

/**
 * @brief Abre um ficheiro txt vazio e escreve a lista criada
 * 
 */
void EscreverMaquina(Operacao *lst){
    FILE *fp;
    fp = fopen("proccess_plan.txt", "w+");

    for (; lst; lst=lst->first){
        Maquina *maquina = lst->next;
        for (; maquina;){
            fprintf(fp, "\n%d,%d,%d", lst->op, maquina->proc, maquina->tempo);
            maquina = maquina->next;
        }
    }
    fclose(fp);
}

/**
 * @brief           Determina o maior tempo de uma lista e retorna-o
 * 
 * 
 * @param inicio    Inicio de uma lista
 * @param maior     Maior tempo a ser determinado
 * @return          A maior quantidade de tempo 
 */
Maquina *MaiorTempo(Maquina *inicio){
    Maquina *maior = inicio;
    if (inicio) {
        while (inicio->next){
            inicio = inicio->next;
            if (inicio-> tempo > maior->tempo){
                maior = inicio;
            }
        }
    }
    return maior;
}

/**
 * @brief           Determina o menor tempo de uma lista e retorna-o
 * 
 * @param inicio    Inicio de uma lista
 * @param menor     Menor tempo a ser determinado
 * @return          A menor quantidade de tempo 
 */
Maquina *MenorTempo(Maquina *inicio){
    Maquina *menor = inicio;
    if (inicio){
        while (inicio->next){
            inicio = inicio->next;
            if (inicio -> tempo < menor->tempo){
                menor = inicio;
            }
        }
    }
    return menor;
}

Maquina *MediaQuantidade(){}
