#include <stdio.h>
 
int main() {

    int Time, Speed;                       // Declaração de variáveis inteiras
    float Fuel_needed;                     // Declaração de variáveis flutuantes
    scanf("%d",&Time);                     // Usuário digita o tempo de viagem
    scanf("%d",&Speed);                    // Usuário digita a velocidade média do carro    
    Fuel_needed=((Time*Speed)/12.0);       // Realiza o cálculo do combustível gasto no percurso
    printf("%.3f\n",Fuel_needed);          // Retorna a quantidade de combustível necessário
    return 0;
}