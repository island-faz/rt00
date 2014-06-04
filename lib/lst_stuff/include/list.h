/*
** list.h for list in /home/bourhi_a/rendu/MUL_2013_rtv1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Mar 13 05:15:43 2014 
** Last update Tue Jun  3 07:06:55 2014 
*/

#ifndef			LIST_H_
# define		LIST_H_

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef struct		s_glist
{
  int			len;
  t_list		*list;
  t_list		*last_elem;
}			t_glist;

t_glist			*init_list();
int			push_back(t_glist *lst, void *data);
int			push_front(t_glist *lst, void *data);
int			list_len(t_glist *lst);
int			rm_last(t_glist *lst);
int			rm_first(t_glist *lst);
int			sort_list(t_glist *lst, int (*cmp)(void*, void*));
int			in_lst(t_glist*, void*, int (*cmp)(void*, void*));
int			rm_elem(t_glist*, void *data, int (*cmp)(void*, void*));
t_glist			*get_rev(t_glist *lst);
t_glist			*clone_list(t_glist *lst);
void			*get_index(t_glist *lst, int index);
char			**to_array(t_glist *lst);
void			*get_elem(t_glist *glst, void *data, int (*cmp)(void*, void*));

#endif			/* LIST_H_ */
