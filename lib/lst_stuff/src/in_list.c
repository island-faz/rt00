/*
** in_list.c for list in /home/bourhi_a/rendu/PSU_2013_minitalk
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Mar 20 18:46:08 2014 
** Last update Tue May 13 02:07:10 2014 
*/

#include <list.h>

int		in_lst(t_glist *glst, void *data, int (*cmp)(void*, void*))
{
  int		nb;
  t_list	*lst;

  nb = 0;
  lst = glst->list;
  if (!lst)
    return (0x0);
  while (lst)
    {
      if (!cmp(lst->data, data))
	nb++;
      lst = lst->next;
    }
  return (nb);
}
