/*
** parser.c for parser functions in /home/troncy_l/prog/gfx_wolf3d
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sun Dec 20 04:44:39 2015 
** Last update Sun Dec 27 21:49:40 2015 
*/

#include <main.h>

int			parse_args(t_all *all, int argc, char **argv)
{
  int			i;

  all->args = malloc(sizeof(t_args));
   if (argc == 2)
    {
      parse_solo(all, argv[1]);
      i = 3;
    }
   else if (my_strcmp(argv[2], "-c") == 0 && argc == 5)
    {
      parse_client(all, argv);
      i = 1;
    }
  else if (my_strcmp(argv[2], "-h") == 0 && argc == 5)
    {
      parse_server(all, argv);
      i = 2;
    }
  else
    {
      disp_usage();
      i = 0;
    }
  return (i);
}

void			parse_solo(t_all *all, char *filename)
{
  all->args->map = filename;
}

void			parse_client(t_all *all, char **argv)
{
  all->args->name = argv[1];
  all->args->ip = argv[3];
  all->args->port = my_getnbr(argv[4]);
}

void			parse_server(t_all *all, char **argv)
{
  all->args->name = argv[1];
  all->args->map = argv[5];
  all->args->port = my_getnbr(argv[4]);
}

void			disp_usage()
{
  write(2, "NO\n", 3);
}
