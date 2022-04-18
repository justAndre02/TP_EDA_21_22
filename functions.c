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


Maquina *CriaMaquina(int novoOp, int novoProc, int novoTempo){
    Maquina *nova = malloc(sizeof(Maquina));
    nova->op = novoOp;
    nova->proc = novoProc;
    nova->tempo = novoTempo;
    nova->next = NULL;
    return nova;
}

/**
 * @brief               Insere a maquina ordenada pelo na lista
 *
 * @param inicio        inicio da lista
 * @param nova          inserção da nova maquina
 * @return              Inicio da nova Lista
 */
Maquina *InserirMaquina(Maquina *inicio, Maquina *nova)
{
    if (nova == NULL)	return inicio;	

	if (inicio == NULL) {	
		inicio = nova;
		return (inicio);
	}
	else {		
		Maquina* aux = inicio;
		Maquina* antAux = aux;
		while (aux != NULL && aux->op < nova->op) {
			antAux = aux;
			aux = aux->next;
		}
		if (aux == inicio) {		
			nova->next = inicio;
			inicio = nova;
			return inicio;
		}
		if (aux != NULL)	
		{
			nova->next = aux;
			antAux->next = nova;
		}
	}
	return inicio;
}

/**
 * @brief Verifica se uma maquina existe
 *
 * @param inicio inicio da lista
 * @param proc id da operação a procurar
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
 * @param inicio inicio da lista
 * @param proc id da operação a encontrar
 * @return Endereço da maquina
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
 * @brief Remove um elemento da lista ordenada dada qualquer posição
 * 
 * @param inicio inicio da lista
 * @param proc id da operação a remover
 * @return next
 * @return original 
 */
Maquina *RemoveMaquina(Maquina* inicio, int op){
    if (inicio == NULL) return NULL;
    if (inicio->op == op) {
        Maquina* next = inicio -> next;
        free(inicio);
        return next;
    }

    Maquina *original = inicio;
    while (inicio->next && inicio->next->op == op) {
        inicio = inicio->next;
    }
    if (inicio->next) {
        Maquina *next = inicio->next->next;
        free(inicio->next);
        inicio->next = next;
    }

    return original;
}

/**
 * @brief Seleciona uma operação e altera o tempo dessa operação
 * 
 * @param elemento Elemento da lista a ser modificado
 * @param index Index que percorre toda a lista
 * @return O novo tempo definido 
 */
Maquina *AlteraMaquina(Maquina *inicio, int elemento, int index){
    Maquina *original = inicio;
    for (int i = 0; i < index; i++){
        if (!original->next) return NULL;

        original = original->next;
    }

    printf("\nA operacao original: %d, %d ,%d", original->op, original->proc, original->tempo);

    original->tempo = elemento;

    printf("\nA operacao apos a sua alteracao: %d, %d ,%d\n\n", original->op, original->proc, original->tempo);

    return original;
}

/**
 * @brief Lê um ficheiro de texto linha a linha
 * 
 * @param nomeFicheiro Identificação do ficheiro a ler
 * @return Conteúdo do ficheiro de texto 
 */
Maquina *LerMaquina(const char *nomeFicheiro)
{
    FILE *fp;
    fp = fopen(nomeFicheiro, "r+");
    Maquina *inicio = NULL;

    if(fp == NULL){
        perror("Failed to open file");
        exit(1);
    } 

    while (!feof(fp)){
        int op;
        int proc;
        int tempo;
        fscanf(fp, "%d,%d,%d\n", &op, &proc, &tempo);
        if (!feof(fp)){
            inicio = InserirMaquina(inicio, CriaMaquina(op, proc, tempo));
        } 
    }
    return inicio;
}


/**
 * @brief Abre um ficheiro txt vazio e escreve a lista criada
 * 
 */
void EscreverMaquina(Maquina *lst){
    FILE *fp;
    fp = fopen("plano_de_processos.txt", "w+");

    for (; lst; lst->next){
        fprintf(fp, "%d,%d,%d", lst->op, lst->proc, lst->tempo);
        fprintf(fp,"\n");
        lst=lst->next;
    }
    fclose(fp);
}

/**
 * @brief Determina o maior tempo de uma lista e retorna-o
 * 
 * @param inicio Inicio de uma lista
 * @param maior Maior tempo a ser determinado
 * @return A maior quantidade de tempo 
 */
Maquina *MaiorTempo(Maquina *inicio, int op){
    Maquina *maior = inicio;
    while(inicio && op <= inicio->op){
        if(inicio -> tempo > maior->tempo){
            maior = inicio;
        }

        inicio = inicio->next;
    }

    return maior;
}

/**
 * @brief Faz a soma do tempo minimo de cada operação para determinar o menor tempo possível de um job
 * 
 * @param inicio Inicio de uma lista
 * @param maior Maior tempo a ser determinado
 * @return A maior quantidade de tempo 
 */
int SomaMaiorTempo(Maquina *inicio){
    int tempoMaximo = 0;
    int numOp = 0;

    Maquina *original = inicio;
    Maquina *maximo;
    Maquina *atual = inicio;

    while(atual->next != NULL){
        atual = atual -> next;
    }

    numOp = atual->op;

    for(int i = 1; i <= numOp; i++){
        maximo = MaiorTempo(original, i);
        if (maximo != NULL){
            tempoMaximo += maximo->tempo;
            printf("\nA operacao %d, demora %d segundos\n", i, maximo->tempo);
        }
    }

    return tempoMaximo;
}

/**
 * @brief Determina o menor tempo de uma lista e retorna-o
 * 
 * @param inicio Inicio de uma lista
 * @param menor Menor tempo a ser determinado
 * @return A menor quantidade de tempo 
 */
Maquina *MenorTempo(Maquina *inicio, int op){
    Maquina *menor = inicio;
    while(inicio && op <= inicio->op){
        if(inicio -> tempo < menor->tempo){
            menor = inicio;
        }

        inicio = inicio->next;
    }

    return menor;
}

/**
 * @brief Faz a soma do tempo minimo de cada operação para determinar o menor tempo possível de um job
 * 
 * @param inicio Inicio da lista a percorrer
 * @param tempoMinimo Armazena o tempo minimo 
 * @param numOp Representa o numero de operações a percorrer na lista 
 * @return int 
 */
int SomaMenorTempo(Maquina *inicio){
    int tempoMinimo = 0;
    int numOp = 0;

    Maquina *original = inicio;
    Maquina *minimo;
    Maquina *atual = inicio;

    while(atual->next != NULL){
        atual = atual -> next;
    }

    numOp = atual->op;

    for(int i = 1; i <= numOp; i++){
        minimo = MenorTempo(original, i);
        if (minimo != NULL){
            tempoMinimo += minimo->tempo;
            printf("\nA operacao %d, demora %d segundos\n", i, minimo->tempo);
        }
    }

    return tempoMinimo;
}

/**
 * @brief Percorre a lista e calcula a média de tempo através de um somatório e um contador
 * 
 * @param inicio Inicio da lista  
 * @param cont Contador do numero de elementos
 * @param sum Somatorio dos valores de tempo
 * @param media Variavel aonde é calculada a média dos tempos
 * @return Média das quantidades de tempo  
 */
float mediaQuantidade(Maquina *inicio, int numeroOp){
    if (!inicio) return -1;

    int cont = 0;
    int sum = 0;
    float media = 0.0;

    Maquina *atual = inicio;
    if (inicio){
        while(atual && atual->op != numeroOp){
            atual = atual->next;
        }
            while (atual && atual->op == numeroOp){
                cont++;
                sum += atual->tempo;
                atual = atual->next;
            }   
            if (cont != 0){
                media = (float)sum / cont;
            }
    }
    return media;
}

/**
 * @brief Lista uma Maquina criada anteriormente
 * 
 * @param inicio Inicio da lista a ser apresentada
 */
void ListaMaquina(Maquina *inicio){
    if (inicio){
        printf("%d, %d ,%d\n", inicio->op, inicio->proc, inicio->tempo);
        ListaMaquina(inicio->next);
    }
}
