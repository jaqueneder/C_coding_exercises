// Jaqueline Neder Maiorino

// Escreva uma função recursiva que resolva o problema das Torres de Hanói para n discos.
// A função deve imprimir cada movimento necessário para resolver o problema.
//     void torresDeHanoi(int n, char origem, char destino, char auxiliar) {
//     }

#include <stdio.h>

void torresDeHanoi(int n, char origem, char destino, char auxiliar);

int main()
{
    int discos;
    char torreOrigem = 'A';
    char torreAux = 'B';
    char torreDestino = 'C';

    printf("\ndigite a quantidade de discos: ");
    scanf("%d", &discos);

    torresDeHanoi(discos, torreOrigem, torreDestino, torreAux);
}

void torresDeHanoi(int n, char origem, char destino, char auxiliar)
{
    // n = 3
    if (n == 1)
    {
        printf("\nmover o disco 1 da torre %c para a torre %c", origem, destino);
        return;
    }
    torresDeHanoi(n - 1, origem, auxiliar, destino);
    printf("\nmover o disco %d da torre %c para a torre %c", n, origem, destino);

    torresDeHanoi(n - 1, auxiliar, destino, origem);
}