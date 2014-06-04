/*
** init_rt.c for rt in /home/bourhi_a/rendu/rt/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Fri May 30 16:43:32 2014 
** Last update Wed Jun  4 09:48:43 2014 
*/

#include <rt.h>

int		init_rt(t_rt *rt)
{
  rt->cam = xmalloc(sizeof(t_ray));
  rt->cam->origin = xmalloc(sizeof(t_dpoint));
  rt->cam->origin->x = 0;
  rt->cam->origin->y = 0;
  rt->cam->origin->z = 0;
  rt->cam->vector = xmalloc(sizeof(t_dpoint));
  rt->cam->vector->x = 1;
  rt->cam->vector->y = 1;
  rt->cam->vector->z = 1;
  rt->title = my_strdup("untitled");
  rt->obj = 0;
  return (!0x0);
}
