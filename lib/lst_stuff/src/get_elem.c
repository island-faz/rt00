/*
** get_elem.c for list in /home/bourhi_a/stork/huffman
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue May 20 19:18:45 2014 
** Last update Tue May 20 19:21:11 2014 
*/

#include <list.h>

void		*get_elem(t_glist *glst, void *data, int (*cmp)(void*, void*))
{
  t_list	*lst;

  lst = glst->list;
  if (!lst)
    return (0x0);
  while (lst)
    {
      if (!cmp(lst->data, data))
	return (lst->data);
      lst = lst->next;
    }
  return (0x0);
}
