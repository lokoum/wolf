/*
** lib.c for lib in /home/troncy_l/prog/gfx_wolf3d/src/lib
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sun Dec 20 04:16:08 2015 
** Last update Sun Dec 27 21:42:08 2015 
*/

#include "main.h"

int		my_strlen(char *str)
{
  int		count;

  count = 0;
  if (str == NULL)
    return (0);
  while (*str++)
    count++;
  return (count);
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
