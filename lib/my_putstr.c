/*
** my_putstr.c for lib in /home/bourhi_a/rendu/PSU_2013_minitalk/lib
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Mar 23 09:14:47 2014 
** Last update Mon Mar 24 04:42:55 2014 
*/

#include <unistd.h>

int	my_putstr(char *s)
{
  if (!s)
    return (0);
  if (!*s)
    return (1);
  write(1, &(*s), 1);
  my_putstr(s + 1);
  return (1);
}
