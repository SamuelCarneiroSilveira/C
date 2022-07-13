/*
    Implementando o comportamento 1

    Ao ligar o GPIO 4 ao GND deve acionar o GPIO 10 como saída

    GPIO 4  == WPI 7  == Pino Físico 7 
    GPIO 10 == WPI 12 == Pino Físico 19 
*/

#include <wiringPi.h> // controle de GPIO
#include <stdio.h> // texto
#include <stdlib.h> // Para usar exit() e pause()
#include <unistd.h> // Para usar exit() e pause()
#include <signal.h> // shutDown limpo

#define bt1 7

#define led1 12

int encerra = 0;

void limpar(int signo){
    
    encerra = 1;

    // exit(0); acho que esse comando kita o programa
}

int main(void){

    // Garante que saídas bruscas sejam capturadas
    signal(SIGHUP,limpar);
    signal(SIGINT,limpar);
    signal(SIGTERM,limpar);

    // Setup dos pinos como WPI
    wiringPiSetup();

    // Setup dos botões com INPUT
    pinMode(bt1,INPUT);

    // Setup do pullUp interno - resistor interno no VCC - Recebe GND
    pullUpDnControl(bt1,PUD_UP);

    // Setup dos leds 
    pinMode(led1, OUTPUT);
    digitalWrite(led1, LOW);

    while(!encerra){

        while(!digitalRead(bt1)){
            // printf("\n Apertado \n");
            digitalWrite(led1, HIGH);
            delay(200);
        } 
         digitalWrite(led1, LOW);
        //  printf("\n");
         delay(50);
        
    }

    // Sequencia de encerramento

    digitalWrite(led1,LOW);
    pinMode(led1,INPUT);
    pullUpDnControl(bt1,PUD_DOWN);

    printf("\n");
    printf("Funcionou");
    printf("\n");

    // pause(); Testar com e sem

    return 0;
}