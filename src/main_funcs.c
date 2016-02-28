/*
** main_funcs.c for main funcs in /home/troncy_l/prog/hotline
** 
** Made by lucas troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Nov  7 23:44:15 2015 lucas troncy
** Last update Sun Dec 27 21:41:23 2015 
*/

#include "main.h"

void			send_serv(t_all *all)
{
  all->player->posx = read_double(all->sock);
  send_double(all->sock, all->posx);
  all->player->posy = read_double(all->sock);
  send_double(all->sock, all->posy);
  all->player->angle = read_double(all->sock);
  send_double(all->sock, all->angle);
}

void			update(t_all *all)
{
  int			a;

  all->player->aposx = all->player->posx;
  all->player->aposy = all->player->posy;
  if (all->whoami == 1)
    send_serv(all);
  a = all->width - (int)all->player->aposx - 1;
  if (all->player->aposx != all->player->posx ||
      all->player->aposy != all->player->posy)
    all->map[a][all->height - (int)all->player->aposy - 1] = 0;
  all->map[a][all->height - (int)all->player->posy - 1] = 2;
}

t_bunny_response	my_loop(void *all)
{
  if (((t_all*)all)->whoami != 3)
    update((t_all*)all);
  if (((t_all*)all)->menu)
    write(1, "Z", 1);
  map_tracer((t_all*)all);
  disp_bmp((t_all*)all);
  bunny_blit(&((t_all*)all)->win->buffer,
	     &((t_all*)all)->pix->clipable,
	     NULL);
  bunny_display(((t_all*)all)->win);
  return (GO_ON);
}

t_bunny_response	my_key(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *all)
{
  int			i;

  i = -1;
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  else if (state == GO_DOWN)
    {
      while (i++ < 5)
	{
	  if (((t_all*)all)->tablem[i].key == keysym && keysym != 0)
	    ((t_all*)all)->tablem[i].call_key(all);
	}
    }
  return (GO_ON);
}
