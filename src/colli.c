/*
** colli.c for collision checker in /home/troncy_l/prog/gfx_wolf3d
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Dec 19 07:12:29 2015 
** Last update Sun Dec 27 21:49:41 2015 
*/

#include "main.h"

int		colli_check(t_all *all, int forward)
{
  double	xtmp;
  double	ytmp;

  if (forward == 1)
    {
      ytmp = all->posy + 0.1 * sin(all->angle * M_PI / 180);
      xtmp = all->posx + 0.1 * cos(all->angle * M_PI / 180);
    }
  else
    {
      ytmp = all->posy - 0.1 * sin(all->angle * M_PI / 180);
      xtmp = all->posx - 0.1 * cos(all->angle * M_PI / 180);
    }
  if (all->map[all->width - (int)xtmp - 1][all->height - (int)ytmp - 1] != 0)
    return (0);
  return (1);
}

int		collix(t_all *all, int forward)
{
  int		a;

  a = all->width - (int)all->posx - forward - 2;
  if (all->map[a][all->height - (int)all->posy - 1] == 0)
    return (1);
  return (0);
}


int		colliy(t_all *all, int forward)
{
  int		a;

  a = all->width - (int)all->posx - 1;
  if (all->map[a][all->height - (int)all->posy - forward - 1] == 0)
    return (1);
  return (0);
}
