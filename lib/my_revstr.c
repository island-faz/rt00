/*
** my_revstr.c for lib in /home/bourhi_a/rendu/PSU_2013_minitalk/lib
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Mar 18 18:49:17 2014 
** Last update Tue Mar 18 18:49:23 2014 
*/

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  int	limit;
  char	tmp;
  char	tmp2;

  i = 0;
  j = my_strlen(str) - 1;
  limit = j / 2;
  while (j > limit)
    {
      tmp = str[i];
      tmp2 = str[j];
      str[i] = tmp2;
      str[j] = tmp;
      i++;
      j--;
    }
  return (str);
}
