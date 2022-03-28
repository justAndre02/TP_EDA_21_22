/**
 * @file main.c
 * @author André (a21112@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "functions.h"

int main(){
    Maquina* inicio;
    inicio = NULL;

    Maquina* nova;
    nova = NovaMaquina(1, "teste");
    inicio = InserirMaquina(inicio, nova);

}

