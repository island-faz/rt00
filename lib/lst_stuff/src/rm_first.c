/*
** rm_first.c for list in /home/bourhi_a/rendu/PSU_2013_minitalk
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Mar 23 05:34:59 2014 
** Last update Tue May 13 14:49:06 2014 
*/

#include <list.h>

int		rm_first(t_glist *lst)
{
  t_list	*tmp;

  tmp = lst->list;
  if (!tmp)
    return (0x0);
  tmp = tmp->next;
  if (!tmp)
    {
      lst->list = 0;
      lst->last_elem = 0;
      return (!0x0);
    }
  tmp->prev = 0;
  lst->list = tmp;
  lst->len--;
  return (!0x0);
}
