// Jaqueline Neder Maiorino

// O programa deve calcular, baseado nos valores solicitados ao usuário, o valor de uma circuferencia completa em Km e na medida de estádios equivalantes a 176,4 metros.

#include <stdio.h>
int main()
{
    double angA, distD, circE, circKm;

    // Entrada da distância D e do ângulo A
    // Solicitação ao usuário da distância em estadios
    printf("digite o valor da distancia em estadios: \n");
    scanf("%lf", &distD);
    // Solicitação ao usuário do valor do ângulo
    printf("digite o valor do angulo: \n");
    scanf("%lf", &angA);
    // A circuferência em Km é calculada a partir da divisão de uma circuferência completa (360°) pelo ângulo-
    // -soliticado, com o objetivo de obter a razão entre esse ângulo e a circunferência completa, o resultado-
    // é multiplicado pela medida de 1 estádio
    circKm = (360.0 / angA) * (distD * (176.4 / 1000));
    // A circuferência em estádios é feita pela divisão da circunferência em Km pela medida de 1 estádio
    circE = circKm / (176.4 / 1000);
    // Saída da circunferência E e da circunferência Km
    printf(" a circunferencia em km e: %.2lf", circKm);
    printf(" a circunferencia em estadios e: %.2lf", circE);
    return 0;
}
