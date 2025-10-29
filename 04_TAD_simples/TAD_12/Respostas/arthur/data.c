#include <stdio.h>
#include "data.h"


Data criaData(int dia, int mes, int ano){
    Data d = {dia, mes, ano};
    return d; 
}

Data lerData(){
    Data d;
    int dia, mes, ano;

    scanf("%d/%d/%d\n", &dia, &mes, &ano);

    d = criaData(dia, mes, ano);

    return d;
}

int diferencaAnoData(Data inicial, Data atual){
    int idade = atual.ano - inicial.ano;

    if (atual.mes < inicial.mes) idade--;
    else if (atual.mes == inicial.mes && atual.dia < inicial.dia) idade--;

    return idade;

}

void imprimeData(Data d){
    printf("%2d/%2d/%4d\n", d.dia, d.mes, d.ano);
}