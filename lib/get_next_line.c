/*
** get_next_line.c for gnl in ~/rendu/prog_elem/get_next_line-2017-bourhi_a
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Nov 19 04:44:18 2013 
** Last update Wed Jun  4 03:05:21 2014 
*/

#include <string.h>
#include <my.h>
#include <get_next_line.h>

char		*my_read(const int fd)
{
  char		*res;
  int		size;

  if (!(res = malloc(BUFF_SIZE + 1)))
    return (0);
  if ((size = read(fd, res, BUFF_SIZE)) <= 0)
    {
      free(res);
      return (0); 
    }
  res[size] = '\0';
  return (res);
}

int		n_exist(char *s)
{
  int		i;

  if (!s)
    return (0);
  i = 0;
  while (s[i])
    {
      if (s[i] == '\n')
	return (i);
      i++;
    }
  return (-1);
}

int		gnl_free(char *buf, char **tmp, char **tmp_fr)
{
  if (buf != *tmp && buf != *tmp_fr)
    {
      free(*tmp_fr);
      *tmp_fr = buf;
    }
  else
    *tmp_fr = 0;
  free(*tmp);
}

char		*gnl_core(int fd, char *line, char *tmp, int *i)
{
  static char	*buf = "";
  static char	*tmp_fr = 0;

  if ((tmp = my_read(fd)))
    {
      buf = merge_string(buf, tmp);
      gnl_free(buf, &tmp, &tmp_fr);
    }
  else if (!buf || !strlen(buf))
    return (0);
  if ((*i = n_exist(buf)) != -1)
    {
      buf[*i] = 0;
      line = strdup(buf);
      buf = buf + *i + 1;
      return (line);
    }
  if (!tmp || !strlen(tmp))
    {
      line = buf;
      buf = 0;
      return (strdup(line));
    }
  return (0x0);
}

char		*get_next_line(const int fd)
{
  int		i;
  char		*tmp;
  char		*line;

  while (!0x0)
    return (gnl_core(fd, line, tmp, &i));
  return (0x0);
}
