/*
** my_strcmp.c for strcmp in /home/troncy_l/rendu/Piscine_C_J06/ex_06
** 
** Made by Lucas TRONCY
** Login   <troncy_l@epitech.net>
** 
** Started on  Mon Oct  5 13:37:32 2015 Lucas TRONCY
** Last update Sun Dec 27 21:43:01 2015 
*/

#include "main.h"

int	my_strcmp(char *s1, char *s2)
{
  int	count;

  count = 0;
  while (s1[count] != '\0' || s2[count] != '\0')
    {
      if (s1[count] != s2[count])
	return (s1[count] - s2[count]);
      count++;
    }
  return (0);
}
