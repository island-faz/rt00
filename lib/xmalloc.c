/*
** xmalloc.c for lib in /home/bourhi_a/rendu/PSU_2013_minitalk/lib
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Mar 18 18:33:42 2014 
** Last update Tue Mar 18 18:46:11 2014 
*/

#include <stdlib.h>

void            *xmalloc(unsigned  int size)
{
  void          *res;

  if ((res = malloc(size)) == 0)
    {
      write(1, "Cannot malloc.\n", 16);
      exit(0);
    }
  return (res);
}
