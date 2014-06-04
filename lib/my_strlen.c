/*
** my_strlen.c for lib in /home/bourhi_a/rendu/PSU_2013_minitalk/lib
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Mar 18 18:32:06 2014 
** Last update Mon Mar 24 07:29:59 2014 
*/

int	my_strlen(char *a)
{
  int	i;

  i = 0;
  if (!a)
    return (0);
  while (*a && a++)
    i++;
  return (i);
}
