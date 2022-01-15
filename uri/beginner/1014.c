#include <stdio.h>
 
int main() {

    int X;                              // Declaração de variáveis inteiras
    float Y, Consumption;               // Declaração de variáveis flutuantes
    scanf("%d",&X);                     // Usuário digita o valor de quilometros percorridos
    scanf("%f",&Y);                     // Usuário digita o valor de combustivel gasto
    Consumption=X/Y;                    // Realiza o cálculo do consumo
    printf("%.3f km/l\n",Consumption);  // Retorna o valor do consumo em km/l
    return 0;
}