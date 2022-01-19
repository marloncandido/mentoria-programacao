#include<PIC16LF876A.h>
#include<stdio.h>
#include<xc.h>


// PIC16LF876A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


#define S2 (PORTB & 0x02)                                    // Define tecla de incremento de velocidade em RB1
#define S3 (PORTB & 0x04)                                    // Define tecla de decremento de velocidade em RB2

// DefiniÃ§Ã£o das variÃ¡veis:
int Velocidade = 0;                                          // Motor desligado
int Tempo_decorrido_us = 0;
int Tempo_disparo_us = 8330;
int Tempos_disparo_us[] = {20000, 6660, 5410, 4580, 4160, 0};

void __interrupt() ISR (void)
{
    if (INTCON & 0x04)                                       // verifica se a interrupÃ§Ã£o Ã© de Timer0
    {
        TMR0 =  0x82;                                        // Inicia no ciclo 130 e conta atÃ© 255, total de 125 ciclos
        Tempo_decorrido_us += 100;                           // Somando 100 us ao contador
        if ((Tempo_decorrido_us < Tempo_disparo_us) || (Tempo_decorrido_us > (Tempo_disparo_us + 300)))
            PORTC = PORTC & 0xFB;                            // Desaciona o TRIAC
        else
            PORTC = PORTC | 0x04;                            // Aciona o TRIAC

        INTCON = INTCON & 0xFB;                              // Limpa flag de interrupÃ§Ã£o do Timer0
    }
    
                                                             //  verifica se a interrupÃ§Ã£o Ã© de RB0
    if (INTCON & 0x02)                                       // Se RB0 for igual a um                      
    {
        TMR0 =  0x82;                                        // Inicia no ciclo 130 e conta atÃ© 255, total de 125 ciclos
        Tempo_decorrido_us = 0;
        INTCON = INTCON & 0xFD;                              // Limpa flag de interrupÃ§Ã£o do RB0
    }
    return;
}


void main(void)
{
    TRISA = 0x00;  //00 0000                                 // Configura terminais RA0 a RA5 como saÃ­das
    TRISB = 0x07;  //0000 0111                               // Configura terminais RB0 a RB2 como entradas e RB3 a RB7 como saÃ­das
    TRISC = 0x00;  //0000 0000                               // Configura terminais RC0 a RC7 como saÃ­das
    PORTA = 0x00;  //00 0000                                 // Inicializa PORTA
    PORTB = 0x07;  //0000 0111                               // Inicializa PORTB
    PORTC = 0x00;  //0000 0000                               // Inicializa PORTC
    INTCON = 0xF0; //1111 0000                               // Limpa flag de interrupÃ§Ã£o e habilita interrupÃ§Ã£o de RB0, timer0, perifÃ©ricos e global
    PIE1 = 0;                                                // Garante que os perifÃ©ricos nÃ£o utilizados nÃ£o gerem interrupÃ§Ãµes
    OPTION_REG = 0x41;                                       // Habilita Prescaler 1:4, InterrupÃ§Ã£o de 0 pra 1 em RB0
    TMR0 = 0x82;                                             // Inicia no ciclo 130 e conta atÃ© 255, total de 125 ciclos
     
    // DefiniÃ§Ã£o das variÃ¡veis:
    int S2_anterior = S2;                                    // Comparar estado da tecla de Incremento
    int S3_anterior = S3;                                    // Comparar estado da tecla de Decremento

    do
    {
        if (S2 != S2_anterior)                               // Tecla de incremento pressionada?
        {
            S2_anterior = S2;

            if (!S2)
            {
                if(Velocidade < 5)
                {
                    Velocidade++;
                    Tempo_disparo_us = Tempos_disparo_us[Velocidade];
                }
            }
        }
        else if (S3 != S3_anterior)                          // Tecla de decremento pressionada?
        {
            S3_anterior = S3;
                
            if (!S3)
            {
                if(Velocidade > 0)
                {
                    Velocidade--;
                    Tempo_disparo_us = Tempos_disparo_us[Velocidade];
                }
            }
        }

           
        if(Velocidade == 0)PORTA = PORTA & 0xE0;             // Motor desligado
        if(Velocidade == 1) PORTA = (PORTA & 0xE0) | 0x01;   // Motor na velocidade 1
        if(Velocidade == 2) PORTA = (PORTA & 0xE0) | 0x02;   // Motor na velocidade 2
        if(Velocidade == 3) PORTA = (PORTA & 0xE0) | 0x04;   // Motor na velocidade 3
        if(Velocidade == 4) PORTA = (PORTA & 0xE0) | 0x08;   // Motor na velocidade 4
        if(Velocidade == 5) PORTA = (PORTA & 0xE0) | 0x20;   // Motor na velocidade 5
    }
    
    while(1);
}