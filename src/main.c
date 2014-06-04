/*
** main.c for rt in /home/bourhi_a/rendu/rt
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Mar 24 04:09:53 2014 
** Last update Wed Jun  4 10:51:36 2014 
*/

#include <stdio.h>
#include <rt.h>

void		rot_arround_axis(t_dpoint **p, t_dpoint *r, double theta)
{
  t_dpoint	*tmp;
  double	costheta;
  double	sintheta;

  tmp = xmalloc(sizeof(t_dpoint));
  costheta = cos(theta);
  sintheta = sin(theta);
  tmp->x = (costheta + (1 - costheta) * r->x * r->x) * (*p)->x;
  tmp->x += ((1 - costheta) * r->x * r->y - r->z* sintheta) * (*p)->y;
  tmp->x += ((1 - costheta) * r->x * r->z + r->y* sintheta) * (*p)->z;
  tmp->y = ((1 - costheta) * r->x * r->y+ r->z * sintheta) * (*p)->x;
  tmp->y += (costheta + (1 - costheta) *r->y * r->y) * (*p)->y;
  tmp->y += ((1 - costheta) * r->y * r->z - r->x * sintheta) * (*p)->z;
  tmp->z = ((1 -costheta) * r->x * r->z - r->y * sintheta) * (*p)->x;
  tmp->z += ((1 - costheta) * r->y * r->z + r->x * sintheta) * (*p)->y;
  tmp->z += (costheta + (1 - costheta) *r->z * r->z) * (*p)->z;
  free(*p);
  *p = tmp;
}

int		render_obj(t_obj *obj, t_ray *cam, t_graphics *gr, t_image *img)
{
  int		x;
  int		y;
  t_ray		*ray;
  t_dpoint	*z_axis;
  t_dpoint	*xy_axis;
  t_dpoint	*intersec;

  if ((y = -1) && (ray = xmalloc(sizeof(t_ray))))
    ray->origin = new_dpoint(cam->origin->x, cam->origin->y, cam->origin->z);
  ray->vector = new_dpoint(cam->vector->x, cam->vector->y, cam->vector->z);
  if ((z_axis = new_dpoint(0, 0, 1)) && (xy_axis = new_dpoint(1, -1, 0)))
    rot_arround_axis(&ray->vector, xy_axis, (M_PI / 12));
  while (++y < WIN_Y && (x = -1))
    {
      printf("\r%d / %d\n", y, WIN_Y);
      rot_arround_axis(&ray->vector, z_axis, (M_PI / 12));
      while (++x < WIN_X)
	{
	  if ((intersec = obj_ray_inter(obj, ray)))
	    {
	      free(intersec);
	      pixel_to_image(x, y, img, 0x6D7B8D);
	    }
	  rot_arround_axis(&ray->vector, z_axis, -(M_PI / 6) / WIN_X);
	}
      rot_arround_axis(&ray->vector, z_axis, (M_PI / 12));
      rot_arround_axis(&ray->vector, xy_axis, -(M_PI / 6) / WIN_Y);
      img_to_win(gr);
    }
  img_to_win(gr);
  return (!0x0);
}

int		main(int ac, char **av)
{
  int		fd;
  t_rt		rt;

  if (ac < 2 && write(2, "usage: ./rt file1.obj\n", 22))
    return (!0x0);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      write(2, "Error: cannot open file.\n", 25);
      return (!0x0);
    }
  init_rt(&rt);
  if (!init_graphix(&rt))
    {
      write(2, "Cannot init graphix->\n", 21);
      return (0x0);
    }
  if (!(rt.obj = parse_file(fd)))
    return (!0x0);
  printf("%s (%d polys) [Ok]\n", av[1], rt.obj->polygones->len);
  set_obj_pos(rt.obj, 10, 10, 10);
  /* set_obj_angle(rt.obj, 0, 0, M_PI / 3); */
  render_obj(rt.obj, rt.cam, &(rt.gr), &(rt.img));
  printf("render is done.\n");
  sleep(5000);
  return (0x0);
}
