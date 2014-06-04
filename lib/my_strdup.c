/*
** my_strdup.c for mysh in /home/bourhi_a/rendu/PSU_2013_minishell1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Fri Dec 13 01:00:03 2013 
** Last update Fri May 30 14:32:19 2014 
*/

#include <string.h>
#include <stdlib.h>

char	*my_strdup(char *src)
{
  char		*res;
  int		i;
  int		len;

  if (!src)
    return (0);
  len = strlen(src);
  res = malloc(len + 1);
  if (!res)
    return (0);
  i = 0;
  while (src[i])
    {
      res[i] = src[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}
