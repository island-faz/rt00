/*
** img_to_win.c for rt in /home/bourhi_a/rendu/rt
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sat May 31 03:14:50 2014 
** Last update Sat May 31 03:14:59 2014 
*/

#include <rt.h>

void      img_to_win(t_graphics *gr)
{
  mlx_put_image_to_window(gr->mlx_ptr, gr->win_ptr, gr->img_ptr, 0, 0);
}
