/*
** ender.c for my ender in /home/troncy_l/prog/rendu/gfx_fdf1
** 
** Made by lucas troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Nov 21 17:11:12 2015 lucas troncy
** Last update Sun Nov 22 12:18:44 2015 lucas troncy
*/

#include "main.h"

void		my_free_all(t_all *all)
{
  bunny_delete_clipable(&all->pix->clipable);
  bunny_stop(all->win);
  bunny_sound_stop(all->zik);
  bunny_sound_stop(all->sax);
  bunny_sound_stop(all->click);
  bunny_delete_sound(all->zik);
  bunny_delete_sound(all->sax);
  bunny_delete_sound(all->click);
}
