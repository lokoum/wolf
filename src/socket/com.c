/*
** com.c for communication functions in /home/troncy_l/prog/gfx_wolf3d/src
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Tue Dec 22 15:49:08 2015 
** Last update Sun Dec 27 21:49:17 2015 
*/

#include "main.h"

double		read_double(int fd)
{
  double	nb;

  if (recv(fd, &nb, sizeof(double), 0) == -1)
    return (-1);
  return (nb);
}

int		send_double(int fd, double nb)
{
  if (write(fd, &nb, sizeof(double)) == -1)
    return (-1);
  return (nb);
}
