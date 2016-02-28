/*
** color_full.c for color full in /home/troncy_l/prog/rendu/noise_2020
** 
** Made by troncy_l
** Login   <troncy_l@epitech.net>
** 
** Started on  Mon Nov  2 14:42:37 2015 troncy_l
** Last update Fri Dec 18 22:45:09 2015 
*/

#include "main.h"

void		noise_color_full(t_bunny_pixelarray *pix,
				 unsigned int rcolor1,
				 unsigned int rcolor2)
{
  int		width;
  int		height;
  t_color	*color;

  width = 0;
  height = pix->clipable.clip_height * pix->clipable.clip_width;
  while (width < height)
    {
      color = (t_color*)pix->pixels + width;
      if (width < height / 2)
	color->full = rcolor1;
      else
	color->full = rcolor2;
      width++;
    }
}
