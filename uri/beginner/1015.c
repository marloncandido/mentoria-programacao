#include <stdio.h>
#include <math.h>
 
int main() {

    double X1, X2, Y1, Y2, Distance;                    // Declaração de variáveis flutuantes
    scanf("%lf",&X1);                                   // Usuário digita a coordenada X do ponto 1
    scanf("%lf",&Y1);                                   // Usuário digita a coordenada Y do ponto 1    
    scanf("%lf",&X2);                                   // Usuário digita a coordenada X do ponto 2
    scanf("%lf",&Y2);                                   // Usuário digita a coordenada Y do ponto 2  
    Distance=sqrt(((X2-X1)*(X2-X1))+((Y2-Y1)*(Y2-Y1))); // Realiza o cálculo da distancia
    printf("%.4lf\n",Distance);                         // Retorna o valor do consumo em km/l
    return 0;
}