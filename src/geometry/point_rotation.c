/*
** point_rotation.c for rt in /home/bourhi_a/rendu/rt
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Jun  4 07:34:27 2014 
** Last update Wed Jun  4 08:57:26 2014 
*/

#include <math.h>
#include <rt.h>

void		rot_x(t_dpoint *coor, double v_cos, double v_sin)
{
  t_dpoint	tmp;

  tmp.y = (v_cos * coor->y) - (v_sin * coor->z);
  tmp.z = (v_sin * coor->y) + (v_cos * coor->z);
  coor->y = tmp.y;
  coor->z = tmp.z;
}

void		rot_y(t_dpoint *p, double v_cos, double v_sin)
{
  t_dpoint	tmp;

  tmp.x = (v_cos * p->x) + (v_sin * p->z);
  tmp.z = (v_cos * p->z) - (v_sin * p->x);
  p->x = tmp.x;
  p->z = tmp.z;
}

void		rot_z(t_dpoint *coor, double v_cos, double v_sin)
{
  t_dpoint	tmp;

  tmp.x = (v_cos * coor->x) - (v_sin * coor->y);
  tmp.y = (v_sin * coor->x) + (v_cos * coor->y);
  coor->x = tmp.x;
  coor->y = tmp.y;
}

void		rotate(t_dpoint *coor, double angle_x,
		       double angle_y, double angle_z)
{
  if (angle_x != 0.0)
    rot_x(coor, cos(angle_x), sin(angle_x));
  if (angle_y != 0.0)
    rot_y(coor, cos(angle_y), sin(angle_y));
  if (angle_z != 0.0)
    rot_z(coor, cos(angle_z), sin(angle_z));
}
