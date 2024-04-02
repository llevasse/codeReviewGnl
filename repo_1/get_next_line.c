#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c, size_t n);
int		read_from_fd(int fd, t_buffer *buf, t_line *line);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*get_next_line(int fd)
{
	static t_buffer	buf = {{0}, 0, 0};
	t_line			line;
	char			*nl;

	init_line(&line);
	nl = ft_strchr(buf.buf + buf.start, '\n', buf.end - buf.start);
	while (nl == NULL)
	{
		if (buf.end != buf.start && add_str_to_line(&line, buf.buf + \
					buf.start, buf.end - buf.start))
			return (NULL);
		if (read_from_fd(fd, &buf, &line))
			return (NULL);
		if (buf.end == 0)
			return (finish_line(&line));
		nl = ft_strchr(buf.buf + buf.start, '\n', buf.end - buf.start);
	}
	nl++;
	if (add_str_to_line(&line, buf.buf + buf.start, nl - (buf.buf + buf.start)))
		return (NULL);
	buf.start = nl - buf.buf;
	return (finish_line(&line));
}

char	*ft_strchr(const char *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (s[i] != (char)c && i < n - 1)
		i++;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

int	read_from_fd(int fd, t_buffer *buf, t_line *line)
{
	buf->end = read(fd, buf->buf, BUFFER_SIZE);
	buf->start = 0;
	if (buf->end < 0)
	{
		if (line->line)
			free(line->line);
		buf->end = 0;
		return (1);
	}
	return (0);
}
