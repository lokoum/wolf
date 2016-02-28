/*
** do_sound.c for sound control keyboard in /home/troncy_l/prog/rendu/gfx_fdf1
** 
** Made by lucas troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Nov 12 19:37:43 2015 lucas troncy
** Last update Sun Dec 27 21:16:38 2015 
*/

#include "main.h"

int		do_p(void *all)
{
  play_click(all);
  if (((t_all*)all)->is_sound_playing)
    {
      ((t_all*)all)->is_sound_playing = 0;
      bunny_sound_stop(((t_all*)all)->zik);
      bunny_sound_stop(((t_all*)all)->sax);
    }
  else
    {
      ((t_all*)all)->is_sound_playing = 1;
      bunny_sound_play(((t_all*)all)->zik);
      }
  return (0);
}

int		do_up(void *all)
{
  if (colli_check(all, 1))
    {
      ((t_all*)all)->posy += 0.1 * sin(((t_all*)all)->angle * M_PI / 180);
      ((t_all*)all)->posx += 0.1 * cos(((t_all*)all)->angle * M_PI / 180);
    }
  play_click(all);
  return (0);
}

int		do_down(void *all)
{
  if (colli_check(all, 1))
    {
      ((t_all*)all)->posy -= 0.1 * sin(((t_all*)all)->angle * M_PI / 180);
      ((t_all*)all)->posx -= 0.1 * cos(((t_all*)all)->angle * M_PI / 180);
    }
  play_click(all);
  return (0);
}

int		do_right(void *all)
{
  ((t_all*)all)->angle -= 3;
  play_click(all);
  return (0);
}

int		do_left(void *all)
{
  ((t_all*)all)->angle += 3;
  play_click(all);
  return (0);
}
