/*
** triangle.c for rt in /home/bourhi_a/rendu/rt/src/geometry
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Jun  2 17:00:51 2014 
** Last update Wed Jun  4 09:38:40 2014 
*/

#include <math.h>
#include <rt.h>

char		sign_of(double dbl)
{
  if (dbl > 0)
    return (0x0);
  return (!0x0);
}

char             lft_rght(t_dpoint *p1, t_dpoint *p2, t_dpoint *p3, t_dpoint *n)
{
  t_dpoint	tmp;
  double	opt_x[2];
  double	opt_y[2];
  double	opt_z[2];
  double	scalaire;

  opt_x[0] = p3->x - p1->x;
  opt_z[0] = p2->z - p1->z;
  opt_y[0] = p3->y - p1->y;
  opt_x[1] = p2->x - p1->x;
  opt_y[1] = p2->y - p1->y;
  opt_z[1] = p3->z - p1->z;
  tmp.x = opt_y[1] * opt_z[1] - opt_y[0] * opt_z[0];
  tmp.y = opt_z[0] * opt_x[0] - opt_z[1] * opt_x[1];
  tmp.z = opt_x[1] * opt_y[0] - opt_x[0] * opt_y[1];
  scalaire = dot_product(&tmp, n);
  return  ((scalaire > 0) ? 1 : 0);
}

t_dpoint	*inside_triangle(t_dpoint *intr, t_triangle *tr,
				 t_dpoint *pos, t_dpoint *angle)
{
  char		b1;
  char		b2;
  char		b3;
  t_dpoint	*tmp_1;
  t_dpoint	*tmp_2;
  t_dpoint	*tmp_3;

  tmp_1 = new_dpoint(tr->v1->point->x, tr->v1->point->y, tr->v1->point->z);
  tmp_2 = new_dpoint(tr->v2->point->x, tr->v2->point->y, tr->v2->point->z);
  tmp_3 = new_dpoint(tr->v3->point->x, tr->v3->point->y, tr->v3->point->z);
  rotate(tmp_1, angle->x, angle->y, angle->z);
  rotate(tmp_2, angle->x, angle->y, angle->z);
  rotate(tmp_3, angle->x, angle->y, angle->z);
  move_dpoint(tmp_1, pos);
  move_dpoint(tmp_2, pos);
  move_dpoint(tmp_3, pos);
  tr->v2->normal = tr->v1->normal;
  rotate(tr->v2->normal, angle->x, angle->y, angle->z);
  b1 = lft_rght(intr, tmp_2, tmp_1, tr->v2->normal);
  b2 = lft_rght(intr, tmp_1, tmp_3, tr->v2->normal);
  b3 = lft_rght(intr, tmp_3, tmp_2, tr->v2->normal);
  free(tmp_1);
  free(tmp_2);
  free(tmp_3);
  if ((b1 == b2) && (b2 == b3))
    return (intr);
  free(intr);
  return(0x0);
}

int		behind_me(t_ray *ray, t_dpoint *inter)
{
  int		flag;
  t_dpoint	*tmp;

  flag = 0;
  tmp = pcouple_to_vector(ray->origin, inter);
  if (sign_of(tmp->x) == sign_of(ray->vector->x) &&
      sign_of(tmp->y) == sign_of(ray->vector->y) &&
      sign_of(tmp->z) == sign_of(ray->vector->z))
    flag = 1;
  free(tmp);
  return (flag);
}

t_dpoint	*triangle_ray_inter(t_triangle *tr, t_dpoint *pos,
				    t_ray *ray, t_dpoint *angle)
{
  t_plane	plane;
  t_dpoint	*inters;

  plane.normal = new_dpoint(tr->v1->normal->x, tr->v1->normal->y,
			    tr->v1->normal->z);
  plane.coor = xmalloc(sizeof(t_dpoint));
  plane.coor->x = tr->v1->point->x + pos->x;
  plane.coor->y = tr->v1->point->y + pos->y;
  plane.coor->z = tr->v1->point->z + pos->z;
  rotate(plane.normal, angle->x, angle->y, angle->z);
  rotate(plane.coor, angle->x, angle->y, angle->z);
  move_dpoint(plane.coor, pos);
  inters = plane_ray_inters(&plane, ray);
  free(plane.coor);
  free(plane.normal);
  if (!behind_me(ray, inters))
    return (0x0);
  if (!inters)
    return (0x0);
  return(inside_triangle(inters, tr, pos, angle));
}
