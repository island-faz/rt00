/*
** rm_elem.c for list in /home/bourhi_a/rendu/PSU_2013_minitalk
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Mar 20 20:07:10 2014 
** Last update Tue May 27 18:41:38 2014 
*/

#include <list.h>

void		rm_element(t_glist *lst, t_list *tmp)
{
  if (!tmp->next && !tmp->prev)
    {
      lst->list = 0;
      lst->last_elem = 0;
    }
  else if (!tmp->next)
    rm_last(lst);
  else if (!tmp->prev)
    rm_first(lst);
  else
    {
      tmp->prev->next = tmp->next;
      tmp->next = tmp->prev;
    }
}

int		rm_elem(t_glist *lst, void *data, int (*cmp)(void*, void*))
{
  int		nb;
  t_list	*tmp;

  nb = 0;
  tmp = lst->list;
  if (!tmp)
    return (0x0);
  while (tmp)
    {
      if (!cmp(tmp->data, data))
	{
	  rm_element(lst, tmp);
	  lst->len--;
	  nb++;
	}
      tmp = tmp->next;
    }
  return (nb);
}
