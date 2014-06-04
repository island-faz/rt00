/*
** my_put_nbr.c for my_put_nbr in /home/bourhi_a/rendu/lib
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Nov 14 05:57:06 2013 bourhime amine
** Last update Mon Mar 24 07:46:03 2014 
*/

#include <my.h>

int		my_putnbr(int a)
{
  char		*s;
  int		i;
  int		is_neg;

  s = xmalloc(16);
  i = 0;
  is_neg = 0;
  if (a == 0)
    write(1, "0", 1);
  else if (a < 0)
    {
      a *= -1;
      is_neg = 1;
    }
  while (a > 0)
    {
      s[i++] = (a % 10) + '0';
      a /= 10;
    }
  if (is_neg == 1)
    s[i++] = '-';
  s[i] = '\0';
  s = my_revstr(s);
  write(1, s, my_strlen(s));
  return (1);
}
