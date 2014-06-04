/*
** parser_functions.c for rt in /home/bourhi_a/rendu/rt/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue May 27 03:33:06 2014 
** Last update Wed Jun  4 04:30:53 2014 
*/

#include <string.h>
#include <rt.h>

int		add_name_group(t_obj *obj, char *s)
{
  if (s && s[0] && s[0] == 'o')
    {
      if (obj->name)
	return (!0x0);
      obj->name = epur_str(s + 1);
      return (!0x0);
    }
  if (s && s[0] && s[0] == 'g')
    {
      if (obj->group)
	return (!0x0);
      obj->group = epur_str(s + 1);
      return (!0x0);
    }
  if (!strncmp(s, "usemtl", 6))
    return (!0x0);
  return (0x0);
}

int		add_point(char **xpl, t_obj_tmp *obj_t)
{
  t_dpoint	*p;

  p = xmalloc(sizeof(t_dpoint));
  p->x = atof(xpl[1]);
  p->y = atof(xpl[2]);
  p->z = atof(xpl[3]);
  push_back(obj_t->v, p);
  return (!0x0);
}

int		add_texture(char **xpl, t_obj_tmp *obj_t)
{
  t_dpoint	*p;

  p = xmalloc(sizeof(t_dpoint));
  p->x = atof(xpl[1]);
  p->y = atof(xpl[2]);
  p->z = (my_stralen(xpl) > 3 ? atof(xpl[3]) : 0);
  push_back(obj_t->vt, p);
  return (!0x0);
}

int		add_normal_vect(char **xpl, t_obj_tmp *obj_t)
{
  t_dpoint	*p;

  p = xmalloc(sizeof(t_dpoint));
  p->x = atof(xpl[1]);
  p->y = atof(xpl[2]);
  p->z = atof(xpl[3]);
  push_back(obj_t->vn, p);
  return (!0x0);
}

t_vertex	*get_vertex(char *s, t_obj_tmp *obj_t)
{
  int		tm;
  t_vertex	*v;
  char		**xpl;

  if (my_stralen(xpl = explode(s, "/")) < 1)
    return (0x0);
  v = xmalloc(sizeof(t_vertex));
  tm = atoi(xpl[0]);
  v->point = get_index(obj_t->v, tm);
  if (!v->point && (put_error(PT_N_FOUND, tm)))
    return (0x0);
  if (!v->point)
    return (0x0);
  if (!xpl[1] && !(v->txtres = 0) && !(v->normal = 0))
    return (v);
  tm = atoi(xpl[1]);
  v->txtres = get_index(obj_t->vt, tm);
  if (!xpl[2] && !(v->normal = 0))
    return (v);
  tm = atoi(xpl[2]);
  v->normal = get_index(obj_t->vn, tm);
  free_xpl(xpl);
  return (v);
}
