/*
** clone_list.c for list in /home/bourhi_a/stork/xbrain/lab/slinked_lists/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue May 13 13:34:03 2014 
** Last update Tue May 13 15:01:28 2014 
*/

#include <stdlib.h>
#include <list.h>

t_glist		*clone_list(t_glist *lst)
{
  t_list	*tmp;
  t_glist	*clone;

  tmp = lst->list;
  clone = init_list();
  if (!clone)
    return (0x0);
  while (tmp)
    {
      push_back(clone, tmp->data);
      tmp = tmp->next;
    }
  return (clone);
}
