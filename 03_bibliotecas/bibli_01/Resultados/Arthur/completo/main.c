#include <stdio.h>
#include "esfera_utils.h"

int main(){
    float R, area, volume;

    scanf("%f", &R);

    area = calcula_area(R);
    volume = calcula_volume(R);

    printf("Area: %.2f\nVolume: %.2f\n", area, volume);

    return 0;
}