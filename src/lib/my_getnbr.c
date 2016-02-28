/*
** my_getnbr.c for Piscine_C_J04 in /home/troncy_l/rendu/Piscine_C_J04
** 
** Made by Lucas TRONCY
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Oct  1 10:30:57 2015 Lucas TRONCY
** Last update Sun Dec 27 21:43:25 2015 
*/

#include "main.h"

int	my_pow(int a, int b)
{
  int	result;

  result = 1;
  while (b)
    {
      result *= a;
      b--;
    }
  return (result);
}

void	calculation(struct lol_norme *norme, char *str)
{
  norme->ki = (str[norme->index_first + norme->n] - 48);
  norme->nbr += norme->ki * my_pow(10, (norme->len - norme->n - 1));
  norme->n += 1;

}

struct lol_norme	*little2(struct lol_norme *norme)
{
  norme = malloc(sizeof(struct lol_norme));
  if (norme == NULL)
    return (0);
  norme->index_first = 0;
  norme->nbr = 0;
  norme->count = 0;
  norme->run = 1;
  norme->n = 0;
  norme->len = 0;
  norme->is_neg = 0;
  norme->ki = 0;
  return (norme);
}

int	my_getnbr(char *str)
{
  struct lol_norme *norme;

  norme = little2(norme);
  while (str[norme->count] != '\0' && norme->run != 0)
    {
      (str[norme->count] > 64 && str[norme->count] < 91) ? norme->run = 0 : 0;
      (str[norme->count] > 96 && str[norme->count] < 123) ? norme->run = 0 : 0;
      if (str[norme->count] >= 48 && str[norme->count] <= 57)
	{
	  norme->index_first = norme->count;
	  norme->is_neg = (str[norme->count - 1] == '-') ? 1 : 0;
	  while (str[norme->count] >= 48 && str[norme->count] <= 57)
	    {
	      norme->len += 1;
	      norme->count += 1;
	    }
	  while (norme->n < norme->len)
	      calculation(norme, str);
	  norme->nbr = (norme->is_neg) ? norme->nbr * (-1) : norme->nbr;
	  return (norme->nbr);
	}
      norme->count += 1;
    }
  return (0);
}
