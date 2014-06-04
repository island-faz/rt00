/*
** my_strncmp.c for mysh in /home/bourhi_a/rendu/PSU_2013_minishell1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Fri Dec 13 00:59:13 2013 
** Last update Sun Mar  9 22:04:34 2014 
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (my_strlen(s2) < n)
    return (1);
  if (my_strlen(s1) < n)
    return (-1);
  while (i < n && s1[i] && s2[i])
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      i++;
    }
  return (0);
}
