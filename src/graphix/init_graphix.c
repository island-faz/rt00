/*
** init_rt.c for rt in /home/bourhi_a/rendu/rt
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Fri May 30 15:44:14 2014 
** Last update Fri May 30 23:37:19 2014 
*/

#include <rt.h>

int	init_graphix(t_rt *rt)
{
  if (!(rt->gr.mlx_ptr = mlx_init()))
    return (0);
  if (!(rt->gr.img_ptr = mlx_new_image(rt->gr.mlx_ptr,
					 WIN_X, WIN_Y)))
    return (0);
  if (!(rt->gr.win_ptr = mlx_new_window(rt->gr.mlx_ptr,
					  WIN_X, WIN_Y, "RT")))
    return (0);
  rt->img.data = (int *)mlx_get_data_addr(rt->gr.img_ptr,
					   &rt->img.bpp,
					   &rt->img.sizeline,
					   &rt->img.endian);
  rt->img.end = (rt->img.sizeline * WIN_Y / 4) - 1;
  return (1);
}
