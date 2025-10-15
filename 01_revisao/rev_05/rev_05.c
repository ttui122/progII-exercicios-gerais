#include <stdio.h>

char buscarAdjacente(int posX, int posY, int linhas, int colunas, int matriz[linhas][colunas], char prioridade[]){
    int posMatrizX = posX - 1;
    int posMatrizY = posY - 1;
    int letra;
    char direcao;
    char retorno = ' ';
    
    for (letra = 0; letra < 4; letra++){
        direcao = prioridade[letra];

        if (direcao == 'B' && posMatrizY < linhas && matriz[posMatrizY+1][posMatrizX] == 0) {
            retorno = 'B';
            break;
        }
        else if (direcao == 'C' && posMatrizY != 0 && matriz[posMatrizY-1][posMatrizX] == 0) {
            retorno = 'C';
            break;
        }
        else if (direcao == 'D' && posMatrizX < colunas && matriz[posMatrizY][posMatrizX+1] == 0) {
            retorno = 'D';
            break;
        }
        else if (direcao == 'E' && posMatrizX != 0 && matriz[posMatrizY][posMatrizX-1] == 0) {
            retorno = 'E';
            break;
        }
    }

    return retorno;

}


int main(){
    int i, j, c;
    int inicio = 0;
    int linhas, colunas;
    int posInicialX, posInicialY;
    int posFinalX, posFinalY;
    int posX, posY;
    char prioridade[4];
    char direcao;

    scanf("%d %d", &linhas, &colunas);

    int matriz[linhas][colunas];

    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    scanf("%d %d", &posInicialY, &posInicialX);
    scanf("%d %d", &posFinalY, &posFinalX);
    for (c = 0; c < 4; c++){
        scanf(" %c", &prioridade[c]);
    }


    while(1){

        if (inicio == 0){
            posX = posInicialX;
            posY = posInicialY;
            printf("(%d,%d) ", posY, posX);
            inicio++;
        }

        if (posX == posFinalX && posY == posFinalY) break;

        direcao = buscarAdjacente(posX, posY, linhas, colunas, matriz, prioridade);   
        matriz[posY-1][posX-1] = 1; 

        if (direcao == 'B'){
            posX = posX;
            posY++;
        }
        else if (direcao == 'C'){
            posX = posX;
            posY--;
        }
        else if (direcao == 'D'){
            posX++;
            posY = posY;
        }
        else if (direcao == 'E'){
            posX--;
            posY = posY;
        }
        else break;

        printf("(%d,%d) ", posY, posX);

    }


    return 0;

}