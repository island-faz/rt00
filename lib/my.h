/*
** my.h for lib in /home/bourhi_a/rendu/PSU_2013_minitalk/lib
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Mar 18 18:28:33 2014 
** Last update Wed Jun  4 03:10:15 2014 
*/

#ifndef		MY_H_
# define	MY_H_

int		is_digit(char c);
char            *epur_str(char *s);
int		is_file(char *path);
int		my_putstr(char *s);
int		my_strlen(char *s);
int		my_stralen(char **a);
int		my_putnbr(int nbr);
void            *xmalloc(unsigned  int size);
char		*my_revstr(char *str);
int		my_atoi(char *s);
double		my_atof(char *s);
char		*my_strdup(char *src);
int		free_xpl(char **xpl);
char		**explode(char *s, char *sep);
int		explose(char **s, char op_tag, char cl_tag);
void		my_memset(void *s, int c, int l);
char		*merge_string(char *a, char *b);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_char_replace(char *str, char old, char new);

#endif		/* MY_H_ */
