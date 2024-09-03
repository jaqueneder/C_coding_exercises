// Desafio Tetris
// O programa simula uma versão do jogo Tetris, onde todos os blocos são retângulos e o tabuleiro tem tamanho fixo 10x10.
// O jogador pode rotacionar e deslocar horizontalmente cada bloco que cai do topo do tabuleiro antes que ele seja posicionado.
// O objetivo do jogo é remover linhas completamente preenchidas para ganhar pontos.

// Briena Bertoni - RA:2760482321033
// Heloisa Moraes - RA:2760482321006
// Jaqueline Neder - RA:2760482321031
// Vannilia Lima - RA:2760482321038
// Yago Sigognini - RA:2760482321037

#include <stdio.h>

// Definição das dimensões do tabuleiro
// Váriaveis globais que serão utilizadas ao longo de todo o programa
#define alturaTabuleiro 10
#define larguraTabuleiro 10

// Função: atualizaPosicao
//
// Parâmetros:
//  *ponteiroLargura: apontador para a largura do bloco que irá cair
//  *ponteiroAltura: apontador para a altura do bloco que irá cair
//  *ponteiroHorizontal: apontador para a posição horizontal inicial do bloco que irá cair
//  deslocamentoHorizontal: deslocamento horizontal a ser aplicado ao bloco (positivo para direita, negativo para a esquerda)
//  rotacionarBloco: 1 se deve rotacionarBlocoacionar o bloco, 0 caso contrário
//
// Retorno:
//  NULL
void atualizaPosicao(int *ponteiroLargura, int *ponteiroAltura, int *ponteiroHorizontal, int deslocamentoHorizontal, int rotacionarBloco)
{
    if (rotacionarBloco)
    {
        int temp = *ponteiroLargura; // A variável 'temp' armazena temporariamente a largura do bloco
        *ponteiroLargura = *ponteiroAltura;
        *ponteiroAltura = temp;
    }
    *ponteiroHorizontal += deslocamentoHorizontal; // Atualiza a posição horizontal com o deslocamento horizontal
    if (*ponteiroHorizontal < 0)
        *ponteiroHorizontal = 0;
    if (*ponteiroHorizontal + *ponteiroLargura > larguraTabuleiro)
        *ponteiroHorizontal = larguraTabuleiro - *ponteiroLargura; // Garante que o bloco não seja maior que a largura do tabuleiro
}

// Função: encontraAltura
//
// Parâmetros:
//  matriz: matriz representando o tabuleiro
//  larguraBloco: largura do bloco que irá cair
//  posHorizontal: posição horizontal do bloco que irá cair
//
// Retorno:
//  Altura final do canto inferior esquerdo do bloco após este descer o máximo possível
int encontraAltura(int matriz[alturaTabuleiro][larguraTabuleiro], int larguraBloco, int posHorizontal)
{
    int alturaCalculada = alturaTabuleiro;
    for (int i = 0; i < larguraBloco; i++)
    {
        int alturaMax = 0;
        while (alturaMax < alturaTabuleiro && matriz[alturaMax][posHorizontal + i] == 0)
        {
            alturaMax++; // Encontra a primeira posição ocupada na coluna do bloco
        }
        if (alturaMax < alturaCalculada)
        {
            alturaCalculada = alturaMax; // Atualiza a altura mínima possível para o bloco
        }
    }
    return alturaCalculada - 1; // Retorna a altura final do bloco
}

// Função: posFinal
// Parâmetros:
//  alturaBloco: altura do bloco que caiu
//  alturaFinal: altura final do bloco que caiu
// Retorno:
//  1 se o bloco naquela posição estiver contido dentro do tabuleiro, ou 0 caso contrário.
int posFinal(int alturaBloco, int alturaFinal)
{
    return alturaFinal + 1 >= alturaBloco; // Verifica se o bloco está completamente dentro do tabuleiro
}

// Função: posicionaBloco
//
// Parâmetros:
//  matriz: matriz do tabuleiro
//  larguraNovoBloco: largura do novo bloco
//  alturaNovoBloco: altura do novo bloco
//  posHorizontalNova: posição horizontal do novo bloco
//  alturaFinalNovoBloco: altura final do novo bloco
//
// Retorno:
//  NULL

void posicionaBloco(int matriz[alturaTabuleiro][larguraTabuleiro], int larguraNovoBloco, int alturaNovoBloco, int posHorizontalNova, int alturaFinalNovoBloco)
{
    for (int i = 0; i < alturaNovoBloco; i++)
    {
        for (int j = 0; j < larguraNovoBloco; j++)
        {
            matriz[alturaFinalNovoBloco - i][posHorizontalNova + j] = 1; // Marca a posição do bloco no tabuleiro
        }
    }
}

// Função: atualizaMatriz
//
// Parâmetros:
//  matriz: matrizriz do tabuleiro
//
// Retorno:
//  Retorna o número de linhas totalmente preenchidas que foram removidas após a atualização do tabuleiro.
int atualizaMatriz(int matriz[alturaTabuleiro][larguraTabuleiro])
{
    int linhasRemovidas = 0;
    for (int i = 0; i < alturaTabuleiro; i++)
    {
        int linhasPreenchidas = 1;
        for (int j = 0; j < larguraTabuleiro; j++)
        {
            if (matriz[i][j] == 0)
            {
                linhasPreenchidas = 0; // Verifica se a linha não está completamente preenchida
                break;
            }
        }
        if (linhasPreenchidas)
        {
            linhasRemovidas++;
            for (int k = i; k > 0; k--)
            {
                for (int j = 0; j < larguraTabuleiro; j++)
                {
                    matriz[k][j] = matriz[k - 1][j]; // Desce todas as linhas
                }
            }
            for (int j = 0; j < larguraTabuleiro; j++)
            {
                matriz[0][j] = 0; // Limpa a linha superior
            }
        }
    }
    return linhasRemovidas; // Retorna o número de linhas removidas
}

int main()
{
    int tabuleiro[alturaTabuleiro][larguraTabuleiro] = {0};
    int largura, altura, posHorizon, deslocamentoHorizontal, rotacionarBloco;
    int numBlocos;

    printf("Digite o numero de blocos: "); // Entrada do número de blocos
    scanf("%d", &numBlocos);

    int pontos = 0; // Contagem de pontos

    for (int i = 0; i < numBlocos; i++)
    {
        printf("Digite os dados do bloco %d (largura, altura, posicionamento horizontal, deslocamento horizontal e rotacao): ", i);
        scanf("%d %d %d %d %d", &largura, &altura, &posHorizon, &deslocamentoHorizontal, &rotacionarBloco);

        atualizaPosicao(&largura, &altura, &posHorizon, deslocamentoHorizontal, rotacionarBloco); // Atualiza a posição do bloco
        int alturaCalc = encontraAltura(tabuleiro, largura, posHorizon);                          // Encontra a altura final do bloco

        if (posFinal(altura, alturaCalc))
        {
            posicionaBloco(tabuleiro, largura, altura, posHorizon, alturaCalc); // Posiciona o bloco no tabuleiro
            pontos += atualizaMatriz(tabuleiro);                                // Atualiza o tabuleiro e soma os pontos
            printf("Bloco: %d\nPontos: %d\n", i, pontos);

            for (int linha = 0; linha < alturaTabuleiro; linha++)
            {
                for (int coluna = 0; coluna < larguraTabuleiro; coluna++)
                {
                    printf("%d", tabuleiro[linha][coluna]); // Imprime o estado atual do tabuleiro
                }
                printf("\n");
            }
        }
        else
        {
            printf("Movimento invalido! O jogo foi encerrado.\n");
            break; // Encerra o jogo se a posição final não for válida
        }
    }
    return 0;
}
