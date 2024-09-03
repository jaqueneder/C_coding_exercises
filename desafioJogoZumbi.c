// Jaqueline Neder RA: 2760482321031

// o objetivo deste exercício é criar um programa que simule as interações entre humanos e zumbis em um cenário apocalíptico cada célula pode ser vazia(0), conter um humano(1) ou um zumbi(2).

#include <stdio.h>
int main()
{
    int m, n, dias;

    // entrada dos valores da matriz
    printf("digite a altura da matriz: ");
    scanf("%d", &m);

    printf("digite a largura da matriz: ");
    scanf("%d", &n);

    // entrada da quantidade de dias
    printf("digite a quantidade de dias: ");
    scanf("%d", &dias);

    int matriz[m][n];

    // entrada dos valores da matriz
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("na posicao %d,%d insira o valor: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int dia = 0;
    // interações dos dias
    for (dia = 0; dia <= dias; dia++)
    {
        printf("iteracao %d\n", dia);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d", matriz[i][j]);
            }
            printf("\n");
        }

        int matrizNova[m][n];

        // copiar a matriz original para a nova matriz
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrizNova[i][j] = matriz[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matriz[i][j] == 1)
                { // se for humano
                    int vizinhosHumanos = 0;
                    if (i > 0 && matriz[i - 1][j] == 2)
                        vizinhosHumanos++; // acima
                    if (i < m - 1 && matriz[i + 1][j] == 2)
                        vizinhosHumanos++; // abaixo
                    if (j > 0 && matriz[i][j - 1] == 2)
                        vizinhosHumanos++; // esquerda
                    if (j < n - 1 && matriz[i][j + 1] == 2)
                        vizinhosHumanos++; // direita

                    if (vizinhosHumanos >= 1)
                    {
                        // se o humano tem pelo menos um vizinho zumbi, ele é infectado
                        matrizNova[i][j] = 2;
                    }
                }
                else if (matriz[i][j] == 2)
                { // se for zumbi
                    int vizinhosHumanos = 0;
                    if (i > 0 && matriz[i - 1][j] == 1)
                        vizinhosHumanos++; // acima
                    if (i < m - 1 && matriz[i + 1][j] == 1)
                        vizinhosHumanos++; // abaixo
                    if (j > 0 && matriz[i][j - 1] == 1)
                        vizinhosHumanos++; // esquerda
                    if (j < n - 1 && matriz[i][j + 1] == 1)
                        vizinhosHumanos++; // direita

                    if (vizinhosHumanos >= 2)
                    {
                        // se o zumbi tem dois ou mais vizinhos humanos, ele é morto pelos humanos
                        matrizNova[i][j] = 0;
                    }
                    else if (vizinhosHumanos == 0)
                    {
                        // se um zumbi não tem nenhum vizinho humano, ele morre de fome
                        matrizNova[i][j] = 0;
                    }
                }
                else if (matriz[i][j] == 0)
                { // se a célula está vazia
                    int vizinhosHumanos = 0;
                    if (i > 0 && matriz[i - 1][j] == 1)
                        vizinhosHumanos++; // acima
                    if (i < m - 1 && matriz[i + 1][j] == 1)
                        vizinhosHumanos++; // abaixo
                    if (j > 0 && matriz[i][j - 1] == 1)
                        vizinhosHumanos++; // esquerda
                    if (j < n - 1 && matriz[i][j + 1] == 1)
                        vizinhosHumanos++; // direita

                    if (vizinhosHumanos == 2)
                    {
                        // se uma célula vazia tem exatamente dois vizinhos humanos, um humano nasce na célula
                        matrizNova[i][j] = 1;
                    }
                }
            }
        }

        // atualizar a matriz original com a nova matriz
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matriz[i][j] = matrizNova[i][j];
            }
        }
    }

    return 0;
}