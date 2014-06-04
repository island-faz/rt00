/*
** show_obj_data.c for rt in /home/bourhi_a/rendu/rt/src for debug
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue May 27 18:45:10 2014 
** Last update Tue Jun  3 07:38:41 2014 
*/

#include <string.h>
#include <stdio.h>
#include <rt.h>

int		put_poly_point_infos(t_vertex *pt, int p, t_dpoint *pos)
{
  if (!pos || !pt)
    return (0x0);
  if (pt->point)
    printf("p%d : (%f, %f, %f) ",
	   p, pt->point->x + pos->x, pt->point->y +
	   pos->y, pt->point->z + pos->z);
  if (pt->normal)
    printf("n%d : (%f, %f, %f) ",
	   p, pt->normal->x, pt->normal->y, pt->normal->z);
  if (pt->txtres)
    printf("t%d : (%f, %f, %f)\n",
	   p, pt->txtres->x, pt->txtres->y, pt->txtres->z);
  return (!0x0);
}

int		show_polygone(t_polygone *p, t_dpoint *pos)
{
  if (!p)
    return (0x0);
  if (p->type == 1)
    {
      put_poly_point_infos(CAST_TRIANGLE(p->polygone)->v1, 1, pos);
      put_poly_point_infos(CAST_TRIANGLE(p->polygone)->v2, 2, pos);
      put_poly_point_infos(CAST_TRIANGLE(p->polygone)->v3, 3, pos);
      return (!0x0);
    }
  if (p->type == 2)
    {
      put_poly_point_infos(CAST_QUADRILA(p->polygone)->v1, 1, pos);
      put_poly_point_infos(CAST_QUADRILA(p->polygone)->v2, 2, pos);
      put_poly_point_infos(CAST_QUADRILA(p->polygone)->v3, 3, pos);
      put_poly_point_infos(CAST_QUADRILA(p->polygone)->v4, 4, pos);
      return (!0x0);
    }
  return (0x0);
}

int		show_obj_data(t_obj *obj)
{
  int		i;
  t_list	*lst;

  i = 1;
  lst = obj->polygones->list;
  while (lst)
    {
      printf("polygone %d\n", i);
      show_polygone(CAST_POLYGONE(lst->data), obj->pos);
      printf("\n");
      lst = lst->next;
      i++;
    }
  return (!0x0);
}

t_obj		*put_error(char *err_msg, int n)
{
  write(2, err_msg, strlen(err_msg));
  my_putnbr(n);
  write(1, ".\n", 2);
  return (0x0);
}
