#include <stdio.h>

int main(void){

    int base, heigth, area;

    printf("type base:");
    scanf("%i", &base);
    printf("type height");
    scanf("%i", &heigth);
    
    area = base * heigth;

    printf("The total area is %i\n", area);

    return 0;
}