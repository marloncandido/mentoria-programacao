#include <stdio.h>
 
int main() {

    int Distance, Time;                    // Declaração de variáveis inteiras
    scanf("%d",&Distance);                 // Usuário digita a distância entre os dois carros
    Time=Distance*2;                       // Realiza o cálculo do tempo
    printf("%d minutos\n",Time);           // Retorna o valor do tempo de viagem necessário 
    return 0;
}