/*
** my_atoi.c for my_atoi in /home/bourhi_a/rendu/Piscine-C-lib/my
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Nov  6 22:31:13 2013 bourhime amine
** Last update Wed Mar 19 00:50:14 2014 
*/

#include <my.h>

int		my_atoi(char *str)
{
  int	 nb;
  int	 isneg;

  nb = 0;
  isneg = 1;
  while (*str == '+' || *str == '-')
     {
       if (*str == '-')
	 isneg *= -1;
       str = str + 1;
     }
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      nb = nb * 10;
      nb = nb + *str - 48;
      str = str + 1;
    }
  return (nb * isneg);
}
