/*
** my_memset.c for allum1 in /home/bourhi_a/rendu/Allum1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Fri Feb  7 01:01:34 2014 
** Last update Thu Mar 20 21:33:19 2014 
*/

void	my_memset(void *s, int c, int l)
{
  char	*tmp;

  tmp = (char*)s;
  while (l > 0)
    {
      *tmp++ = c;
      l--;
    }
}
