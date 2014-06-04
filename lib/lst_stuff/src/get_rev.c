/*
** get_rev.c for list in /home/bourhi_a/rendu/prog_elem/lem_in/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sat May  3 20:25:39 2014 
** Last update Tue May 13 13:54:35 2014 
*/

#include <list.h>

t_glist		*get_rev(t_glist *lst)
{
  int		i;
  t_glist	*rev;
  t_list	*list;

  i = 0;
  rev = init_list();
  list = lst->list;
  if (!rev || !list)
    return (0x0);
  while (list)
    {
      push_front(rev, list->data);
      if (!i)
	rev->last_elem = rev->list;
      list = list->next;
      i = 1;
    }
  return (rev);
}
