/*
** list_len.c for list in /home/bourhi_a/rendu/PSU_2013_minitalk/lib/lst_stuff
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Fri Mar 21 08:32:01 2014 
** Last update Tue May 13 14:50:24 2014 
*/

#include <list.h>

int		list_len(t_glist *glst)
{
  if (glst)
    return (glst->len);
  return (0x0);
}
