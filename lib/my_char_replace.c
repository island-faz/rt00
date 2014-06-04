/*
** str_replace.c for minishell in /home/bourhi_a/rendu/PSU_2013_minishell1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Dec 26 06:07:05 2013 
** Last update Mon Mar 10 18:43:48 2014 
*/

char	*my_char_replace(char *str, char old, char new)
{
  int	i;

  if (!str || !old || !new)
    return (0);
  i = 0;
  while (str[i])
    {
      if (str[i] == old)
	str[i] = new;
      i++;
    }
  return (str);
}
