/*
    Implementando o comportamento 2

    Ao ligar o GPIO 4 ao GND deve acionar o GPIO 10 como saída

    Quando o botão associado ao gpio20 estiver acionado, a leitura
    do gpio4 deve ser interrompida, e a porta gpio2 deve estar em high

    GPIO 4  == WPI 7  == Pino Físico 7 
    GPIO 10 == WPI 12 == Pino Físico 19 

    GPIO 20 == WPI 28 == Pino Físico 38 
    GPIO 2 == WPI 8 == Pino Físico  3
*/

#include <wiringPi.h> // controle de GPIO
#include <stdio.h> // texto
#include <stdlib.h> // Para usar exit() e pause()
#include <unistd.h> // Para usar exi    t() e pause()
#include <signal.h> // shutDown limpo

#define bt1 7
#define bt2 28

#define led1 12
#define led2 8

int encerra = 0;

void funcaoBotao1(){
    digitalWrite(led1, HIGH);
    delay(200);
}

void funcaoBotao2(){
    digitalWrite(led2, HIGH);
    delay(200);
}
    
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
    pinMode(bt2,INPUT);

    // Setup do pullUp interno - resistor interno no VCC - Recebe GND
    pullUpDnControl(bt1,PUD_UP);
    pullUpDnControl(bt2,PUD_UP);

    // Setup dos leds 
    pinMode(led1, OUTPUT);
    digitalWrite(led1, LOW);
    pinMode(led2, OUTPUT);
    digitalWrite(led2, LOW);

    while(!encerra){

        while(!digitalRead(bt1) && digitalRead(bt2)){
            // printf("\n Apertado \n");
            funcaoBotao1();
        } 
        digitalWrite(led1, LOW);

        while(!digitalRead(bt2)){ // remover a condição ligada ao bt1 (digitalRead(bt1) && )
            funcaoBotao2();
        }
         
        digitalWrite(led2, LOW);
         delay(50);
        //  printf("\n");
        
    }

    // Sequencia de encerramento

    digitalWrite(led1,LOW);
    pinMode(led1,INPUT);
    pullUpDnControl(bt1,PUD_DOWN);
    digitalWrite(led2,LOW);
    pinMode(led2,INPUT);
    pullUpDnControl(bt2,PUD_DOWN);

    printf("\n");
    printf("Funcionou");
    printf("\n");


    //pause(); // Testar com e sem
    // exit(0);
    return 0;
}