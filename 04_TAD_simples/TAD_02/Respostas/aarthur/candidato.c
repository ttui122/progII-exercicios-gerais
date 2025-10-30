#include <stdio.h>
#include <string.h>
#include "candidato.h"

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato c;

    strcpy(c.nome, nome);
    strcpy(c.partido, partido);
    c.cargo = cargo;
    c.id = id;
    c.votos = 0;
    
    return c;
}

tCandidato LeCandidato(){
    char nome[101], partido[101], cargo;
    int id;
    
    
    scanf(" %[^,], %[^,], %c, %d\n", nome, partido, &cargo, &id);
    
    tCandidato c = CriaCandidato(nome, partido, cargo, id);
    
    return c;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato){
    candidato.votos += 1;
    return candidato;
}

int VerificaIdCandidato(tCandidato candidato, int id){
    return candidato.id == id;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2){
    return candidato1.id == candidato2.id;
}

char ObtemCargo(tCandidato candidato){
    return candidato.cargo;
}

int ObtemVotos(tCandidato candidato){
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos){
    return (float)candidato.votos/(float)totalVotos * 100.0;
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos){
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}


