/*
** my_strcmp.c for my_strcmp in /home/bourhi_a/rendu/Piscine-C-Jour_06
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Oct  7 16:42:10 2013 bourhime amine
** Last update Mon Mar 24 06:43:58 2014 
*/

#include <my.h>

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (!s1 || !s2)
    return (-2);
  if (!(i = 0) && my_strlen(s1) != my_strlen(s2))
    return (1);
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (-1);
      i++;
    }
  return (0);
}
