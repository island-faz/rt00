/*
** obj_functions.c for rt in /home/bourhi_a/rendu/rt
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Fri May 30 15:07:36 2014 
** Last update Wed Jun  4 09:54:53 2014 
*/

#include <rt.h>

int		set_obj_pos(t_obj *obj, double x, double y, double z)
{
  if (!obj)
    return (0x0);
  obj->pos->x = x;
  obj->pos->y = y;
  obj->pos->z = z;
  return (!0x0);
}

int		set_obj_angle(t_obj *obj, double x, double y, double z)
{
  if (!obj)
    return (0x0);
  obj->angle->x = x;
  obj->angle->y = y;
  obj->angle->z = z;
  return (!0x0);
}

void		move_dpoint(t_dpoint *p, t_dpoint *inc)
{
  p->x += inc->x;
  p->y += inc->y;
  p->z += inc->z;
}
