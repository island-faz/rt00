/*
** geometry_functions.c for rt in /home/bourhi_a/rendu/rt/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu May 29 03:39:11 2014 
** Last update Wed Jun  4 08:57:39 2014 
*/

#include <rt.h>

double		dot_product(t_dpoint *v1, t_dpoint *v2)
{
  return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_dpoint	*vcouple_to_normal(t_dpoint *v1, t_dpoint *v2)
{
  t_dpoint	*normal;

  if (!v1 || !v2)
    return (0x0);
  normal = xmalloc(sizeof(t_dpoint));
  normal->x = v1->y * v2->z - v1->z * v2->y;
  normal->y = (v1->z * v2->x - v1->x * v2->z);
  normal->z = v1->x * v2->y - v1->y * v2->x;
  return (normal);
}

t_dpoint	*pcouple_to_vector(t_dpoint *p1, t_dpoint *p2)
{
  t_dpoint	*vector;

  if (!p1 || !p2)
    return (0x0);
  vector = xmalloc(sizeof(t_dpoint));
  vector->x = p2->x - p1->x;
  vector->y = p2->y - p1->y;
  vector->z = p2->z - p1->z;
  return (vector);
}

int		vects_r_collinear(t_dpoint *v1, t_dpoint *v2)
{
  int		j;
  int		i;
  double	k[3];

  if (!v1 || !v2)
    return (0x0);
  if (!(i = 0) && !(j = 0) && v2->x != (double)0 && (k[i] = v1->x / v2->x))
    i++;
  if (v2->y != (double)0 && (k[i] = v1->y / v2->y))
    i++;
  if (v2->z != (double)0 && (k[i] = v1->z / v2->z))
    i++;
  while (j < i)
    {
      if (v1->x == k[j] * v2->x &&
	  v1->y == k[j] * v2->y &&
	  v1->z == k[j] * v2->z)
	return (!0x0);
      j++;
    }
  return (0x0);
}
