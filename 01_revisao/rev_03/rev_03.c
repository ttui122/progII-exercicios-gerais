#include <stdio.h>

void lerIdentificadores(int Nlivros, int ids[]){
    int i;

    for (i = 0; i < Nlivros; i++){
        scanf("%d", &ids[i]);
    }

}

int naoPossuiCopia(int id, int Nlivros, int ids[]){
    int i;

    for (i = 0; i < Nlivros; i++){
        if (id == ids[i]) return 0;
    }

    return 1;

}

int main(){
    int Nlivros;
    int i;
    int copia = 0;

    scanf("%d\n", &Nlivros);

    int ids[Nlivros];

    lerIdentificadores(Nlivros, ids);

    for (i = 0; i < Nlivros; i++){
        if (naoPossuiCopia(ids[i], Nlivros, ids)) {
            printf("%d ", ids[i]);
            copia++;
        }
    }

    if (copia == 0) printf("NENHUM");

    return 0;

}