/*
** put_xpl.c for lib in /home/bourhi_a/rendu/rt
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon May 26 23:22:21 2014 
** Last update Tue Jun  3 11:05:14 2014 
*/

#include <string.h>
#include <unistd.h>

int		explose(char **s, char op, char cl)
{
  int		i;

  if (!s || !s[0])
    return (0x0);
  i = 0;
  while (s[i])
    {
      write(1, &op, 1);
      write(1, s[i], strlen(s[i]));
      write(1, &cl, 1);
      write(1, " ", 1);
      i++;
    }
  write(1, "\n", 1);
  return (!0x0);
}
