/*
** is_file.c for 106bombyx in /home/bourhi_a/rendu/106bombyx
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Feb 18 09:04:10 2014 
** Last update Mon Mar 24 05:02:14 2014 
*/

#include <sys/stat.h>

int		is_file(char *path)
{
  struct stat	sb;

  if (!lstat(path, &sb))
    return (S_ISREG(sb.st_mode)) ? (1) : (0);
  return (0);
}
