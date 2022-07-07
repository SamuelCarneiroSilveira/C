#include <stdio.h>

int main(void){

    int myAge = 23;
    int momAge = 60;
    int dadAge = 58;
    int brotherAge = 40;

    int totalAge;

    totalAge = myAge * momAge / dadAge + brotherAge;

    printf("Total age %i\n", totalAge * 100);

    return 0;
}