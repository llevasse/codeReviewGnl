#include "get_next_line.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	init_line(t_line *line)
{
	line->len = 0;
	line->allocated = 0;
	line->line = NULL;
}

int	add_to_line(t_line *line, char c)
{
	char	*new;

	if (line->len == line->allocated)
	{
		if (line->allocated == 0)
			line->allocated = 8096;
		else
			line->allocated *= 2;
		new = malloc(line->allocated);
		if (new == NULL)
		{
			free(line->line);
			return (1);
		}
		ft_memcpy(new, line->line, line->len);
		if (line->line)
			free(line->line);
		line->line = new;
	}
	line->line[line->len] = c;
	line->len++;
	return (0);
}

int	add_str_to_line(t_line *line, char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (add_to_line(line, s[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*finish_line(t_line *line)
{
	char	*new;

	if (line->line == NULL)
		return (NULL);
	new = malloc(line->len + 1);
	if (new == NULL)
	{
		free(line->line);
		return (NULL);
	}
	ft_memcpy(new, line->line, line->len);
	new[line->len] = '\0';
	free(line->line);
	return (new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		n--;
		((char *)(dest))[n] = ((char *)(src))[n];
	}
	return (dest);
}
