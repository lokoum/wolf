/*
** key.h for key functions init in /home/troncy_l/prog/rendu/gfx_fdf1
** 
** Made by lucas troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Nov 12 19:59:54 2015 lucas troncy
** Last update Sat Dec 19 03:46:38 2015 
*/

#ifndef KEY_H_
# define KEY_H_

void		init_keyboard(t_key *tablem);
void		init_key_sound(t_key *tablem);
int		do_up(void *all);
int		do_down(void *all);
int		do_p(void *all);
int		do_left(void *all);
int		do_right(void *all);

#endif /* !KEY_H_ */
