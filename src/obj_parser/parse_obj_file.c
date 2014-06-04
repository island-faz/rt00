/*
** parse_obj_file.c for rt in /home/bourhi_a/rendu/rt/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue May 27 03:29:46 2014 
** Last update Wed Jun  4 08:20:21 2014 
*/

#include <string.h>
#include <unistd.h>
#include <rt.h>

int		init_obj_data(t_obj **obj, t_obj_tmp **obj_t)
{
  (*obj) = xmalloc(sizeof(t_obj));
  (*obj)->name = 0;
  (*obj)->group = 0;
  (*obj)->polygones = init_list();
  (*obj_t) = xmalloc(sizeof(t_obj_tmp));
  (*obj_t)->v = init_list();
  (*obj_t)->vt = init_list();
  (*obj_t)->vn = init_list();
  return (!0x0);
}

int		add_triangle(char **xpl, t_obj *obj, t_obj_tmp *obj_t)
{
  t_polygone	*poly;
  t_triangle	*triangle;

  triangle = xmalloc(sizeof(t_triangle));
  triangle->v1 = get_vertex(xpl[1], obj_t);
  if (!triangle->v1)
    return (0x0);
  triangle->v2 = get_vertex(xpl[2], obj_t);
  if (!triangle->v2)
    return (0x0);
  triangle->v3 = get_vertex(xpl[3], obj_t);
  if (!triangle->v3)
    return (0x0);
  poly = xmalloc(sizeof(t_polygone));
  poly->type = 1;
  poly->polygone = triangle;
  push_back(obj->polygones, poly);
  return (!0x0);
}

int		add_quadrilateral(char **xpl, t_obj *obj, t_obj_tmp *obj_t)
{
  t_polygone	*poly;
  t_quadri	*quadri;

  quadri = xmalloc(sizeof(t_quadri));
  quadri->v1 = get_vertex(xpl[1], obj_t);
  if (!quadri->v1)
    return (0x0);
  quadri->v2 = get_vertex(xpl[2], obj_t);
  if (!quadri->v2)
    return (0x0);
  quadri->v3 = get_vertex(xpl[3], obj_t);
  if (!quadri->v3)
    return (0x0);
  quadri->v4 = get_vertex(xpl[4], obj_t);
  if (!quadri->v4)
    return (0x0);
  poly = xmalloc(sizeof(t_polygone));
  poly->type = 2;
  poly->polygone = quadri;
  push_back(obj->polygones, poly);
  return (!0x0);
}

int		put_obj_data(char **xpl, t_obj *obj, t_obj_tmp *obj_t)
{
  char		xpl_len;

  if (!xpl || !xpl[0])
    return (0x0);
  xpl_len = my_stralen(xpl);
  if (xpl_len == 4 && !strcmp(xpl[0], "v"))
    return (add_point(xpl, obj_t));
  if (xpl_len >= 3 && !strcmp(xpl[0], "vt"))
    return (add_texture(xpl, obj_t));
  if (xpl_len == 4 && !strcmp(xpl[0], "vn"))
    return (add_normal_vect(xpl, obj_t));
  if (!my_strcmp(xpl[0], "f"))
    {
      if (xpl_len == 4)
	return (add_triangle(xpl, obj, obj_t));
      if (xpl_len == 5)
      	return (add_quadrilateral(xpl, obj, obj_t));
    }
  return (!0x0);
}

t_obj		*parse_file(int fd)
{
  int		i;
  char		*s;
  char		**xpl;
  int		flag;
  t_obj		*obj;
  t_obj_tmp	*obj_t;

  i = 1;
  init_obj_data(&obj, &obj_t);
  while ((s = get_next_line(fd)) && (s = epur_str(s)) && !(flag = 0) && i++)
    {
      if (strlen(s) && s[0] != '#' && (xpl = explode(s, " ")))
	{
	  if (!obj->name || !obj->group)
	    flag = add_name_group(obj, s);
	  if (!flag && !put_obj_data(xpl, obj, obj_t))
	    return (put_error("Error at line ", i));
	  free_xpl(xpl);
	}
      free(s);
    }
  obj->pos = xmalloc(sizeof(t_dpoint));
  obj->angle = xmalloc(sizeof(t_dpoint));
  if (set_obj_pos(obj, 10, 10, 0) && set_obj_angle(obj, 0, 0, 0))
    check_obj_normals(obj);
  return (obj);
}
