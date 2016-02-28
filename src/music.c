/*
** music.c for music controler in /home/troncy_l/prog/rendu/gfx_fdf1
** 
** Made by lucas troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Nov 12 18:09:19 2015 lucas troncy
** Last update Sun Nov 22 18:41:37 2015 lucas troncy
*/

#include "main.h"

int			my_music(t_all *all)
{
  all->zik = bunny_load_music("assets/sounds/anemo.ogg");
  all->sax = bunny_load_music("assets/sounds/sax.ogg");
  all->click = bunny_load_effect("assets/sounds/click.ogg");
  all->is_sound_playing = 1;
  bunny_sound_play(all->zik);
  return (0);
}

int			play_click(t_all *all)
{
  bunny_sound_play(all->click);
  return (0);
}
