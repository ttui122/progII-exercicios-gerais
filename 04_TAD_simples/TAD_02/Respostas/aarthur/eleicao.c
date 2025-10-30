#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"

tEleicao InicializaEleicao(){
    tEleicao e;
    
    e.votosBrancosGovernador = 0;
    e.votosNulosGovernador = 0;
    e.totalGovernadores = 0;
    
    e.votosBrancosPresidente = 0;
    e.votosNulosPresidente = 0;
    e.totalPresidentes = 0;

    e.totalEleitores = 0;

    int qtdCandidatos;

    scanf("%d", &qtdCandidatos);

    for (int i = 0; i < qtdCandidatos; i++){
        tCandidato candidato = LeCandidato();

        if (ObtemCargo(candidato) == 'P') {
            e.presidentes[e.totalPresidentes] = candidato;
            e.totalPresidentes++;
        }
        else if (ObtemCargo(candidato) == 'G') {
            e.governadores[e.totalGovernadores] = candidato;
            e.totalGovernadores++;
        }
    }

    return e;

}

tEleicao RealizaEleicao(tEleicao eleicao){
    
    scanf("%d", &eleicao.totalEleitores);
    
    if (eleicao.totalEleitores > 10) {
        printf("ELEICAO ANULADA\n");
        exit(0);
    }
    
    for (int i = 0; i < eleicao.totalEleitores; i++){
        tEleitor eleitor = LeEleitor();
        eleicao.eleitores[i] = eleitor;
    }
    
    for (int i = 0; i < eleicao.totalEleitores; i++){
        int candidatoEncontrado = 0;

        tEleitor eleitorAtual = eleicao.eleitores[i];

        int votoP = ObtemVotoPresidente(eleitorAtual);
        int votoG = ObtemVotoGovernador(eleitorAtual);
        
        for (int j = 0; j < eleicao.totalEleitores; j++){
            if (i != j && EhMesmoEleitor(eleitorAtual, eleicao.eleitores[j])){
                printf("ELEICAO ANULADA\n");
                exit(0);
            }
        }

        if (votoP == 0) {
            eleicao.votosBrancosPresidente++;
            candidatoEncontrado = 1;
        }
        else {
            for (int k = 0; k < eleicao.totalPresidentes; k++){
                if (VerificaIdCandidato(eleicao.presidentes[k], votoP)) {
                    eleicao.presidentes[k] = IncrementaVotoCandidato(eleicao.presidentes[k]);
                    candidatoEncontrado = 1;
                    break;
                }

            }
        }

        if (!candidatoEncontrado) eleicao.votosNulosPresidente++;
        
        candidatoEncontrado = 0;

        if (votoG == 0) {
            eleicao.votosBrancosGovernador++;
            candidatoEncontrado = 1;
        }
        else {
            for (int k = 0; k < eleicao.totalGovernadores; k++){
                if (VerificaIdCandidato(eleicao.governadores[k], votoG)) {
                    eleicao.governadores[k] = IncrementaVotoCandidato(eleicao.governadores[k]);
                    candidatoEncontrado = 1;
                    break;
                }
            }
        }
        
        if (!candidatoEncontrado) eleicao.votosNulosGovernador++;
        
    }

    return eleicao;

}

void ImprimeResultadoEleicao(tEleicao eleicao){
    int maiorVotosP = 0;
    int votosPresAtual, indexPres;
    int totalVotosPres = 0;

    int maiorVotosG = 0;
    int votosGovAtual, indexGov;
    int totalVotosGov = 0;

    int empate = 0;

    printf("- PRESIDENTE ELEITO: ");

    for (int i = 0; i < eleicao.totalPresidentes; i++){
        
        votosPresAtual = ObtemVotos(eleicao.presidentes[i]);
        totalVotosPres += votosPresAtual;

        if (votosPresAtual > maiorVotosP) {
            maiorVotosP = votosPresAtual;
            indexPres = i;
        }

    }

    for (int i = 0; i < eleicao.totalPresidentes; i++){
        if (i != indexPres && ObtemVotos(eleicao.presidentes[i]) == maiorVotosP) empate = 1;
    }
    
    totalVotosPres += eleicao.votosNulosPresidente + eleicao.votosBrancosPresidente;

    tCandidato presidente = eleicao.presidentes[indexPres];

    if (!empate && maiorVotosP < eleicao.votosBrancosPresidente+eleicao.votosNulosPresidente) printf("SEM DECISAO\n");
    else if (empate) printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    else ImprimeCandidato(presidente, CalculaPercentualVotos(presidente, totalVotosPres));

    printf("- GOVERNADOR ELEITO: ");

    empate = 0;

    for (int i = 0; i < eleicao.totalGovernadores; i++){
        
        votosGovAtual = ObtemVotos(eleicao.governadores[i]);
        totalVotosGov += votosGovAtual;

        if (votosGovAtual > maiorVotosG) {
            maiorVotosG = votosGovAtual;
            indexGov = i;
        }

    }

    for (int i = 0; i < eleicao.totalGovernadores; i++){
        if (i != indexGov && ObtemVotos(eleicao.governadores[i]) == maiorVotosG) empate = 1;
    }
    

    totalVotosGov += eleicao.votosNulosGovernador + eleicao.votosBrancosGovernador;

    tCandidato governador = eleicao.governadores[indexGov];

    if (!empate && maiorVotosG < eleicao.votosBrancosGovernador+eleicao.votosNulosGovernador) printf("SEM DECISAO\n");
    else if (empate) printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    else ImprimeCandidato(governador, CalculaPercentualVotos(governador, totalVotosGov));

    printf("- NULOS E BRANCOS: %d, %d", eleicao.votosNulosPresidente+eleicao.votosNulosGovernador, eleicao.votosBrancosPresidente+eleicao.votosBrancosGovernador);

}