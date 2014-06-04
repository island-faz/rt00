/*
** geometry.h for rt in /home/bourhi_a/rendu/rt/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed May 28 04:51:21 2014 
** Last update Wed Jun  4 10:41:20 2014 
*/

#ifndef				GEOMETRY_H_
# define			GEOMETRY_H_

#define CAST_QUADRILA(x)	((t_quadri*)(x))
#define CAST_TRIANGLE(x)	((t_triangle*)(x))
#define CAST_POLYGONE(x)	((t_polygone*)(x))

typedef struct	s_dpoint
{
  double	x;
  double	y;
  double	z;
}		t_dpoint;

typedef struct	s_plane
{
  t_dpoint	*coor;
  t_dpoint	*normal;
}		t_plane;

typedef struct	s_ray
{
  t_dpoint	*origin;
  t_dpoint	*vector;
}		t_ray;

typedef struct	s_vertex
{
  t_dpoint	*point;
  t_dpoint	*normal;	/*     Normal vector to the polygone	*/
  t_dpoint	*txtres;
}		t_vertex;

typedef struct	s_triangle
{
  t_vertex	*v1;
  t_vertex	*v2;
  t_vertex	*v3;
}		t_triangle;

typedef struct	s_quadri
{
  t_vertex	*v1;
  t_vertex	*v2;
  t_vertex	*v3;  
  t_vertex	*v4;
}		t_quadri;

typedef struct	s_polygone
{
  char		type;		/*   (1 : triangle, 2 : quadrilateral)	*/
  void		*polygone;	/*     can be t_triangle or t_quadri	*/
}		t_polygone;

/*------------------------[geometry functions]--------------------------*/

double		dot_product(t_dpoint *v1, t_dpoint *v2);
t_dpoint	*plane_ray_inters(t_plane *plane, t_ray *ray);
t_dpoint	*triangle_ray_inter(t_triangle *tr, t_dpoint *pos, t_ray *ray);
t_dpoint	*quad_ray_inter(t_quadri *q, t_dpoint *pos, t_ray *ray);
void		move_dpoint(t_dpoint *p, t_dpoint *inc);
void		rotate(t_dpoint *coor, double, double, double);

/*----------------------------------------------------------------------*/

#endif				/* !GEOMETRY_H_ */
