/*
** my_tracer.c for tracer in /home/troncy_l/prog/gfx_wolf3d/src
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri Dec 18 22:38:18 2015 
** Last update Sun Dec 27 21:46:48 2015 
*/

#include "main.h"

int		map_tracer(t_all *all)
{
  noise_color_full(all->pix, 16711680, 8355711);
  check_wall(all);
  return (0);
}

void		check_wall(t_all *all)
{
  int		i;

  i = 0;
  while (i < 1000)
    {
      calc_vec(all, i);
      wall_calc(all, i);
      i++;
    }
}

void		calc_vec(t_all *all, int i)
{
  double	x1;
  double	y1;
  double	ang;

  ang = (all->angle * M_PI) / 180;
  x1 = 0.55;
  y1 = (1.1 * ((1000 / 2) - i)) / (1000);
  all->vx = x1 * cos(ang) - y1 * sin(ang);
  all->vy = x1 * sin(ang) + y1 * cos(ang);
}

void		wall_calc(t_all *all, int i)
{
  double	k;
  double	y;
  double	x;

  k = 0;
  y = 0;
  x = 0;
  while ((int)y < all->height && (int)x < all->width)
    {
      x = all->posx + k * all->vx;
      y = all->posy + k * all->vy;
      if (all->map[all->width - (int)x - 1][all->height - (int)y - 1] == 1
	  && k >= 1)
	{
	  disp_wall(all, k, i, 255);
	  break;
	}
      if (all->map[all->width - (int)x - 1][all->height - (int)y - 1] == 2
	  && k >= 1)
	{
	  disp_wall(all, k, i, 84753);
	  break;
	}
      k += 0.001;
    }
}

void		disp_wall(t_all *all, double k, int i, unsigned int color)
{
  int		wall2;
  int		start;
  int		end;
  t_color	*r;

  wall2 = 1000 / (2 * k);
  start = 1000 * (1000 / 2) + i - (1000 * wall2);
  end = 1000 * (1000 / 2) + i + (1000 * wall2);
  r = all->pix->pixels;
  if (start > 0 && end < 1000 * 1000)
    {
      while (start < end)
	{
	  r[start].full = color;
	  start += 1000;
	}
    }
}
