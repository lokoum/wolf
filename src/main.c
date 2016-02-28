/*
** main.c for main hotline in /home/troncy_l/prog/hotline
** 
** Made by lucas troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Nov  7 23:29:56 2015 lucas troncy
** Last update Sun Dec 27 21:54:34 2015 
*/

#include "main.h"

int			main(int argc, char **argv)
{
  t_all			all;
  t_bunny_loop		loop;
  t_bunny_key		key;

  if (argc < 2 || argc > 5 || (all.whoami = parse_args(&all, argc, argv)) == 0)
    {
      disp_usage();
      return (0);
    }
  loop = &my_loop;
  key = &my_key;
  all.win = bunny_start(1000, 1000, false, "wolf3d");
  all.pix = bunny_new_pixelarray(1000, 1000);
  set_me(&all);
  if (my_renderer(&all) == -1)
    {
      my_free_all(&all);
      return (-1);
    }
  bunny_set_key_response(key);
  bunny_set_loop_main_function(loop);
  bunny_loop(all.win, 60, &all);
  my_free_all(&all);
  return (0);
}

void			set_me(t_all *all)
{
  all->posx = 3;
  all->posy = 8;
  all->menu = 0;
  all->vol = 50;
}
