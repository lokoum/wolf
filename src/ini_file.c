/*
** ini_file.c for ini file in /home/troncy_l/prog/rendu/gfx_fdf1
** 
** Made by lucas troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Nov 12 18:27:39 2015 lucas troncy
** Last update Sun Dec 27 21:15:52 2015 
*/

#include "main.h"

int		my_ini_file(t_all *all, char *str)
{
  all->ini = bunny_load_ini(str);
  if (all->ini == 0)
    return (-1);
  return (1);
}

int		get_height_map(t_all *all)
{
  char		*b;

  b = (char*)bunny_ini_get_field(all->ini, INI_NAME, "height", 0);
  all->height = my_getnbr(b);
  if (all->whoami == 2)
    msend(all->sock, b);
  return (0);
}

int		get_width_map(t_all *all)
{
  char		*b;

  b = (char*)bunny_ini_get_field(all->ini, INI_NAME, "width", 0);
  all->width = my_getnbr(b);
  if (all->whoami == 2)
    msend(all->sock, b);
  return (0);
}

int		load_data_field(t_all *all, int i, int j, int count)
{
  char		*b;

  get_width_map(all);
  get_height_map(all);
  b = malloc(sizeof(char) * all->width);
  if ((all->map = bunny_malloc(sizeof(int *) * all->height)) == NULL)
    return (-1);
  while (i < all->height)
    {
      if ((all->map[i] = bunny_malloc(sizeof(int) * all->width)) == NULL)
	return (-1);
      while (j < all->width)
	{
	  b[j] = *(char *)bunny_ini_get_field(all->ini, INI_NAME, "data", count);
	  all->map[i][j] = (b[j] == 49) ? 1 : 0;
	  count++;
	  j++;
	}
      b[all->width] = '\0';
      j = 0;
      i++;
    }
  free(b);
  return (0);
}
