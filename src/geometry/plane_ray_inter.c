/*
** helpers.c for rt in /home/bourhi_a/rendu/rt/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu May 29 03:19:35 2014 
** Last update Tue Jun  3 01:44:48 2014 
*/

#include <rt.h>
#include <stdio.h>

t_dpoint	*plane_ray_inters(t_plane *plane, t_ray *ray)
{
  double	abx[3];
  t_dpoint	*intersec;

  abx[0] = plane->normal->x * ray->vector->x;
  abx[0] += plane->normal->y * ray->vector->y;
  abx[0] += plane->normal->z * ray->vector->z;
  abx[1] = plane->normal->x * (ray->origin->x - plane->coor->x);
  abx[1] += plane->normal->y * (ray->origin->y - plane->coor->y);
  abx[1] += plane->normal->z * (ray->origin->z - plane->coor->z);
  if (abx[0] == 0)
    return (0x0);
  abx[2] = -abx[1] / abx[0];
  intersec = xmalloc(sizeof(t_dpoint));
  intersec->x = ray->vector->x * abx[2] + ray->origin->x;
  intersec->y = ray->vector->y * abx[2] + ray->origin->y;
  intersec->z = ray->vector->z * abx[2] + ray->origin->z;
  return (intersec);
}

void		line_inter_test()
{
  t_ray		*ray;
  t_plane	*plane;
  t_dpoint	*intr;

  plane = xmalloc(sizeof(t_plane));
  plane->normal = xmalloc(sizeof(t_dpoint));
  plane->normal->x = 0;
  plane->normal->y = 1;
  plane->normal->z = 0;
  plane->coor = xmalloc(sizeof(t_dpoint));
  plane->coor->x = 0;
  plane->coor->y = 5;
  plane->coor->z = 0;
  ray = xmalloc(sizeof(t_ray));
  ray->origin = xmalloc(sizeof(t_dpoint));
  ray->origin->x = 0;
  ray->origin->y = 0;
  ray->origin->z = 0;
  ray->vector = xmalloc(sizeof(t_dpoint));
  ray->vector->x = 1;
  ray->vector->y = 1;
  ray->vector->z = 0;
  intr = plane_ray_inters(plane, ray);
  (intr ? printf("(%f:%f:%f)\n", intr->x, intr->y, intr->z)
   : printf("No intersection.\n"));
}
