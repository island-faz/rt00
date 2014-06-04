/*
** explode.c for rtv1 in /home/bourhi_a/rendu/rtv/lib
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sat Feb  1 17:49:43 2014 
** Last update Wed Jun  4 03:09:55 2014 
*/

#include <string.h>
#include <stdlib.h>

int	is_separator(char str, char *sep)
{
  int	i;

  i = 0;
  while (sep[i] != '\0')
  {
    if (str == sep[i])
      return (0);
    i++;
  }
  return (1);
}

int	cnt_wrd(char *str, char *sep)
{
  int	i;
  int	cnt;

  i = 0;
  cnt = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
  {
    if (is_separator(str[i], sep) == 1)
    {
      cnt++;
      while (is_separator(str[i], sep) == 1 && str[i] != 0)
	i++;
    }
    if (str[i] != 0)
      i++;
  }
  return (cnt);
}

int	cnt_char(char *str, char *sep)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && is_separator(str[i], sep) == 1)
    i++;
  return (i);
}

char	**explode(char *str, char *sep)
{
  int	i;
  int	cnt;
  int	wd;
  char	**tab;

  if (!(wd = cnt_wrd(str, sep)) || !(tab = malloc((wd + 1) * sizeof(char*))))
    return (0x0);
  i = 0;
  cnt = 0;
  while ((str[i] != '\0') && (wd > 0))
  {
    if (is_separator(str[i], sep) == 1)
    {
      tab[cnt] = strdup(str + i);
      tab[cnt][cnt_char((str + i), sep)] = '\0';
      cnt++;
      wd--;
      while (is_separator(str[i], sep) == 1 && str[i] != 0)
	i++;
    }
    if (str[i] != 0)
      i++;
  }
  tab[cnt] = 0;
  return (tab);
}

int		free_xpl(char **xpl)
{
  int		i;

  if (!xpl)
    return (0x0);
  i = 0;
  while(xpl[i])
    {
      free(xpl[i]);
      i++;
    }
  free(xpl);
  return (!0x0);
}
