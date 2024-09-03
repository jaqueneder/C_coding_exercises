// Jaqueline Neder Maiorino

// Considere a necessidade de armazenar informações sobre produtos em um supermercado. Cada produto deve conter os seguintes atributos:
// Nome do produto (uma string de até 50 caracteres)
// Preço do produto (um número de ponto flutuante)
// Quantidade em estoque (um número inteiro)
// Escreva um programa em C que permita ao usuário cadastrar informações de até 5 produtos. Se o número for inválido, continuar perguntando até receber um valor válido
// Após o cadastro, o programa deve exibir na tela os dados de todos os produtos cadastrados, incluindo nome, preço e quantidade em estoque.

#include <stdio.h>
#include <string.h>

typedef struct Produto
{
    char nomeProd[51];
    double valorProd;
    int quantProd;
} Produto;

void leProdutos(Produto produtos[], int n);
void imprimeProdutos(Produto produtos[], int n);

int main()
{
    Produto produtos[5];
    int n;

    printf("digite a quantidade de produtos para cadastrar: ");
    scanf("%d", &n);

    while (n > 5)
    {
        printf("numero invalido! digite a quantidade de produtos para cadastrar: ");
        scanf("%d", &n);
    }
    getchar();

    leProdutos(produtos, n);

    imprimeProdutos(produtos, n);
}

void leProdutos(Produto produtos[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("digite o nome do produto: ");
        fgets(produtos[i].nomeProd, 50, stdin);
        produtos[i].nomeProd[strlen(produtos[i].nomeProd) - 1] = '\0';
        printf("digite o valor do produto: ");
        scanf("%lf", &produtos[i].valorProd);
        getchar();
        printf("digite a quantidade de produtos: ");
        scanf("%d", &produtos[i].quantProd);
        getchar();
        fflush(stdin);
    }
}

void imprimeProdutos(Produto produtos[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\nproduto %d: \n", i + 1);
        printf("nome do produto: %s\n valor do produto: %lf\n quantidade de produtos:%d\n", produtos[i].nomeProd, produtos[i].valorProd, produtos[i].quantProd);
    }
}
