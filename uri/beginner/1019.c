#include <stdio.h>
 
int main() {

    int Time_total, Hours, Minutes, Seconds;           // Declaração de variáveis inteiras
    scanf("%d",&Time_total);                           // Usuário digita o tempo total em segundos
    Hours=Time_total/3600;                             // Realiza o calculo do número de horas
    Minutes=(Time_total-(Hours*3600))/60;              // Realiza o calculo do número de minutos
    Seconds=(Time_total-(Hours*3600)-(Minutes*60));    // Realiza o calculo do número de segundos
    printf("%d:%d:%d\n",Hours,Minutes,Seconds);          // Retorna o valor total dividido
    return 0;
}