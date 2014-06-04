/*
** to_array.c for list in /home/bourhi_a/rendu/rt/lib/lst_stuff/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Jun  3 06:55:27 2014 
** Last update Wed Jun  4 10:56:41 2014 
*/

#include <stdio.h>
#include <stdlib.h>
#include <list.h>

char		**to_array(t_glist *lst)
{
  int		i;
  t_list	*tmp;
  char		**arr;

  i = 0;
  tmp = lst->list;
  if (!(arr = malloc(sizeof(char *) * lst->len + 1)))
    return (0x0);
  while (tmp)
    {
      arr[i] = tmp->data;
      i++;
      tmp = tmp->next;
    }
  arr[i] = 0;
  return (arr);
}

void		to_array_test()
{
  int		i = 10;
  t_glist	*lst;
  char		**arr;

  lst = init_list();
  while (i > 0)
    {
      push_back(lst, &i);
      i--;
    }
  arr = to_array(lst);
  i = 0;
  while (arr[i])
    {
      printf("%s\n", arr[i]);
      i++;
    }
}
