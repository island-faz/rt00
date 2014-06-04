/*
** rt.h for rt in /home/bourhi_a/rendu/rt
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Mar 24 04:24:37 2014 
** Last update Wed Jun  4 10:45:02 2014 
*/

#ifndef				RT_H_
# define			RT_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mlx.h>
#include <my.h>
#include <list.h>
#include <math.h>
#include <geometry.h>
#include <mlx_gr.h>
#include <get_next_line.h>

# define WIN_X			200
# define WIN_Y			200

#define DBL_MAX			1.7976931348623158e+308
# define ABS(x)                 ((((x)) < 0) ? (-(x)) : ((x)))
# define M_PI                   3.14159265359

# define PT_N_FOUND		"Cannot find point "
# define TXT_N_FOUND		"Cannot find texture "
# define NRM_N_FOUND		"Cannot find normal "

/*
** Temporary structure helpful for the obj parser
*/
typedef struct	s_obj_tmp
{
  t_glist	*v;
  t_glist	*vt;
  t_glist	*vn;
}		t_obj_tmp;

typedef struct	s_obj
{
  char		*name;
  char		*group;
  t_dpoint	*pos;		/*     Position of the model	*/
  t_dpoint	*angle;		/*        rotation angle	*/
  t_glist	*polygones;	/*        All polys list	*/
}		t_obj;

typedef struct	s_rt
{
  t_graphics	gr;
  t_image	img;
  char		*title;
  t_ray		*cam;
  t_obj		*obj;
}		t_rt;

/*-----------------------[Parser functions]-----------------------------*/

t_obj		*parse_file(int fd);
t_vertex	*get_vertex(char *s, t_obj_tmp *obj_t);
int		add_name_group(t_obj *obj, char *s);
int		add_point(char **xpl, t_obj_tmp *obj_t);
int		add_texture(char **xpl, t_obj_tmp *obj_t);
int		add_normal_vect(char **xpl, t_obj_tmp *obj_t);
int		add_triangle(char **xpl, t_obj *obj, t_obj_tmp *obj_t);
t_obj		*put_error(char *err_msg, int n);
int		check_obj_normals(t_obj *obj);

/*
** This function put the content of obj struct (for debug)
*/
int		show_obj_data(t_obj *obj);

/*-----------------------[Geometry functions]---------------------------*/

t_dpoint	*pcouple_to_vector(t_dpoint *p1, t_dpoint *p2);
t_dpoint	*vcouple_to_normal(t_dpoint *v1, t_dpoint *v2);
int		vects_r_collinear(t_dpoint *v1, t_dpoint *v2);
int		set_obj_pos(t_obj *obj, double x, double y, double z);
int		set_obj_angle(t_obj *obj, double x, double y, double z);
t_dpoint	*new_dpoint(double x, double y, double z);
t_dpoint	*obj_ray_inter(t_obj *obj, t_ray *ray);

/*--------------------------[RT functions]------------------------------*/

int		init_rt(t_rt *rt);

/*------------------------[my mlx functions]----------------------------*/

int		init_graphix(t_rt *rt);
void		img_to_win(t_graphics *gr);
void		pixel_to_image(int x, int y, t_image *img, int color);

/*----------------------------------------------------------------------*/

int	write_bmp(const char *filename, int width, int height, char *rgb);

#endif		/* !RT_H_ */
