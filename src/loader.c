/*
** loader.c for load bmd file in /home/troncy_l/prog/gfx_wolf3d
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Dec 19 21:20:18 2015 
** Last update Sun Dec 27 21:47:34 2015 
*/

#include "main.h"

int		load_bmp(t_all *all, char *filename)
{
  int		fd;
  int		len;
  int		a;

  all->header = malloc(sizeof(t_header));
  all->info_header = malloc(sizeof(t_iheader));
  fd = open(filename, O_RDONLY);
  read(fd, all->header, sizeof(t_header));
  read(fd, all->info_header, sizeof(t_iheader));
  a = all->info_header->height;
  all->tab = malloc(sizeof(unsigned int) * a * all->info_header->width);
  if (all->header->type != 0x4D42)
    write(1, "Not a BMP\n", 10);
  len = read(fd, all->tab, 4 * a * all->info_header->width);
  return (len);
}

void		rev_bmp(t_all *all)
{
  int		i;

  i = 0;
  while (i < all->width)
    i++;
}

void		disp_bmp(t_all *all)
{
  t_color		*r;
  int			i;
  int			j;
  int			tmp;

  i = 0;
  j = 0;
  tmp = 0;
  r = all->pix->pixels;
  while (i < all->info_header->height * all->info_header->width)
    {
      if (tmp == all->info_header->width)
	{
	  j += 1000 -  all->info_header->width;
	  tmp = 0;
	}
      r[j].full = all->tab[i];
      tmp++;
      i++;
      j++;
    }
}
