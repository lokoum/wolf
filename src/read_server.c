/*
** read_server.c for get all data from server in /home/troncy_l/prog/gfx_wolf3d
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sun Dec 20 07:40:06 2015 
** Last update Sun Dec 27 21:45:57 2015 
*/

#include "main.h"

void		read_server(t_all *all)
{
  char		*tmp;

  tmp = mread(all->sock);
  free(tmp);
  msend(all->sock, "OK");
  tmp = mread(all->sock);
  all->height = my_getnbr(tmp);
  free(tmp);
  msend(all->sock, "OK");
  tmp = mread(all->sock);
  all->width = my_getnbr(tmp);
  free(tmp);
  msend(all->sock, "OK");
  read_map(all);
  read_server2(all, tmp);
}

void		read_server2(t_all *all, char *tmp)
{
  all->player->posx = read_double(all->sock);
  msend(all->sock, "OK");
  all->player->posy = read_double(all->sock);
  msend(all->sock, "OK");
  all->player->angle = read_double(all->sock);
  msend(all->sock, "OK");
  send_double(all->sock, all->posx);
  tmp = mread(all->sock);
  free(tmp);
  send_double(all->sock, all->posy);
  tmp = mread(all->sock);
  free(tmp);
  send_double(all->sock, all->angle);
}

void		read_map(t_all *all)
{
  int		i;
  int		j;
  char		*tmp;

  i = 0;
  j = 0;
  all->map = malloc(sizeof(int *) * all->height);
  while (i < all->height)
    {
      tmp = mread(all->sock);
      all->map[i] = malloc(sizeof(int) * all->width);
      while (j < all->width)
	{
	  all->map[i][j] = tmp[j];
	  j++;
	}
      free(tmp);
      msend(all->sock, "OK");
      j = 0;
      i++;
    }
}
