/*
** put_elem.c for list in /home/bourhi_a/rendu/MUL_2013_rtv1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Mar 13 05:13:00 2014 
** Last update Tue May 13 15:00:18 2014 
*/

#include <stdlib.h>
#include <list.h>

int	      push_back(t_glist *lst, void *data)
{
  t_list      *tmp;

  tmp = malloc(sizeof(t_list));
  if (!tmp)
    return (0x0);
  tmp->data = data;
  tmp->next = 0;
  if (lst->list)
    {
      tmp->prev = lst->last_elem;
      lst->last_elem->next = tmp;
      lst->last_elem = lst->last_elem->next;
    }
  else
    {
      tmp->prev = 0;
      lst->list = tmp;
      lst->last_elem = tmp;
    }
  lst->len++;
  return (1);
}
