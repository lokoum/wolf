/*
** my_renderer.c for my renderer in /home/troncy_l/prog/rendu/gfx_fdf1
** 
** Made by lucas troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Nov 12 18:02:47 2015 lucas troncy
** Last update Sun Feb 28 00:55:25 2016 Lucas Troncy
*/

#include "main.h"

int			my_renderer(t_all *all)
{
  init_launcher(all);
  my_music(all);
  init_keyboard(all->tablem);
  all->angle = 33.33;
  all->posx = 1;
  all->posy = all->height - 2 - 1;
  map_tracer(all);
  /*load_bmp(all, "a.bmp");*/
  bunny_blit(&all->win->buffer, &all->pix->clipable, &all->pos);
  bunny_display(all->win);
  return (0);
}

int			init_launcher(t_all * all)
{
  if (all->whoami == 1)
    init_client(all);
  else if (all->whoami == 2)
    init_server(all);
  else if (all->whoami == 3)
    init_solo(all);
  else
    return (-1);
  return (0);
}

int			init_client(t_all *all)
{
  all->player = malloc(sizeof(t_player));
  all->sock = client_socket(all->args->ip, all->args->port);
  all->player->name = mread(all->sock);
  msend(all->sock, all->args->name);
  read_server(all);
  return (0);
}

int			init_server(t_all *all)
{
  all->sock = server_socket(all->args->port);
  msend(all->sock, all->args->name);
  all->player->name = mread(all->sock);
  if (my_ini_file(all, all->args->map) == -1)
    {
      write(2, "wrong file !\n", 13);
      return (-1);
    }
  load_data_field(all, 0, 0, 0);
  return (0);
}

int		init_solo(t_all *all)
{
  if (my_ini_file(all, all->args->map) == -1)
    {
      write(2, "wrong file !\n", 13);
      return (-1);
    }
  load_data_field(all, 0, 0, 0);
  return (0);
}
