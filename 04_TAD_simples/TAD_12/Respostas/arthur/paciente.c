#include <stdio.h>
#include <string.h>
#include "paciente.h"

Paciente criaPaciente(char *nome, char *cartaoSus, char genero, Data dataNasc){
    Paciente p;

    strcpy(p.nome, nome);
    strcpy(p.cartaoSus, cartaoSus);
    p.genero = genero;
    p.dataNasc = dataNasc;
    p.numLesoes = 0;

    return p;  
}

Paciente lerPaciente(){
    Paciente p;
    char nome[MAX_NOME_PAC];
    char cartaoSus[MAX_CARTAO_SUS];
    char genero;
    Data data;

    scanf("%[^\n]\n", nome);
    data = lerData();
    scanf("%[^\n]\n", cartaoSus);
    scanf("%c", &genero);

    p = criaPaciente(nome, cartaoSus, genero, data);

    return p;
}

Paciente vinculaLesaoPaciente(Paciente p, Lesao l){
    if (p.numLesoes < MAX_LESOES){
        p.lesoes[p.numLesoes] = l;
        p.numLesoes++;
    }

    return p;
}

int calculaIdadePaciente(Paciente p, Data dataBase){    
    return diferencaAnoData(p.dataNasc, dataBase);
}

void getCartaoSusPaciente(Paciente p, char *cartaoSus){
    strcpy(cartaoSus, p.cartaoSus);
}

int getNumLesoesPaciente(Paciente p){
    return p.numLesoes;
}

int qtdLesoesCirurgicasPaciente(Paciente p){
    int lesoesCirurgicas = 0;

    for (int i = 0; i < p.numLesoes; i++){
        if (verificaCirurgicaLesao(p.lesoes[i])) lesoesCirurgicas++;
    }

    return lesoesCirurgicas;
}

void imprimePaciente(Paciente p){
    if (p.numLesoes >= 1){
        printf("- %s - ", p.nome);
    
        for (int i = 0; i < p.numLesoes; i++){
            imprimeIdLesao(p.lesoes[i]);
        }
    
        printf("\n");
    }
}