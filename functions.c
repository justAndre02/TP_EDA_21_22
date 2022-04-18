/**
 * @file functions.c
 * @author André (a21112@alunos.ipca.pt)
 * @brief Criação de listas
 * @version 0.1
 * @date 2022-04-18
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
Maquina *InserirMaquina(Maquina *inicio, int op, int proc, int tempo)
{
    if (!inicio || strcmp(proc, inicio->proc) < 0){

        Maquina *nova = (Maquina *) malloc(sizeof(Maquina));
        assert(nova);
        strcpy(nova->proc, proc);
        nova->tempo = tempo;
        nova->op = op;

        nova->next = inicio;
        inicio = nova;
    }
    else{
        inicio->next = InserirMaquina(inicio->next, op, proc, tempo);
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
 * @brief Seleciona uma operação e altera o tempo dessa operação
 * 
 * @param elemento  Elemento da lista a ser modificado
 * @param index     Index que percorre toda a lista
 * @return          O novo tempo definido 
 */
Maquina *AlteraMaquina(Maquina *inicio, int elemento, int index){
    Maquina *original = inicio;
    for (int i = 0; i < index; i++){
        if (!original->next) return NULL;

        original = original->next;
    }
    original->tempo = elemento;

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
                inicio = InserirMaquina(inicio, op, proc, tempo);
            }
        }
    }
}

/**
 * @brief Abre um ficheiro txt vazio e escreve a lista criada
 * 
 */
void EscreverMaquina(Maquina *lst){
    FILE *fp;
    fp = fopen("proccess_plan.txt", "w+");

    for (; lst; lst->next){
        fprintf(fp, "\n%d,%d,%d", lst->op, lst->proc, lst->tempo);
        lst=lst->next;
    }
    fclose(fp);
}

/**
 * @brief           Determina o maior tempo de uma lista e retorna-o
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

/**
 * @brief           Percorre a lista e calcula a média de tempo através de um somatório e um contador
 * 
 * @param inicio    Inicio da lista  
 * @param cont      Contador do numero de elementos
 * @param sum       Somatorio dos valores de tempo
 * @param media     Variavel aonde é calculada a média dos tempos
 * @return          Média das quantidades de tempo  
 */
float mediaQuantidade(Maquina *inicio){
    if (!inicio) return -1;
    int cont = 0;
    int sum = 0;
    float media = 0.0;

    Maquina *atual = inicio;
    if (inicio){
        while (inicio->next){
            cont++;
            sum += atual->tempo;
            atual = atual->next;
        }   
        
        media = sum / cont;
    }
    
    return media;
}

/**
 * @brief       Lista um Maquina criada anteriormente
 * 
 * @param inicio    Inicio da lista a ser apresentada
 */
void ListaMaquina(Maquina *inicio){
    if (inicio){
        printf("%d, %d ,%d", inicio->op, inicio->proc, inicio->tempo);
        ListaMaquina(inicio->next);
    }
}