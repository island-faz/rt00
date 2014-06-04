/*
** epur_str.c<2> for lib in /home/bourhi_a/rendu/rt
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Mar 24 06:11:49 2014 
** Last update Mon Mar 24 07:10:36 2014 
*/

#include <my.h>

char            *epur_str(char *s)
{
  int		i;
  char		*ret;

  if (!s || my_strlen(s) == 0)
    return (s);
  i = 0;
  ret = xmalloc(sizeof(char) * (my_strlen(s) + 1));
  s = my_char_replace(s, '\t', ' ');
  while (*s)
    {
      if (i > 0 && ret[i - 1] == ' ')
	{
	  if (*s && *s != ' ' && *s != '\t' && (ret[i] = *s))
	    i++;
	}
      else if ((ret[i] = *s))
	i++;
      s++;
    }
  ret[i] = 0;
  ret[i - 1] = (ret[i - 1] == ' ' ? 0 : ret[i - 1]);
  ret = (ret[0] == ' ' ? ret + 1 : ret);
  return (ret);
}
