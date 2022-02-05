/* 
 * File:   DC Motor speed control.c
 * Author: marlon.candido
 *
 * Created on 18 de Janeiro de 2022, 13:04
 */


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

// Definição das variáveis:
int Velocidade = 0;                                          // Motor desligado


void main(void)
{
    TRISA = 0x00;  //00 0000                                 // Configura terminais RA0 a RA5 como saídas
    TRISB = 0x06;  //0000 0110                               // Configura terminais RB1 e RB2 como entradas e RB0, RB3 a RB7 como saídas
    TRISC = 0x00;  //0000 0000                               // Configura terminais RC0 a RC7 como saídas
    PORTA = 0x00;  //00 0000                                 // Inicializa PORTA
    PORTB = 0x07;  //0000 0111                               // Inicializa PORTB
    PORTC = 0x00;  //0000 0000                               // Inicializa PORTC
    INTCON = 0x00; //0000 0000                               // Desabilita todas as interrupções
    CCP1CON = 0x0C; //0000 1100                              // 2 bits menos significativos do PWM Duty Cycle
    CCPR1L = 0xFF; //1111 1111                               // 8 bits mais significativos do PWM Duty Cycle
    PR2 = 0xFF; //1111 1111                                  // Período total igual a 1/1,22 kHz
    T2CON = 0x07; //0000 0111                                // Prescaler 1:16, Timer2 on, Postscaler 1:1
     
    // Definição das variáveis:
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
                    CCPR1L -= 0x33;                          // Incrementa 20% na velocidade
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
                    CCPR1L += 0x33;                          // Decrementa 20% na velocidade
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