/*
** my_stralen.c for my_stralen in /home/bourhi_a/rendu/rt
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Mar 24 07:36:00 2014 
** Last update Mon Mar 24 07:37:39 2014 
*/

int	my_stralen(char **a)
{
  int	i;

  if (!a)
    return (0);
  i = 0;
  while (a[i])
      i++;
  return (i);
}
