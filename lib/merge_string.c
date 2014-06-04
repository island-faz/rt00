/*
** merge_string.c for rtv1 in /home/bourhi_a/rendu/MUL_2013_rtv1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Mar 10 17:38:01 2014 
** Last update Tue Jun  3 23:47:03 2014 
*/

#include <string.h>
#include <stdlib.h>
#include <my.h>

char		*lmg(char *a, char *b)
{
  char		*res;
  int		inc[2];
  int		len[2];

  inc[0] = 0;
  inc[1] = 0;
  len[0] = strlen(a);
  len[1] = strlen(b);
  if (!(res = malloc(len[0] + len[1] + 1)))
    return (0);
  while (inc[0] < len[0])
    {
      res[inc[0]] = a[inc[0]];
      (inc[0])++;
    }
  while (inc[1] < len[1])
    {
      res[inc[0]] = b[inc[1]];
      (inc[0])++;
      (inc[1])++;
    }
  res[inc[0]] = '\0';
  return (res);
}

char		*merge_string(char *a, char *b)
{
  if (!a && b)
    return (b); 
  if (!b && a)
    return (a); 
  if (!a && !b)
    return (0);
  return (lmg(a, b));
}
