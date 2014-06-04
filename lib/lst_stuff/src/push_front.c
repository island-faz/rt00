/*
** push_front.c for list in /home/bourhi_a/rendu/prog_elem/lem_in/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu May  1 02:55:05 2014 
** Last update Tue May 13 14:48:40 2014 
*/

#include <stdlib.h>
#include <list.h>

int      push_front(t_glist *lst, void *data)
{
  t_list      *tmp;

  tmp = malloc(sizeof(t_list));
  if (!tmp)
    return (0x0);
  tmp->data = data;
  tmp->prev = 0;
  tmp->next = lst->list;
  if (lst->list)
    lst->list->prev = tmp;
  else
    lst->last_elem = tmp;
  lst->list = tmp;
  lst->len++;
  return (!0x0);
}
