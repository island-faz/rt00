/*
** is_digit.c for lib in /home/bourhi_a/rendu/MUL_2013_rtv1/lib
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Mar 16 18:56:13 2014 
** Last update Sun Mar 16 18:56:15 2014 
*/

int		is_digit(char c)
{
  return (c >= '0' && c <= '9' ? 1 : 0);
}
