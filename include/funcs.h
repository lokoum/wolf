/*
** funcs.h for all funcs in /home/troncy_l/prog/rendu/gfx_fdf1/include
** 
** Made by lucas troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Nov 12 16:04:56 2015 lucas troncy
** Last update Sun Dec 27 21:54:16 2015 
*/

#ifndef FUNCS_H_
# define FUNCS_H_

void			tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color);
t_bunny_response	my_loop(void *all);
t_bunny_response	my_key(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *all);
void			noise_color_full(t_bunny_pixelarray *pix,
					 unsigned int rcolor1,
					 unsigned int rcolor2);
int			my_renderer(t_all *all);
int			my_music(t_all *all);
int			play_click(t_all *all);
int			my_ini_file(t_all *all, char *str);
int			load_data_field(t_all *all, int j, int i, int count);
int			map_tracer(t_all *all);
void			init_map_control(t_key *teblem);
void			my_free_all(t_all *all);
void			map_pretracer(t_all *all);
int			my_getnbr(char *str);
int			colli_check(t_all *all, int forward);
int			collix(t_all *all, int forward);
int			colliy(t_all *all, int forward);
int			parse_args(t_all *all, int argc, char **argv);
void			parse_solo(t_all *all, char *filename);
void			parse_client(t_all *all, char **argv);
void			parse_server(t_all *all, char **argv);
void			disp_usage();
int			init_launcher(t_all * all);
int			init_client(t_all *all);
int			init_server(t_all *all);
int			init_solo(t_all *all);
void			read_server(t_all *all);
void			read_server2(t_all *all, char *tmp);
void			read_map(t_all *all);
int			map_tracer(t_all *all);
void			check_wall(t_all *all);
void			calc_vec(t_all *all, int i);
void			wall_calc(t_all *all, int i);
void			disp_wall(t_all *all, double k, int i, unsigned int color);
double			read_double(int fd);
int			send_double(int fd, double nb);
void			bind_serv(struct sockaddr_in *server,
				  int sock,
				  int port);
int			server_socket(int port);
int			client_socket(char *ip, int port);
int			msend(int fd, char *data);
char			*mread(int fd);
int			load_bmp(t_all *all, char *filename);
void			rev_bmp(t_all *all);
void			disp_bmp(t_all *all);
void			set_me(t_all *all);

#endif /* !FUNCS_H_ */
