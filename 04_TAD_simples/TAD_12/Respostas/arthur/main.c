#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "lesao.h"
#include "data.h"

#define MAX_PACIENTES 100

void imprimeRelatorio(int numPacientes, int somaIdades, int numLesoes, int numCirurgias, Paciente *pacientes){
    int mediaIdade;

    printf("TOTAL PACIENTES: %d\n", numPacientes);
    if (numPacientes != 0 && somaIdades != 0) {
        mediaIdade = somaIdades/numPacientes;
        printf("MEDIA IDADE (ANOS): %d\n", mediaIdade);
    }
    else printf("MEDIA IDADE (ANOS): -\n");
    printf("TOTAL LESOES: %d\n", numLesoes);
    printf("TOTAL CIRURGIAS: %d\n", numCirurgias);
    printf("LISTA DE PACIENTES:\n");
    for (int i = 0; i < numPacientes; i++){
        imprimePaciente(pacientes[i]);
    }
}


int main(){
    char comando;
    char cartaoSusLesao[MAX_CARTAO_LES];
    char cartaoSusPaciente[MAX_CARTAO_SUS];
    int numPacientes = 0;
    int numLesoes = 0;
    int numCirurgias = 0;
    int somaIdades = 0;

    Data dataBase = {12, 9, 2023};

    Paciente pacientes[MAX_PACIENTES];
    Paciente p;

    Lesao l;


    while (1){
        scanf("%c\n", &comando);

        if (comando == 'P' && numPacientes < MAX_PACIENTES){
            p = lerPaciente();
            pacientes[numPacientes] = p;
            numPacientes++;
            somaIdades += calculaIdadePaciente(p, dataBase);
        }
        else if (comando == 'L'){
            l = lerLesao();
            getCartaoSusLesao(l, cartaoSusLesao);
            
            for (int i = 0; i < numPacientes; i++){
                getCartaoSusPaciente(pacientes[i], cartaoSusPaciente);
                if (!strcmp(cartaoSusLesao, cartaoSusPaciente)){
                    pacientes[i] = vinculaLesaoPaciente(pacientes[i], l);
                    numLesoes++;
                    if (verificaCirurgicaLesao(l)) numCirurgias++;
                }
            }

        }
        else if (comando == 'F') break;

    }

    imprimeRelatorio(numPacientes, somaIdades, numLesoes, numCirurgias, pacientes);

    return 0;

}
