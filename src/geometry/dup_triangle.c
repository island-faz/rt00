/*
** dup_triangle.c for rt in /home/bourhi_a/rendu/rt/src/geometry
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Jun  4 10:00:19 2014 
** Last update Wed Jun  4 10:05:39 2014 
*/

#include <rt.h>

t_dpoint	*dup_triangle(t_triangle *tr)
{
  t_triangle	*ret;

  ret = xmalloc(sizeof(t_triangle));
  ret->v1->point = new_dpoint(tr->v1->point->x,
			      tr->v1->point->y, tr->v1->point->z);
  ret->v2->point = new_dpoint(tr->v2->point->x,
			      tr->v2->point->y, tr->v2->point->z);
  ret->v3->point = new_dpoint(tr->v3->point->x,
			      tr->v3->point->y, tr->v3->zpoint->);
  ret->v1->normal = new_dpoint(tr->v1->normal->x,
			       tr->v1->normal->y, tr->v1->normal->z);
  ret->v2->normal = ret->v1->normal;
  ret->v3->normal = ret->v1->normal;
}
