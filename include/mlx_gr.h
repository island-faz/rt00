/*
** mlx_gr.h for rt in /home/bourhi_a/rendu/rt/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed May 28 04:54:22 2014 
** Last update Fri May 30 23:40:12 2014 
*/

#ifndef		MLX_GR_H_
# define	MLX_GR_H_

typedef struct  s_graphics
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
}		t_graphics;

typedef struct  s_image
{
  int           bpp;
  int		sizeline;
  int		*data;
  int		endian;
  int		end;
}		t_image;

#endif		/* !MLX_GR_H_ */
