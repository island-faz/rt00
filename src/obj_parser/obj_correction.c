/*
** obj_correction.c for rt in /home/bourhi_a/rendu/rt
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu May 29 05:42:23 2014 
** Last update Wed Jun  4 04:31:36 2014 
*/

#include <rt.h>

int		check_obj_normals(t_obj *obj)
{
  t_dpoint	*u;
  t_dpoint	*v;
  t_triangle	*t;
  t_dpoint	*normal;
  t_list	*lst;

  lst = obj->polygones->list;
  while (lst && (t = CAST_TRIANGLE(CAST_POLYGONE(lst->data)->polygone)))
    {
      u = pcouple_to_vector(t->v1->point, t->v2->point);
      v = pcouple_to_vector(t->v1->point, t->v3->point);
      normal = vcouple_to_normal(u, v);
      if (!t->v1->normal || !vects_r_collinear(normal, t->v1->normal))
	{
	  t->v1->normal = normal;
	  t->v2->normal = normal;
	  t->v3->normal = normal;
	  if (CAST_POLYGONE(lst->data)->type == 2)
	    CAST_QUADRILA(t)->v4->normal = normal;
	}
      lst = lst->next;
    }
  return (!0x0);
}
