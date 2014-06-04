/*
** rm_last.c for list in /home/bourhi_a/rendu/prog_elem/lem_in/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sat May  3 06:10:16 2014 
** Last update Tue May 13 14:56:44 2014 
*/

#include <list.h>

int		rm_last(t_glist *lst)
{
  t_list	*tmp;

  tmp = lst->last_elem;
  if (!tmp)
    return (0x0);
  if (tmp->prev)
    {
      tmp->prev->next = 0;
      lst->last_elem = tmp->prev;
    }
  else
    {
      lst->list = 0;
      lst->last_elem = 0;
    }
  lst->len--;
  return (1);
}
