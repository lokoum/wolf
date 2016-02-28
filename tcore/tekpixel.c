/*
** tekpixel.c for tekpixel in /home/troncy_l/prog/rendu/gfx_fdf1
** 
** Made by lucas troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Nov 12 14:00:34 2015 lucas troncy
** Last update Sat Nov 21 17:03:56 2015 lucas troncy
*/

#include "main.h"

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color)
{
  int		fin;
  t_color	*rcolor;

  fin = pos[0].x + (pos[0].y * pix->clipable.clip_width);
  if (fin > 1 && fin < pix->clipable.clip_width * pix->clipable.clip_height)
    {
      rcolor = (t_color*)pix->pixels + fin;
      rcolor->full = color->full;
    }
}
