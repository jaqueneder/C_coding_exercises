// Jaqueline Neder Maiorino

// O programa deve determinar pela contagem de pontos quem venceu a luta entre Ryu e Ken.

#include <stdio.h>
int main()
{

  int i, num, perfeito, triangular, ryu, ken, somaDivisores, j;
  perfeito = 0;
  triangular = 0;
  ryu = 0;
  ken = 0;
  somaDivisores = 0;

  printf("digite a sua sequencia de pontos: \n");

  for (i = 1;; i++)
  {
    scanf("%d", &num);

    if (num == 0)
      break; // quando o número digitado for igual a zero, o loop é interrompido.

    somaDivisores = 0;

    if (num > 0)
    {
      for (j = 1; j <= num / 2; j++) // para descobrir se o número é perfeito.
      {
        if (num % j == 0)     // para achar os divisores do número dado pelo usuário.
          somaDivisores += j; // soma dos divisores do número digitado.
      }
      perfeito = somaDivisores == num; // se a soma dos divisores for igual o número digitado, é perfeito.

      somaDivisores = 0;

      for (j = 1; somaDivisores < num; j++) // para descobrir se o número é triangular.
      {
        somaDivisores += j;
      }
      triangular = somaDivisores == num;

      if (perfeito) // se for perfeito cai nessa condição.
      {
        ryu += num * 3;
      }
      else if (triangular) // se for triangular cai nessa condição.
      {
        ryu += num * 2;
      }
      else // se não for perifeito nem triangular, o número é apenas somado.
        ryu += num;
    }

    else
    {
      num = -num; // converte o número negativo digitado para positivo.

      for (j = 1; j <= num / 2; j++)
      {
        if (num % j == 0)
          somaDivisores += j;
      }
      perfeito = somaDivisores == num;
      somaDivisores = 0;

      for (j = 1; somaDivisores < num; j++)
      {
        somaDivisores += j;
      }
      triangular = somaDivisores == num;

      if (perfeito)
      {
        ken += num * 3;
      }
      else if (triangular)
      {
        ken += num * 2;
      }
      else
        ken += num;
    }
  }

  printf("Ryu fez %d pontos e Ken fez %d pontos\n", ryu, ken);

  if (ryu > ken)
    printf("\nRyu venceu!");

  else if (ryu < ken)
    printf("\nKen venceu!");

  else
    printf("\nEmpate!");
}
