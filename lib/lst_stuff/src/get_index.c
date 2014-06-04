/*
** get_index.c for lists in /home/bourhi_a/rendu/rt/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue May 27 04:01:34 2014 
** Last update Tue Jun  3 08:13:38 2014 
*/

#include <list.h>

void		*get_index(t_glist *lst, int index)
{
  t_list	*tmp;
  int		i;

  i = 1;
  tmp = lst->list;
  while (tmp)
    {
      if (i == index)
	return (tmp->data);
      i++;
      tmp = tmp->next;
    }
  return (0x0);
}
