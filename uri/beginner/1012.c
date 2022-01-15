#include <stdio.h>
 
int main() {

    double A, B, C, TRIANGULO, CIRCULO, TRAPEZIO, QUADRADO, RETANGULO;   // Declaração de variáveis flutuantes
    scanf("%lf",&A);                                                     // Usuário digita o valor de A
    scanf("%lf",&B);                                                     // Usuário digita o valor de B
    scanf("%lf",&C);                                                     // Usuário digita o valor de C
    TRIANGULO=(A*C)/2;                                                   // Realiza o cálculo da área do triangulo
    CIRCULO=3.14159*C*C;                                                 // Realiza o cálculo da área do circulo
    TRAPEZIO=((A+B)*C)/2;                                                // Realiza o cálculo da área do trapezio
    QUADRADO=B*B;                                                        // Realiza o cálculo da área do quadrado
    RETANGULO=A*B;                                                       // Realiza o cálculo da área do retangulo
    printf("TRIANGULO: %.3lf\n",TRIANGULO);                              // Retorna o valor da área do triangulo
    printf("CIRCULO: %.3lf\n",CIRCULO);                                  // Retorna o valor da área do circulo
    printf("TRAPEZIO: %.3lf\n",TRAPEZIO);                                // Retorna o valor da área do trapezio
    printf("QUADRADO: %.3lf\n",QUADRADO);                                // Retorna o valor da área do quadrado
    printf("RETANGULO: %.3lf\n",RETANGULO);                              // Retorna o valor da área do retangulo
    return 0;
}