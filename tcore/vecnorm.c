/*
** vecnorm.c for vecnorm function in /home/troncy_l/prog/gfx_wolf3d/tcore
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri Dec 18 22:15:30 2015 
** Last update Fri Dec 18 22:26:21 2015 
*/

#include "main.h"

double		vecnorm(t_bunny_position coord0, t_bunny_position coord1)
{
  double	res;

  res = (coord1.x - coord0.x) * (coord1.x - coord0.x);
  res +=  (coord1.y - coord0.y) * (coord1.y - coord0.y);
  res = sqrt((double)res);
  return (res);
}
