/*
** init_keyboard.c for init keyboard in /home/troncy_l/prog/rendu/gfx_fdf1/src/key
** 
** Made by lucas troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Nov 12 19:21:48 2015 lucas troncy
** Last update Sat Dec 19 03:48:35 2015 
*/

#include "main.h"

void		init_keyboard(t_key *tablem)
{
  init_key_sound(tablem);
}

void		  init_key_sound(t_key *tablem)
{
  tablem[0].call_key = &do_up;
  tablem[0].key = BKS_UP;
  tablem[1].call_key = &do_down;
  tablem[1].key = BKS_DOWN;
  tablem[2].call_key = &do_p;
  tablem[2].key = 15;
  tablem[3].call_key = &do_right;
  tablem[3].key = BKS_RIGHT;
  tablem[4].call_key = &do_left;
  tablem[4].key = BKS_LEFT;
 }
