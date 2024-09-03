// Aluna: Briena Bertoni RA: 2760482321033
// Aluna: Jaqueline Neder RA: 2760482321031

// Desenvolver um programa em C que realize operações básicas de manipulação de string sem textos depostagens em uma mídia social fictícia.
// O programa deverá ser capaz de:
// 1.Ler até 5 postagens, onde cada postagem possui um limite de 500 caracteres;
// 2.Contar o número total de palavras em cada postagem e calcular a média de palavras de todas as postagens;
// 3.Mostrar quais são as 3 palavras que mais aparecem nas postagens.
// Excluir artigos(exemplos: a, e, o), preposições(exemplos: em, antes, desde, entre)e pronomes(exemplos: ele, ela, dele, dela).

#include <stdio.h>
#include <string.h>

#define MAXPOSTAGENS 5
#define MAXPALAVRAS 300
#define TAMPALAVRA 15

int main()
{
    // Criação das varíaveis.
    char postagens[MAXPOSTAGENS][501];
    char totalPalavras[MAXPALAVRAS][TAMPALAVRA];
    int totalOcorrencias[MAXPALAVRAS] = {0};
    int numDiferentes = 0;
    int palavrasTotal = 0;
    int anterior = 0;
    int numPostagens, i, palavrasPostagem, media;

    // Definição da quantidade de postagens.
    printf("digite a quantidade de postagens (MAX %d): \n", MAXPOSTAGENS);
    scanf("%d", &numPostagens);
    getchar();

    // Armazenamento das postagens nos vetores.
    if (numPostagens > 0 && numPostagens <= MAXPOSTAGENS)
    {
        for (i = 0; i < numPostagens; i++)
        {
            printf("digite a postagem %d: ", i + 1);
            fgets(postagens[i], 500, stdin);
        }
    }

    // Contagem das palavras por postagem.
    for (int i = 0; i < numPostagens; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            if (postagens[i][j] == ' ' || postagens[i][j] == '\n')
            {
                palavrasTotal++;
            }
            else if (postagens[i][j] == '\0')
            {
                break;
            }
        }
        palavrasPostagem = palavrasTotal - anterior;
        anterior = palavrasTotal;
        printf("\na quantidade de numeros da postagem %d eh: %d.", i + 1, palavrasPostagem);
    }

    // Cálculo da média de palavras das postagens.
    media = palavrasTotal / numPostagens;
    printf("\na media de palavras por postagem eh %d.\n", media);

    // Separação das palavras das postagens em um vetor.
    for (int i = 0; i < numPostagens; i++)
    {
        char *token = strtok(postagens[i], " \n");
        while (token != NULL)
        {
            int palavraExiste = 0;
            // Verifica se uma palavra já existe.
            for (int j = 0; j < numDiferentes; j++)
            {
                if (strcmp(totalPalavras[j], token) == 0)
                {
                    totalOcorrencias[j]++;
                    palavraExiste = 1;
                    break;
                }
            }
            // Caso a palavra ainda não esteja presente, ela é incluída.
            if (!palavraExiste)
            {
                strcpy(totalPalavras[numDiferentes], token);
                totalOcorrencias[numDiferentes]++;
                numDiferentes++;
            }
            token = strtok(NULL, " \n");
        }
    }

    // Definição das 3 palavras mais frequentes.
    printf("\nas palavras mais frequentes nas postagens:\n");
    for (int k = 0; k < 3; k++)
    {
        int maxOcorrencias = 0;
        int indiceOcorrencias = -1;

        for (int i = 0; i < numDiferentes; i++)
        {
            if (totalOcorrencias[i] > maxOcorrencias)
            {
                maxOcorrencias = totalOcorrencias[i];
                indiceOcorrencias = i;
            }
        }

        if (indiceOcorrencias != -1)
        {
            printf("%s\n", totalPalavras[indiceOcorrencias]);
            totalOcorrencias[indiceOcorrencias] = 0;
        }
    }

    return 0;
}
