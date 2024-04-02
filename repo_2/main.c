#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv){
	if (argc == 1)
		return (0);
	int	i = 1;
	int	fd;
	char	*s;
	while (i < argc){
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			continue ;
		while (1){
			s = get_next_line(fd);
			if (!s)
				break ;
			printf("%s", s);
			free(s);
		}
		close(fd);
		i++;
	}
}
