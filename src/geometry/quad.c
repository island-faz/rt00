/*
** quad.c for rt in /home/bourhi_a/rendu/rt/src/geometry
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Jun  2 17:00:31 2014 
** Last update Wed Jun  4 10:41:07 2014 
*/

#include <math.h>
#include <rt.h>

t_dpoint	*quad_ray_inter(t_quadri *q, t_dpoint *pos, t_ray *ray)
{
  t_triangle	t1;
  t_triangle	t2;  
  t_dpoint	*inters;

  t1.v1 = q->v1;
  t1.v2 = q->v2;
  t1.v3 = q->v3;
  t2.v1 = q->v2;
  t2.v2 = q->v3;
  t2.v3 = q->v4;
  if ((inters = triangle_ray_inter(&t1, pos, ray)) ||
      (inters = triangle_ray_inter(&t2, pos, ray)))
    return (inters);
  return (0x0);
}
