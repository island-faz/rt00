/*
** obj_ray_inters.c for rt in /home/bourhi_a/rendu/rt
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sat May 31 03:12:50 2014 
** Last update Wed Jun  4 10:41:33 2014 
*/

#include <rt.h>

t_dpoint	*new_dpoint(double x, double y, double z)
{
  t_dpoint	*p;

  p = xmalloc(sizeof(t_dpoint));
  p->x = x;
  p->y = y;
  p->z = z;
  return (p);
}

double		get_distance(t_dpoint *p1, t_dpoint *p2)
{
  double	distance;

  if (!p1 || !p2)
    return (0x0);
  distance = pow(p2->x - p1->x, 2) +
    pow(p2->y - p1->y, 2) + pow(p2->z - p1->z, 2);
  return(sqrt(distance));
}

void		check_dst(t_dpoint *inter, t_dpoint **rint,
			  t_ray *ray, double *dst)
{
  double	dst_tmp;

  if (inter)
    {
      dst_tmp = get_distance(ray->origin, inter);
      if (dst_tmp < *dst)
	{
	  *rint = inter;
	  *dst = dst_tmp;
	}
    }
}

t_dpoint	*obj_ray_inter(t_obj *obj, t_ray *ray)
{
  int		flag;
  t_list	*lst;
  t_polygone	*poly;
  t_dpoint	*inter;
  t_dpoint	*ret_int;
  double	distance;

  if (!(flag = 0) && !(inter = 0) && !(ret_int = 0) && (distance = DBL_MAX))
    lst = obj->polygones->list;
  while (lst)
    {
      poly = CAST_POLYGONE(lst->data);
      if (poly->type == 1 && (flag = 2))
	inter = triangle_ray_inter(poly->polygone, obj->pos, ray);
      else if (poly->type == 2 && (flag = 3))
	inter = quad_ray_inter(poly->polygone, obj->pos, ray);
      if (flag > 1 && (flag = 1) && inter)
	check_dst(inter, &ret_int, ray, &distance);    
      lst = lst->next;
    }
  return (ret_int);
}
