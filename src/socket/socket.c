/*
** socket.c for socket functions in /home/troncy_l/prog/gfx_wolf3d/src/socket
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sun Dec 20 02:33:24 2015 
** Last update Sun Dec 27 21:50:30 2015 
*/

#include "main.h"

void			bind_serv(struct sockaddr_in *server,
				  int sock,
				  int port)
{
  server->sin_addr.s_addr = INADDR_ANY;
  server->sin_family = AF_INET;
  server->sin_port = htons(port);
  if (bind(sock, (struct sockaddr *)server, sizeof(*server)) < 0)
    {
      my_putstr("cannot bind\n");
      return ;
    }
}

int			server_socket(int port)
{
  int			final;
  int			sock;
  int			c;
  struct sockaddr_in	server;
  struct sockaddr_in	client;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      my_putstr("cannot create socket \n");
      return (-1);
    }
  bind_serv(&server, sock, port);
  listen(sock, 1);
  c = sizeof(struct sockaddr_in);
  if ((final = accept(sock, (struct sockaddr *)&client, (socklen_t*)&c)) < 0)
    {
      my_putstr("cannot accept");
      return (-1);
    }
  return (final);
}

int			client_socket(char *ip, int port)
{
  int			sock;
  struct sockaddr_in	server;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      my_putstr("cannot create socket \n");
      return (-1);
    }
  server.sin_addr.s_addr = inet_addr(ip);
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
      my_putstr("cannot connect\n");
      return (-1);
    }
  return (sock);
}

int		msend(int fd, char *data)
{
  if (write(fd, data, my_strlen(data)) == -1)
    {
      my_putstr("error sending data\n");
      return (1);
    }
  return (0);
}

char		*mread(int fd)
{
  char		*data;
  int		len;

  data = malloc(sizeof(char) * BUFF_SIZE + 1);
  if ((len = read(fd, data, BUFF_SIZE)) < 0)
    {
      my_putstr("error sending data\n");
      return (NULL);
    }
  data[len] = '\0';
  return (data);
}
