/*
** init_list.c for list in /home/bourhi_a/stork/xbrain/lab/slinked_lists/tests
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon May 12 21:21:44 2014 
** Last update Tue May 13 14:09:36 2014 
*/

#include <stdlib.h>
#include <list.h>

t_glist		*init_list()
{
  t_glist	*lst;

  lst = malloc(sizeof(t_glist));
  if (!lst)
    return (0x0);
  lst->list = 0;
  lst->len = 0;
  lst->last_elem = 0;
  return (lst);
}
