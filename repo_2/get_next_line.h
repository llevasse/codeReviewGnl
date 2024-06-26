#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
void		fill_char(char *dst, char *src, int till_nl);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);
int			is_nl(const char *str);
void		get_left_over(char *line, char *stach);
void		clear_buff(char buff[BUFFER_SIZE]);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_setzero(char *stach);
void		empty_buff(char buff[BUFFER_SIZE]);
char		*check_stach_nl(char *stach, char buff[BUFFER_SIZE + 1], int fd);
char		*stach_empty(char *stach, int fd, char buff[BUFFER_SIZE]);
char		*return_line(char *stach);

#endif
