/*
** my.h for my in /home/troncy_l/rendu/Piscine_C_J09/include
** 
** Made by Lucas TRONCY
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Oct  8 10:30:01 2015 Lucas TRONCY
** Last update Tue Nov 17 13:47:12 2015 lucas troncy
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_put_unbr(unsigned int nb);
int	my_put_nbr_base(int nb, int base);
int	my_put_unbr_base(unsigned int nb, int base);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_printf(const char *format, ...);
int	type_checker(char c, va_list ap);
int	do_int(va_list argv);
int	do_char(va_list argv);
int	do_string(va_list argv);
int	do_nstring(va_list argv);
int	do_pointer(va_list argv);
int	do_uoctal(va_list argv);
int	do_udeci(va_list argv);
int	do_uhexa(va_list argv);
int	do_uhexa_maj(va_list argv);
int	do_ubinary(va_list argv);
int	my_put_nbr_hexa(unsigned long nbr, int maj);
struct lol_norme
{
  int index_first;
  int run;
  int n;
  int is_neg;
  int len;
  int nbr;
  int count;
  int ki;
};
typedef struct		s_op
{
  char			c;
  int			(*call_it)(va_list argv);
}			t_op;

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

#endif /* !MY_H_ */
