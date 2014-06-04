/*
** my_atof.c for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sat Feb  1 18:06:22 2014 
** Last update Tue May 27 06:04:12 2014 
*/

#include <my.h>

double		my_atof(char *s)
{
  double	a;
  int		e;
  int		c;
  int		sign;

  e = 0;
  a = 0.0;
  sign = ((s = epur_str(s)) && s[0] == '-' && s++ ? -1 : 1);
  while ((c = *s++) != '\0' && is_digit(c))
    a = a * 10.0 + (c - '0');
  if (c == '.')
    while ((c = *s++) != '\0' && is_digit(c))
      {
	a = a * 10.0 + (c - '0');
	e = e - 1;
      }
  while (e > 0)
    {
      a *= 10.0;
      e--;
    }
  while (e++ < 0)
    a *= 0.1;
  return (a * sign);
}
