/*
** my_struct.h for struct in /home/troncy_l/prog/hotline
** 
** Made by lucas troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Nov  7 23:37:03 2015 lucas troncy
** Last update Sun Dec 20 10:33:47 2015 
*/

#ifndef MY_STRUCT_H_
# define MY_STRUCT_H_

typedef struct s_all	t_all;

typedef struct					s_header
{
  __attribute__((packed)) unsigned short	type;
  __attribute__((packed)) unsigned int		size;
  __attribute__((packed)) unsigned int		reserved;
  __attribute__((packed)) unsigned int		offset;
}			t_header;

typedef struct		s_iheader
{
  __attribute__((packed)) unsigned int		size;
  __attribute__((packed)) int			width;
  __attribute__((packed)) int			height;
  __attribute__((packed)) unsigned short	planes;
  __attribute__((packed)) unsigned short	bits;
  __attribute__((packed)) unsigned int		compression;
  __attribute__((packed)) unsigned int		imagesize;
  __attribute__((packed)) int			xreso;
  __attribute__((packed)) int			yreso;
  __attribute__((packed)) unsigned int		ncolours;
  __attribute__((packed)) unsigned int		icolours;
}			t_iheader;

typedef struct		s_args
{
  int			port;
  char			*name;
  char			*ip;
  char			*map;
}			t_args;

typedef struct		s_player
{
  double		posx;
  double		posy;
  double		aposx;
  double		aposy;
  double		angle;
  char			*name;
}			t_player;

typedef struct		s_key
{
  int			key;
  int			(*call_key)(void *all);
}			t_key;

struct			s_all
{
  t_bunny_window	*win;
  t_bunny_position	pos;
  t_bunny_pixelarray	*pix;
  t_bunny_music		*zik;
  t_bunny_music		*sax;
  t_bunny_effect	*click;
  t_bunny_ini		*ini;
  t_key			tablem[5];
  double		vol;
  int			*table;
  int			menu;
  int			**map;
  int			height;
  int			width;
  t_header		*header;
  t_iheader		*info_header;
  t_args		*args;
  t_player		*player;
  int			sock;
  int			whoami;
  unsigned int		*tab;
  double		posx;
  double		posy;
  double		angle;
  double		vx;
  double		vy;
  int			is_sound_playing;
};

#endif /* !MY_STRUCT_H_ */
