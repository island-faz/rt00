/*
** get_next_line.h for get_next_line in /home/bourhi_a/rendu/rt
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Mar 24 05:24:38 2014 
** Last update Tue Jun  3 05:04:55 2014 
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

#include <stdlib.h>
#include <unistd.h>
#include <my.h>

# define	BUFF_SIZE 1024 * 4

char		*get_next_line(const int fd);

#endif		/* !GET_NEXT_LINE_H_ */
