/*
** my_strcpy.c for my_strcpy in /home/troncy_l/rendu/Piscine_C_J06/ex_02
** 
** Made by Lucas TRONCY
** Login   <troncy_l@epitech.net>
** 
** Started on  Mon Oct  5 09:52:21 2015 Lucas TRONCY
** Last update Sun Dec 27 21:35:57 2015 
*/

#include "main.h"

char	*my_strcpy(char *dest, char *src)
{
  int	count;

  count = 0;
  while (src[count] != '\0')
    {
      dest[count] = src[count];
      count++;
    }
  dest[count] = '\0';
  return (dest);
}
